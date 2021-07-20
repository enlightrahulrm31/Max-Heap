#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
class MaxHeap{
    int cur;
    int arr[MAX];
public:
    MaxHeap(){
        cur = -1 ;
    }
    void push(int num);
    void MaintainOrderInserting(int index);   // function to maintain the order after inserting an element
    void MaintainOrderDeleting();             // function to maintain the order after deleting an element
    void pop();
    int top();
};
void MaxHeap::MaintainOrderInserting(int index){
       int par = (index-1)/2;                    // after inserting we are comparing it with ancesector and swaping if necessary
       while(arr[par]<arr[index]){
          swap(arr[index],arr[par]);
          index = par;
          par = (index-1)/2;
       }
}
void MaxHeap:: MaintainOrderDeleting(){
       int par = 0;                        // after deleting we are checking it with their childrens and the swaping
       int child1 = par*2+1;
       int child2 = par*2+2;
       if(child1>cur && child2>cur){
          return ;
        }
       while(arr[par]<max(arr[child1],arr[child2])){
            if(arr[child1]>=arr[child2]){
                swap(arr[child1],arr[par]);
                 par = child1;
                 child1 = par*2+1;
                 child2 = par*2+2;
                 if(child1>cur && child2>cur){
                    break;
                 }
            }
            else{
                swap(arr[child2],arr[par]);
                 par = child2;
                 child1 = par*2+1;
                 child2 = par*2+2;
                 if(child1>cur && child2>cur){
                    break;
                 }
            }
       }
}
void MaxHeap:: push(int num){
    cur++;
    arr[cur] = num;
    MaintainOrderInserting(cur);
}
int  MaxHeap:: top(){
    if(cur == -1){
        return -1;
    }
    else{
        return arr[0];
    }
}
void MaxHeap::pop(){
    arr[0] = arr[cur];
    cur--;
    MaintainOrderDeleting();
}
int main(){
    MaxHeap heap;
/*   sample operations on heap
    heap.push(1);
    heap.push(2);
    heap.push(4);
    heap.push(3);
    heap.pop();
    cout<<heap.top()<<"\n";
    heap.pop();
    cout<<heap.top()<<"\n";
    heap.pop();
    cout<<heap.top()<<"\n";          */
}

