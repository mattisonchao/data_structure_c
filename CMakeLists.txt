cmake_minimum_required(VERSION 3.26.4)

project(data_structure_c)

set(CMAKE_C_STANDARD 99)

# --------- copy from criterion https://github.com/Snaipe/Criterion/blob/bleeding/dev/FindCriterion.cmake
find_package(PkgConfig)
find_path(CRITERION_INCLUDE_DIR criterion/criterion.h
        PATH_SUFFIXES criterion)
find_library(CRITERION_LIBRARY NAMES criterion libcriterion)
set(CRITERION_LIBRARIES ${CRITERION_LIBRARY})
set(CRITERION_INCLUDE_DIRS ${CRITERION_INCLUDE_DIR})
include(FindPackageHandleStandardArgs)
# handle the QUIET and REQUIRED arguments and set CRITERION_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Criterion DEFAULT_MSG
        CRITERION_LIBRARY CRITERION_INCLUDE_DIR)
mark_as_advanced(CRITERION_INCLUDE_DIR CRITERION_LIBRARY)
# ----------------------------------------------------

add_library(data_structure_lib src/list.c)
add_executable(tests tests/list_test.c)

target_link_libraries(tests ${CRITERION_LIBRARIES} data_structure_lib)
include_directories(${CRITERION_INCLUDE_DIRS})
include_directories(./include)

enable_testing()
add_test(NAME DATA_STRUCTURE_C COMMAND tests)
