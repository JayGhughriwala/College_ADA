#include<iostream>
using namespace std;
int factorialUsingRec(int n)
{
   
    if(n==1)
    return 1;
    else
    return n * factorialUsingRec(n-1);
}
int factorialUsingIter(int n)
{
    int fact=1;
    while(n>0)
    {
        fact=fact*n;
        n=n-1;
    }
    return fact;
}
int main()
{
    cout<<"This is a program of a factorial finding"<<endl;
    cout<<"Factorial Finding using a recursive method"<<endl;
    cout<<"Enter a number for finding a factorial -- > "<<endl;
    int num;
    cin>>num;
     clock_t start=clock();
    cout<<"Factorial Using Recursion "<<factorialUsingRec(num)<<endl;
     clock_t end=clock();
     clock_t start_1= clock();

    cout<<"Factorial Using Iterative "<<factorialUsingIter(num)<<endl;    
    clock_t end_1= clock();
    cout<<"\n\tTime taken by the Recursion "<<double((end-start))/CLOCKS_PER_SEC<<endl;
    cout<<"\n\tTime taken by the Iteratin "<<double((end_1-start_1))/CLOCKS_PER_SEC<<endl;


}