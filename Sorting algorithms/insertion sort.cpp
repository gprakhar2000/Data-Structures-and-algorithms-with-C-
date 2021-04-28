#include <iostream>

using namespace std;
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[]={2,8,4,3,10,11,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    printarray(arr,n);
    return 0;
}