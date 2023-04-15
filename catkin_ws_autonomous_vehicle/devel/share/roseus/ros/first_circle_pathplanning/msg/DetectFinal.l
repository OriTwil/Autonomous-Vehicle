;; Auto-generated. Do not edit!


(when (boundp 'first_circle_pathplanning::DetectFinal)
  (if (not (find-package "FIRST_CIRCLE_PATHPLANNING"))
    (make-package "FIRST_CIRCLE_PATHPLANNING"))
  (shadow 'DetectFinal (find-package "FIRST_CIRCLE_PATHPLANNING")))
(unless (find-package "FIRST_CIRCLE_PATHPLANNING::DETECTFINAL")
  (make-package "FIRST_CIRCLE_PATHPLANNING::DETECTFINAL"))

(in-package "ROS")
;;//! \htmlinclude DetectFinal.msg.html


(defclass first_circle_pathplanning::DetectFinal
  :super ros::object
  :slots (_barrels_x _barrels_y _barrels_z ))

(defmethod first_circle_pathplanning::DetectFinal
  (:init
   (&key
    ((:barrels_x __barrels_x) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:barrels_y __barrels_y) (make-array 8 :initial-element 0.0 :element-type :float))
    ((:barrels_z __barrels_z) (make-array 8 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _barrels_x __barrels_x)
   (setq _barrels_y __barrels_y)
   (setq _barrels_z __barrels_z)
   self)
  (:barrels_x
   (&optional __barrels_x)
   (if __barrels_x (setq _barrels_x __barrels_x)) _barrels_x)
  (:barrels_y
   (&optional __barrels_y)
   (if __barrels_y (setq _barrels_y __barrels_y)) _barrels_y)
  (:barrels_z
   (&optional __barrels_z)
   (if __barrels_z (setq _barrels_z __barrels_z)) _barrels_z)
  (:serialization-length
   ()
   (+
    ;; float32[8] _barrels_x
    (* 4    8)
    ;; float32[8] _barrels_y
    (* 4    8)
    ;; float32[8] _barrels_z
    (* 4    8)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
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
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
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
   ;;
   self)
  )

(setf (get first_circle_pathplanning::DetectFinal :md5sum-) "47a5bbb1bcd3f2398868a84a6aefd851")
(setf (get first_circle_pathplanning::DetectFinal :datatype-) "first_circle_pathplanning/DetectFinal")
(setf (get first_circle_pathplanning::DetectFinal :definition-)
      "float32[8] barrels_x
float32[8] barrels_y
float32[8] barrels_z
# int32 color[8]
")



(provide :first_circle_pathplanning/DetectFinal "47a5bbb1bcd3f2398868a84a6aefd851")


