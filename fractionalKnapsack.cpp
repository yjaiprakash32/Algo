#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int , int> p1 , pair <int , int> p2){
    double a1 = (double) p1.first/p1.second;
    double a2 = (double) p2.first/p2.second;
    return a1>a2;
}

double fractionalKnapsack(int W, vector<pair<int , int>> v){
sort(v.begin(),v.end(),cmp);
int currWieght = 0;
double value = 0.0;
for(int i =0;i<v.size();i++){
    if(currWieght+v[i].second<=W){
        currWieght += v[i].second;
        value += v[i].first;
    }
    else{
        int remain = W - currWieght;
        value += v[i].first * ((double)remain/v[i].second);
        break;
    }
}
return value;
}

int main(){
    cout<<"Enter number of objects and max weight"<<endl;
    int nm,W;
    cin>>nm>>W;
    vector <pair<int, int>> vec;
    pair<int , int> p;
    cout<<"Enter the price followed by weight of each object"<<endl;
    for(int i =0;i<nm;i++){
    cin>>p.first>>p.second;
    vec.push_back(p);
    }
    cout<<fractionalKnapsack(W,vec);

}