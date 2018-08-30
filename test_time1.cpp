#include "my_sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define ARRLEN 1000000

void GetData(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	for(int i = 0;i < len; ++i)
	{
		arr[i] = rand()%10000;
	}
}

int main()
{
	int arr[ARRLEN] = {0};
	srand(time(0));

	clock_t start,end;

	GetData(arr,ARRLEN);

	start = clock();
	shellSort(arr,ARRLEN);
	end = clock();
	cout<<"希尔排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	quickSort(arr,ARRLEN);
	end = clock();
	cout<<"快速排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	heapSort(arr,ARRLEN);
	end = clock();
	cout<<"堆排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	mergeSort(arr,ARRLEN);
	end = clock();
	cout<<"归并排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	GetData(arr,ARRLEN);

	start = clock();
	countSort(arr,ARRLEN);
	end = clock();
	cout<<"计数排序用时："<<(double)(end - start) / CLOCKS_PER_SEC<<"(s)"<<endl;

	return 0;
}
