//Binary Search Recursive

#include <iostream>
using namespace std;

int binarySearch(int arr[], int leftIndex, int rightIndex, int query)
{
    while(leftIndex <= rightIndex) {
        
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if(arr[middleIndex] == query) {
            return middleIndex;
        }

        if(arr[middleIndex] < query) {
            leftIndex = middleIndex + 1;
        }

        else {
            rightIndex = middleIndex - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int query = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, query);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}

