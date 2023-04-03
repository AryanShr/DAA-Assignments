#include<bits/stdc++.h>
using namespace std;

int BinRec(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n%2 + 10*BinRec(n/2));
    }
}

int main(){
    int n;
    cin>>n;
    cout<<BinRec(n)<<endl;
    return 0;
}