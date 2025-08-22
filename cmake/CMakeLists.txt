# Reference video: https://www.youtube.com/watch?v=4U-lnfxY2U0

cmake_minimum_required(VERSION 4.1.0)
#project(projName version vvv usedLanguages lang lang2) - C is not mandatory here, if just for example sake.
project(Rooster VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard using the CMAKE_CXX_STANDARD CMake variable.
set(CMAKE_CXX_STANDARD 23)
# We are requiring the compiler to support/enable this standard.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMake allows us to bring in third party dependencies, we need to include the
# FetchContent module. We bring in the well known C++ fmt library (used to pretty
# print things).
# We bring in the fmt library. First we give it a name (fmt), then we het the Git repo link 
# (the one you would use for git clone).
# Then the tag. To get it, you go on the Git page, click on the master/main button which lists branches/tags,
# then click on "Tags" 
include(FetchContent)
FetchContent_Declare(
    fmt 
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.2.0
)

# Here we make actually make it available
FetchContent_MakeAvailable(fmt)

# We specify the executable name and we specify the file it should be made available into,
# which is the main.cpp file. 
# We can also include other files. We could only input person.cpp, which would automatically bring in
# person.h, but some people include them both. 
add_executable(rooster main.cpp person.h person.cpp)
# To make the fmt library actually available to our executable we use this command.
# We specify the target that we want to link to the imported library. 
# The PRIVATE keyword is not explained in the video.
# With fmt::fmt we specify the thing that we want to link to in the library that we pulled.
target_link_libraries(rooster PRIVATE fmt::fmt)

# Then we have to make a kit. To do so open the command palette (ctrl + shift + p) and select
# or CMake: Select a kit or Scan for Kits which will scan for available kits in the computer.
# Kits are a compiler and tools associated with it to build our project. We can first scan and then select our toolkit.
# In this case we are using Visual Studio Community - Release amd64.
# This will generate a "build" folder with a lot of files, along with a visual studio solution, but we don't actually
# need to open it with Visual Studio.

# Now we can execute "CMake build". This will actually build the project and link our library as well.
# The folder is now "./build/debug/rooster.exe"

# Changing compilers is easy: just nuke the build folder and re-run the kit generation with a different compiler
# (maybe it's enought to just re-run the kit gen and will delete the build folder automatically)

# In the _deps folder we have the fmt library

# CMake also makes this project understandable for other IDEs as well (e.g. Visual Studio).
# In the .vscode/settings.json file, we can also configure the CMake status bar visibility for VSCode as well.

# This however is not the best way and we can use preset files which improves things even further.
# YouTube channel reference: https://www.youtube.com/@LearnQtGuide
# CMake presets: https://www.youtube.com/watch?v=2nAoYarq_r4
# For Modules: https://www.youtube.com/watch?v=RYrtMgMARBM