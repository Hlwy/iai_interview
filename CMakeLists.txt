cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(iai_interview)

# ===========================
#       Set Build Options
# ===========================
set(VERBOSE         OFF CACHE INTERNAL  "CMake execution debugging")
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
add_subdirectory(src)
