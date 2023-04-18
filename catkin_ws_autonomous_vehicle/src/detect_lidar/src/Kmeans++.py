#K-means++的动态过程演示
import matplotlib.pyplot as plt
import numpy as np

# 随机生成数据
np.random.seed(0)
X = np.random.randn(100, 2)

# 初始化簇中心
k = 3
centers = X[np.random.choice(len(X), k, replace=False), :]

# 初始化画布
fig, ax = plt.subplots(figsize=(8, 6))
ax.scatter(X[:, 0], X[:, 1], s=50)

# 迭代计算
for i in range(10):
    # 计算距离
    distances = np.linalg.norm(X[:, np.newaxis, :] - centers, axis=2)
    # 分配簇
    labels = np.argmin(distances, axis=1)
    # 更新簇中心
    centers = np.array([X[labels == j].mean(axis=0) for j in range(k)])

    # 绘制当前的簇中心和簇的分配情况
    ax.cla()
    ax.scatter(X[:, 0], X[:, 1], c=labels, s=50)
    ax.scatter(centers[:, 0], centers[:, 1], c='r', s=200, marker='x')
    ax.set_title(f"Iteration {i + 1}")

    # 添加延时，以便观察动态过程
    plt.pause(1)

plt.show()
