#include <iostream>

using namespace std;

int partition(int arr[],int l,int h){
    int i=l;
    int j=h;
    int pivot=arr[l];
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void quicksort(int arr[],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quicksort(arr,l,p);
        quicksort(arr,p+1,h);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[]={25,12,5,3,1,8,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}