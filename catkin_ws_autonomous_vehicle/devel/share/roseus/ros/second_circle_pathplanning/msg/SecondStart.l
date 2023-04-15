;; Auto-generated. Do not edit!


(when (boundp 'second_circle_pathplanning::SecondStart)
  (if (not (find-package "SECOND_CIRCLE_PATHPLANNING"))
    (make-package "SECOND_CIRCLE_PATHPLANNING"))
  (shadow 'SecondStart (find-package "SECOND_CIRCLE_PATHPLANNING")))
(unless (find-package "SECOND_CIRCLE_PATHPLANNING::SECONDSTART")
  (make-package "SECOND_CIRCLE_PATHPLANNING::SECONDSTART"))

(in-package "ROS")
;;//! \htmlinclude SecondStart.msg.html


(defclass second_circle_pathplanning::SecondStart
  :super ros::object
  :slots (_second_flag _optimization_flag ))

(defmethod second_circle_pathplanning::SecondStart
  (:init
   (&key
    ((:second_flag __second_flag) nil)
    ((:optimization_flag __optimization_flag) nil)
    )
   (send-super :init)
   (setq _second_flag __second_flag)
   (setq _optimization_flag __optimization_flag)
   self)
  (:second_flag
   (&optional (__second_flag :null))
   (if (not (eq __second_flag :null)) (setq _second_flag __second_flag)) _second_flag)
  (:optimization_flag
   (&optional (__optimization_flag :null))
   (if (not (eq __optimization_flag :null)) (setq _optimization_flag __optimization_flag)) _optimization_flag)
  (:serialization-length
   ()
   (+
    ;; bool _second_flag
    1
    ;; bool _optimization_flag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _second_flag
       (if _second_flag (write-byte -1 s) (write-byte 0 s))
     ;; bool _optimization_flag
       (if _optimization_flag (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _second_flag
     (setq _second_flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _optimization_flag
     (setq _optimization_flag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get second_circle_pathplanning::SecondStart :md5sum-) "f0667236eadb504e422cb705b4187e2d")
(setf (get second_circle_pathplanning::SecondStart :datatype-) "second_circle_pathplanning/SecondStart")
(setf (get second_circle_pathplanning::SecondStart :definition-)
      "bool second_flag
bool optimization_flag
")



(provide :second_circle_pathplanning/SecondStart "f0667236eadb504e422cb705b4187e2d")


