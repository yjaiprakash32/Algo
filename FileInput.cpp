#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
    string name;
    cin>>name;
    ifstream infile;
    infile.open(name);
    stringstream strStream;
    strStream << infile.rdbuf();
    string str = strStream.str();
    cout<<str;
}