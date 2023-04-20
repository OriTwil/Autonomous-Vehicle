# Autonomous-Vehicle
workspace for Autonomous Vehicle competition.

## Update
* April 15th, compiled some of the function packages and prepared for experiments.
* 4.22 完成实验1-9，还需要测试深度学习视觉物体识别的效果

## Buglists
* 获得预训练权重应使用（换为yolov3）
```makefile
wget https://github.com/AlexeyAB/darknet/releases/download/darknet_yolo_v3_optimal/yolov3.weights
```
* 测试程序
```makefile
/darknet detector test cfg/coco.data cfg/yolov3.cfg yolov3.weights -thresh 0.25 ./data/dog.jpg
```
