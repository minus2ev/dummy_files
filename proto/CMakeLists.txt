set(ProtoFiles
    dummy_files.proto)
    
PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
add_library(proto STATIC ${ProtoSources} ${ProtoHeaders})
target_link_libraries(proto ${PROTOBUF_LIBRARY})
