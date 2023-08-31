cmake_minimum_required(VERSION 3.15)

project(ProtobufExample)

set(CMAKE_CXX_STANDARD 17)

#find_package(Protobuf REQUIRED)
#find_package(gRPC CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(protocol)

add_executable(${PROJECT_NAME} src/main.cpp src/messagehub/messagehubimpl.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC MessageHub ${Protobuf_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})