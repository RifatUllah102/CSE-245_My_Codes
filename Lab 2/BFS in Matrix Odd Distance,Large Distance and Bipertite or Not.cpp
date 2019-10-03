#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int adj[101][101],vtx,Vertex[101]={0};

void BFS(int);

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
            cout<<"Invalid Input";
        }
        else{
            adj[x][y]++;
            adj[y][x]++;
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

    BFS(s);

    return 0;
}

void BFS(int s){
    queue<int>Q;
    int clr[101],prev[101],d[101],u;

    for(int i=1; i<=vtx; i++){
            clr[i]=0;
            prev[i]=-1;
            d[i]=20000;

    }

    clr[s]=1;
    d[s]=0;

    Q.push(s);

    while(!Q.empty()){

        u=Q.front();
        Q.pop();

        for(int i=1; i<=vtx; i++){

            if(adj[u][i]==1 && clr[i]==0){
                clr[i]=1;
                d[i]=d[u]+1;
                prev[i]=u;

                Q.push(i);
            }

        }
        clr[u]=2;
    }
    for(int i=1; i<=vtx; i++){
        cout<<"Distace :"<<d[i]<<endl;
    }

    for(int i=1; i<=vtx; i++){
        cout<<"Colur :"<<clr[i]<<endl;
    }
    for(int i=1; i<=vtx; i++){
        cout<<"Previous :"<<prev[i]<<endl;
    }

    for(int i=1; i<=vtx; i++){
        if(d[i]%2!=0){
            cout<<"Odd Distance from the source Node is "<<Vertex[i]<<endl;
        }
    }
    int max=0,a;
    for(int i=1; i<=vtx; i++){
        if(d[i]>max){
            max=d[i];
            //a=Vertex[i];
        }
    }
    for(int i=1; i<=vtx; i++){
        if(max=d[i]){
            cout<<"Largest Distance from the source Node is "<<Vertex[i]<<endl;
        }
    }


}
