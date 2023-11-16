import matplotlib.pyplot as plt


def plot_points_and_lines(n, points):
    # 解析输入
    x = [point[0] for point in points]
    y = [point[1] for point in points]

    # 画出点
    plt.scatter(x, y, color="red")

    # 画出连接线
    for i in range(n - 1):
        plt.plot([x[i], x[i + 1]], [y[i], y[i + 1]], color="blue")

    # 首尾相连
    plt.plot([x[n - 1], x[0]], [y[n - 1], y[0]], color="blue")

    # 显示图形
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.title("Connected Points")
    plt.grid(True)
    plt.show()


with open("input.txt", "r") as file:
    # 读取点的数量
    n = int(file.readline())

    # 读取每个点的坐标
    points = [tuple(map(float, file.readline().split())) for _ in range(n)]

# 画图
plot_points_and_lines(n, points)
