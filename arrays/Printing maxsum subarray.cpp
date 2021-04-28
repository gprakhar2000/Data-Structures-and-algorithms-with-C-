
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubarraySum(int arr[], int n){
    vector<int> ans;
    int currsum=0;
    int maxsum=0;
    int start=0;
    int end=0;
    int mstart=-1;
    int mend=-1;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum>maxsum){
            maxsum=currsum;
            mstart=start;
            mend=end;
        }
        if(currsum<0){
            currsum=0;
            start=i+1;
        }
        end++;
    }
    for(int i=mstart;i<=mend;i++){
        ans.push_back(arr[i]);
    }
    return ans;
    
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> ans=maxSubarraySum(arr,n);
	for(int i=0;i<ans.size();i++){
	    cout<<ans[i]<<" ";
	}
}