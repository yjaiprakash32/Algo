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
    cin>>len;
    int price[len];
    for(int i=0;i<len;i++)
    cin>>price[i];

    cout<<cutRod(price,len);
}