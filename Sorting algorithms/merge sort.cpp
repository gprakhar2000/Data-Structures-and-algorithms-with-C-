#include <iostream>

using namespace std;


void merge(int arr[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for(i=0;i<n1;i++){
        L[i] = arr[l + i];
    }
        
    for(j=0;j<n2;j++){
        R[j]=arr[m + 1 + j];
    }
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        
        merge(arr,l,m,r);
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
    mergesort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}
