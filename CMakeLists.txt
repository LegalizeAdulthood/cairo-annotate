cmake_minimum_required(VERSION 3.23)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CAIRO_ANNOTATE_PROJECT_NAME "Cairo Annotate" CACHE "STRING" "Default project name for IDEs")
project("${CAIRO_ANNOTATE_PROJECT_NAME}" CXX)

include(CTest)

add_subdirectory(lib)
add_subdirectory(tools)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
