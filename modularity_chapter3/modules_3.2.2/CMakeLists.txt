# Create library
add_library(my_vector)

# Add the module file to the library
target_sources(my_vector
    PUBLIC 
        FILE_SET CXX_MODULES FILES
        my_vector.cpp
)

add_executable(rooster main.cpp)
target_link_libraries(rooster PRIVATE my_vector)