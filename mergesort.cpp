
#include <iostream>
using namespace std;

int NewMerge(int arr[], int st, int end)
{
    int mid = st + (end - st) / 2;

    int length1 = mid - st + 1;
    int length2 = end - mid;

    int *array1 = new int[length1];
    int *array2 = new int[length2];

    int newIndex = st;

    for (int i = 0; i < length1; i++)
    {
        array1[i] = arr[newIndex++];
    }
    for (int i = 0; i < length2; i++)
    {
        array2[i] = arr[newIndex++];
    }
    newIndex = st;

    int index1 = 0, index2 = 0;
    while (index1 < length1 && index2 < length2)
    {
        if (array1[index1] < array2[index2])
        {
            arr[newIndex++] = array1[index1++];
        }
        else
        {
            arr[newIndex++] = array2[index2++];
        }
    }

    while (index1 < length1)
    {
        arr[newIndex++] = array1[index1++];
    }

    while (index2 < length2)
    {
        arr[newIndex++] = array2[index2++];
    }
}

void MergeSort(int arr[], int st, int end)
{

    if (st >= end)
    {
        return;
    }
    int mid = st + (end - st) / 2;

    MergeSort(arr, st, mid);
    MergeSort(arr, mid + 1, end);
    NewMerge(arr, st, end);
}

int PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 50, 2, 10, 40, 12, 3, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);
    PrintArray(arr, n);
}