#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>

using namespace std;

//#define GRAPHSIZE 2048
//#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))

void dijkstra(int x);
void output();

int adj[101][101];
int n,s,vtx,edg,i,j,x,y,w;
int d[101],dist[101][101];;

int main(){
    FILE *fp;
    fp=fopen("Graph_MatrixBFS.txt","r");


    fscanf(fp,"%d",&vtx);

    for (i=1; i<=vtx;++i){
        for (j=0;j<vtx;++j){
            adj[i][j] = 0;
        }
    }
    n = -1;
    for (i=1; i<=vtx; ++i){
        fscanf(fp,"%d %d %d", &x, &y, &w);
        adj[x][y] = w;
        n = MAX(x, MAX(y, n));
    }

    cout<<"Input are taken from the File.\n";
    cout<<"\nAdjacency Matrix:\n";
    for(i=1; i<=vtx; i++){
        cout<<"\n";
        for(j=1; j<=vtx; j++){
            cout<<adj[i][j]<<" ";
        }
    }
    cout<<"\n\n";


    fclose(fp);

    dijkstra(1);
    output();

    cin>>edg;

    return 0;
}


void dijkstra(int x) {
    int i, k, small;
    int visited[101];

    for (i = 1; i <= vtx; ++i) {
        d[i] = INFINITY;
        visited[i] = 0;
    }

    d[x] = 0;

    for (k = 1; k <= vtx; ++k) {
        small = -1;
        for (i = 1; i <= vtx; ++i)
            if (!visited[i] && ((small == -1) || (d[i] < d[small])))
                small = i;

        visited[small] = 1;

        for (i = 1; i <= vtx; ++i){
            if (adj[small][i]){
                if (d[small] + adj[small][i] < d[i]){
                    d[i] = d[small] + adj[small][i];
                }
            }
        }
    }
}

void output(){
    int i;

    for (i=1; i<=vtx; ++i){
        cout<<"Shortest Path of "<<i<<" is "<<d[i];;
        cout<<endl;
    }
}
