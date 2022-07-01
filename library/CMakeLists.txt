add_library(
    ccsdsParse
        temp.c
)

target_include_directories(ccsdsParse PRIVATE ${PROJECT_SOURCE_DIR}/include())
