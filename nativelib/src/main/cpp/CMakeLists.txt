cmake_minimum_required(VERSION 3.6)

project(nativelib CXX)

#add_subdirectory(../../../JniHelper ${CMAKE_CURRENT_BINARY_DIR}/jniHelper)

find_package (Java REQUIRED)
if(ANDROID)
    #
else()
    find_package(JNI REQUIRED)
endif(ANDROID)

include (UseJava)
include_directories(${JNI_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

# set(CMAKE_BUILD_TYPE RelWithDebInfo)
add_compile_definitions(DEBUG=1)

# add_compile_definitions(NDEBUG=1)
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
else()
endif()

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "jni/*.cpp")
list(APPEND ALL_SOURCES ${SOURCES})

add_library(nativelib SHARED ${ALL_SOURCES})

target_link_libraries(nativelib
    PRIVATE
)
