project(server VERSION 0.1 LANGUAGES CXX)

set(Sources
    main.cpp)

include_directories(${CMAKE_BINARY_DIR}/proto)

add_executable(server ${Sources})
target_link_libraries(server proto OpenSSL::Crypto)