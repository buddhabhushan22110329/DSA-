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
        swap(arr[curr], arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int size=n-1;
    while(size>0){
        swap(arr[0], arr[size]);
        size--;

        heapify(arr,size,0);
    }
}

int main(){

    // take array input & create a maxHeap from it (zero based indexing)
    int n=5;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Array before heapify: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i=n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }

    cout<<"Array after heapify: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);

    cout<<"Array after Sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}