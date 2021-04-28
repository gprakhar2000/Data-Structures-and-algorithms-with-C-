int maxSubarraySum(int arr[], int n){
    int currsum=arr[0];
    int maxsum=arr[0];
    for(int i=1;i<n;i++){
        currsum+=arr[i];
        currsum=max(currsum,arr[i]);
        if(currsum>maxsum){
            maxsum=currsum;
        }
    }
    return maxsum;
    
    
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxSubarraySum(arr,n);
}