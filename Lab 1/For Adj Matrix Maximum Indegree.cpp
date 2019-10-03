#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;

int main(){
    int adj[101][101],sum,max=0;
    int n,vtx,edg,i,j,x,y;

    cout<<"Input Number of Vertex: ";
    cin>>vtx;
    edg=1;

    cout<<"\nPress 0 0 in Edge for 'STOP' Input.\n\n";

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

    for(i=1; i<=vtx; i++){
        sum=0;
        for(j=1; j<=vtx; j++){
            sum=sum+adj[i][j];
        }
        if(sum>max){
                max=sum;
                n=i;
            }
        else
            continue;
    }
    cout<<"\n"<<n<<" Node has Maximum Degree and "<<"Maximum Degree is: "<<max<<endl;

    return 0;
}

