#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 20
#define MAX_X 10
#define INFTY 1e9

int n; // ǽ����Ŀ
double dp[MAX_N][MAX_X + 1]; // ��̬�滮��
double walls[MAX_N][5]; // �洢ǽ��ȱ����Ϣ

// �����(x1, y1)��(x2, y2)�������پ���
double manhattanDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2);
}

int main() {
    scanf("%d", &n); // ��ȡǽ����Ŀ
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%lf", &walls[i][j]);
        }
    }

    // ��ʼ����̬�滮��
    memset(dp, 0, sizeof(dp));

    // ״̬ת�ƣ�����㵽��һ��ǽ��ÿ��ȱ��
    for (int i = 0; i < 5; ++i) {
        dp[0][i] = manhattanDist(0, 5, walls[0][2 * i], 5) +
            manhattanDist(walls[0][2 * i], 5, walls[0][2 * i + 1], 5);
    }

    // ��̬�滮���
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            // ѡ��ͨ��ǰһ��ǽ���ĸ�ȱ�ڵ��ﵱǰǽ�����·��
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

    // ���������ڵ���̾���
    double shortestPath = INFTY;
    for (int i = 0; i < 5; ++i) {
        shortestPath = fmin(shortestPath, dp[n - 1][i] +
            manhattanDist(walls[n - 1][2 * i + 1], 5, 10, 5));
    }
    printf("%.2f\n", shortestPath > INFTY ? -1 : shortestPath);

    return 0;
}
typedef struct {
    double x; // ǽ�ĺ�����
    double a1, b1; // ��һ��ȱ�ڵ����귶Χ
    double a2, b2; // �ڶ���ȱ�ڵ����귶Χ
} Wall;

double min(double a, double b) {
    return a < b ? a : b;
}

// ���ݵ�ǰλ�ú�ǽ����Ϣ������ͨ��ȱ�ڵ����·��
double calculateShortestPath(double currentX, Wall wall) {
    // ѡ�������ȱ��
    double distanceToGap1 = min(wall.a1, 5) - currentX;
    double distanceToGap2 = min(wall.a2, 5) - currentX;
    double distanceFromGap1 = 5 - min(wall.b1, 5);
    double distanceFromGap2 = 5 - min(wall.b2, 5);

    // ѡ����̵�·��
    double path1 = distanceToGap1 + distanceFromGap1;
    double path2 = distanceToGap2 + distanceFromGap2;
    return min(path1, path2);
}

int main() {
    int n;
    scanf("%d", &n); // ��ȡǽ����Ŀ

    Wall walls[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf", &walls[i].x, &walls[i].a1, &walls[i].b1, &walls[i].a2, &walls[i].b2);
    }

    double currentX = 0; // С���ĵ�ǰλ��
    double totalDistance = 0; // ��·������

    for (int i = 0; i < n; i++) {
        Wall wall = walls[i];
        totalDistance += calculateShortestPath(currentX, wall);
        currentX = wall.x; // ����С����λ��Ϊǽ����һ��
    }

    // �������һ�ε����ڵľ���
    totalDistance += 10 - currentX;

    printf("%.2f\n", totalDistance);

    return 0;
}