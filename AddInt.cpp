#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string num1, num2;
    cout<<"Enter two integers: ";
    cin>>num1>>num2;
    int len1 = num1.length(), len2 = num2.length();
    if(len1>len2) {
        swap(num1,num2);
        swap(len1,len2);
    }

    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    string ans = "";
    int c = 0;

    for(int i=0;i<len1;i++){
        int temp_sum = ((num1[i]-'0')+(num2[i]-'0')+c);
        ans.push_back(temp_sum%10+'0');
        c = temp_sum/10;
    }
    for(int i = len1;i<len2;i++){
        int temp_sum = ((num2[i]-'0') + c);
        ans.push_back(temp_sum%10+'0');
        c = temp_sum/10;
    }
    if(c) ans.push_back(c+'0');

    reverse(ans.begin(), ans.end());

    cout<<ans<<endl;
}