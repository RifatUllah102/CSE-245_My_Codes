#include<iostream>
#include<cmath>
#include<cstdio>


using namespace std;

int x,y,d,d1,x1,y2,gcd;

int Euclid(int a,int b){
    if(b==0){
        cout<<"GCD is "<<a<<endl;
    }
    else{
        Euclid(b,(a%b));
    }
}

int ExtEuclid(int a,int b){
    if(b==0){
        return (a,1,0);
    }
    else{
        //cout<<"Coming...";
        (d1,x1,y2)=ExtEuclid(b,(a%b));
        (d,x,y)=(d1,y2,(x1-floor(a/b)*y2));
        return (d,x,y);
    }
//        d=gcd=(a*x+b*y);
//        cout<<"X = "<<x<<"\nY = "<<y;
}

int main(){
    int a,b;
    cout<<"Enter The Number of a = ";
    cin>>a;
    cout<<"Enter The Number of b = ";
    cin>>b;

    gcd=Euclid(a,b);
    ExtEuclid(a,b);

//    d=gcd=(a*x+b*y);
//    cout<<"X = "<<x<<"\nY = "<<y;

    return 0;
}
