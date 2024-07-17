#include<iostream>

using namespace std;

// Selection Sort 
// Worst case time complexity: O(N^2);
// Best case time complexity: O(N^2);

void selectionSort(int arr[], int n)
{
    for(int i = 0;i<n-1;i++){
        int mini = INT16_MAX, index = -1;
        for(int j = i;j<n;j++){
            if(mini > arr[j]){
                mini = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

int main(){

    int n;
    cin>>n;
    int *arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
