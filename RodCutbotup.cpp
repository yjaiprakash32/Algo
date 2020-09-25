#include <iostream>
using namespace std;
 int cutRod(int price[], int len){
     int val[len+1];
     val[0]=0;

     for(int i=1;i<=len;i++){
         int value = INT8_MIN;
         for(int j=0;j<i;j++)
             value = max(value,price[j]+val[i-j-1]);
         val[i] = value;
     }
     return val[len];
 }

int main(){
    int len;
    double x;
    cout<<"Enter value of len and x ";
    cin>>len>>x;
    if(x==0.50)
    len=len*2;
    if(x==0.25)
    len = len*4;
    if(x==0.20)
    len= len*5;
    int price[len];
    cout<<"Enter the prices: ";
    for(int i=0;i<len;i++)
    cin>>price[i];

    cout<<cutRod(price,len);
}