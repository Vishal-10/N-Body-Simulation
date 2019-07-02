n_body_sources = [
  'Body.hpp',
  'Constants.hpp',
  'Main.cpp',
  'Math.cpp',
  'Math.hpp',
  'Graphics.cpp',
  'Graphics.hpp',
  'Simulator.cpp',
  'Simulator.hpp'
]

n_body_dependencies = [
  dependency('GL'),
  dependency('glu'),
  dependency('glut'),
  dependency('eigen3'),
]

exe_c_args = []

executable('n-body', n_body_sources,
  exe_c_args,
  dependencies: n_body_dependencies,
  gui_app: true,
  install: true,
  pie: true,
)

