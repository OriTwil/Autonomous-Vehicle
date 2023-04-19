# Install script for directory: /home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization

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
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/catkin_generated/installspace/grad_traj_optimization.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/grad_traj_optimization/cmake" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/catkin_generated/installspace/grad_traj_optimizationConfig.cmake"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/catkin_generated/installspace/grad_traj_optimizationConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/grad_traj_optimization" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/arc_utilities/cmake_install.cmake")
  include("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/cmake_install.cmake")

endif()

