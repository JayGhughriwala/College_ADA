#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[],int val[],int n)
{
    int i,w;
    vector<vector<int>> K(n+1, vector<int>(W +1));

    for(i =0;i<=n;i++){
        for(w = 0;w<=W;w++)
        {
            if(i == 0 || w== 0)
            {
                K[i][w] = 0;
            }
            else if(wt[i-1]<=w)
            {
                K[i][w]= max(val[i-1] + K[i-1][w-wt[i-1]],K[i-1][w]);
            }
            else
            {
                K[i][w] = K[i-1][w];
            }
        }

        
    }return K[n][W];
}
int main()
{
    int value[] = {200,180,120,100};
    int weight[]= {20,20,30,40};
    int capacity = 90;
    int n = sizeof(value)/sizeof(value[0]);

    cout<<"The Maximum profit we can get that  is "<<knapSack(capacity,weight,value,n)<<endl;

    return 0;


}