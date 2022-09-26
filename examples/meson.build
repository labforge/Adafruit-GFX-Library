source_files = files([
  'main.cpp',
])

stereo_aq = executable(
  'example',
  source_files,
  include_directories : app_inc,
  install: true,
  dependencies: [app_deps],
  link_with: lib_gfx,
)