
"use strict";

let YoloDetect = require('./YoloDetect.js');
let car_location = require('./car_location.js');
let LidarDetect = require('./LidarDetect.js');
let DetectFinal = require('./DetectFinal.js');

module.exports = {
  YoloDetect: YoloDetect,
  car_location: car_location,
  LidarDetect: LidarDetect,
  DetectFinal: DetectFinal,
};
