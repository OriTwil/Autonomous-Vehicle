; Auto-generated. Do not edit!


(cl:in-package first_circle_pathplanning-msg)


;//! \htmlinclude DetectFinal.msg.html

(cl:defclass <DetectFinal> (roslisp-msg-protocol:ros-message)
  ((barrels_x
    :reader barrels_x
    :initarg :barrels_x
    :type (cl:vector cl:float)
   :initform (cl:make-array 8 :element-type 'cl:float :initial-element 0.0))
   (barrels_y
    :reader barrels_y
    :initarg :barrels_y
    :type (cl:vector cl:float)
   :initform (cl:make-array 8 :element-type 'cl:float :initial-element 0.0))
   (barrels_z
    :reader barrels_z
    :initarg :barrels_z
    :type (cl:vector cl:float)
   :initform (cl:make-array 8 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass DetectFinal (<DetectFinal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DetectFinal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DetectFinal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name first_circle_pathplanning-msg:<DetectFinal> is deprecated: use first_circle_pathplanning-msg:DetectFinal instead.")))

(cl:ensure-generic-function 'barrels_x-val :lambda-list '(m))
(cl:defmethod barrels_x-val ((m <DetectFinal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader first_circle_pathplanning-msg:barrels_x-val is deprecated.  Use first_circle_pathplanning-msg:barrels_x instead.")
  (barrels_x m))

(cl:ensure-generic-function 'barrels_y-val :lambda-list '(m))
(cl:defmethod barrels_y-val ((m <DetectFinal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader first_circle_pathplanning-msg:barrels_y-val is deprecated.  Use first_circle_pathplanning-msg:barrels_y instead.")
  (barrels_y m))

(cl:ensure-generic-function 'barrels_z-val :lambda-list '(m))
(cl:defmethod barrels_z-val ((m <DetectFinal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader first_circle_pathplanning-msg:barrels_z-val is deprecated.  Use first_circle_pathplanning-msg:barrels_z instead.")
  (barrels_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DetectFinal>) ostream)
  "Serializes a message object of type '<DetectFinal>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'barrels_x))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'barrels_y))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'barrels_z))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DetectFinal>) istream)
  "Deserializes a message object of type '<DetectFinal>"
  (cl:setf (cl:slot-value msg 'barrels_x) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'barrels_x)))
    (cl:dotimes (i 8)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'barrels_y) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'barrels_y)))
    (cl:dotimes (i 8)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'barrels_z) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'barrels_z)))
    (cl:dotimes (i 8)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DetectFinal>)))
  "Returns string type for a message object of type '<DetectFinal>"
  "first_circle_pathplanning/DetectFinal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DetectFinal)))
  "Returns string type for a message object of type 'DetectFinal"
  "first_circle_pathplanning/DetectFinal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DetectFinal>)))
  "Returns md5sum for a message object of type '<DetectFinal>"
  "47a5bbb1bcd3f2398868a84a6aefd851")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DetectFinal)))
  "Returns md5sum for a message object of type 'DetectFinal"
  "47a5bbb1bcd3f2398868a84a6aefd851")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DetectFinal>)))
  "Returns full string definition for message of type '<DetectFinal>"
  (cl:format cl:nil "float32[8] barrels_x~%float32[8] barrels_y~%float32[8] barrels_z~%# int32 color[8]~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DetectFinal)))
  "Returns full string definition for message of type 'DetectFinal"
  (cl:format cl:nil "float32[8] barrels_x~%float32[8] barrels_y~%float32[8] barrels_z~%# int32 color[8]~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DetectFinal>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'barrels_x) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'barrels_y) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'barrels_z) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DetectFinal>))
  "Converts a ROS message object to a list"
  (cl:list 'DetectFinal
    (cl:cons ':barrels_x (barrels_x msg))
    (cl:cons ':barrels_y (barrels_y msg))
    (cl:cons ':barrels_z (barrels_z msg))
))
