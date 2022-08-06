#include<iostream>
#include<time.h>
using namespace std;
double time_takenByBubbleSort=0;
double time_takenBySelectionSort=0;
double time_takenByInsertionSort=0;
void PrintElement(int Array[], int sIze)
{
    cout<<"The Elements are "<<endl;
    for(int i = 0; i < sIze; i++)
    {
    
        cout<<Array[i]<<" ";
    }
    cout<<endl;
    
}
void BubbleSort(int Array[], int sIze)
{
    clock_t start,end;
    start = clock();
    for(int i=0;i<sIze;i++)
    {
        for(int j=0;j<sIze-i-1;j++)
        {
            if(Array[j]>Array[j+1])
                swap(Array[j],Array[j+1]);
        }
    }
    end=clock();
    time_takenByBubbleSort=((double)(end-start))/ CLOCKS_PER_SEC;
    
}
void SelectionSort(int Array[],int sIze)
{
    clock_t start,end;
    start = clock();
    for(int i =0;i<sIze-1;i++)
    {
        for(int j =i+1;j<sIze;j++)  
        if (Array[i]>Array[j])
        {
            swap(Array[i],Array[j]);
        }
        
    }
    end = clock();
    time_takenBySelectionSort=((double)(end-start))/ CLOCKS_PER_SEC;
   
}
void InsertionSort(int Array[],int sIze)
{
    int j=0;
    int key;    
    clock_t start,end;
    start = clock();
    for(int i=1;i<sIze;i++)
    {
        key = Array[i];
        j=i-1;
        while(j>=0 && Array[j]>key)
        {
            Array[j+1] = Array[j];
            j=j-1;
        }
        Array[j+1]=key;
    }
    end = clock();
    time_takenByInsertionSort=((double)(end-start))/ CLOCKS_PER_SEC;
}
int main()
{
    // this is a program of the bubble sort 
    // First Clear the past values
    srand(time(NULL));
    // Now asking the user how many elements are you generating
    cout<<"How many elements are you need to generate ? ";  
    int sIze;
    cin>>sIze;
    int Array[sIze]; 
    // This loop for generating elements  randomaly

    for (int i = 0; i < sIze; i++)
    {
        Array[i]=rand()%1000;
    }
    // Now call the Bubble sorting function
    PrintElement(Array,sIze);
    BubbleSort(Array,sIze);  
    SelectionSort(Array,sIze); 
    InsertionSort(Array,sIze);
    PrintElement(Array,sIze);
    cout<<endl;
    cout<<"Time Taken By Bubble Sort is "<<time_takenByBubbleSort<<" SECONDS "<<endl;
    cout<<"Time Taken By Selection Sort is "<<time_takenBySelectionSort<<" SECONDS "<<endl;
    cout<<"Time Taken By Insertion Sort is "<<time_takenByInsertionSort<<" SECONDS "<<endl;

    cout<<"\t\t\t\n";
    
}