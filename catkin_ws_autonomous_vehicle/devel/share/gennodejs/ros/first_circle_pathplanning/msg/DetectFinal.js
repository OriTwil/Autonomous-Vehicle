// Auto-generated. Do not edit!

// (in-package first_circle_pathplanning.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class DetectFinal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.barrels_x = null;
      this.barrels_y = null;
      this.barrels_z = null;
    }
    else {
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DetectFinal
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
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DetectFinal
    let len;
    let data = new DetectFinal(null);
    // Deserialize message field [barrels_x]
    data.barrels_x = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    // Deserialize message field [barrels_y]
    data.barrels_y = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    // Deserialize message field [barrels_z]
    data.barrels_z = _arrayDeserializer.float32(buffer, bufferOffset, 8)
    return data;
  }

  static getMessageSize(object) {
    return 96;
  }

  static datatype() {
    // Returns string type for a message object
    return 'first_circle_pathplanning/DetectFinal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '47a5bbb1bcd3f2398868a84a6aefd851';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[8] barrels_x
    float32[8] barrels_y
    float32[8] barrels_z
    # int32 color[8]
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DetectFinal(null);
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

    return resolved;
    }
};

module.exports = DetectFinal;
