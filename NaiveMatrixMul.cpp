#include<iostream>
#include<cmath>
#include<chrono>
using namespace std::chrono;
using namespace std;

void naiveMul( int** a,int** b, int** c,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++)
            c[i][j]+=a[i][k]*b[k][j];
        }
    }
}

int main(){
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int n = pow(2,k);

    int **a= new int* [n];
    int **b= new int* [n];
    int **outNaive= new int* [n];

    for(int i = 0;i<n;i++){
        a[i] =  new int[n];
        b[i] =  new int[n];
        outNaive[i] =  new int[n];
    }
    cout<<"enter elements of a ";
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter elements of b ";
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    naiveMul(a,b,outNaive,n);
    cout<<"Using Naive: "<<endl;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<outNaive[i][j]<<" ";
        }
        cout<<endl;
    }
}