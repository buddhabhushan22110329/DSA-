// store first k elements of array in maxHeap
// compare rest elements of array with maxHeap.top()
// if ele < maxHeap.top() --> maxHeap.pop(); 
//                            maxHeap.push(ele);
// at the end, k small elements of array will be in maxHeap (i.e maxHeap.size()=k)
// and max of them is our answer (i.e maxHeap.top())
#include<iostream>
#include<queue>
using namespace std;


int main(){

    priority_queue<int>maxHeap;

    int n=6;
    int arr[n] = {7,15,10,8,5,6};
    int k=4;                        // 4th smallest ele is 8

    /*
    for(int i=0; i<k; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    cout<<k<<"th smallest element is: "<<maxHeap.top()<<endl;
    */

    // another approach: aditya verma
    // traverse all array elements 
    // after pushing array element if maxHeap.size() > k, then pop from maxHeap

    for(int i=0; i<n; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) maxHeap.pop();
    }

    cout<<k<<"th smallest element is: "<<maxHeap.top()<<endl;

    return 0;

}