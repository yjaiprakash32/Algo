#include <iostream>
using namespace std;

int cutRodaux(int price[],int n , int arr[]){
    if(arr[n]>=0)
    return arr[n];
    int val;
    if(n==0)
    val=0;
    else{
        val = INT16_MIN;
        for(int i =0 ;i<n;i++){
            val = max(val,price[i]+cutRodaux(price,n-i-1,arr));
        }
    }
    arr[n]= val;
    return val;   
}

int cutRod(int price[], int n){
    int arr[n+1];
    int i;
    for(int i = 0 ; i<=n;i++)
    arr[i]= INT16_MIN;
    return cutRodaux(price,n,arr);
}

int main(){
    int len;
    cin>>len;
    int price[len];
    for(int i=0;i<len;i++)
    cin>>price[i];
    cout<<cutRod(price,len);
}