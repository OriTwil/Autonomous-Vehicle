cmake_minimum_required(VERSION 3.0.2)
project(get_map)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  car_msgs
  geometry_msgs
  std_msgs
  message_filters
)

find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(get_map src/get_map.cpp)
add_library(MapHandler src/MapHandler.cpp)
target_link_libraries(get_map ${catkin_LIBRARIES} ${OpenCV_LIBS} MapHandler)
add_dependencies(get_map ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(get_map /opt/ros/noetic/lib/libmessage_filters.so)
