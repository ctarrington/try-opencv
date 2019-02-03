cmake_minimum_required(VERSION 3.0)
PROJECT(FLD)

#############  Common Instructions for all Users  ############
find_package( OpenCV REQUIRED )
MESSAGE("OpenCV version : ${OpenCV_VERSION}")

find_package( dlib REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} dlib::dlib)
ENDMACRO()

add_example(version)
add_example(video)