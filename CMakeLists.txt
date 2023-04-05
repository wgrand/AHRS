cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AHRS)

# Set C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include directories
include_directories(include)

# Source files
set(SOURCES 
   ./main.cpp
   ./model/RotationMatrix.cpp
   ./filter/ComplementaryFilter.cpp
   )

add_library(${PROJECT_NAME} ${SOURCES})


### TESTS ###

# Google Test libraries
message(STATUS "Fetching googletest")
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test subdirectory
add_subdirectory(test)

# Add test executables
function(add_test_executable test_name)

   # Create executable
   add_executable(${test_name} test/${test_name}.cpp ${ARGN})

   # Link libraries
   target_link_libraries(${test_name} gtest gtest_main)

   # Register test
   add_test(NAME ${test_name} COMMAND ${test_name})
   
endfunction()

add_test_executable(QuaternionTests)
add_test_executable(VectorTests)
add_test_executable(RotationMatrixTests)
