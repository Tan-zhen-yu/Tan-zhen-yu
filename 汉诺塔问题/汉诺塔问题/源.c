#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 20
#define MAX_X 10
#define INFTY 1e9

int n; // 墙的数目
double dp[MAX_N][MAX_X + 1]; // 动态规划表
double walls[MAX_N][5]; // 存储墙和缺口信息

// 计算从(x1, y1)到(x2, y2)的曼哈顿距离
double manhattanDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2);
}

int main() {
    scanf("%d", &n); // 读取墙的数目
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%lf", &walls[i][j]);
        }
    }

    // 初始化动态规划表
    memset(dp, 0, sizeof(dp));

    // 状态转移：从起点到第一堵墙的每个缺口
    for (int i = 0; i < 5; ++i) {
        dp[0][i] = manhattanDist(0, 5, walls[0][2 * i], 5) +
            manhattanDist(walls[0][2 * i], 5, walls[0][2 * i + 1], 5);
    }

    // 动态规划填表
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            // 选择通过前一堵墙的哪个缺口到达当前墙的最短路径
            dp[i][j] = INFTY;
            for (int k = 0; k < 5; ++k) {
                if (walls[i - 1][2 * k] <= walls[i][2 * j - 2] &&
                    walls[i - 1][2 * k + 1] >= walls[i][2 * j - 3]) {
                    dp[i][j] = fmin(dp[i][j], dp[i - 1][k] +
                        manhattanDist(walls[i - 1][2 * k + 1], 5, walls[i][2 * j - 2], 5));
                }
            }
        }
    }

    // 输出到达出口的最短距离
    double shortestPath = INFTY;
    for (int i = 0; i < 5; ++i) {
        shortestPath = fmin(shortestPath, dp[n - 1][i] +
            manhattanDist(walls[n - 1][2 * i + 1], 5, 10, 5));
    }
    printf("%.2f\n", shortestPath > INFTY ? -1 : shortestPath);

    return 0;
}
typedef struct {
    double x; // 墙的横坐标
    double a1, b1; // 第一个缺口的坐标范围
    double a2, b2; // 第二个缺口的坐标范围
} Wall;

double min(double a, double b) {
    return a < b ? a : b;
}

// 根据当前位置和墙的信息，计算通过缺口的最短路径
double calculateShortestPath(double currentX, Wall wall) {
    // 选择最近的缺口
    double distanceToGap1 = min(wall.a1, 5) - currentX;
    double distanceToGap2 = min(wall.a2, 5) - currentX;
    double distanceFromGap1 = 5 - min(wall.b1, 5);
    double distanceFromGap2 = 5 - min(wall.b2, 5);

    // 选择最短的路径
    double path1 = distanceToGap1 + distanceFromGap1;
    double path2 = distanceToGap2 + distanceFromGap2;
    return min(path1, path2);
}

int main() {
    int n;
    scanf("%d", &n); // 读取墙的数目

    Wall walls[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf", &walls[i].x, &walls[i].a1, &walls[i].b1, &walls[i].a2, &walls[i].b2);
    }

    double currentX = 0; // 小明的当前位置
    double totalDistance = 0; // 总路径长度

    for (int i = 0; i < n; i++) {
        Wall wall = walls[i];
        totalDistance += calculateShortestPath(currentX, wall);
        currentX = wall.x; // 更新小明的位置为墙的另一侧
    }

    // 加上最后一段到出口的距离
    totalDistance += 10 - currentX;

    printf("%.2f\n", totalDistance);

    return 0;
}