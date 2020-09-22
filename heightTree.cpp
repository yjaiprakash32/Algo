#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a = log2(n);
    int b = 1.44*log2(n);
    cout<<"Max and Height if node ground is 0: "<<b<<" "<<floor(a)<<endl;
    cout<<"Max height for 1 base indexing: "<<b+1<<" "<<floor(a)+1<<endl;
    }