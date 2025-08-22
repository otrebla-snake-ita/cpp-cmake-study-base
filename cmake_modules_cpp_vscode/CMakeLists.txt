# Youtube video reference: https://www.youtube.com/watch?v=RYrtMgMARBM 
cmake_minimum_required(VERSION 4.1.0)
project(Rooster VERSION 0.1.0 LANGUAGES C CXX)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
# Turning off extensions avoids issues with the CLang 16 compiler, but from CLang 17 this can be avoided.
SET(CMAKE_CXX_EXTENSIONS OFF)

# Building the fmt library dependency
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.2.0
)

FetchContent_MakeAvailable(fmt)

# Create a library, we set up the calculator library.
add_library(calculator)
# We add the module file to the library. The module file will be brought in to be part of a library in CMake.
# We specify the library we want these things to be part of. The "PUBLIC" keyword is not explained in this video.
# We specify the type of the file that we are putting in this library. The FILE_SET CXX MODULES FILES means that these
# are going to be C++20 module files. If needed, we can keep adding module files (e.g. a math.ixx module).
target_sources(calculator
    PUBLIC
    FILE_SET CXX_MODULES FILES
    calculator.ixx
)

# Once we have the library declared, we need to link to it if we have any other target using it and we want our executable
# rooster.exe to be linked against the library, so that things from main.cpp can use things from calculator.
add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE fmt::fmt calculator)