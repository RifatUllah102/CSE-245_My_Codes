#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;

int n,W,w[101],v[101];

int KnapSack(int W, int wt[], int val[], int n){
    int i, w;
    int K[n + 1][W + 1];

    for (i=0;i<=n;i++){
        for (w=0;w<=W;w++){
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1]<=w)
                K[i][w]= max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main(){
    int MaxProfit=0;
    cout<<"Enter the Number of the Item: ";
    cin>>n;
    cout<<"Enter the Capacity of Weight: ";
    cin>>W;

    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" Item weight : ";
        cin>>w[i];
        cout<<"Enter "<<i+1<<" Item value : ";
        cin>>v[i];
    }

    MaxProfit=KnapSack(W,w,v,n);

    cout<<"Max Profit is: "<<MaxProfit;

    return 0;
}
