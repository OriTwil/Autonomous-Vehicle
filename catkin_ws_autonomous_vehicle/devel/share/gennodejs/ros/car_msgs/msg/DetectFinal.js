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

class DetectFinal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.barrels_x = null;
      this.barrels_y = null;
      this.barrels_z = null;
      this.color = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('barrels_x')) {
        this.barrels_x = initObj.barrels_x
      }
      else {
        this.barrels_x = new Array(8).fill(0);
      }
      if (initObj.hasOwnProperty('barrels_y')) {
        this.barrels_y = initObj.barrels_y
      }
      else {
        this.barrels_y = new Array(8).fill(0);
      }
      if (initObj.hasOwnProperty('barrels_z')) {
        this.barrels_z = initObj.barrels_z
      }
      else {
        this.barrels_z = new Array(8).fill(0);
      }
      if (initObj.hasOwnProperty('color')) {
        this.color = initObj.color
      }
      else {
        this.color = new Array(8).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DetectFinal
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [barrels_x] has the right length
    if (obj.barrels_x.length !== 8) {
      throw new Error('Unable to serialize array field barrels_x - length must be 8')
    }
    // Serialize message field [barrels_x]
    bufferOffset = _arraySerializer.float32(obj.barrels_x, buffer, bufferOffset, 8);
    // Check that the constant length array field [barrels_y] has the right length
    if (obj.barrels_y.length !== 8) {
      throw new Error('Unable to serialize array field barrels_y - length must be 8')
    }
    // Serialize message field [barrels_y]
    bufferOffset = _arraySerializer.float32(obj.barrels_y, buffer, bufferOffset, 8);
    // Check that the constant length array field [barrels_z] has the right length
    if (obj.barrels_z.length !== 8) {
      throw new Error('Unable to serialize array field barrels_z - length must be 8')
    }
    // Serialize message field [barrels_z]
    bufferOffset = _arraySerializer.float32(obj.barrels_z, buffer, bufferOffset, 8);
    // Check that the constant length array field [color] has the right length
    if (obj.color.length !== 8) {
      throw new Error('Unable to serialize array field color - length must be 8')
    }
    // Serialize message field [color]
    bufferOffset = _arraySerializer.int8(obj.color, buffer, bufferOffset, 8);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DetectFinal
    let len;
    let data = new DetectFinal(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [barrels_x]
    data.barrels_x = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    // Deserialize message field [barrels_y]
    data.barrels_y = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    // Deserialize message field [barrels_z]
    data.barrels_z = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    // Deserialize message field [color]
    data.color = _arrayDeserializer.int8(buffer, bufferOffset, 8)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 104;
  }

  static datatype() {
    // Returns string type for a message object
    return 'car_msgs/DetectFinal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4fd76da9078b59d2164edc8fa38c8dee';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DetectFinal(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.barrels_x !== undefined) {
      resolved.barrels_x = msg.barrels_x;
    }
    else {
      resolved.barrels_x = new Array(8).fill(0)
    }

    if (msg.barrels_y !== undefined) {
      resolved.barrels_y = msg.barrels_y;
    }
    else {
      resolved.barrels_y = new Array(8).fill(0)
    }

    if (msg.barrels_z !== undefined) {
      resolved.barrels_z = msg.barrels_z;
    }
    else {
      resolved.barrels_z = new Array(8).fill(0)
    }

    if (msg.color !== undefined) {
      resolved.color = msg.color;
    }
    else {
      resolved.color = new Array(8).fill(0)
    }

    return resolved;
    }
};

module.exports = DetectFinal;
