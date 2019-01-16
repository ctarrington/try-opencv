cmake_minimum_required(VERSION 2.8.12)

PROJECT(FLD)

#############  Common Instructions for all Users  ############
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})
include(../../common/dlib/dlib/cmake)

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} dlib::dlib)
ENDMACRO()

add_example(version)
add_example(video)