#include <iostream>
using namespace std;
double quicksortTime = 0.0;
double BinarySearchTime = 0.0;

void printElements(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i];
    }
    cout << endl;
}
int partition(int array[], int low, int high)
{

    int i = low + 1;
    int j = high;
    int pivot = array[low];
    int temp;
    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}

void quicksort(int array[], int low, int high)
{
    int partitionindex = 0;
    if (low < high)
    {
        partitionindex = partition(array, low, high);
        quicksort(array, low, partitionindex - 1);
        quicksort(array, partitionindex + 1, high);
    }
}
int binarySearch(int array[], int element, int low, int high)
{
    int mid = (int)((low + high) / 2);
    if (array[mid] == element)
    {
        return mid;
    }
    else if (array[mid] > element)
    {
        return binarySearch(array, element, low, mid - 1);
    }
    else if (array[mid] < element)
    {
        return binarySearch(array, element, mid + 1, high);
    }
    else
    {
        return -1;
    }
}
int main()
{
    // this is the program for the searching of the binary searching
    //  now generating a array by the user size

    cout << "How many elements you need to generate in the array ? " << endl;
    int Size;
    cin >> Size;
    int array[Size];
    srand(time(NULL));
    for (int i = 0; i < Size; i++)
    {
        array[i] = rand() % 1000 + 1;
    }
    // Now we need to sort this array in the ascending order in order to apply a binary search

    cout << "Array Elements are randomly generated" << endl;
    printElements(array, Size - 1);
    cout << "Which element are you need to find ? ";
    int element;
    cin >> element;

    clock_t start = clock();
    quicksort(array, 0, Size - 1);
    start = clock() - start;

    quicksortTime = (double)start / CLOCKS_PER_SEC;
   

    // now call the binary search method
    printElements(array,Size-1);
    start = clock();
    int binarySeachIndex = binarySearch(array, element, 0, Size - 1);
    start = clock() - start;
    BinarySearchTime = (double)binarySeachIndex / CLOCKS_PER_SEC;
    if (binarySeachIndex == -1)
    {
        cout << "Your searched element does not exist in the array" << endl;
        cout << "Time taken by binary search is " << BinarySearchTime <<"SECONDS"<< endl;
    }
    else
    {
        cout << "Element found at the index " << binarySeachIndex << endl;
        cout << "Time taken by binary search is " << BinarySearchTime << "SECONDS"<<endl;
    }
     cout<<"Time taken by the quicksort is "<<quicksortTime<<"SECONDS"<<endl;
    
}