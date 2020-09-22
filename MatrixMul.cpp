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

int** matrixAdd(int **a, int **b, int n){
    int **arr= new int*[n];
    for(int i =0;i<n;i++)
    arr[i]= new int[n];

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=a[i][j]+b[i][j];
        }
    }
    return arr;
}

int** muldc(int** a, int** b , int n){
    int **C = new int*[n];
    for(int i =0;i<n;i++)
    C[i]= new int[n];
    
    if(n==1)
    C[0][0]=a[0][0]*b[0][0];
    
    else{
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

    for(int i =0;i<n/2;i++){
        for(int j=0;j<n/2;++j){
            x[i][j]= a[i][j];
            y[i][j]= a[i][j+n/2];
            z[i][j]= a[i+n/2][j];
            p[i][j]= a[i+n/2][j+n/2];
            q[i][j]= b[i][j];
            r[i][j]= b[i][j+n/2];
            s[i][j]= b[i+n/2][j];
            t[i][j]= b[i+n/2][j+n/2];
        }
    }

    int **c11 =matrixAdd(muldc(x,q,n/2),muldc(y,s,n/2),n/2);
    int **c12 =matrixAdd(muldc(x,r,n/2),muldc(y,t,n/2),n/2);
    int **c21 =matrixAdd(muldc(z,q,n/2),muldc(p,s,n/2),n/2);
    int **c22 =matrixAdd(muldc(z,r,n/2),muldc(p,t,n/2),n/2);

    for(int i = 0;i<n/2;i++){
        for(int j = 0;j<n/2;j++){
            C[i][j]= c11[i][j];
            C[i][j+n/2]= c12[i][j];
            C[i+n/2][j]= c21[i][j];
            C[i+n/2][j+n/2]= c22[i][j];
        }
    }
    }
    return C;

}
int** matrixSub(int **a, int **b, int n){
    int **arr= new int*[n];
    for(int i =0;i<n;i++)
    arr[i]= new int[n];

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=a[i][j]-b[i][j];
        }
    }
    return arr;
}

int** strassen(int **a,int **b, int n){
   int **C = new int*[n];
    for(int i =0;i<n;i++)
    C[i]= new int[n];
    
    if(n==1)
    C[0][0]=a[0][0]*b[0][0];
    
    else{
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

    for(int i =0;i<n/2;i++){
        for(int j=0;j<n/2;++j){
            x[i][j]= a[i][j];
            y[i][j]= a[i][j+n/2];
            z[i][j]= a[i+n/2][j];
            p[i][j]= a[i+n/2][j+n/2];
            q[i][j]= b[i][j];
            r[i][j]= b[i][j+n/2];
            s[i][j]= b[i+n/2][j];
            t[i][j]= b[i+n/2][j+n/2];
        }
    } 
        int **p1=strassen(matrixAdd(x,p,n/2),matrixAdd(q,t,n/2),n/2);
        int **p2=strassen(matrixAdd(z,t,n/2),q,n/2);
        int **p3=strassen(x,matrixSub(r,t,n/2),n/2);
        int **p4=strassen(p,matrixSub(r,p,n/2),n/2);
        int **p5=strassen(matrixAdd(x,y,n/2),t,n/2);
        int **p6=strassen(matrixSub(z,x,n/2),matrixAdd(p,q,n/2),n/2);
        int **p7=strassen(matrixAdd(y,p,n/2),matrixAdd(s,t,n/2),n/2);

        int **c11=matrixAdd(matrixSub(matrixAdd(p1,p4,n/2),p5,n/2),p7,n/2);
        int **c12=matrixAdd(p3,p5,n/2);
        int **c21=matrixAdd(p2,p4,n/2);
        int **c22=matrixAdd(matrixSub(matrixAdd(p1,p3,n/2),p2,n/2),p6,n/2);

        for (int i = 0; i < n/2; ++i)
        {
        	for (int j = 0; j < n/2; ++j)
        	{
        		C[i][j]=c11[i][j];
        		C[i][j+n/2]=c12[i][j];
        		C[i+n/2][j]=c21[i][j];
        		C[i+n/2][j+n/2]=c22[j][j];
        		
        	}
        	
        } 
    }
    return C;
} 



int main(){
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int n = pow(2,k);

    int **a= new int* [n];
    int **b= new int* [n];
    int **outNaive= new int* [n];
    int **outDc= new int* [n];
    int **outStra = new int* [n];

    for(int i = 0;i<n;i++){
        a[i] =  new int[n];
        b[i] =  new int[n];
        outNaive[i] =  new int[n];
        outDc[i] = new int[n];
        outStra[i] = new int[n];
    }
    // cout<<"enter elements of a ";
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>a[i][j];
    //     }
    // }
    // cout<<"Enter elements of b ";
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>b[i][j];
    //     }
    // }

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            a[i][j]=rand()%10+1;
            b[i][j]=rand()%10+1;
        }
    }
    auto strt1 = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    naiveMul(a,b,outNaive,n);
    auto end1 =high_resolution_clock::now();
    auto time1=duration_cast<microseconds>(end1-strt1);
    
    cout<<time1.count()<<endl;
    // cout<<"Using Naive: "<<endl;
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<outNaive[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    auto strt2 = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    outDc =muldc(a,b,n);
    auto end2 =high_resolution_clock::now();
    auto time2=duration_cast<microseconds>(end2-strt2);
    
    cout<<time2.count()<<endl;
    // cout<<"Using Divide and conquer: "<<endl;
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<outDc[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    auto strt3 = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    outStra =strassen(a,b,n);
    auto end3 =high_resolution_clock::now();
    auto time3=duration_cast<microseconds>(end3-strt3);
    cout<<time3.count()<<endl;
    // cout<<"Using Strassen "<<endl;
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<outStra[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
}