#include<stdio.h>

int main()

{

	int max, min;

	int a[10] = { 0 };

	for (int i=0; i < 10; i++)

	{

		scanf("%d", &a[i]);

	}

	max = a[0];

	min = a[0];

	for (int i = 1; i < 10; i++) {

		if (a[i] > max)

		{

			max = a[i];

		}

		if (a[i] < min)

		{

			min = a[i];

		}

	}

	printf("最大值是%d,最小值是%d", max, min);

	return 0;

}