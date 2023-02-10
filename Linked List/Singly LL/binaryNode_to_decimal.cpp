#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v){

    int size= v.size();
    int ans=0, index=1;

    for(int i=size-1; i>=0; i--){
        if(v[i] == 1){
            ans = ans + index;
        }
        index *= 2;
    }
    return ans;
}

int digitSum(int n){
        
        int sum=0;
        while(n!=0){
            int lastDigit = n%10;
            sum += lastDigit;
            n = n/10;
        }
        return sum;
    }

int main(){

    vector<int> v = {1,1,0};

    // cout<< solve(v);
    // cout<<digitSum(28);

    int cnt=0;
        for(int i=1; i<=10; i++){
            
            int dSum = digitSum(i);
            if(dSum % 2 == 0) cnt++; 
        }
        cout<< cnt;

    return 0;
}