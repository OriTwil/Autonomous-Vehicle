#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/arc_utilities"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/lib/python3/dist-packages:/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build" \
    "/usr/bin/python3" \
    "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/src/grad_traj_optimization/third_party/arc_utilities/setup.py" \
    egg_info --egg-base /home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/arc_utilities \
    build --build-base "/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/build/grad_traj_optimization/third_party/arc_utilities" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install" --install-scripts="/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/install/bin"
