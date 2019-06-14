// Binary_search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "MyUtil.h"
using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target)
{
	int l = 0, r = n - 1;  //在[l...r]的范围里寻找target

	while (l<=r)    //当l==r时，区间[l...r]依然是有效的
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (target > arr[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return -1;
}

int main()
{
	int n = 1000000;

	int *data = MyUtil::generateOrderArray(n);

	clock_t startTime = clock();

	for (int i=0;i<n;i++)
	{
		assert(i == binarySearch(data, n, i));
	}

	clock_t endTime = clock();

	cout << "binarySearch test complete." << endl;
	cout << "Time cost: " << double(endTime - startTime)/CLOCKS_PER_SEC << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
