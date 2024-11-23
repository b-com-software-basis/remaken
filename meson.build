project('remaken', 'cpp')
#NOTE: BOOST_OS_LINUX_AVAILABLE is defined hardcoded : must figure out why os detection doesn't work within boost/predef ?
add_project_arguments('-DMYVERSIONSTRING="1.10.1"', '-DBOOST_OS_LINUX_AVAILABLE', language : 'cpp')
cc = meson.get_compiler('cpp')
incdir = include_directories('libs/CLI11/include', 'libs/nlohmann-json/single_include', 'src')
openssl_dep = dependency('openssl')
boost_lib_dir = meson.project_source_root() / 'libs/boost_install/lib'
boost_dep = declare_dependency(
  dependencies : [cc.find_library('boost_atomic', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_charconv', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_chrono', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_cobalt', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_container', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_context', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_contract', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_coroutine', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_date_time', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_fiber', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_fiber_numa', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_filesystem', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_graph', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_iostreams', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_json', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_locale', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_log', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_log_setup', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_nowide', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_prg_exec_monitor', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_process', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_program_options', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_random', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_serialization', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_stacktrace_addr2line', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_stacktrace_backtrace', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_stacktrace_basic', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_stacktrace_from_exception', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_stacktrace_noop', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_test_exec_monitor', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_thread', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_timer', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_type_erasure', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_unit_test_framework', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_url', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_wave', dirs : [boost_lib_dir]), \ 
    cc.find_library('boost_wserialization', dirs : [boost_lib_dir])], \ 
  include_directories : include_directories('libs/boost_install/include/boost')
)

#boost_dep = dependency('boost', modules : ['DLL', 'Filesystem', 'Fiber'])
remaken = executable('remaken',  'src/backends/BackendGeneratorFactory.cpp', \
    'src/backends/BazelGeneratorBackend.cpp', \
    'src/backends/CMakeGeneratorBackend.cpp', \
    'src/backends/JSONGeneratorBackend.cpp', \
    'src/backends/QMakeGeneratorBackend.cpp', \
    'src/backends/MesonGeneratorBackend.cpp', \
    'src/commands/RemoteCommand.cpp', \
    'src/commands/SearchCommand.cpp', \
    'src/managers/BundleManager.cpp', \
    'src/commands/BundleXpcfCommand.cpp', \
    'src/commands/CleanCommand.cpp', \
    'src/commands/ConfigureCommand.cpp', \
    'src/commands/ListCommand.cpp', \
    'src/managers/XpcfXmlManager.cpp', \
    'src/tools/BrewSystemTool.cpp', \
    'src/tools/ConanSystemTool.cpp', \
    'src/tools/GitTool.cpp', \
    'src/commands/InfoCommand.cpp', \
    'src/commands/PackageCommand.cpp', \
    'src/commands/InitCommand.cpp', \
    'src/tools/NativeSystemTools.cpp', \
    'src/tools/PkgConfigTool.cpp', \
    'src/utils/DepUtils.cpp', \
    'src/utils/OsUtils.cpp', \
    'src/utils/PathBuilder.cpp', \
    'src/commands/ProfileCommand.cpp', \
    'src/commands/RunCommand.cpp', \
    'src/tools/VCPKGSystemTool.cpp', \
    'src/tools/ZipTool.cpp', \
    'src/main.cpp', \
    'src/Dependency.cpp', \
    'src/managers/DependencyManager.cpp', \
    'src/Constants.cpp', \
    'src/CmdOptions.cpp', \
    'src/Cache.cpp', \
    'src/commands/InstallCommand.cpp', \
    'src/commands/VersionCommand.cpp', \
    'src/commands/AbstractCommand.cpp', \
    'src/FileHandlerFactory.cpp', \
    'src/retrievers/CredentialsFileRetriever.cpp', \
    'src/retrievers/FSFileRetriever.cpp', \
    'src/retrievers/HttpFileRetriever.cpp', \
    'src/retrievers/AbstractFileRetriever.cpp', \
    'src/HttpHandlerFactory.cpp', \
    'src/retrievers/ConanFileRetriever.cpp', \
    'src/retrievers/SystemFileRetriever.cpp', \
    'src/tools/SystemTools.cpp', \
    'src/commands/ParseCommand.cpp', \
    'src/commands/BundleCommand.cpp', \
    'src/tinyxml2.cpp', \
    'src/tinyxmlhelper.cpp', 
    include_directories : incdir, 
    dependencies : [boost_dep, openssl_dep])
