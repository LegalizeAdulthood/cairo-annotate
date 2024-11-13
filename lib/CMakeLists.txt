find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIROMM REQUIRED IMPORTED_TARGET cairomm-1.16)

find_package(OpenImageIO CONFIG REQUIRED)

add_library(annotater
    include/annotater/annotater.h
    annotater.cpp)
set_target_properties(annotater PROPERTIES FOLDER "Libraries")
target_include_directories(annotater PUBLIC include)
target_link_libraries(annotater PUBLIC PkgConfig::CAIROMM OpenImageIO::OpenImageIO)
