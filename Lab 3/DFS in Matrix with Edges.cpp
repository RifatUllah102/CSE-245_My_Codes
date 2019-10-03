#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int adj[101][101],vtx,u,Vertex[101]={0};
int clr[101],prev[101],d[101],f[101],time;

void DFS(int);
void DFS_Visit(int);

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

    cout<<"\n\n0 = White.\n";
    cout<<"1 = Grey.\n";
    cout<<"2 = Black.\n\n";

    DFS(s);

    return 0;
}

void DFS(int s){
    queue<int>Q;

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
                //u=i;
                DFS_Visit(i);
            }
        }
    }

    for(int i=1; i<=vtx; i++){
        cout<<"Discovery time of Vertex "<<i<<" :"<<d[i]<<endl;
    }

    for(int i=1; i<=vtx; i++){
        cout<<"Colur of Vertex "<<i<<" :"<<clr[i]<<endl;
    }
    for(int i=1; i<=vtx; i++){
        cout<<"Previous of Vertex "<<i<<" :"<<prev[i]<<endl;
    }
    for(int i=1; i<=vtx; i++){
        cout<<"Finishing time of Vertex "<<i<<" :"<<f[i]<<endl;
    }

}

void DFS_Visit(int u){
    clr[u]=1;
    time=time+1;
    d[u]=time;

    for(int i=1; i<=vtx; i++){
        if(adj[u][i]==1 && clr[i]==0){
            cout<<u<<"-->"<<i<<" Tree Edge.\n";
            prev[i]=u;
            DFS_Visit(i);
        }
        else if(adj[u][i]==1 && clr[i]==1){
                cout<<u<<"-->"<<i<<" Back Edge.\n";
        }
        else if(adj[u][i]==1 && clr[i]==2){
                if(d[u]<d[i]){
                    cout<<u<<"-->"<<i<<" Forward Edge.\n";
                }
                else if(d[u]>d[i]){
                    cout<<u<<"-->"<<i<<" Cross Edge.\n";
                }
        }
    }
    clr[u]=2;
    time=time+1;
    f[u]=time;
}
