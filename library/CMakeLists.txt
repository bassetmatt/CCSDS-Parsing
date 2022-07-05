add_library(
    ccsdsParse
        tmpacket.c
)

target_include_directories(ccsdsParse PRIVATE ${PROJECT_SOURCE_DIR}/include)
