cmake_minimum_required(VERSION 3.19)
project(scratch_pad)

set(CMAKE_CXX_STANDARD 23)

include(./build/conan/conanbuildinfo.cmake)

include_directories(./include)

add_compile_options(-Wall -Wextra -Wconversion)

# Set global property (all targets are impacted)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

find_package(PkgConfig)
pkg_check_modules(GLIBMM glibmm-2.68)

link_directories(
        ${GLIBMM_LIBRARY_DIRS})
include_directories(
        ${GLIBMM_INCLUDE_DIRS})
include_directories(
        ${GLIBMM_INCLUDE_DIRS}/glibmm)

conan_basic_setup()
set(LIBS lib)
set(Catch2_DIR ${LIBS}/cmake/Catch2)

find_package(Catch2 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/vs_glib_ustring.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLIBMM_LIBRARIES})

add_executable(${PROJECT_NAME}_test src/main.cpp src/vs_glib_ustring.cpp)
target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_NAME}_test PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${CONAN_LIBS})
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${GLIBMM_LIBRARIES})
