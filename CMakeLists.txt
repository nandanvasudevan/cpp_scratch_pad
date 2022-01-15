cmake_minimum_required(VERSION 3.19)
project(scratch_pad)

set(CMAKE_CXX_STANDARD 23)

include(./build/conan/conanbuildinfo.cmake)
include(./build/conan/conan_paths.cmake)
include(./build/conan/Findfmt.cmake)
include(./build/conan/Findspdlog.cmake)

include_directories(./include)

# Set global property (all targets are impacted)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

conan_basic_setup()
set(LIBS lib)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

add_library(catch2Main STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(catch2Main PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/${LIBS}/libCatch2Main.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include/catch2/"
        )

add_library(catch2 STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(catch2 PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/${LIBS}/libCatch2.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include/catch2/"
        )

add_executable(${PROJECT_NAME}_test src/main.cpp)
target_link_libraries(${PROJECT_NAME}_test PRIVATE catch2Main catch2)
target_link_libraries(${PROJECT_NAME}_test PRIVATE fmt::fmt)
