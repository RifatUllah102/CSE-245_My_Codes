#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

void Search(char *P, char *T){
    int m,n;
    m=strlen(T);
    n=strlen(P);
    for(int i=0;i<=m-n;i++){
        for(int j=0;j<n;j++){
            if(T[i+j]!=P[j]){
                break;
            }
            else if(j==n){
                cout<<"String Match at Position "<<i<<",\n";
            }

        }
    }
}

int main(){
    char P[101],T[101];

    cout<<"Enter your Text : ";
    cin>>T;
    cout<<"Enter the Pattern : ";
    cin>>P;

    Search(P,T);

    return 0;
}
