
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 101  // 定义最大矩阵尺寸，需要是奇数

// 打印米字形矩阵
void printMilet(int n) {
    char matrix[MAX_SIZE][MAX_SIZE];  // 创建矩阵数组
    int size = 2 * n - 1;  // 计算矩阵的实际大小
    char letter = 'A';  // 字母起始字符

    // 初始化矩阵为 '.'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = '.';
        }
    }

   
  

















    // 打印矩阵
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

  



    printf("请输入n的值（1 <= n <= 50）：");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("输入的n值超出范围。\n");
        return 1;
    }

    printMilet(n);

    return 0;
}