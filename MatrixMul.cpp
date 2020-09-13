#include<iostream>
using namespace std;

void naiveMul(int** a, int** b, int** c,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++)
            c[i][j]+=a[i][k]*b[k][j];
        }
    }
}




int main(){
    int n;
    cin>>n;

    int **a= new int* [n];
    int **b= new int* [n];
    int **c= new int* [n];

    for(int i = 0;i<n;i++){
        a[i] =  new int[n];
        b[i] =  new int[n];
        c[i] =  new int[n];
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
    naiveMul(a,b,c,n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    
}