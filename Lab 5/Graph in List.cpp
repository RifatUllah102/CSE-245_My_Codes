#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;

int main(){
    int n,vtx,edg,i,j,x,y;

    list<int> adj[101];
    list<int>:: iterator it;

    cout<<"Input Number of Vertex: ";
    cin>>vtx;
    edg=1;

    cout<<"\nPress 0 0 in Edge for 'STOP' Input.\n\n";

    FILE *fp;

    while(1){
        cout<<"Edge "<<edg<<": ";
        cin>>x>>y;

        if(x==0 || y==0){
            break;
        }
        if(x<1 || x>vtx || y<1 || y>vtx){
            cout<<"Invalid Input";
        }
        else{
            adj[x].push_back(y);
            adj[y].push_back(x);
            edg++;
        }
    }

    fp=fopen("Graph_ListBFS.txt","w");

    fprintf(fp,"Vertex : ");
    fprintf(fp,"%d",vtx);
    fprintf(fp,"\nAdjacency List:\n");

    cout<<"\nAdjacency List:\n";
    for(i=1; i<=vtx; i++){
        cout<<"Adj["<<i<<"]: ";
        fprintf(fp,"%d : ",i);
        for(it=adj[i].begin(); it!=adj[i].end(); it++){
            cout<<"->"<< *it;
            fprintf(fp,"->%d",*it);
        }
        fprintf(fp,"\n");
        cout<<endl;
    }
    fclose(fp);

    return 0;
}
