## Project definition
# https://mesonbuild.com/Reference-manual.html#project
project('Adafruit GFX Library', ['c', 'cpp'],
    version : '1.11.3LF',
    license : 'BSD',
    meson_version : '>= 0.52',
    default_options : ['cpp_std=gnu++17',
                       'warning_level=3',
                       'buildtype=release',
                       'b_ndebug=if-release',
                       'werror=true',
                       'warning_level=3',
                       ],
    )

## Add all library dependencies here before subdirectories and executables
cpp = meson.get_compiler('cpp')

# Lump together all monolithic dependencies from above
app_deps = []

test_cpp_args = []
test_link_args = []

app_inc = include_directories(
	'.',
	)

library('adafruitgfx', ['Adafruit_GFX.cpp', 'glcdfont.c'], version : '1.11.3')