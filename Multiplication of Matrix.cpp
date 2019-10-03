#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

void SingleMatrix(){
    int a[101][101],b[101][101],mul[101][101],sum[101][101];
    int i,j,c,d,n;

    cout<<"How Many Vertex's : ";
    cin>>n;

    cout<<"\nEnter The Adjacency Matrix:\n";

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(c=0; c<n; c++){
        for(d=0; d<n; d++){
            sum[c][d]=0;
            for(i=0,j=0; i<n; i++,j++){
                sum[c][d]=sum[c][d]+(a[c][j]*a[i][d]);
            }
        }
    }
    for(i=0; i<n; i++){
        cout<<"\n";
        for(j=0; j<n; j++){
            mul[i][j]=sum[i][j];
            cout<<mul[i][j]<<" ";
        }
    }
}

int main(){

    SingleMatrix();

    return 0;
}
