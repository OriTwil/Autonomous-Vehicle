cmake_minimum_required(VERSION 3.0.2)
project(first_circle_pathplanning)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)
find_package(OpenCV REQUIRED)

add_message_files(
  FILES
  DetectFinal.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES plumbing_pub_sub
 CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs message_runtime
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(first_pathplanning src/first_pathplanning.cpp)
add_dependencies(first_pathplanning ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(first_pathplanning
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
