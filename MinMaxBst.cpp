#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int d;
    struct node* right=NULL;
    struct node* left=NULL;
};
struct node *h1,*h2;

int ctr = 0;

struct node* maxheight(int a[],int n){
    if(ctr>n-1) return NULL;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->d = a[ctr];
    ctr++;
    newNode->right = maxheight(a,n);
    newNode->left = NULL;
    return newNode;

}

struct node* minheight(int a[],int l,int r){
    if(l>r) 
    return NULL;
    
    int mid = (r+l)/2;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->d = a[mid];
    newNode->left = minheight(a,l,mid-1);
    newNode->right = minheight(a,mid+1,r);
    return newNode;
}



void print(struct node* N){
    if(N!=NULL){
        print(N->left);
        print(N->right);
        cout<<N->d<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
    cin>>a[i];

    sort(a,a+n);

    h1 = maxheight(a,n);
    cout<<"maxHeight tree post-order : "<<endl;
    print(h1);
    cout<<endl;

    h2 = minheight(a,0,n-1);
    cout<<"minHeight tree post-order : "<<endl;
    print(h2);
}