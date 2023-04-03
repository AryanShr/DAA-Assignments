#include<bits/stdc++.h>
#include <iostream>
#include<chrono>
#include<fstream>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= m) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[l + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void merge4(vector<int>&arr, int left, int m1,int m2,int m3, int r){
    int n1 = m1-left+1;
    int n2 = m2-m1;
    int n3 = m3-m2;
    int n4 = r-m3;

    int L[n1],M[n2],O[n3],P[n4];

    vector<int> temp;

    for(int i = 0;i<n1;i++){
        L[i] = arr[left+i];
    }
    for(int i = 0;i<n2;i++){
        M[i] = arr[m1+1+i];
    }
    for(int i = 0;i<n3;i++){
        O[i] = arr[m2+1+i];
    }
    for(int i = 0;i<n4;i++){
        P[i] = arr[m3+1+i];
    }

    int i = 0, j= 0 ,k = 0, l = 0;

    while(i<n1 && j<n2 && k< n3 && l< n4){
        if(L[i]<= M[j] && L[i]<= O[k] && L[i]<= P[l]){
            temp.push_back(L[i]);
            i++;
        }
        else if(M[j]<= L[i] && M[j]<= O[k] && M[j]<= P[l]){
            temp.push_back(M[j]);
            j++;
        }
        else if(O[k]<= M[j] && O[k]<= L[i] && O[k]<= P[l]){
            temp.push_back(O[k]);
            k++;
        }
        else if(P[l]<= M[j] && P[l]<= O[k] && P[l]<=L[i]){
            temp.push_back(P[l]);
            l++;
        }
    }

    while(i<n1 && j<n2 && k<n3){
        if(L[i]<=M[j] && L[i]<=O[k]){
            temp.push_back(L[i]);
            i++;
        }
        else if(M[j]<=L[i] && M[j]<=O[k]){
            temp.push_back(M[j]);
            j++;
        }
        else{
            temp.push_back(O[k]);
            k++;
        }
    }
    while(i<n1 && j<n2 && l<n4){
        if(L[i]<=M[j] && L[i]<=P[l]){
            temp.push_back(L[i]);
            i++;
        }
        else if(M[j]<=L[i] && M[j]<=P[l]){
            temp.push_back(M[j]);
            j++;
        }else{
            temp.push_back(P[l]);
            l++;
        }
    }

    while(i<n1 && k<n3 && l<n4){
        if(L[i]<=O[k] && L[i]<=P[l]){
            temp.push_back(L[i]);
            i++;
        }
        else if(O[k]<=L[i] && O[k]<=P[l]){
            temp.push_back(O[k]);
            k++;
        }else{
            temp.push_back(P[l]);
            l++;
        }
    }
    

    while(j<n2 && k<n3 && l<n4){
        if(M[j]<=O[k] && M[j]<=P[l]){
            temp.push_back(M[j]);
            j++;
        }
        else if(O[k]<=M[j] && O[k]<=P[l]){
            temp.push_back(O[k]);
            k++;
        }else{
            temp.push_back(P[l]);
            l++;
        }
    }

    while(i<n1 && j<n2){
        if (L[i] <= M[j]) {
            temp.push_back(L[i]);
            i++;
        }
        else {
            temp.push_back(M[j]);
            j++;
        }
    }
    while(i<n1 && k<n3){
        if (L[i] <= O[k]) {
            temp.push_back(L[i]);
            i++;
        }
        else {
            temp.push_back(O[k]);
            k++;
        }
    }
    while(i<n1 && l<n4){
        if (L[i] <= P[l]) {
            temp.push_back(L[i]);
            i++;
        }
        else {
            temp.push_back(P[l]);
            l++;
        }
    }
    while(j<n2 && k<n3){
        if (M[j] <= O[k]) {
            temp.push_back(M[j]);
            j++;
        }
        else {
            temp.push_back(O[k]);
            k++;
        }
    }
    while(j<n2 && l<n4){
        if (M[j] <= P[l]) {
            temp.push_back(O[j]);
            j++;
        }
        else {
            temp.push_back(P[l]);
            l++;
        }
    }
    while(k<n3 && l<n4){
        if (O[k] <= P[l]) {
            temp.push_back(O[k]);
            k++;
        }
        else {
            temp.push_back(P[l]);
            l++;
        }
    }
    while(i<n1){
        temp.push_back(L[i]);
        i++;
    }
    while(j<n2){
        temp.push_back(M[j]);
        j++;
    }
    while(k<n3){
        temp.push_back(O[k]);
        k++;
    }
    while(l<n4){
        temp.push_back(P[l]);
        l++;
    }

    for(int i = 0 ;i<temp.size();i++){
        arr[i] = temp[i];
    }
}

void mergeSort4(vector<int>&arr,int l,int r){
    if(l<r){
        int m1 = l + (r-l)/ 4;
        int m2 = l + (r-l)/ 2;
        int m3 = l + 3*(r-l)/ 4;
        mergeSort4(arr, l, m1);
        mergeSort4(arr, m1+1, m2);
        mergeSort4(arr, m2+1, m3);
        mergeSort4(arr, m3+1,r);

        merge4(arr,l,m1,m2,m3,r);
    }
}


int main(){
    ifstream fin("test_case.txt");
    if(!fin.is_open()){
        cerr<<"Error opening the input file"<<endl;
        return 1;
    }
    ofstream fout("running_time.txt");
    if(!fout.is_open()){
        cerr<<"Error opening the output file"<<endl;
        return 1;
    }
    ofstream fout2("running_time_mergeSort4.txt");
    if(!fout.is_open()){
        cerr<<"Error opening the output file"<<endl;
        return 1;
    }

    string line;
    while(getline(fin,line)){
        if(!line.empty()){
            vector<int> arr;
            int val;
            istringstream iss(line);
            while(iss>>line){
                arr.push_back(val);
            }
            auto start = chrono::high_resolution_clock::now();
            mergeSort(arr,0,arr.size()-1);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
            fout<<arr.size()<<" "<<duration.count()<<endl;

            start = chrono::high_resolution_clock::now();
            mergeSort4(arr,0,arr.size()-1);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::microseconds>(end-start);
            fout2<<arr.size()<<" "<<duration.count()<<endl;
        }
    }
        fin.close();
        fout.close();
        fout2.close();
        FILE *gp = popen("gnuplot -persistent","w");
        if(gp == NULL){
            cerr<<"Error Opening GNU Plot"<<endl;
            return 1;
        }
        fprintf(gp, "set xlabel 'Input size'\n");
        fprintf(gp, "set ylabel 'Running time (microseconds)'\n");
        fprintf(gp, "plot 'running_time.txt' using 1:2 with lines title 'MergeSort2', 'running_time_mergeSort4.txt' using 1:2 with lines title 'MergeSort4'\n");
        pclose(gp);
        return 0;
}