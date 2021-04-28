#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int size){
    int min_index;
    for(int i=0;i<size-1;i++){
        min_index=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(&arr[i],&arr[min_index]);
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}


int main()
{
    int arr[]={25,12,13,1,5,71,18};
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionsort(arr,n);
    cout<<"Sorted array is:"<<endl;
    printArray(arr,n);
    return 0;
}