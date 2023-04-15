; Auto-generated. Do not edit!


(cl:in-package second_circle_pathplanning-msg)


;//! \htmlinclude SecondStart.msg.html

(cl:defclass <SecondStart> (roslisp-msg-protocol:ros-message)
  ((second_flag
    :reader second_flag
    :initarg :second_flag
    :type cl:boolean
    :initform cl:nil)
   (optimization_flag
    :reader optimization_flag
    :initarg :optimization_flag
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SecondStart (<SecondStart>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SecondStart>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SecondStart)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name second_circle_pathplanning-msg:<SecondStart> is deprecated: use second_circle_pathplanning-msg:SecondStart instead.")))

(cl:ensure-generic-function 'second_flag-val :lambda-list '(m))
(cl:defmethod second_flag-val ((m <SecondStart>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader second_circle_pathplanning-msg:second_flag-val is deprecated.  Use second_circle_pathplanning-msg:second_flag instead.")
  (second_flag m))

(cl:ensure-generic-function 'optimization_flag-val :lambda-list '(m))
(cl:defmethod optimization_flag-val ((m <SecondStart>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader second_circle_pathplanning-msg:optimization_flag-val is deprecated.  Use second_circle_pathplanning-msg:optimization_flag instead.")
  (optimization_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SecondStart>) ostream)
  "Serializes a message object of type '<SecondStart>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'second_flag) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'optimization_flag) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SecondStart>) istream)
  "Deserializes a message object of type '<SecondStart>"
    (cl:setf (cl:slot-value msg 'second_flag) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'optimization_flag) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SecondStart>)))
  "Returns string type for a message object of type '<SecondStart>"
  "second_circle_pathplanning/SecondStart")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SecondStart)))
  "Returns string type for a message object of type 'SecondStart"
  "second_circle_pathplanning/SecondStart")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SecondStart>)))
  "Returns md5sum for a message object of type '<SecondStart>"
  "f0667236eadb504e422cb705b4187e2d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SecondStart)))
  "Returns md5sum for a message object of type 'SecondStart"
  "f0667236eadb504e422cb705b4187e2d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SecondStart>)))
  "Returns full string definition for message of type '<SecondStart>"
  (cl:format cl:nil "bool second_flag~%bool optimization_flag~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SecondStart)))
  "Returns full string definition for message of type 'SecondStart"
  (cl:format cl:nil "bool second_flag~%bool optimization_flag~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SecondStart>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SecondStart>))
  "Converts a ROS message object to a list"
  (cl:list 'SecondStart
    (cl:cons ':second_flag (second_flag msg))
    (cl:cons ':optimization_flag (optimization_flag msg))
))
