#include <cstdlib>
#include <cstdio>

#include "Adafruit_GFX.h"

u_int8_t *read_raw(const char*name) {
    FILE *f = fopen(name, "rb");
    fseek(f, 0, SEEK_END);
    size_t file_size = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    u_int8_t *contents = new u_int8_t[file_size];
    ssize_t sz = fread(contents, file_size, 1, f);
    if(sz < 0) {
        fprintf(stderr, "IO error reading: %s\n", name);
    }
    fclose(f);

    return contents;
}

void write_raw(const char*name, uint8_t*contents, size_t size) {
    FILE *f = fopen(name, "wb");
    ssize_t sz = fwrite(contents, size, 1, f);
    if(sz < 0) {
        fprintf(stderr, "Could not write to file: %s\n", name);
        exit(1);
    }
    fclose(f);
}

int main(int argc, char**argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage %s <infile> <outfile>\n", argv[0]);
        return 1;
    }
    u_int8_t *buffer = read_raw(argv[1]);

    GFXcanvas24 canvas(128, 128, buffer);
    canvas.drawLine(10, 10, 118, 10, GFXcanvas24::RgbToRgb565(0xFF, 0, 0));

    write_raw(argv[2], buffer, 128*128*3);

    delete [] buffer;


    return 0;
}