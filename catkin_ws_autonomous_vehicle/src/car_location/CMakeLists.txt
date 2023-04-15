cmake_minimum_required(VERSION 3.0.2)
project(car_location)

set(OpenCV_DIR /usr/lib/x86_64-linux-gnu/cmake/opencv4/)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  OpenCV
  std_msgs
  nav_msgs
  geometry_msgs
  car_msgs
  actionlib
  message_generation
  message_filters
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  nav_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
)
include_directories(include ${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
add_executable(car_location src/car_location.cpp)
add_executable(car_track src/car_track.cpp)
add_dependencies(car_location  ${catkin_EXPORTED_TARGETS})
add_dependencies(car_track  ${catkin_EXPORTED_TARGETS})
target_link_libraries(car_location ${catkin_LIBRARIES})
target_link_libraries(car_track ${catkin_LIBRARIES} ${OpenCV_LIBS})



