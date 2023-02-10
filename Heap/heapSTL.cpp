#include<iostream>
#include<queue>
using namespace std;


int main(){

    priority_queue<int>pq;  // maxHeap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    pq.push(7);
    pq.push(5);
    pq.push(14);
    pq.push(3);
    pq.push(2);

    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    cout<<"Size: "<<pq.size()<<endl;
    if(!pq.empty()) cout<<"Not empty"<<endl;

    return 0;
}