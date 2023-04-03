#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>&arr, int n){
    for(int i=0; i<=n-2; i++){
        for(int j=0; j<=n-2-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    BubbleSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}