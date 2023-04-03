#include<bits/stdc++.h>
using namespace std;
#include <chrono>
//Multiplication by divide and conquer

long long multiply(vector<int>&x, vector<int>&y){
    int n = x.size();
    if(n==1){
        return x[0]*y[0];
    }
    int m = n/2;
    vector<int> a(x.begin(), x.begin()+m);
    vector<int> b(x.begin()+m, x.end());
    vector<int> c(y.begin(), y.begin()+m);
    vector<int> d(y.begin()+m, y.end());
    int ac = multiply(a,c);
    int ad = multiply(a,d);
    int bc = multiply(b,c);
    int bd = multiply(b,d);
    
    return ac*pow(10,n) + (ad+bc)*pow(10,m) + bd;
}

int main(){
    vector<int> x = {1,2,3,4,5,6,7,8};
    vector<int> y = {5,6,7,8,9,0,1,2};
    auto start = chrono::high_resolution_clock::now();
    cout<<multiply(x,y)<<endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<endl<<duration.count()<<"ms"<<endl;
    return 0;
}

