#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<float.h>
using namespace std;

double dist(double x,double y,double x1,double y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

double bruteForce(vector<pair<double,double>> v,int n){
    double mini = DBL_MAX;
    for(int i = 0;i<n;++i){
        for(int j = i+1 ;j<n;++j){
            if(dist(v[i].first,v[i].second,v[j].first,v[j].second)<mini);
            mini = dist(v[i].first,v[i].second,v[j].first,v[j].second);
        }
    }
    return mini;
}
bool sortbysec(const pair<double,double> &a, const pair<double,double> &b) { 
    return (a.second < b.second); 
} 

double strip(vector<pair<double,double>> v, double dis){
    double minm = dis;
    sort(v.begin(),v.end(),sortbysec);
    for(int i =0;i<v.size();++i){
        for(int j = i+1;j<v.size() && (v[i].second-v[j].second<minm);++j){
            if(dist(v[i].first,v[i].second,v[j].first,v[j].second)<minm);
            minm = dist(v[i].first,v[i].second,v[j].first,v[j].second);
        }
    }
    return minm;
}

float closest(vector<pair<double,double>> v,int n){
    if(n<=5)
    return bruteForce(v,n);
    
    int mid = n/2;
    vector<pair<double,double>> v2 = v[mid][mid];
    double distleft = closest(v,mid);
    
    double distright = closest(v.begin()+mid,n-mid);


}

int main(){
    return 0;
}