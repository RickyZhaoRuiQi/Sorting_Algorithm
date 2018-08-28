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

void my_sort(int arr[],int len);

int main()
{
	int arr[ARRLEN] = {0};
	srand(time(0));
	for(int i = 0;i < ARRLEN;++i)
	  arr[i] = rand()%100 + 1;

	for_each(arr,arr+ARRLEN,dis<int>());
	cout<<endl;
	my_sort(arr,ARRLEN);
	for_each(arr,arr+ARRLEN,dis<int>());
	cout<<endl;

	return 0;
}
