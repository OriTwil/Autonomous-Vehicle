
(cl:in-package :asdf)

(defsystem "second_circle_pathplanning-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SecondStart" :depends-on ("_package_SecondStart"))
    (:file "_package_SecondStart" :depends-on ("_package"))
  ))