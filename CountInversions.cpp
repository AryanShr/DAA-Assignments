#include<bits/stdc++.h>
using namespace std;
#include<chrono>
//Count Inversions Brute Force
int countInversions(vector<int>&arr){
    int n = arr.size();
    int countInv = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                countInv++;
            }
        }
    }
    return countInv;
}


//using merge sort

int merge(vector<int>&arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int countInv = 0;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
            countInv += m-l-i+1;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return countInv;
}

int mergeSortCountInv(vector<int>&arr, int l, int r){
    int countInv = 0;
    if(l<r){
        int m = l+(r-l)/2;
        countInv += mergeSortCountInv(arr, l, m);
        countInv += mergeSortCountInv(arr, m+1, r);
        countInv += merge(arr, l, m, r);
    }
    return countInv;
}

int main(){
    vector<int> arr = {1,3,5,2,4,6};
    auto start = chrono::high_resolution_clock::now();
    cout<<countInversions(arr)<<endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<endl<<duration.count()<<"ms"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    start = chrono::high_resolution_clock::now();
    cout<<mergeSortCountInv(arr, 0, arr.size()-1)<<endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<endl<<duration.count()<<"ms"<<endl;

    return 0;
}