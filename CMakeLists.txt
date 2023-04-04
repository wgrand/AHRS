cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AHRS)

# Set C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include directories
include_directories(include)

# Source files
set(SOURCES ./main.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Google Test libraries
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# Enable testing
enable_testing()

# Add googletest subdirectory
add_subdirectory(libs/googletest)

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
