//scan and swap to strings
#include<iostream>
#include<string.h>
using namespace std;



int main(){
string s1;
string s2;
string temp;
cout<<"Enter string1: ";
getline(cin,s1);
cout<<"Enter string2: ";
getline(cin,s2);

cout<<"S1 is: "<<s1<<endl;
cout<<"S2 is: "<<s2<<endl<<endl;

temp = s1;
s1 = s2;
s2 = temp;

cout<<"S1 is: "<<s1<<endl;
cout<<"S2 is: "<<s2<<endl;

    return 0;
}