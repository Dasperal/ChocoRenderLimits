set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

cmake_minimum_required(VERSION 3.7.2)
project("CRL" VERSION 1.0.0 LANGUAGES C)

# Autotools variables
set(top_srcdir ${CMAKE_CURRENT_SOURCE_DIR})
set(top_builddir ${CMAKE_CURRENT_BINARY_DIR})

# AC_INIT variables
set(PACKAGE_VERSION "1.0")
set(PACKAGE_NAME "${PROJECT_NAME}")
set(PACKAGE_TARNAME "crl-doom")
set(PACKAGE_STRING "${PROJECT_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "julia.nechaevskaya@live.com")

string(REGEX REPLACE " Doom$" "" PACKAGE_SHORTNAME "${PACKAGE_NAME}")
set(PACKAGE_COPYRIGHT "Copyright (C) 2023 Julia Nechaevskaya")
set(PACKAGE_LICENSE "GNU GPL (version 2)")

# Any settings that should apply to all targets in this directory and all
# subdirectories should go here.  Use judiciously.
if(MSVC)
    add_definitions("/D_CRT_SECURE_NO_WARNINGS" "/D_CRT_SECURE_NO_DEPRECATE"
                    "/D_CRT_NONSTDC_NO_DEPRECATE")
else()
    add_compile_options("-Wall" "-Wdeclaration-after-statement"
                        "-Wredundant-decls")
endif()

option(ENABLE_SDL2_NET "Enable SDL2_net" On)
option(ENABLE_SDL2_MIXER "Enable SDL2_mixer" On)

find_package(SDL2 2.0.7)
if(ENABLE_SDL2_MIXER)
    find_package(SDL2_mixer 2.0.2)
else()
    add_compile_definitions(DISABLE_SDL2MIXER=1)
endif()

if(ENABLE_SDL2_NET)
    find_package(SDL2_net 2.0.0)
else()
    add_compile_definitions(DISABLE_SDL2NET=1)
endif()

# Check for libsamplerate.
find_package(samplerate)
if(SAMPLERATE_FOUND)
    set(HAVE_LIBSAMPLERATE TRUE)
endif()

# Check for Miniz (replaces libpng).
find_package(miniz 2.0.0)
if(NOT MINIZ_FOUND)
    message(STATUS "Using vendored miniz library")
    add_subdirectory("miniz")
endif()

find_package(m)

include(CheckSymbolExists)
include(CheckIncludeFile)
check_symbol_exists(strcasecmp "strings.h" HAVE_DECL_STRCASECMP)
check_symbol_exists(strncasecmp "strings.h" HAVE_DECL_STRNCASECMP)
check_include_file("dirent.h" HAVE_DIRENT_H)

string(CONCAT WINDOWS_RC_VERSION "${PROJECT_VERSION_MAJOR}, "
    "${PROJECT_VERSION_MINOR}, ${PROJECT_VERSION_PATCH}, 0")

# Without a hyphen. This is used for the bash-completion scripts.
string(TOLOWER "${PACKAGE_SHORTNAME}" PROGRAM_SPREFIX)

# With a hyphen, used almost everywhere else.
set(PROGRAM_PREFIX "${PROGRAM_SPREFIX}-")

configure_file(cmake/config.h.cin config.h)

configure_file(src/doom-res.rc.in src/doom-res.rc)
configure_file(src/setup-res.rc.in src/setup-res.rc)
configure_file(src/setup/setup-manifest.xml.in src/setup/setup-manifest.xml)

foreach(SUBDIR textscreen opl pcsound src)
    add_subdirectory("${SUBDIR}")
endforeach()
