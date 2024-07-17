#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class heap{
    public:
    vector<int>arr;
    int size = 0;
   
   //INSERTION IN A HEAP(MAX HEAP)
    void insert(int x){
        arr.push_back(x);
        int index = size;
        size +=1;
        while(index > 0){
            int parent = (index-1)/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
              return;
            }
        }
    }  
    void delete_from_heap(){
        if(size == 0) return;
        arr[0] = arr[size-1];
        size--;
        int index = 0;
        while(index < size){
            int parent = (index-1)/2;
            int leftchild = 2*index + 1;
            int rightchild = 2*index + 2;

            if(leftchild < size && arr[parent]<arr[leftchild]){
                swap(arr[parent],arr[leftchild]);
                index = leftchild;
            }
            if(rightchild < size && arr[parent]<arr[rightchild]){
                swap(arr[parent],arr[rightchild]);
                index = rightchild;
            }
            else return;
        }
    }

  
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};


void heapify(vector<int>&arr,int size,int i){
    int largest = i;
    int leftchild = 2*i + 1;
    int rightchild = 2*i + 2;

    if(leftchild < size && arr[largest] < arr[leftchild]){
        largest = leftchild;
    }
    if(rightchild < size && arr[largest] < arr[rightchild]){
        largest = rightchild;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

void heapsort(vector<int>&arr, int size){
    //step1: swap 1st and last element
    //step2: heapify 1st element
    // (n/2 + 1) to n are leaf nodes
    int t = size;
    while(t>0){
        swap(arr[t-1],arr[0]);
        t--;

        heapify(arr,t,0);
    }
    //complexity -> O(nlogn)
}

int main(){
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(70);
    h.print();
    h.delete_from_heap();
    cout<<endl;
    h.print();cout<<endl;

    // heap creation
    vector<int>arr = {10,20,70,50,40};
    for(int i = arr.size()/2 + 1;i>=0;i--){
        heapify(arr,arr.size(),i);
    }
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heapsort
    heapsort(arr,arr.size());
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}
