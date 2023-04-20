# Autonomous-Vehicle
workspace for Autonomous Vehicle competition.

## Update
* April 15th, compiled some of the function packages and prepared for experiments.
* April 22nd, completed experiments 1-9 and need to test the effectiveness of deep learning visual object recognition.

## Buglists
* (switch to yolov3) To obtain pre-trained weights, use:
```makefile
wget https://github.com/AlexeyAB/darknet/releases/download/darknet_yolo_v3_optimal/yolov3.weights
```
* Test program:
```makefile
/darknet detector test cfg/coco.data cfg/yolov3.cfg yolov3.weights -thresh 0.25 ./data/dog.jpg
```
