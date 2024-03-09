cmake_minimum_required(VERSION 3.18)

project(dummy_files VERSION 0.1 LANGUAGES CXX)

find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)

add_subdirectory(proto)
add_subdirectory(server)
add_subdirectory(client)