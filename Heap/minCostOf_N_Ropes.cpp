// cost req to connect two ropes is sum of their length
// i.e we've to get two smallest elements from array at that instant
#include<iostream>
#include<queue>
using namespace std;


int main(){

    int n=4;
    int arr[n] = {4,3,2,6};     // ans will be 29

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<n; i++){
        minHeap.push(arr[i]);
    }

    int ans=0;

    while(minHeap.size()>1){
        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        int sum = a+b;
        ans += sum;
        minHeap.push(sum);
    }

    cout<<"Min cost req is: "<<ans<<endl;

    return 0;
}