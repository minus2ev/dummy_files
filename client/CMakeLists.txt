project(client VERSION 0.1 LANGUAGES CXX)

set(Sources
    main.cpp)

include_directories(${CMAKE_BINARY_DIR}/proto)

add_executable(client ${Sources})
target_link_libraries(proto OpenSSL:Crypto)