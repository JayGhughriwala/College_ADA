#include <bits/stdc++.h>
using namespace std;

// for printing a Array

void printArray(int Array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}
void heapify(int array[], int size, int i)
{

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    // untill root not largest
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}
void heapSort(int Array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(Array, size, i);
    }

    // Now heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(Array[0], Array[i]);
        // Now heapify the root element to get  a highest element root again

        heapify(Array, i, 0);
    }
}
int main()
{
    int size ;
    cout << "\tHere 's the program of the sorting the elements using a heapsort\n\n" << endl;
    cout<<"---\t\tHow many Numbers are you wish to randomly generate ? ";
    
    cin>>size;
    int Array[size];
    srand(time(NULL));
    for(int i=0 ;i<size;i++)
    {
        Array[i] = rand() % 100 + 1;
    }
    cout << "Unsorted Array :- ";
    printArray(Array, size);
    heapSort(Array, size);

    cout << "Now Sorted Array is " << endl;
    printArray(Array, size);
    return 0;
}