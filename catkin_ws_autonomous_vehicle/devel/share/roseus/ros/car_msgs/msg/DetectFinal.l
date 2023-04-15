;; Auto-generated. Do not edit!


(when (boundp 'car_msgs::DetectFinal)
  (if (not (find-package "CAR_MSGS"))
    (make-package "CAR_MSGS"))
  (shadow 'DetectFinal (find-package "CAR_MSGS")))
(unless (find-package "CAR_MSGS::DETECTFINAL")
  (make-package "CAR_MSGS::DETECTFINAL"))

(in-package "ROS")
;;//! \htmlinclude DetectFinal.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass car_msgs::DetectFinal
  :super ros::object
  :slots (_header _barrels_x _barrels_y _barrels_z _color ))

(defmethod car_msgs::DetectFinal
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:barrels_x __barrels_x) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:barrels_y __barrels_y) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:barrels_z __barrels_z) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:color __color) (make-array 8 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _header __header)
   (setq _barrels_x __barrels_x)
   (setq _barrels_y __barrels_y)
   (setq _barrels_z __barrels_z)
   (setq _color __color)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:barrels_x
   (&optional __barrels_x)
   (if __barrels_x (setq _barrels_x __barrels_x)) _barrels_x)
  (:barrels_y
   (&optional __barrels_y)
   (if __barrels_y (setq _barrels_y __barrels_y)) _barrels_y)
  (:barrels_z
   (&optional __barrels_z)
   (if __barrels_z (setq _barrels_z __barrels_z)) _barrels_z)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32[8] _barrels_x
    (* 4    8)
    ;; float32[8] _barrels_y
    (* 4    8)
    ;; float32[8] _barrels_z
    (* 4    8)
    ;; int8[8] _color
    (* 1    8)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32[8] _barrels_x
     (dotimes (i 8)
       (sys::poke (elt _barrels_x i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[8] _barrels_y
     (dotimes (i 8)
       (sys::poke (elt _barrels_y i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[8] _barrels_z
     (dotimes (i 8)
       (sys::poke (elt _barrels_z i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; int8[8] _color
     (dotimes (i 8)
       (write-byte (elt _color i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32[8] _barrels_x
   (dotimes (i (length _barrels_x))
     (setf (elt _barrels_x i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[8] _barrels_y
   (dotimes (i (length _barrels_y))
     (setf (elt _barrels_y i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[8] _barrels_z
   (dotimes (i (length _barrels_z))
     (setf (elt _barrels_z i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; int8[8] _color
   (dotimes (i (length _color))
     (setf (elt _color i) (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> (elt _color i) 127) (setf (elt _color i) (- (elt _color i) 256)))
     )
   ;;
   self)
  )

(setf (get car_msgs::DetectFinal :md5sum-) "4fd76da9078b59d2164edc8fa38c8dee")
(setf (get car_msgs::DetectFinal :datatype-) "car_msgs/DetectFinal")
(setf (get car_msgs::DetectFinal :definition-)
      "Header header
float32[8] barrels_x
float32[8] barrels_y
float32[8] barrels_z
int8[8] color

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



(provide :car_msgs/DetectFinal "4fd76da9078b59d2164edc8fa38c8dee")


