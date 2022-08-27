file(GLOB FUNC_SRC *.cpp)

add_library(FUNCTIONS_LIB SHARED ${FUNC_SRC})
target_include_directories(FUNCTIONS_LIB PUBLIC .)