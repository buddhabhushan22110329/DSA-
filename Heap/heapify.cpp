// an array is given, convert it into maxHeap
// for zero based indexing: leftIndex of ele-> 2*i+1
//                          rightIndex of ele-> 2*i+2   
// leaf nodes are already heap So we will not iterate on them
// Zero based indexing: leaf nodes are from n/2 to n-1 th index in compBinaryTree 
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int curr){

    int largest = curr;
    int leftIndex = 2*curr+1;
    int rightIndex = 2*curr+2;

    if(leftIndex<n && arr[leftIndex] > arr[largest]){
        largest=leftIndex;
    }

    if(rightIndex<n && arr[rightIndex] > arr[largest]){
        largest=rightIndex;
    }

    if(largest!=curr){
        swap(arr[largest], arr[curr]);
        heapify(arr,n,largest);         // to look more possible place
    }
}

int main(){

    int n=5;
    int arr[n] = {57,50,58,54,53};

    cout<<"Array before heapify is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }

    // printing 
    cout<<"Array after heapify is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}