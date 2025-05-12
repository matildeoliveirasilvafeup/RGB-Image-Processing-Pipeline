cmake_minimum_required(VERSION 3.15)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

project(image_processor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wno-missing-field-initializers)
endif()

# Better alternative to GLOB_RECURSE
file(GLOB SOURCES CONFIGURE_DEPENDS
        "src/*.cpp"
        "src/Command/*.cpp"
)

add_executable(runscrim
        ${SOURCES}
        main/RunScrim.cpp
)

add_executable(tester
        ${SOURCES}
        main/Tester.cpp
)

target_include_directories(runscrim PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Command
        ${CMAKE_SOURCE_DIR}/include/stb
        ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(tester PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Command
        ${CMAKE_SOURCE_DIR}/include/stb
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(runscrim)
target_link_libraries(tester)