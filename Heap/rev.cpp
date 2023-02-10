#include<iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    // cons
    heap(){
        arr[0] = -1;
        size=0;
    }

    // insert function-> insert @ last index & then put it at its correct place
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        // put inserted ele @ its correct position using parent
        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }
            else return;
        }
    }

    // delete root node-> put last ele at root index, remove last ele(size--)
    // put new root ele @ its correct place

    void deleteRoot(){
        arr[1] = arr[size];
        size--;

        // put new root ele @ its correct place

        int curr=1;
        
        while(curr < size){
            
            int leftIndex = 2*curr+1;
            int rightIndex = 2*curr+2;

            if(leftIndex < size && arr[leftIndex] > arr[curr]){
                swap(arr[curr], arr[leftIndex]);
                curr = leftIndex;
            }

            if(rightIndex<size && arr[rightIndex] > arr[curr]){
                swap(arr[curr], arr[rightIndex]);
                curr = rightIndex;
            }
            else return;
        }
    }

    // print fun
    void print(){
        for(int i=1; i<size+1; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){

    heap h;
    h.insert(14);
    h.insert(47);
    h.insert(10);
    h.insert(58);
    h.insert(50);
    h.insert(54);

    cout<<"heap before deletion: ";h.print();

    h.deleteRoot();
    cout<<"heap after deletion: ";h.print();

    return 0;
}