#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

int* myrand(int* arr,int count) {
	for (int i = 0; i < 3; i++) {

		int a = rand() % 2;
		count += a;
		if (count == 2 or count ==3) {
			a = 0;
		}
		arr[i] = a;

	}
	if (count == 0) {
		myrand(arr, 0);
	}
	return arr;
}

int main()
{
	srand(time(0));
	
	int a = rand()%1;
	int count = 0;

	int arr[3] = { 0 };

	

	float c = 0;

	for (int i = 0; i < 10000000; i++) {

		myrand(arr,0);
			int flag = 0;
			int index;

			int choose = rand() % 3;

			for (int j = 0; j < 3; j++) {
				if (arr[j] == 0){
					if (j != choose) {
						index = j;
					}
				}
				
				
			}
			
			for (int j = 0; j < 3; j++) {
				if (j != index and j != choose) {
					choose = j;
					break;
				}
			}


			if (arr[choose] == 1) {
				flag = 1;
			}
			c += flag;

		
		
		for (int j = 0; j < 3; j++) {
			arr[j] = 0;

		}


	}
	
	float p = c / 10000000;
	printf("%f", p);




	return 0;
}