execute_process(COMMAND "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/arc_utilities/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/arc_utilities/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
