// return K largest elements of array in any order
#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int> >minHeap;

    int n=6;
    int arr[n] = {7,15,10,8,5,6};
    int k=4;

    // approach1: love babbar
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

    // now minHeap has K largest element
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    */

    // approach2: aditya verma
    for(int i=0; i<n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k) minHeap.pop();
    }

    // now minHeap has K largest element
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }        

    return 0;
}