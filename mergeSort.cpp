#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int size;
double timeMerge = 0.0;
void printElements(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i];
    }
    cout <<"\n\n"<< endl;
}
void merge(int array[],int mid,int low,int high)
{
    int i = low;
    int j= mid+1;
    int copyArray[size];
    int k=low;
    while(i<=mid && j<=high){
        if(array[i]<array[j])
        {
            copyArray[k] = array[i];
            i++;
            k++;
        }
        else
        {
            copyArray[k] =array[j];
            j++;
            k++;

        }
    }
    while(i<=mid)
    {
        copyArray[k] = array[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        copyArray[k] = array[j];
        j++;
        k++;
    }

    // Now for put all values in the array

    for(int i =low;i<=high;i++)
    {
        array[i] = copyArray[i];
    }
}
void mergesort(int array[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = floor((low+high)/2);
        mergesort(array,low,mid);
        mergesort(array,mid+1,high);
        merge(array,mid,low,high);

    }
}
int main()
{
    cout<<"How many elements are you generating in the array ? "<<endl;
    
    cin >> size;
    int array[size];

    srand(time(NULL));
    for(int i =0;i<size;i++)
    {
        array[i] = rand() % 1000 + 1;

    }
    printElements(array,size-1);
    clock_t start = clock();
    mergesort(array,0,size-1);

    start = clock() - start;
    timeMerge = (double)start/CLOCKS_PER_SEC;
    printElements(array,size-1);

    cout<<"Time taken by the merge sort is "<<timeMerge<<endl;
    
    //   Now calling a mergeSort()
}