cmake_minimum_required(VERSION 3.1)
project(car_msgs)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  nav_msgs
  geometry_msgs
  actionlib
  message_generation
  message_filters
)

add_action_files(
  DIRECTORY action
  FILES
)

add_message_files(
  DIRECTORY msg
  FILES
  YoloDetect.msg
  LidarDetect.msg
  DetectFinal.msg
  car_location.msg
)

add_service_files(
  DIRECTORY srv
  FILES
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
