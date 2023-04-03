#include<bits/stdc++.h>
using namespace std;

int BinIterative(int n){
    int result = 0;
    int i = 1;
    while(n>0){
        result += (n%2)*i;
        n /= 2;
        i *= 10;
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    cout<<BinIterative(n)<<endl;
    return 0;
}