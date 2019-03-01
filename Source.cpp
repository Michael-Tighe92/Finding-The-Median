#include<iostream>
using namespace std;
float findMedian(float[], float[], int, int);
int main()
{
	int size1, size2;
	float median;
	cout << "What will be the size of nums1 array?" << endl;
	cin >> size1;
	float * nums1 = new float[size1];
	cout << "What will be the size of nums2 array?" << endl;
	cin >> size2;
	float * nums2 = new float[size2];
	for (int i = 0;i < size1;i++)
	{
		cout << "Please enter a value for nums1[" << i << "]:";
		cin >> nums1[i];
	}
	cout << endl;
	for (int i = 0;i < size2;i++)
	{
		cout << "Please enter a value for nums2[" << i << "]:";
		cin >> nums2[i];
	}
	cout << endl;
	cout << "nums1: ";
	for (int i = 0;i < size1;i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	cout << "nums2: ";
	for (int i = 0;i < size2;i++)
	{
		cout << nums2[i] << " ";
	}
	cout << endl;
	median = findMedian(nums1, nums2, size1, size2);
	cout << "The median is: " << median << endl;
	system("pause");
}

float findMedian(float nums1[], float nums2[], int size1, int size2)
{
	int totalSize = size1 + size2, leftoff = 0, counter = totalSize-1;
	float * medianArr = new float[totalSize];
	for (int i = 0;i < size1;i++)
	{
		medianArr[i] = nums1[i];
		leftoff = i+1;
	}
	for (int i = 0;i < size2;i++)
	{
		medianArr[leftoff] = nums2[i];
		leftoff++;
	}
	//Sort in ascending order
	for (int i = 0; i < totalSize;i++)
	{
		for (int j = 0;j < totalSize;j++)
		{
			if (medianArr[i] < medianArr[j])
			{
				swap(medianArr[i], medianArr[j]);
			}
		}
	}
	if (totalSize % 2 != 0)
	{
		for (int i = 0;i < totalSize;i++,counter--)
		{
				if (i == counter)
				return medianArr[i];	
		}
	}
	else
	{
		for (int i = 0;i < totalSize;i++, counter--)
		{
			if (i + 1 == counter)
				return (medianArr[i] + medianArr[counter])/2;
		}
	}
}