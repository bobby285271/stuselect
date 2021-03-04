stuselect_sources = [
  'main.vala',
  'window.vala',
]

stuselect_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

stuselect_sources += gnome.compile_resources('stuselect-resources',
  'stuselect.gresource.xml',
  c_name: 'stuselect'
)

executable('stuselect', stuselect_sources,
  vala_args: '--target-glib=2.50',  dependencies: stuselect_deps,
  install: true,
)
