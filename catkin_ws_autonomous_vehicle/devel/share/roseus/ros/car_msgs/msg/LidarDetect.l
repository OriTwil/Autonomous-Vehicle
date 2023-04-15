;; Auto-generated. Do not edit!


(when (boundp 'car_msgs::LidarDetect)
  (if (not (find-package "CAR_MSGS"))
    (make-package "CAR_MSGS"))
  (shadow 'LidarDetect (find-package "CAR_MSGS")))
(unless (find-package "CAR_MSGS::LIDARDETECT")
  (make-package "CAR_MSGS::LIDARDETECT"))

(in-package "ROS")
;;//! \htmlinclude LidarDetect.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass car_msgs::LidarDetect
  :super ros::object
  :slots (_header _x _y _z ))

(defmethod car_msgs::LidarDetect
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:x __x) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:y __y) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:z __z) (make-array 8 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _x __x)
   (setq _y __y)
   (setq _z __z)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32[8] _x
    (* 4    8)
    ;; float32[8] _y
    (* 4    8)
    ;; float32[8] _z
    (* 4    8)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32[8] _x
     (dotimes (i 8)
       (sys::poke (elt _x i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[8] _y
     (dotimes (i 8)
       (sys::poke (elt _y i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[8] _z
     (dotimes (i 8)
       (sys::poke (elt _z i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32[8] _x
   (dotimes (i (length _x))
     (setf (elt _x i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[8] _y
   (dotimes (i (length _y))
     (setf (elt _y i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[8] _z
   (dotimes (i (length _z))
     (setf (elt _z i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get car_msgs::LidarDetect :md5sum-) "37bef1e1e7f3d7f8ed3b5e27818ef51e")
(setf (get car_msgs::LidarDetect :datatype-) "car_msgs/LidarDetect")
(setf (get car_msgs::LidarDetect :definition-)
      "Header header
float32[8] x
float32[8] y
float32[8] z

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :car_msgs/LidarDetect "37bef1e1e7f3d7f8ed3b5e27818ef51e")


