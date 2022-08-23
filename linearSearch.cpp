#include<iostream>
using namespace std;
double timetaken=0;
int linearSearch(int value)
{
    int array[1000];
    short index=0;
    bool flag = false;
 
    srand(time(NULL));

    for(int i=0;i<1000;i++)
    {
        array[i] = rand()%10000;
    }
     for(int i=0;i<1000;i++)
    {
        cout<<array[i]<<" ";
    }
    
    clock_t now = clock();
    for(int i=0;i<(sizeof(array)/sizeof(array[0]));i++)
    {
        if(array[i]==value)
            {
                index = i;
                flag=true;
                break;
            }
    }
    now = clock() - now;
    timetaken=double(now)/CLOCKS_PER_SEC;
    if (flag==true)
        return index;
    else
        return flag;
}

int main()
{
    cout<<"This is a linear Search Program"<<endl;
    cout<<"Enter a Value to find in the array "<<endl;
    int value;
    cin>>value;
    int ind = linearSearch(value);
    if (ind)
      
      {  cout<<"Element found at the index \n"<<ind;
        cout<<"\nTime taken "<<timetaken<<endl;}
    else
       {cout<<"\nElement not found\n";
       cout<<"\nTime taken "<<timetaken<<endl;
       }
}