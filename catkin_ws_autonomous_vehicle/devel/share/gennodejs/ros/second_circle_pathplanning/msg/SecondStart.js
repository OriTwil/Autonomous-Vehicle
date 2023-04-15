// Auto-generated. Do not edit!

// (in-package second_circle_pathplanning.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class SecondStart {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.second_flag = null;
      this.optimization_flag = null;
    }
    else {
      if (initObj.hasOwnProperty('second_flag')) {
        this.second_flag = initObj.second_flag
      }
      else {
        this.second_flag = false;
      }
      if (initObj.hasOwnProperty('optimization_flag')) {
        this.optimization_flag = initObj.optimization_flag
      }
      else {
        this.optimization_flag = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SecondStart
    // Serialize message field [second_flag]
    bufferOffset = _serializer.bool(obj.second_flag, buffer, bufferOffset);
    // Serialize message field [optimization_flag]
    bufferOffset = _serializer.bool(obj.optimization_flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SecondStart
    let len;
    let data = new SecondStart(null);
    // Deserialize message field [second_flag]
    data.second_flag = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [optimization_flag]
    data.optimization_flag = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'second_circle_pathplanning/SecondStart';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f0667236eadb504e422cb705b4187e2d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool second_flag
    bool optimization_flag
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SecondStart(null);
    if (msg.second_flag !== undefined) {
      resolved.second_flag = msg.second_flag;
    }
    else {
      resolved.second_flag = false
    }

    if (msg.optimization_flag !== undefined) {
      resolved.optimization_flag = msg.optimization_flag;
    }
    else {
      resolved.optimization_flag = false
    }

    return resolved;
    }
};

module.exports = SecondStart;
