
(cl:in-package :asdf)

(defsystem "car_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DetectFinal" :depends-on ("_package_DetectFinal"))
    (:file "_package_DetectFinal" :depends-on ("_package"))
    (:file "LidarDetect" :depends-on ("_package_LidarDetect"))
    (:file "_package_LidarDetect" :depends-on ("_package"))
    (:file "YoloDetect" :depends-on ("_package_YoloDetect"))
    (:file "_package_YoloDetect" :depends-on ("_package"))
    (:file "car_location" :depends-on ("_package_car_location"))
    (:file "_package_car_location" :depends-on ("_package"))
  ))