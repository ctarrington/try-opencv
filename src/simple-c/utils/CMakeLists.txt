SET(UTILS_LIB_SRC
   greet.cpp
)

add_library(Utils ${UTILS_LIB_SRC})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
