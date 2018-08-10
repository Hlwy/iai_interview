cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(iai_interview)

# ===========================
#       Set Build Options
# ===========================
set(VERBOSE         ON CACHE INTERNAL  "CMake execution debugging")
set(BUILD_TESTS     ON CACHE INTERNAL   "Build all test executables")

# ===========================
#        Set Compiler
# ===========================
# if(COMPILE_ARM)
#      set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
#      set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
# endif(COMPILE_ARM)

# ===========================
#    Set CMake Properties
# ===========================
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBS_DIR ${LIBRARY_OUTPUT_PATH})
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCS_DIR "${PROJECT_SOURCE_DIR}/include")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")
set(HOME_DIR "${PROJECT_SOURCE_DIR}")

# ============================================
#       Find & Include Dependencies
# ============================================
include_directories(
     include
)

# ===========================
#     Build Targets
# ===========================
if(VERBOSE)
message(STATUS "------ BUILDING Libraries")
endif(VERBOSE)

# IAI Interface
add_library(iai_interface SHARED src/iai_interface.cpp)
target_link_libraries(iai_interface ${LIBS})

# IAI Text File Implementation
add_library(iai_file_impl SHARED src/iai_implementation.cpp)
target_link_libraries(iai_file_impl iai_interface ${LIBS})

if(VERBOSE)
message(STATUS "------ BUILDING Libraries")
endif(VERBOSE)

# Test executable
add_executable(test_iai src/iai_main.cpp)
target_link_libraries(test_iai iai_file_impl)
