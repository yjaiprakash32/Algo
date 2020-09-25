#include <iostream>
using namespace std;

int maxCrossSum(int arr[], int left , int mid, int right){
    int leftSum = INT32_MIN;
    int rightSum = INT32_MIN;
    int sum = 0;
    for(int i = mid ; i >left-1;i--){
        sum+=arr[i];
        if(sum>leftSum)
        leftSum= sum;
    }
    int sumr = 0;
    for(int i = mid+1 ; i <right+1;i++){
        sumr+=arr[i];
        if(sumr>rightSum)
        rightSum= sumr;
    }

    return max(max(rightSum+leftSum,rightSum),leftSum);
}


int maxSum(int arr[],int left, int right){
    if(left == right)
    return arr[left];

    int mid = (left+right)/2;
    return(max(max(maxSum(arr,left,mid),maxSum(arr,mid+1,right)),maxCrossSum(arr,left,mid,right)));
}

int main(){
    int len;
    cout<<"Enter length of Array: ";
    cin>>len;
    int arr[len];
    cout<<"Enter the values: ";
    for(int i =0;i<len;i++)
    cin>>arr[i];

    cout<<maxSum(arr,0,len-1)<<endl;
}