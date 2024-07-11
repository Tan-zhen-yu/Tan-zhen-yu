#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<malloc.h>
using namespace std;

//归并过程
void merge(int arr[], int l, int mid, int r) {
	int* B = (int*)malloc((r - l + 2) * sizeof(int));
	int i = l;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= r)
	{
		if (arr[i] <= arr[j])
			B[k++] = arr[i++];
		else
			B[k++] = arr[j++];
	}

	while (i <= mid)
		B[k++] = arr[i++];

	while (j <= r)
		B[k++] = arr[j++];

	for (i = l, k = 0; i <= r; i++)
		arr[i] = B[k++];

	


	/********end**************/
}

//递归
static void mergeSort(int arr[], int l, int r) {
	/********begin************/
	if (l < r)
	{
		int mid;
		mid = (l + r) / 2;                              //计算中间位置
		mergeSort(arr, l, mid);                               //对数组A[left:mid]中的元素进行归并排序
		mergeSort(arr, mid + 1, r);                          //对数组A[mid+1:right]中的元素进行归并排序
		merge(arr, l, mid, r);                            //进行合并操作
	}

	/********end**************/
}

//归并排序整个数组
void mergeSort(int arr[], int n) {
	//如果数组为空或只有一个元素，不需要排序
	if (arr == NULL || n < 2) {
		return;
	}
	mergeSort(arr, 0, n - 1);
}


int main() {
	int n;
	scanf("%d", &n);
	int *arr=(int*)malloc(n*(sizeof(int)));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	mergeSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}
