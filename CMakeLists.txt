cmake_minimum_required(VERSION 3.18)

find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)

add_subdirectory(proto)
#add_subdirectory(server)
add_subdirectory(client)