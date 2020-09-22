#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
long long karatsuba(long long x , long long y){
  if(x<10||y<10)
  return x*y;
  int len = max(to_string(x).length(),to_string(y).length());
  int m = ceil(len/2);
  long long xh=floor(x/pow(10,m));
  long long xl=x%int(pow(10,m));
  long long yh=floor(y/pow(10,m));
  long long yl=y%int(pow(10,m));
  long long p1 = karatsuba(xh,yh);
  long long p2 = karatsuba(xl,yl);
  long long pr =karatsuba(xh+xl,yh+yl)-p1-p2;
  return int(p1*(pow(10,len))+(pr)*(pow(10,m))+p2);

}

int main(){
    long long x,y;
    cin>>x>>y;
    cout<<karatsuba(x,y)<<endl;
}