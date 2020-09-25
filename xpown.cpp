#include <iostream>
using namespace std;

long long power(long long x, int n){
    if(n==0)
    return 1;
    if(n==1)
    return x;
    if(n%2==0)
    return power(x*x,n/2);
    else
    return power(x*x,n/2)*x;    
}

int main(){
    cout<<"Enter x and y: "
    long long x;
    int y;
    cin>>x>>y;
    long long ans = power(x,y);
    cout<<ans;
}