
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 101  // ����������ߴ磬��Ҫ������

// ��ӡ�����ξ���
void printMilet(int n) {
    char matrix[MAX_SIZE][MAX_SIZE];  // ������������
    int size = 2 * n - 1;  // ��������ʵ�ʴ�С
    char letter = 'A';  // ��ĸ��ʼ�ַ�

    // ��ʼ������Ϊ '.'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = '.';
        }
    }

   
  

















    // ��ӡ����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

  



    printf("������n��ֵ��1 <= n <= 50����");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("�����nֵ������Χ��\n");
        return 1;
    }

    printMilet(n);

    return 0;
}