#include <iostream>
using namespace std;

int rodCut(int price[], int len){
    if(len<1)
    return 0;

    int val = INT8_MIN;
    for(int i=0;i<len;i++)
    val = max(val,price[i]+rodCut(price,len-i-1));

    return val;
}

int main(){
    int len;
    cin>>len;
    int price[len];
    for(int i=0;i<len;i++)
    cin>>price[i];

    cout<<rodCut(price,len);
}