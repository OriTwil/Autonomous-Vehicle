// Auto-generated. Do not edit!

// (in-package car_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class YoloDetect {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.left = null;
      this.top = null;
      this.width = null;
      this.height = null;
      this.ID = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = new Array(4).fill(0);
      }
      if (initObj.hasOwnProperty('top')) {
        this.top = initObj.top
      }
      else {
        this.top = new Array(4).fill(0);
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = new Array(4).fill(0);
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = new Array(4).fill(0);
      }
      if (initObj.hasOwnProperty('ID')) {
        this.ID = initObj.ID
      }
      else {
        this.ID = new Array(4).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type YoloDetect
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [left] has the right length
    if (obj.left.length !== 4) {
      throw new Error('Unable to serialize array field left - length must be 4')
    }
    // Serialize message field [left]
    bufferOffset = _arraySerializer.float32(obj.left, buffer, bufferOffset, 4);
    // Check that the constant length array field [top] has the right length
    if (obj.top.length !== 4) {
      throw new Error('Unable to serialize array field top - length must be 4')
    }
    // Serialize message field [top]
    bufferOffset = _arraySerializer.float32(obj.top, buffer, bufferOffset, 4);
    // Check that the constant length array field [width] has the right length
    if (obj.width.length !== 4) {
      throw new Error('Unable to serialize array field width - length must be 4')
    }
    // Serialize message field [width]
    bufferOffset = _arraySerializer.float32(obj.width, buffer, bufferOffset, 4);
    // Check that the constant length array field [height] has the right length
    if (obj.height.length !== 4) {
      throw new Error('Unable to serialize array field height - length must be 4')
    }
    // Serialize message field [height]
    bufferOffset = _arraySerializer.float32(obj.height, buffer, bufferOffset, 4);
    // Check that the constant length array field [ID] has the right length
    if (obj.ID.length !== 4) {
      throw new Error('Unable to serialize array field ID - length must be 4')
    }
    // Serialize message field [ID]
    bufferOffset = _arraySerializer.float32(obj.ID, buffer, bufferOffset, 4);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type YoloDetect
    let len;
    let data = new YoloDetect(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [left]
    data.left = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    // Deserialize message field [top]
    data.top = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    // Deserialize message field [width]
    data.width = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    // Deserialize message field [height]
    data.height = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    // Deserialize message field [ID]
    data.ID = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 80;
  }

  static datatype() {
    // Returns string type for a message object
    return 'car_msgs/YoloDetect';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '47e43372ff5d834c96206e6a1ba9ceea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new YoloDetect(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.left !== undefined) {
      resolved.left = msg.left;
    }
    else {
      resolved.left = new Array(4).fill(0)
    }

    if (msg.top !== undefined) {
      resolved.top = msg.top;
    }
    else {
      resolved.top = new Array(4).fill(0)
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = new Array(4).fill(0)
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = new Array(4).fill(0)
    }

    if (msg.ID !== undefined) {
      resolved.ID = msg.ID;
    }
    else {
      resolved.ID = new Array(4).fill(0)
    }

    return resolved;
    }
};

module.exports = YoloDetect;
