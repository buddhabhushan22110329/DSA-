// heap is a data structure in form of a complete binaryTree
// maxHeap: node data is greater than its child nodes
// minHeap: node data is smaller than its child nodes

// we give indexing to nodes from left to right manner 
// if node is at ith index, then
// it's left child is present at 2*i th index   (for zero-based indexing: 2*i+1)
// it's right child is present at 2*i+1 th index
// it's parent at i/2 th index
// In complete Binary Tree: leaf nodes are present from index (n/2 + 1)th to nth index
//                                                         for zero-based indexing: n/2 to n-1

// Height of heap: (total nodes - leaf nodes)-1     (for zeroBased indexing)

// INSERTION IN MAX-HEAP: implement in form of array, insert val at end of the array, there should be nothing at 0th index

#include<iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    // cons
    heap(){
        arr[0] = -1;
        size = 0;
    }

    // insert function
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;       // inserting val at end of array

        // now put val at its correct position(parent data > childrens data in maxHeap)
        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[index], arr[parent]);
                index=parent;
            }
            else return;
        }
    }

    // print function
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    // delete fun: to delete root Node
    void deleteRoot(){  
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        // put last node val at first index
        arr[1] = arr[size];

        // remove last node val
        size--;

        // take new root node val to its correct position
        int i=1;
        while(i<size){
            int leftIndex= 2*i;
            int rightIndex= 2*i+1;

            if(leftIndex<size && arr[leftIndex] > arr[i]){
                swap(arr[i], arr[leftIndex]);
                i=leftIndex;
            }

            else if(rightIndex<size && arr[rightIndex] > arr[i]){
                swap(arr[i], arr[rightIndex]);
                i=rightIndex;
            }

            else return;
        }
    }
};

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteRoot();
    cout<<"After deletion: ";
    h.print();

    return 0;
}