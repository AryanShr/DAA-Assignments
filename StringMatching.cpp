#include<bits/stdc++.h>
using namespace std;

int stringMatching(string s, string p){
    int n = s.length();
    int m = p.length();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(s[i+j]!=p[j]){
                break;
            }
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}

int main(){
    string s, p;
    cin>>s>>p;
    cout<<stringMatching(s, p)<<endl;
    return 0;
}