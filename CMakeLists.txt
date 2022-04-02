# --------------------------------------------------
# CMAKE VERSION
# --------------------------------------------------
cmake_minimum_required(VERSION 3.12)

# --------------------------------------------------
# PROJECT NAME AND VERSION
# --------------------------------------------------
project(camera VERSION 1.0)

# --------------------------------------------------
# GENERATE COMPILATION DATABASE (FOR YCM)
# --------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------
# BUILD SHARED LIBRARIES
# --------------------------------------------------
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# --------------------------------------------------
# CONFIGURATION HEADER
# --------------------------------------------------
configure_file(include/Config.h.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h)

# -------------------------------------------------
# Add Library for Exetable file
# -------------------------------------------------

# Compile shared library from source files
add_library(v4l2_lib lib/camera.cpp lib/cv.cpp)

# State that any target linking to this library can see 
# the passed source directories
target_include_directories(v4l2_lib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

link_directories(/usr/lib/x86_64-linux-gnu/)

target_link_libraries(v4l2_lib opencv_core opencv_imgproc opencv_highgui)
# --------------------------------------------------
# EXECUTABLE
# --------------------------------------------------

add_executable(camera
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Link Executable file to the library
target_link_libraries(camera v4l2_lib)


# --------------------------------------------------
# TARGET INCLUDE DIRECTORIES
# --------------------------------------------------
target_include_directories(camera PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

# --------------------------------------------------
# SET OUTPUT DIRECTORIES
# --------------------------------------------------
set_target_properties(camera
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")
     
# --------------------------------------------------
# COMPILER FLAGS
# --------------------------------------------------
#target_compile_features(Boilerplate PUBLIC cxx_std_11)

# add compiler warning flags just when building this project
# via the BUILD_INTERFACE generator expression
#set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
#set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

#set(gcc_flags "-Wall;-Wextra;-Wshadow;-Wshadow;-Wformat=2")
#set(msvc_flags "-W3")

#target_compile_options(Boilerplate PRIVATE
#   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
#   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")

#target_compile_options(interp PRIVATE
#   "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_flags}>>"
#   "$<${msvc_cxx}: $<BUILD_INTERFACE:${msvc_flags}>>")
