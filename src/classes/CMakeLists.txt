file(GLOB CLASSES_SRC *.cpp)

add_library(CLASSES_LIB SHARED ${CLASSES_SRC})
target_include_directories(CLASSES_LIB PUBLIC .)