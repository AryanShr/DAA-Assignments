#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum and minimum element in an array using Divide and Conquer

pair<int,int> MaxMin(vector<int>&arr){
    if(arr.size()==2) return make_pair(max(arr[0], arr[1]), min(arr[0], arr[1]));
    else{
        //Divide arr into two parts
        vector<int>arr1(arr.begin(), arr.begin()+arr.size()/2);
        vector<int>arr2(arr.begin()+arr.size()/2, arr.end());
        pair<int,int>maxmin1 = MaxMin(arr1);
        pair<int,int>maxmin2 = MaxMin(arr2);
        return make_pair(max(maxmin1.first, maxmin2.first), min(maxmin1.second, maxmin2.second));
    }
}

pair<int,int> MaxMinUni(vector<int>&arr, int start, int end){
    if(start==end) return make_pair(arr[start], arr[start]);
    else if(start==end-1) return make_pair(max(arr[start], arr[end]), min(arr[start], arr[end]));
    else{
        //Divide arr into two parts
        int mid = (start+end)/2;
        pair<int,int>maxmin1 = MaxMinUni(arr, start, mid);
        pair<int,int>maxmin2 = MaxMinUni(arr, mid+1, end);
        return make_pair(max(maxmin1.first, maxmin2.first), min(maxmin1.second, maxmin2.second));
    }
}




int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    pair<int,int>maxmin = MaxMinUni(arr,0,n-1);
    cout<<"Max: "<<maxmin.first<<endl;
    cout<<"Min: "<<maxmin.second<<endl;
    return 0;
}