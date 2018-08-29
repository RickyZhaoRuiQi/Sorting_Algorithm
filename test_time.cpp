#include "my_sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define ARRLEN 100000

void GetData(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	for(int i = 0;i < len; ++i)
	{
		arr[i] = rand();
	}
}

int main()
{
	int arr[ARRLEN] = {0};
	srand(time(0));

	GetData(arr,ARRLEN);

	clock_t start = clock();
	insertSort(arr,ARRLEN);
	clock_t end = clock();
	cout<<"直接插入排序用时:"<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	bubbleSort(arr,ARRLEN);
	end = clock();
	cout<<"冒泡排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	selectSort(arr,ARRLEN);
	end = clock();
	cout<<"简单选择排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	shellSort(arr,ARRLEN);
	end = clock();
	cout<<"希尔排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	quickSort(arr,ARRLEN);
	end = clock();
	cout<<"快速排序用时间："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	heapSort(arr,ARRLEN);
	end = clock();
	cout<<"堆排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	return 0;
}
