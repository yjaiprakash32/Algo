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

int** muldc(int** a, int** b , int n){
    if(n==1)
    return a[0][0]*b[0][0];
    int **x = new int*[n/2];
    int **y = new int*[n/2];
    int **z = new int*[n/2];
    int **p = new int*[n/2];
    int **q = new int*[n/2];
    int **r = new int*[n/2];
    int **s = new int*[n/2];
    int **t = new int*[n/2];
    for(int i = 0 ;i <n/2;i++){
        x[i] = new int[n/2];
        y[i] = new int[n/2];
        z[i] = new int[n/2];
        p[i] = new int[n/2];
        q[i] = new int[n/2];
        r[i] = new int[n/2];
        s[i] = new int[n/2];
        t[i] = new int[n/2];
    }

    for(int i = 0; i < n/2; i++){
        for(int j = 0 ;j<n/2;j++){
            x[i][j]= a[i][j];
            q[i][j]= b[i][j];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0 ;j<n/2;j++){
            y[i][j]= a[i][j+n/2];
            r[i][j]= b[i][j+n/2];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0 ;j<n/2;j++){
            x[i][j]= a[i][j];
            q[i][j]= b[i][j];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0 ;j<n/2;j++){
            x[i][j]= a[i][j];
            q[i][j]= b[i][j];
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