cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AHRS)

# Set C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(CMAKE_CXX_STANDARD_REQUIRED True)


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

# Add test executable
add_executable(quaternionTests test/QuaternionTest.cpp)
add_executable(vectorTests test/VectorTest.cpp)
add_executable(rotationMatrixTests test/RotationMatrixTest.cpp)
target_link_libraries(quaternionTests gtest gtest_main)
target_link_libraries(vectorTests gtest gtest_main)
target_link_libraries(rotationMatrixTests gtest gtest_main)

# Register tests
add_test(NAME MyTest COMMAND runTests)
