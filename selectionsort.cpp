#include <iostream>
using namespace std;

int SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallIDX = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIDX])
            {
                smallIDX = j;
            }
        }

        swap(arr[i], arr[smallIDX]);
    }
}
int main()
{
    int arr[] = {12, 32, 1, 4, 35, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}