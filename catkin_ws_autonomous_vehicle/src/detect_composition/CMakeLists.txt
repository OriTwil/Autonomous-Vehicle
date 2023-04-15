cmake_minimum_required(VERSION 3.0.2)
project(detect_composition)

# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  car_msgs
  detect_yolo
  roscpp
  rospy
  message_filters
)
find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/detect_composition.cpp
# )

add_executable(detect_node src/detect_node.cpp)

add_dependencies(detect_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(detect_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)


