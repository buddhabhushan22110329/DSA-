#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute force-> O(n^2 logn)
void solve(int arr[], int n, vector<int> &ans){

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            ans.push_back(sum);
        }
    }
}

// optimised using minHeap-> O(n^2 logK)
int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>, greater<int> >minH;
        int sum=0;
        
        for(int i=0; i<N; i++){
            sum=0;
            for(int j=i; j<N; j++){
                sum += Arr[j];
                minH.push(sum);
                
                if(minH.size() > K){
                    minH.pop();
                }
            }
        }
        
        return minH.top();
    }

int main(){

    int n=5;
    int arr[n] = {1,2,3,4,5};
    vector<int>ans;     // store all subArrays sum in vector

    solve(arr,n,ans);
    sort(ans.begin(), ans.end());

    for(auto &i:ans){
        cout<<i<<" ";
    }cout<<endl;

    int k;
    cout<<"Enter k: "; cin>>k;

    cout<<k<<" th largest subarray sum is: "<<ans[ans.size()-k]<<endl;

    return 0;
}