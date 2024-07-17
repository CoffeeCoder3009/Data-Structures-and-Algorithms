#include<iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    // Worst and average case time complexity -> O(n^2)
    // Best case time complexity -> O(n) 
    for(int i = 0;i<n;i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){

    int n;
    cin>>n;
    int *arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
