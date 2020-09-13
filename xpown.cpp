#include <iostream>
using namespace std;

float power(float x , unsigned int y){
    float temp;
    if(y==0)
    return 1;

    temp = power(x,y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        if(y>0)
        return x*temp*temp;
        else 
        return temp*temp/2;
    }
}

int main(){
    float x;
    unsigned int y;
    cin>>x>>y;
    float ans = power(x,y);
    cout<<ans;
}