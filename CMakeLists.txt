#
# CMakeLists.txt
# Copyright Tim Wroge 202020

cmake_minimum_required (VERSION 3.5 FATAL_ERROR)
include(ExternalProject)

project (ProjectName
    VERSION 1.0.0
    LANGUAGES CXX
)
set(PRECOMPILED_README ${CMAKE_SOURCE_DIR}/PRECOMPILED_README.md)
set(OUTPUT_README ${CMAKE_SOURCE_DIR}/README.md)

if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")

    add_custom_target (readme_depends
        COMMAND pip3 install --user readme2tex
    )

    add_custom_target (readme
        DEPENDS ${PRECOMPILEDREADME} ${OUTPUT_README} readme_depends
        COMMAND python3 -m readme2tex  --svgdir doc/equations --nocdn --output README.md PRECOMPILED_README.md
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )

    add_custom_target (tests
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif ()
# add some ... compiler flags
set (CMAKE_CXX_FLAGS " -std=c++17 -fexceptions -pedantic -O -Wall -Weffc++ -pedantic")

# makes teh binaries go to release within the cmake binary directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
#include(${CMAKE_SOURCE_DIR}/include/)

set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/release)

# example External project
# ExternalProject_Add(manif
#     TMP_DIR ${CMAKE_SOURCE_DIR}/external/manif/misc
#     PREFIX  ${CMAKE_SOURCE_DIR}/external/manif/
#     BINARY_DIR ${CMAKE_SOURCE_DIR}/external/manif/build
#     DOWNLOAD_DIR ${CMAKE_SOURCE_DIR}/external/manif/misc/
#     STAMP_DIR ${CMAKE_SOURCE_DIR}/external/manif/stamp/
#     INSTALL_DIR ${CMAKE_SOURCE_DIR}/external/manif/install
#     CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/external/manif/install"
#     GIT_REPOSITORY git@github.com:artivis/manif.git
#     GIT_TAG 0.0.3)

#add subdirectories for the rest of the project
add_subdirectory(src)
add_subdirectory(test)
