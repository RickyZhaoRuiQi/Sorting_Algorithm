/***********************************************************************************************************************
 *排序大的分类可以分为两种：内排序和外排序。在排序过程中，全部记录存放在内存，则称为内排序，如果排序过程中需要使用外存，
 *则称为外排序。内排序有可以分为以下几类：
 *(1)、插入排序：直接插入排序、希尔排序。
 *(2)、选择排序：简单选择排序、堆排序。
 *(3)、交换排序：冒泡排序、快速排序。
 *(4)、归并排序
 *(5)、线性时间排序：计数排序、基数排序、桶排序
 ***********************************************************************************************************************/


//排序算法稳定性：排序算法如果是稳定的，那么从一个健上排序，然后再从另一个健上排序，前一个健排序的结果可以
//为后一个健排序锁用。基数排序就是这样，先按低位排序，逐次按高位排序，低位排序后元素的顺序在高位也相同不变


#ifndef MY_SORT_H_
#define MY_SORT_H_

#include<time.h>
#include <iostream>

void insertSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	for(int i = 1;i < len;++i)
	{
		int j = i;
		int tmp = arr[j];
		while(j > 0 && tmp < arr[j-1]) //为arr[j]找到合适的位置
		{
			arr[j] = arr[j-1];
			--j;
		}
		arr[j] = tmp;
	}
}
/*
 * 直接插入排序：空间复杂度：O（1），最好时间复杂度O（n），最坏和平均时间复杂度O（n^2）。最好情况比较n-1次移动0次
 * 直接插入算法是稳定的算法，适合少量数据排序或者数据基本有序的情况
 */

void shellSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	int gap = len / 2;
	while(gap > 0)
	{
		for(int i = 1;i < len;++i)
		{
			int j = i;
			int tmp = arr[j];
			while(j >= gap && tmp < arr[j-gap])
			{
				arr[j] = arr[j-gap];
				j-=gap;
			}
			arr[j] = tmp;
		}
		gap /= 2;
	}
}
/*
 *希尔排序：希尔排序可以算是直接插入排序的一种优化。当gap很大时，每一趟需要排序的项很少，数据距离很长。
 *当gap减小时，每一趟需要移动数据变多，但它们经过前面的移动已经很接近它们排序后的最终位置。
 *空间复杂度O（1），最好情况O(n)，平均O（n^1.3），最差情况O（n^2）。最好即已经有序的情况。不稳定排序
 *shell排序的最差和平均情况相差不是很大，在中小规模的数据排序表现良好。
 */

void selectSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	while(len > 0)
	{
		int max = 0;
		for(int i = 1;i < len;++i)
		{
			if(arr[max] < arr[i])
			  max = i;
		}
		int tmp = arr[max];
		arr[max] = arr[--len];
		arr[len] = tmp;
	}
}
/*
 *选择排序：空间复杂度O（1），时间复杂度最好、平均、最差情况都是O（n^2）。比较次数O（n^2），移动O（n），不稳定
 */

static void adjustHeap(int arr[],int size,int top)
{
	while(top * 2 + 1 <= size - 1)
	{
		int change = 0;
		if(top * 2 + 1 == size - 1)//只有左子节点
		{
			change = top * 2 + 1;
			if(arr[top] >= arr[top * 2 + 1])
			  break;
		}
		else
		{
			change = arr[top * 2 + 1] > arr[top * 2 + 2]? top * 2 + 1:top * 2 + 2;
			if(arr[top] >= arr[change])
			  break;
		}
		int tmp = arr[top];
		arr[top] = arr[change];
		arr[change] = tmp;
		top = change;
	}
}

static void createHeap(int arr[],int len)
{
	for(int i = len/2 - 1;i >= 0;--i)
	{
		adjustHeap(arr,len,i);
	}
}

void heapSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	createHeap(arr,len);
	while(len >= 2)
	{
		int tmp = arr[len-1];
		arr[len-1] = arr[0];
		arr[0] = tmp;
		adjustHeap(arr,--len,0);
	}
}
/*
 * 堆排序：空间复杂度O（1），时间复杂度最好、平均、最差o（nlogn），不稳定。因为建堆的代价，堆排序不适合数据量较少的排序
 */

void bubbleSort(int arr[], int len)
{
	if (nullptr == arr || len < 2)
		return;

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < len - 1; ++i)
		{
			if (arr[i + 1] < arr[i])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = false;
			}
		}
		--len;
	}
}
/*
 * 冒泡排序：空间复杂度O（1），时间复杂度，最好O（n），最坏和平均O（n^2），最好即有序的情况下，比较一轮就停下。
 * 冒泡排序是稳定的
 */

static int partition(int arr[], int lo, int hi)
{
	int tmp = arr[lo];
	while (lo < hi)
	{
		while (lo < hi && tmp <= arr[hi])
			--hi;
		arr[lo] = arr[hi];
		while (lo < hi && arr[lo] <= tmp)
			++lo;
		arr[hi] = arr[lo];
	}
	arr[lo] = tmp;
	return lo;
}

void quickSort(int arr[], int lo, int hi)
{
	if (nullptr == arr || hi - lo < 2)
		return;

	int res = partition(arr, lo, hi - 1);
	quickSort(arr, lo, res);
	quickSort(arr, res + 1, hi);
}

void quickSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;
	quickSort(arr,0,len);
}
/*
 * 快速排序：基本思想-选取一个基准数，将比它小的排在它的左边比它大的排在它的右边。再第归左右
 * 空间复杂度O（logn）-O（n），时间复杂度，最好和平均O（nlogn），最坏O（n^2）,不稳定
 * 最坏情况下，每次都划分为n-1和1个元素，可以通过优化哨兵选取来较少这种情况出现的概率，比如三者取中或随即选取
 */

static void merge(int arr[],int lo,int mi,int hi)
{
	int left_len = mi - lo, right_len = hi - mi;
	int *left = new int[left_len];
	int *ptr = arr + lo;
	int *right = arr + mi;
	for(int i = 0;i < left_len;++i)
	  left[i] = ptr[i];

	int i = 0,j = 0,k = 0;
	while((j < left_len) || (k < right_len))
	{
		if((j < left_len) && (k >= right_len || left[j] <= right[k]))
		  ptr[i++] = left[j++];
		if((k < right_len) && (j >= left_len || right[k] < left[j]))
		  ptr[i++] = right[k++];
	}
	delete[]left;
}

void mergeSort(int arr[],int lo,int hi)
{
	if(nullptr == arr || hi - lo < 2)
	  return;

	int mi = (lo + hi) >> 1;
	mergeSort(arr,lo,mi);
	mergeSort(arr,mi,hi);
	merge(arr,lo,mi,hi);
}

void mergeSort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;
	mergeSort(arr,0,len);
}
/*
 * 归并排序：空间复杂度O（n），时间复杂度，最好平均和最差都是O（nlogn），稳定算法。
 */

void my_sort(int arr[],int len)
{
	if(nullptr == arr || len < 2)
	  return;

	srand(time(0));
	unsigned choose = rand() % 6;
	switch(choose)
	{
		case 0:
			{
				std::cout<<"call insert sort"<<std::endl;
				insertSort(arr,len);
				break;
			}
		case 1:
			{
				std::cout<<"call bubble sort"<<std::endl;
				bubbleSort(arr,len);
				break;
			}
		case 2:
			{
				std::cout<<"call select sort"<<std::endl;
				selectSort(arr,len);
				break;
			}
		case 3:
			{
				std::cout<<"call shell sort"<<std::endl;
				shellSort(arr,len);
				break;
			}
		case 4:
			{
				std::cout<<"call quick sort"<<std::endl;
				quickSort(arr,len);
				break;
			}
		case 5:
			{
				std::cout<<"call heap sort"<<std::endl;
				heapSort(arr,len);
				break;
			}
		default:
			{
				std::cout<<"call merge sort"<<std::endl;
				mergeSort(arr,len);
			}
	}
}

void countSort(int arr[],int max, int len)
{
	int *count = new int[max + 1];
	int *tmp = new int[len];

	for (int i = 0; i <= max; ++i)
		count[i] = 0;

	for (int i = 0; i < len; ++i)
		++count[arr[i]];

	for (int i = 1; i <= max; ++i)
		count[i] = count[i] + count[i - 1];

	for (int i = len - 1 ; i >= 0; --i)
	{
		tmp[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	for (int i = 0; i < len; ++i)
	{
		arr[i] = tmp[i];
	}

	delete[]count;
	delete[]tmp;
}

void countSort(int arr[], int len)
{
	if (nullptr == arr || len < 2)
		return;

	int max = arr[0];
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] < 0)
			return;
		if (max < arr[i])
			max = arr[i];
	}
	countSort(arr, max, len);
}

/*
 * 计数排序：空间复杂度O（n + k），时间复杂度O（n + k），适用于自然数序列，且最大数小于等于或者比n大的不多的情况
 */

#endif
