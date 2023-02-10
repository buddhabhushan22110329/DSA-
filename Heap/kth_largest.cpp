// for Kth largest: use minHeap
#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int> >minHeap;

    int n=6;
    int arr[n] = {7,15,10,8,5,6};
    int k=4;   

    // aproach1: love Babbar sir
    // store first K elements in minHeap
    // check rest of ele, if(ele > minHeap.top()) then-> pop & push

    /*
    for(int i=0; i<k; i++){
        minHeap.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    cout<<k<<"th largest element is: "<<minHeap.top()<<endl;
    */

    // approach2: aditya verma
    // same as of kth smallest ele

    for(int i=0; i<n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k) minHeap.pop();
    }

    cout<<k<<"th largest element is: "<<minHeap.top()<<endl;    

    return 0;
}