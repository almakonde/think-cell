cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(think-cell)

### External Libraries ##############
set(FindModuleDir ${CMAKE_SOURCE_DIR}/cmake CACHE STRING "path to directory containing the Find<Module>.cmake modules")
mark_as_advanced(FindModuleDir)
list(APPEND CMAKE_MODULE_PATH ${FindModuleDir})
find_package(Catch2 REQUIRED MODULE)

### Testing #########################
ENABLE_TESTING()
include(CTest)

### Main Body #######################
add_subdirectory(src)