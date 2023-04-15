cmake_minimum_required(VERSION 3.0.2)
project(get_scan_new)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(get_scan_new src/get_scan_new.cpp)
target_link_libraries(get_scan_new ${catkin_LIBRARIES})
add_dependencies(get_scan_new ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})