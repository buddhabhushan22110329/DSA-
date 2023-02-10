#include<iostream>
using namespace std;

int Guess(int entered_value){
int max=100;
int min=1;
int guess= (max+min)/2;

string isTrue;
string low="lower";
string high="higher";
string correct="correct";

do{
    cout<<"I guess You've picked: "<<guess<<endl;
    cout<<"Tell me how's ur number (higher or lower or correct)?:  ";
    getline(cin,isTrue);

    if(isTrue=="lower") max=guess;
    else if(isTrue=="higher") min=guess;
    // else if(isTrue=="correct") cout<<"Yes! You've picked: "<<guess<<endl;

    //updating guess
    guess=(max+min)/2;

}while(isTrue!="correct");
cout<<"Yes! You've picked: "<<guess<<endl;

}

int main(){
int entered_value;
cout<<"Enter a value between 1-100: ";
cin>>entered_value;

int ans=
// cout<<"You entered: "<<ans<<endl;
Guess(entered_value);

    return 0;
}