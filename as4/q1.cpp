#include <iostream>
using namespace std;

int maxInBitonic(int arr[], int low, int high)
{
	int n = high + 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1])
			return arr[mid];
		else if (arr[mid] < arr[mid + 1])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return arr[high];
}

int main()
{
	int arr[] = { 1, 3, 50, 10, 9, 7, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The maximum element is "<< maxInBitonic(arr, 0, n - 1)<<endl;
	return 0;
}

