#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;

int adj[101][101],L[101][101];
int n,vtx,edg,i,j,x,y,w,Count=1;

void FloydWarshall();
void Output();

int main(){


    cout<<"Input Number of Vertex: ";
    cin>>vtx;
    edg=1;

    for(i=1; i<=vtx; i++){
        for(j=1; j<=vtx; j++){
            adj[i][j]=2000;
        }
    }

    cout<<"\nPress 0 0 in Edge for 'STOP' Input.\n\n";

    while(1){
        cout<<"Edge "<<edg<<": ";
        cin>>x>>y;

        if(x!=0 && y!=0){
            cout<<"Enter Weight : ";
            cin>>w;
        }
        if(x==0 || y==0){
            break;
        }
        if(x<1 || x>vtx || y<1 || y>vtx){
            cout<<"Invalid Input";
        }
        else{
            adj[x][y]=w;
            adj[x][x]=0;
            edg++;
        }
    }

    cout<<"\nWait Matrix:\n";
    for(i=1; i<=vtx; i++){
        cout<<"\n";
        for(j=1; j<=vtx; j++){
            cout<<adj[i][j]<<"        ";
        }
    }

    FloydWarshall();

    return 0;
}

void FloydWarshall(){

    for(int k=1; k<=vtx; k++){
            for(int i=1; i<=vtx; i++){
                for(int j=1; j<=vtx; j++){
                    if(adj[i][j]>adj[i][k]+adj[k][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                        Count++;
                    }
                }
            }
        }

    for(int i=1; i<=vtx; i++){
        for(int j=1; j<=vtx; j++){
            L[i][j]=adj[i][j];
        }
    }


    cout<<"\n\n";
    cout<<"-----------------------------------------------------------------------------";
    Output();

}

void Output(){
    cout<<"Final Result Is : \n";
    cout<<"-----------------------------------------------------------------------------";
    for(i=1; i<=vtx; i++){
            cout<<"\n";
            for(j=1; j<=vtx; j++){
                cout<<L[i][j]<<"        ";
            }
        }
}

