# Install script for directory: /home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE PROGRAM FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE PROGRAM FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/setup.bash;/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/setup.bash"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/setup.sh;/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/setup.sh"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/setup.zsh;/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/setup.zsh"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/gtest/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/imu_launch/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/navigation_stage/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/navigation_tutorials/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/roomba_stage/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/first_circle_pathplanning/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/get_scan_new/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/second_circle_pathplanning/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/ls01x/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/car_msgs/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/car_location/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/detect_lidar/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/get_map/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/camera_init/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/laser_scan_publisher_tutorial/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/point_cloud_publisher_tutorial/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/car_test/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/encoder_driver/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/imu_tool/imu_complementary_filter/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/imu_tool/imu_filter_madgwick/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/odometry_publisher_tutorial/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/robot_localization/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/robot_setup_tf_tutorial/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/navigation_tutorials/simple_navigation_goals_tutorial/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/serial_imu/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/ucar_map/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/imu_tool/rviz_imu_plugin/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/art_racecar/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
