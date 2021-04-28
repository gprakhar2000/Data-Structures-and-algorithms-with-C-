#include <iostream>

using namespace std;
void bubblesort(int arr[],int n){
    if(n==1)
    	return;

    bool swapped=false;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
            swapped=true;
    }
    if(swapped=false)
    	return;
    bubblesort(arr,n-1);
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={2,17,4,6,4,20,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    printArray(arr,n);
    return 0;
}
