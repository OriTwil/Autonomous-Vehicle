cmake_minimum_required(VERSION 3.0.2)
project(detect_lidar)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  message_generation
  car_msgs
)
find_package(OpenCV REQUIRED)

# generate_messages(
#   DEPENDENCIES
#   sensor_msgs
# )

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

# sub_data
add_executable(detect_lidar src/detect_lidar.cpp)
target_link_libraries(detect_lidar ${catkin_LIBRARIES} ${OpenCV_LIBS} )
add_dependencies(detect_lidar ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
