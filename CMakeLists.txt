cmake_minimum_required(VERSION 3.8)

project(ProtoBufExample)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB src CONFIGURE_DEPENDS src/main.cpp src/protocol/person.pb.cc)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS} protobuf)