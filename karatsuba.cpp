#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

string add(string s1,string s2){
    if(s1.length()>s2.length())
    swap(s1,s2);

    string res="";
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int c=0;
    for(int i =0;i<s1.length();++i){
        int sum = (s1[i]-'0')+(s2[i]-'0')+c;
        res.push_back(sum%10+'0');
        c=sum/10;
    }
    for(int i = s1.length();i<s2.length();i++){
        int sum = (s2[i]-'0')+c;
        res.push_back(sum%10+'0');
        c=sum/10;
    }
    if(c!=0)
    res.push_back(c+'0');

    reverse(res.begin(),res.end());
    return res;
}

long long karatsuba(string s1, string s2){
    int len = max(s1.length(),s2.length());
    if(len==0)
    return 0;
    if(len==1)    
    return (s1[0]-'0')*(s2[0]-'0');

    string subs11 = s1.substr(0,len/2);
    string subs12 = s1.substr(len/2,len - len/2);
    string subs21 = s2.substr(0,len/2);
    string subs22 = s2.substr(len/2,len-len/2);

    long long p1= karatsuba(subs11,subs21);
    long long p2= karatsuba(subs12,subs22);
    long long p3= karatsuba(add(subs11,subs12),add(subs21,subs22));

    return p1*(pow(10,len))+(p3-p2-p1)*pow(10,len/2)+p2;

}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    cout<<karatsuba(str1,str2);
}