;; Auto-generated. Do not edit!


(when (boundp 'car_msgs::YoloDetect)
  (if (not (find-package "CAR_MSGS"))
    (make-package "CAR_MSGS"))
  (shadow 'YoloDetect (find-package "CAR_MSGS")))
(unless (find-package "CAR_MSGS::YOLODETECT")
  (make-package "CAR_MSGS::YOLODETECT"))

(in-package "ROS")
;;//! \htmlinclude YoloDetect.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass car_msgs::YoloDetect
  :super ros::object
  :slots (_header _left _top _width _height _ID ))

(defmethod car_msgs::YoloDetect
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:left __left) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:top __top) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:width __width) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:height __height) (make-array 4 :initial-element 0.0 :element-type :float))
    ((:ID __ID) (make-array 4 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _left __left)
   (setq _top __top)
   (setq _width __width)
   (setq _height __height)
   (setq _ID __ID)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:top
   (&optional __top)
   (if __top (setq _top __top)) _top)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:ID
   (&optional __ID)
   (if __ID (setq _ID __ID)) _ID)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32[4] _left
    (* 4    4)
    ;; float32[4] _top
    (* 4    4)
    ;; float32[4] _width
    (* 4    4)
    ;; float32[4] _height
    (* 4    4)
    ;; float32[4] _ID
    (* 4    4)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32[4] _left
     (dotimes (i 4)
       (sys::poke (elt _left i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[4] _top
     (dotimes (i 4)
       (sys::poke (elt _top i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[4] _width
     (dotimes (i 4)
       (sys::poke (elt _width i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[4] _height
     (dotimes (i 4)
       (sys::poke (elt _height i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[4] _ID
     (dotimes (i 4)
       (sys::poke (elt _ID i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32[4] _left
   (dotimes (i (length _left))
     (setf (elt _left i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[4] _top
   (dotimes (i (length _top))
     (setf (elt _top i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[4] _width
   (dotimes (i (length _width))
     (setf (elt _width i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[4] _height
   (dotimes (i (length _height))
     (setf (elt _height i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[4] _ID
   (dotimes (i (length _ID))
     (setf (elt _ID i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get car_msgs::YoloDetect :md5sum-) "47e43372ff5d834c96206e6a1ba9ceea")
(setf (get car_msgs::YoloDetect :datatype-) "car_msgs/YoloDetect")
(setf (get car_msgs::YoloDetect :definition-)
      "Header header
float32[4] left
float32[4] top
float32[4] width
float32[4] height
float32[4] ID
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



(provide :car_msgs/YoloDetect "47e43372ff5d834c96206e6a1ba9ceea")


