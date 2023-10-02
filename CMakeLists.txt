cmake_minimum_required(VERSION 3.27)
project(blog_backend)

# Set test executable name
set(TEST_EXE ${PROJECT_NAME}_test)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)

# Check if the target platform is Linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

# Set build type to Release
set(CMAKE_BUILD_TYPE Debug)

# Set policies
cmake_policy(SET CMP0135 NEW)

# Include Google Test
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SOURECS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Add your source files
add_executable(${PROJECT_NAME}
main.cpp
${SOURECS}
)
# Link the executable with Google Test
target_link_libraries(${PROJECT_NAME}
  GTest::gtest
  GTest::gtest_main
)

enable_testing()

file(GLOB_RECURSE TEST_SOURECS
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)


# Add your test files
add_executable(${TEST_EXE}
  ${TEST_SOURECS}
  ${SOURECS}
)

target_include_directories(${TEST_EXE} PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link the test executable with Google Test
target_link_libraries(${TEST_EXE}
  GTest::gtest
  GTest::gtest_main
)

# Add custom target to run the binary directly with "make run" command
add_custom_target(run
  COMMAND ./${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
)

# Add custom target to run the binary directly with "make run" command
add_custom_target(tests
  COMMAND ./${TEST_EXE}
  DEPENDS ${TEST_EXE}
)

# Add a test
include(GoogleTest)
gtest_discover_tests(${TEST_EXE})