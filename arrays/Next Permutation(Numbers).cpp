#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(vector<int> &a,int l,int r){
    while(l<r){
        swap(&a[l++],&a[r--]);
    }
}
vector<int> nextPermutation(int N, vector<int> arr){
        // code here
    int i=N-2;
    while(i>=0 && arr[i]>=arr[i+1]){
        i--;
    }
    int k;
    if(i<0){
        return arr;
    }
    
    else{
        for(k=N-1;k>i;k--){
            if(arr[k]>arr[i]){
                break;
            }
        }
    }
    swap(arr[i],arr[k]);
    reverse(arr,i+1,N-1);
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    vector<int> ans=nextPermutation(n,arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}