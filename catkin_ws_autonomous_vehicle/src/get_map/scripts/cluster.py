import numpy as np
import cv2
from sklearn.cluster import Birch
from urllib3 import disable_warnings
import math
import rospy
from std_msgs.msg import Bool

THRE = 1
ANGLE_THRES = 80
def copy_by_mask(track_img: np.ndarray, map_img: np.ndarray) -> tuple:
    '''
        @param track_img: car track which is recomended to be binary image
        @param map_img: the map you want to seperate
        @output inner: inner part of the map
        @output outer: outer part of the map
    '''
    ###    Parameters and Structures    ###
    # kernels
    kernel_dilate = cv2.getStructuringElement(cv2.MORPH_RECT,(5,5))
    kernel_erode = cv2.getStructuringElement(cv2.MORPH_RECT,(7,7))


    ###           Work Stream           ###
    # convert track to gray img and then to binary img
    frame_gray = cv2.cvtColor(track_img, cv2.COLOR_BGR2GRAY)
    frame_binary = cv2.threshold(frame_gray, 0, 255, cv2.THRESH_BINARY)[1]
    
    # dilate the binary img to close the track
    frame_binary = cv2.dilate(frame_binary, kernel_dilate)

    # find contours of the frame_binary and fill inner-sections to get mask (with eroding to reduce the mask size)
    contours = cv2.findContours(frame_binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)[0]
    mask = cv2.fillPoly(frame_binary, [contours[0]], 255)
    mask = cv2.erode(mask,kernel_erode)
    mask_inverse = 255-mask  # produce inverse-mask conveniently

    # get results by copying with masks and then output
    inner = cv2.copyTo(map_img, mask)
    outer = cv2.copyTo(map_img, mask_inverse)
    return inner, outer



def cluster_color(X,threshold_):
    y_pre = Birch(n_clusters=None,threshold=threshold_).fit_predict(X)
    x_centers = []
    y_centers = []
    x1 = X[:,0].reshape(X.shape[0])
    x2 = X[:,1].reshape(X.shape[0])
    for i in range(0,y_pre[-1]):
        x_center = 0
        y_center = 0
        count  = 0
        for j,x in enumerate(y_pre):
            if x == i and j < x1.shape[1]:
                x_center += x1.tolist()[0][j]
                y_center += x2.tolist()[0][j]
                count +=1
        x_centers.append(x_center//count)
        y_centers.append(y_center//count)
    return x_centers, y_centers


    
def png2array(map_green): 
    delta = 50
    map_zero = np.zeros((600, 800, 1), np.uint8)
    map_green = np.concatenate([map_zero, map_green[:,:,1:2], map_zero], axis=2)
    array_blue = list()
    array_green = list()
    array_red = list()

    for i in range(len(map_green)):
        for j in range(len(map_green[0])):
            map_green[i][j][1] = map_green[i][j][1] if map_green[i][j][1] >= delta*THRE else 0

    for i in range(len(map_green)):
        for j in range(len(map_green[0])):
        # green
            if(map_green[i][j][1] >= 3*delta):
                array_green.append([j, i, map_green[i][j][1]//delta])
    array = np.matrix(array_green)
    return array

def getDistMat1(nCities, coordinates):
    distMat = np.zeros((nCities, nCities))
    for i in range(nCities):
        for j in range(i,nCities):
            distMat[i][j] = distMat[j][i] = round(np.linalg.norm(coordinates[i]-coordinates[j]))
    return distMat

# dist 为距离矩阵，start_index 为起始位置
def tsp_quick(dist: list, start_index: int, tolerence: int):
    sum_distance, seq_result, n = 0, [start_index, ], len(dist)
    for path_index in range(1, n):
        distance_list = dist[start_index]
        min_dis = max(distance_list)
        for index, distance in enumerate(distance_list):
            # if (index not in seq_result) and (distance <= min(min_dis, tolerence)):
            if (index not in seq_result) and (distance <= min_dis):
                min_dis = distance
                start_index = index
        # if min_dis < tolerence:
        sum_distance += min_dis
        seq_result.append(start_index)
    return sum_distance,seq_result



def get_map_colored(sequence_inner, points_inner, sequence_outer, points_outer):
    # create a blank map which is pure white
    map_colored = np.zeros((600, 800, 3), np.uint8)
    map_colored.fill(255)

    # draw points on the map
    # inner
    print(sequence_inner)
    for i in range(len(sequence_inner)):
        cv2.circle(map_colored, tuple(points_inner[sequence_inner[i]]), 5, (0, 0, 255), -1)
        cv2.line(map_colored, tuple(points_inner[sequence_inner[i-1]]), tuple(points_inner[sequence_inner[i]]), (0, 0, 255), 2, cv2.LINE_AA)
        cv2.putText(map_colored, "{}".format(sequence_inner[i]), tuple(points_inner[sequence_inner[i]]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,0), 2)
    # outer
    for i in range(len(sequence_outer)):
        cv2.circle(map_colored, tuple(points_outer[sequence_outer[i]]), 5, (255, 0, 0), -1)
        cv2.line(map_colored, tuple(points_outer[sequence_outer[i-1]]), tuple(points_outer[sequence_outer[i]]), (255, 0, 0), 2, cv2.LINE_AA)

    # return
    return map_colored
#####################
def cal_ang(point_1, point_2, point_3):
    """
    根据三点坐标计算夹角
    :param point_1: 点1坐标
    :param point_2: 点2坐标
    :param point_3: 点3坐标
    :return: 返回任意角的夹角值,这里只是返回点2的夹角
    """
    a=math.sqrt((point_2[0]-point_3[0])*(point_2[0]-point_3[0])+(point_2[1]-point_3[1])*(point_2[1] - point_3[1]))
    b=math.sqrt((point_1[0]-point_3[0])*(point_1[0]-point_3[0])+(point_1[1]-point_3[1])*(point_1[1] - point_3[1]))
    c=math.sqrt((point_1[0]-point_2[0])*(point_1[0]-point_2[0])+(point_1[1]-point_2[1])*(point_1[1]-point_2[1]))
    A=math.degrees(math.acos((a*a-b*b-c*c)/(-2*b*c)))
    B=math.degrees(math.acos((b*b-a*a-c*c)/(-2*a*c)))
    C=math.degrees(math.acos((c*c-a*a-b*b)/(-2*a*b)))
    return B
######################

def get_costmap(sequence_inner, points_inner, sequence_outer, points_outer):
    # create a blank map
    map_inner = np.zeros((600, 800), np.uint8)
    map_outer = np.zeros((600, 800), np.uint8)

    # draw points on the map
    
    #############################
    error_points = []
    for i in range(len(sequence_inner)-1):
        angle = cal_ang(points_inner[sequence_inner[i-1]],points_inner[sequence_inner[i]],points_inner[sequence_inner[i+1]])
        if(angle < ANGLE_THRES):
            error_points.append(i)
    sequence_inner = np.delete(sequence_inner,error_points)  
    #############################      
    for i in range(len(sequence_inner)):
        cv2.line(map_inner, tuple(points_inner[sequence_inner[i-1]]), tuple(points_inner[sequence_inner[i]]), 255, 2, cv2.LINE_AA)
    for i in range(len(sequence_outer)):
        cv2.line(map_outer, tuple(points_outer[sequence_outer[i-1]]), tuple(points_outer[sequence_outer[i]]), 255, 2, cv2.LINE_AA)

    # find contours and fill
    contours_inner = cv2.findContours(map_inner, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)[0]
    contours_outer = cv2.findContours(map_outer, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)[0]
    mask_inner = cv2.fillPoly(map_inner, [contours_inner[0]], 255)
    mask_outer = 255 - cv2.fillPoly(map_outer, [contours_outer[0]], 255)
    costmap = np.zeros((600, 800), np.uint8) + mask_inner + mask_outer

    # return
    return costmap


def MapCallBack(finished):
    if finished == True:
        track_img = cv2.imread("../maps/track.png")
        map_img = cv2.imread("../maps/map_zzx_new.png")

        # get 2 parts of map
        inner, outer = copy_by_mask(track_img, map_img)

        # clustering and get sequence of points
        array_inner = png2array(inner)
        array_outer = png2array(outer)
        x_inner, y_inner = cluster_color(array_inner[:,:2], 12)
        x_outer, y_outer = cluster_color(array_outer[:,:2], 12)

        # solve TSP
        xy_inner = np.array(list(zip(x_inner, y_inner)))
        xy_outer = np.array(list(zip(x_outer, y_outer)))
        dismat_inter = getDistMat1(len(xy_inner), xy_inner)
        dismat_exter = getDistMat1(len(xy_outer), xy_outer)
        seq_inner = tsp_quick(dismat_inter, 10, 100)[1]
        seq_outer = tsp_quick(dismat_exter, 10, 100)[1]

        # draw map
        map_colored = get_map_colored(seq_inner, xy_inner, seq_outer, xy_outer)
        costmap = get_costmap(seq_inner, xy_inner, seq_outer, xy_outer)
        cv2.imshow("map_colored", map_colored)
        cv2.imshow("costmap", costmap)
        cv2.imwrite("./cost_map.png", costmap)
        cv2.imwrite("./final_map.png", map_colored)
        cv2.waitKey(100)
        exit(0)


if __name__ == '__main__':
    # read image form files
    # rospy.init_node('optimize_map', anonymous=True)
    # rate = rospy.Rate(10)
    # map_optimize = rospy.Subscriber('/finish_first_round',Bool,MapCallBack)
    # map_finished = rospy.Publisher('/map_finished',Bool)
    # rospy.spin()
    MapCallBack(True)