#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionpoint(int arr[], int low, int high)
{
    int pivot = arr[high]; // selecting the right most element as pivot element
    int i = low - 1;       // pointer to greater element

    // comparing each element with pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&arr[i], &arr[j]);
        }
    }
    // swap pivot with the greater element at i
    swap(&arr[i + 1], &arr[high]);

    // return the partition point
    return (i + 1);
}

int quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionpoint(arr, low, high);
        // recursive call on the left of pivot
        quicksort(arr, low, pi - 1);

        // recursive call on the right of pivot
        quicksort(arr, pi + 1, high);
    }
}

// function to print the array
int printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {5, 6, 8, 10, 20, 1, 22, 56, 89, 3, 99, 102, 4, 110};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "the unsorted array is :" << endl;
    printarray(array, size);

    quicksort(array, 0, size - 1);
    cout << "the array after applying quicksort algorithm is :" << endl;
    printarray(array, size);
}