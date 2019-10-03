#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<list>

using namespace std;

void Euclid(int a,int b){
    if(b==0){
        cout<<"GCD is "<<a<<endl;
    }
    else{
        Euclid(b,(a%b));
    }
}

//void ExtEuclid(int a,int b){
//    if(b==0){
//        return (a,1,0);
//    }
//    else{
//        (d1,x1,y1)=ExtEuclid(b,(a%b));
//        (d,x,y)=(d1,y1,x1-floor(a/b)y1);
//        return (d,x,y);
//    }
//    d=ax+by;
//    cout<<"X = "<<x<<"\nY = "<<Y;
//}

int main(){
    int a,b;
    cout<<"Enter The Number of a = ";
    cin>>a;
    cout<<"Enter The Number of b = ";
    cin>>b;

    Euclid(a,b);
    //ExtEuclid(a,b);

    return 0;
}
