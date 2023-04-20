#coding:utf-8
import cv2

# 打开摄像头
cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

# 检查摄像头是否打开成功
flag = cap.isOpened()

# 初始化保存图片的编号
index = 1

# 循环读取并显示摄像头捕获的图像
while (flag):
    # 读取摄像头捕获的图像
    ret, frame = cap.read()

    # 显示摄像头捕获的图像
    cv2.imshow("Capture_Paizhao", frame)

    # 等待键盘输入
    k = cv2.waitKey(1) & 0xFF

    # 如果按下s键，保存当前帧的图像
    if k == ord('s'):
        cv2.imwrite("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/datasets/test/" + str(index) + ".jpg", frame)
        print("save" + str(index) + ".jpg successfuly!")
        print("-------------------------")
        index += 1

    # 如果按下q键，退出程序
    elif k == ord('q'):
        break

# 释放摄像头
cap.release()

# 销毁窗口
cv2.destroyAllWindows()
