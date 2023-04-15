
(cl:in-package :asdf)

(defsystem "first_circle_pathplanning-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DetectFinal" :depends-on ("_package_DetectFinal"))
    (:file "_package_DetectFinal" :depends-on ("_package"))
  ))