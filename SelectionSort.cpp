#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&arr, int n){
    for(int i=0; i<=n-2; i++){
        int min = i;
        for(int j=i+1; j<=n-1; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    SelectionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}