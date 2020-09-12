#include <iostream>
using namespace std;

struct Pair{
    int min, max;
};
struct Pair findMinMax(int arr[],int low, int high){
   struct Pair comp,l,r;
    if(low==high){
        comp.max = arr[low];
        comp.min=arr[high];
        return comp;
    }

    if(high==low+1){
        if(arr[low]>arr[high]){
            comp.max=arr[low];
            comp.min=arr[high];
        }
        else{
            comp.max=arr[high];
            comp.min=arr[low];
        }
        return comp;
    }
    int mid = (low+high)/2;
    l = findMinMax(arr,low,mid);
    r = findMinMax(arr,mid+1,high);
    if(l.max>r.max)
    comp.max=l.max;
    else
    comp.max=r.max;
    if(l.min>r.min)
    comp.min=r.min;
    else
    comp.min=l.min;

    return comp;
    
}

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i =0;i<t;i++)
    cin>>arr[i];
    struct Pair pair =  findMinMax(arr,0,t-1);
    cout<<pair.max<<" "<<pair.min; 
}

