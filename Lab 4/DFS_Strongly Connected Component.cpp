#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<windows.h>

using namespace std;

list<int>Q;

int adj[101][101],vtx,u,Vertex[101]={0},InverseAdj[101][101];
int clr[101],prev[101],d[101],f[101],time;

void DFS(int);
void DFS_Visit(int);
void DFS_Transpose(int);
void DFS_VisitTranspose(int);

int main(){

    int n,edg,i,j,x,y,s;

    cout<<"Input Number of Vertex: ";
    cin>>vtx;
    edg=1;

    for(int i=1; i<=vtx; i++){    //Set all Vertex in an array the name Vertex[101]
        Vertex[i]=i;
    }

    cout<<"\nPress 0 0 in Edge for 'STOP' Input.\n\n";

    while(1){
        cout<<"Edge "<<edg<<": ";
        cin>>x>>y;

        if(x==0 || y==0){
            cout<<"\nEnter The Source Vertex: "<<endl;
            cin>>s;
            break;
        }
        if(x<1 || x>vtx || y<1 || y>vtx){
            cout<<"Invalid Input.\n";
        }
        else{
            adj[x][y]++;
            //adj[y][x]++;
            edg++;
        }
    }

    cout<<"\nAdjacency Matrix:\n";
    for(i=1; i<=vtx; i++){
        cout<<"\n";
        for(j=1; j<=vtx; j++){
            cout<<adj[i][j]<<" ";
        }
    }

    for(i=1; i<=vtx; i++){
        for(j=1; j<=vtx; j++){
            InverseAdj[j][i]=adj[i][j];
        }
    }

    cout<<"\nGraph Transpose:\n";
    for(i=1; i<=vtx; i++){
        cout<<"\n";
        for(j=1; j<=vtx; j++){
            cout<<InverseAdj[i][j]<<" ";
        }
    }

    cout<<"\n\n0 = White.\n";
    cout<<"1 = Grey.\n";
    cout<<"2 = Black.\n\n";

    DFS(s);

    int a[101],temp;
    for(int i=1; i<=vtx; i++){
        a[i]=f[i];
    }
    for(int i=1; i<=vtx; i++){
        for(int j=1; j<=vtx; j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i=1; i<=vtx; i++){
        for(int j=0; j<=vtx; ++j){
            if(a[i]==f[j]){

                DFS_Transpose(Vertex[j]);
            }
        }
    }

    return 0;
}

void DFS(int s){

    for(int i=1; i<=vtx; i++){
            clr[i]=0;
            prev[i]=-1;
            d[i]=20000;
            f[i]=20000;
    }

    time=0;

    for(int i=1; i<=vtx; i++){
        for(int j=1; j<=vtx; j++){
            if(adj[i][j]==1 && clr[j]==0){
                DFS_Visit(i);
            }
        }
    }
    for(int i=1; i<=vtx; i++){
        cout<<"Discovery time of Vertex "<<i<<" :"<<d[i]<<endl;
    }
    Sleep(1000);
    for(int i=1; i<=vtx; i++){
        cout<<"Colur of Vertex "<<i<<" :"<<clr[i]<<endl;
    }
    Sleep(1000);
    for(int i=1; i<=vtx; i++){
        cout<<"Previous of Vertex "<<i<<" :"<<prev[i]<<endl;
    }
    Sleep(1000);
    for(int i=1; i<=vtx; i++){
        cout<<"Finishing time of Vertex "<<i<<" :"<<f[i]<<endl;
    }
    Sleep(1000);

}

void DFS_Visit(int u){
    clr[u]=1;
    time=time+1;
    d[u]=time;

    for(int i=1; i<=vtx; i++){
        if(adj[u][i]==1 && clr[i]==0){
            prev[i]=u;
            DFS_Visit(i);
        }
    }
    clr[u]=2;
    time=time+1;
    f[u]=time;
}

void DFS_Transpose(int s){

    for(int i=1; i<=vtx; i++){
        for(int j=1; j<=vtx; j++){
            if(InverseAdj[i][j]==1 && clr[j]==2){
                DFS_VisitTranspose(i);
            }
        }
    }
    cout<<"\n are the Strongly Connected Component.\n";

}

void DFS_VisitTranspose(int u){
    int SCC[101];
    clr[u]=3;

    for(int i=1; i<=vtx; i++){
        if(InverseAdj[u][i]==1 && clr[i]==2){
            //prev[i]=u;
            SCC[i]=u;
            cout<<SCC[i]<<"\n";
            DFS_VisitTranspose(i);
        }
        //cout<<"\n";
    }

}
