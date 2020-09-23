#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
cout<<"Enter two numbers : ";
    string num1,num2;
    cin>>num1>>num2;

    int len1 = num1.length(); 
    int len2 = num2.length(); 

    string nump1 = num1.substr(0);
    string nump2 = num2.substr(0);
    
    if(len1==0||len2==0) {
        cout<<"INVALID"<<endl; 
        return 0;
        }

    char sign = '+';
    if((num1[0]=='-' || num2[0]=='-')&&(num1[0]!='-' || num2[0]!='-')) 
    sign = '-';
    
    if(num1[0]=='-' && num2[0]=='-'){
    num1=num1.substr(1);
    num2=num2.substr(1);
    }
    else if(num1[0]=='-' && num2[0]!='-'){
        num1=num1.substr(1);
    }
    else if(num1[0]!='-' && num2[0]=='-'){
        num2=num2.substr(1);
    }

    len1 = num1.length(); 
    len2 = num2.length(); 

    int d = 0,i=len1-1;
    while(i>=0 && num1[i]!='.'){
        i--; d++;
    }
    if(i==-1){d-=len1;}

    i =len2-1;
    while(i>=0 && num2[i]!='.'){
        i--; d++;
    }
    if(i==-1){d-=len2;}
    vector<int> arr(len1+len2,0);
    int a=0,b=0;


    for(int i=len1-1;i>=0;i--){
        if(num1[i]=='.') continue;
        int c = 0;
        b = 0;
        
        for(int j=len2-1;j>=0;j--){
            if(num2[j]=='.') continue;
            int x = ((num1[i]-'0')*(num2[j]-'0')+c+arr[a+b]);
            arr[a+b]=x%10;
            c = x/10;
            b++;
        }
        if(c) arr[a+b]+=c;
        a++;
    }

    int len = arr.size()-1;
    while(len>=0 && arr[len]==0) len--;
    if(len<0) {
        cout<<"ERROR!"<<endl;
        return 0;
    }
    if(sign=='-') cout<<sign;

    for(i = len;i>=d;i--) cout<<arr[i];
    cout<<'.';
    for(i=d-1;i>=0;i--) cout<<arr[i];
    cout<<endl;


}