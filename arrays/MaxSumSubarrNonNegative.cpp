#include <vector>
#include<bits/stdc++.h>
vector<int> maxset(int *a, int size)
{
  
    vector<int> ans;
    int currsum=0;
    int maxsum=INT_MIN;
    int start=0;int mstart=-1;
    int end=0;int mend=-1;
    for(int i=0;i<size;i++){
        if(a[i]>0){
            currsum+=a[i];
            if(currsum>maxsum || (currsum==maxsum && mend-mstart < end-start)){
                maxsum=currsum;
                mstart=start;mend=end;
            }
        }
        else{
            currsum=0;
            start=i+1;
        }
        end++;
    }
    if(mstart==-1){
        ans.push_back(-1);
        return ans;
    }
    for(int i=mstart;i<=mend;i++){
        ans.push_back(a[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
	cin>>arr[i];
    }
    vector<int>ans=maxset(arr,n);
    for(int i=0;i<ans.size();i++){
	cout<<ans[i]<<" ";
    }
    return 0;

}