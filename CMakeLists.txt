cmake_minimum_required(VERSION 3.21)

project(heic_to_jpg VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${CONAN_CMAKE})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake" ${CONAN_CMAKE})
endif()

include(${CONAN_CMAKE})

conan_cmake_run(
    REQUIRES
    libheif/1.12.0
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

add_executable(heic_to_jpg main.cpp)

target_link_libraries(heic_to_jpg
    PRIVATE
    CONAN_PKG::libheif
)
