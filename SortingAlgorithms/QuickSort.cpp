#include<iostream>
#include<algorithm>

using namespace std;

int partition (int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while(i < j){
        while(arr[i] <= pivot && i< high){
            i++;
        }
            
        while(arr[j] > pivot && j>low){
            j--;
        }
            
        if(i<=j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int partition_indx = partition(arr,low,high);
        quickSort(arr,low, partition_indx-1);
        quickSort(arr,partition_indx + 1, high);
    }
}

int main(){

    int n;
    cin>>n;
    int *arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
