# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "second_circle_pathplanning: 1 messages, 0 services")

set(MSG_I_FLAGS "-Isecond_circle_pathplanning:/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(second_circle_pathplanning_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_custom_target(_second_circle_pathplanning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "second_circle_pathplanning" "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(second_circle_pathplanning
  "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/second_circle_pathplanning
)

### Generating Services

### Generating Module File
_generate_module_cpp(second_circle_pathplanning
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/second_circle_pathplanning
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(second_circle_pathplanning_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(second_circle_pathplanning_generate_messages second_circle_pathplanning_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_dependencies(second_circle_pathplanning_generate_messages_cpp _second_circle_pathplanning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(second_circle_pathplanning_gencpp)
add_dependencies(second_circle_pathplanning_gencpp second_circle_pathplanning_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS second_circle_pathplanning_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(second_circle_pathplanning
  "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/second_circle_pathplanning
)

### Generating Services

### Generating Module File
_generate_module_eus(second_circle_pathplanning
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/second_circle_pathplanning
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(second_circle_pathplanning_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(second_circle_pathplanning_generate_messages second_circle_pathplanning_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_dependencies(second_circle_pathplanning_generate_messages_eus _second_circle_pathplanning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(second_circle_pathplanning_geneus)
add_dependencies(second_circle_pathplanning_geneus second_circle_pathplanning_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS second_circle_pathplanning_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(second_circle_pathplanning
  "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/second_circle_pathplanning
)

### Generating Services

### Generating Module File
_generate_module_lisp(second_circle_pathplanning
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/second_circle_pathplanning
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(second_circle_pathplanning_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(second_circle_pathplanning_generate_messages second_circle_pathplanning_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_dependencies(second_circle_pathplanning_generate_messages_lisp _second_circle_pathplanning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(second_circle_pathplanning_genlisp)
add_dependencies(second_circle_pathplanning_genlisp second_circle_pathplanning_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS second_circle_pathplanning_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(second_circle_pathplanning
  "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/second_circle_pathplanning
)

### Generating Services

### Generating Module File
_generate_module_nodejs(second_circle_pathplanning
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/second_circle_pathplanning
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(second_circle_pathplanning_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(second_circle_pathplanning_generate_messages second_circle_pathplanning_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_dependencies(second_circle_pathplanning_generate_messages_nodejs _second_circle_pathplanning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(second_circle_pathplanning_gennodejs)
add_dependencies(second_circle_pathplanning_gennodejs second_circle_pathplanning_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS second_circle_pathplanning_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(second_circle_pathplanning
  "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/second_circle_pathplanning
)

### Generating Services

### Generating Module File
_generate_module_py(second_circle_pathplanning
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/second_circle_pathplanning
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(second_circle_pathplanning_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(second_circle_pathplanning_generate_messages second_circle_pathplanning_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/second_circle_pathplanning/msg/SecondStart.msg" NAME_WE)
add_dependencies(second_circle_pathplanning_generate_messages_py _second_circle_pathplanning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(second_circle_pathplanning_genpy)
add_dependencies(second_circle_pathplanning_genpy second_circle_pathplanning_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS second_circle_pathplanning_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/second_circle_pathplanning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/second_circle_pathplanning
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(second_circle_pathplanning_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/second_circle_pathplanning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/second_circle_pathplanning
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(second_circle_pathplanning_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/second_circle_pathplanning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/second_circle_pathplanning
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(second_circle_pathplanning_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/second_circle_pathplanning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/second_circle_pathplanning
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(second_circle_pathplanning_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/second_circle_pathplanning)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/second_circle_pathplanning\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/second_circle_pathplanning
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(second_circle_pathplanning_generate_messages_py std_msgs_generate_messages_py)
endif()
