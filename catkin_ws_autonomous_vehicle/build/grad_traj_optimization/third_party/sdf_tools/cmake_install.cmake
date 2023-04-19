# Install script for directory: /home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools/msg" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/msg/SDF.msg"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/msg/CollisionMap.msg"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/msg/TaggedObjectCollisionMap.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools/srv" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/srv/ComputeSDF.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools/cmake" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/catkin_generated/installspace/sdf_tools-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/include/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/share/roseus/ros/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/share/common-lisp/ros/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/share/gennodejs/ros/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/lib/python3/dist-packages/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/lib/python3/dist-packages/sdf_tools")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/catkin_generated/installspace/sdf_tools.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools/cmake" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/catkin_generated/installspace/sdf_tools-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools/cmake" TYPE FILE FILES
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/catkin_generated/installspace/sdf_toolsConfig.cmake"
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/sdf_tools/catkin_generated/installspace/sdf_toolsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sdf_tools" TYPE FILE FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib" TYPE SHARED_LIBRARY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so")
  if(EXISTS "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so"
         OLD_RPATH "/opt/ros/noetic/lib:/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/lib/libsdf_tools.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/include/sdf_tools/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/include/sdf_tools" TYPE DIRECTORY FILES "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/sdf_tools/include/sdf_tools/" REGEX "/\\.svn$" EXCLUDE)
endif()

