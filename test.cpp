#include "my_sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define ARRLEN 20

template<typename T>
struct dis
{
	void operator()(const T & x)
	{
		cout<<x<<" ";
	}
};

void GetData(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	for(int i = 0;i < len; ++i)
	{
		arr[i] = rand()%100;
	}
}

int main()
{
	int arr[ARRLEN] = {0};
	srand(time(0));
	
	GetData(arr,ARRLEN);
	for_each(arr,arr+ARRLEN,dis<int>());
	cout<<endl;
	mergeSort(arr,ARRLEN);
	//my_sort(arr,ARRLEN);
	for_each(arr,arr+ARRLEN,dis<int>());
	cout<<endl;

	return 0;
}
