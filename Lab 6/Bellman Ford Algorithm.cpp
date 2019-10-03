#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;

int main(){
    int vertex,edge,src,i;
    int d[100],eu[100],ev[100],ecost[100],u,v;
    cout<<"Input Number of Vertex: ";
    cin>>vertex;
    cout<<"How many Edge  :  ";
    cin>>edge;

    for(i=1;i<=vertex;i++){
        d[i]=1000000000;
    }



    for(i=1;i<=edge;i++){
         cout<<"Enter Edge "<<i<<" : ";
         cin>>eu[i]>>ev[i]>>ecost[i];
    }
    cout<<"Enter  Source : ";
    cin>>src;

    d[src]=0;
    int negcycle=0;
    int pass;
    int updated;
    for( pass=1;pass<=vertex;pass++)
    {
        int updated=0;
        for( i=1;i<=edge;i++){
            u=eu[i];
            v=ev[i];
            if(d[v]>d[u]+ecost[i]){
                updated=1;
                if(pass==vertex){
                    negcycle=1;
                }
                d[v]=d[u]+ecost[i];

            }

        }
        if(updated==0)
            break;
    }

    if(negcycle==0){
        for (i=1; i<=vertex; ++i){
            cout<<"Shortest Path of "<<i<<" is "<<d[i];;
            cout<<endl;
        }
    }
    else
        cout<<"Negative  Cycle Exist.No Shortest Path Available.\n";


    return 0;
}
