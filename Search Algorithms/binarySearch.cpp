#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) // first occurrence of element
{
    while (left <= right)
    {
        int mid = left + (right-left)/2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;
    cout << binarySearch(arr, 0, n-1, x) << endl;

    return 0;
}
