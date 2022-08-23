#include<iostream>
using namespace std;
int linearSearch(int value)
{
    int array[] = {0,1,2,3,4,5,6,7,11 ,11,1,122,1200,13232,12};
    short index=0;
    bool flag = false;
    for(int i=0;i<(sizeof(array)/sizeof(array[0]));i++)
    {
        if(array[i]==value)
            {
                index = i;
                flag=true;
                break;
            }
    }
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
        cout<<"Element found at the index \n"<<ind;
    else
        cout<<"Element not found\n";
}