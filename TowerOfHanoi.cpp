#include<bits/stdc++.h>

using namespace std;


void Hanoi(int n, char A, char B, char C){
    if(n==1){
        cout<<"Move disk 1 from rod "<<A<<" to rod "<<C<<endl;
    }
    else{
        Hanoi(n-1, A, C, B);
        cout<<"Move disk "<<n<<" from rod "<<A<<" to rod "<<C<<endl;
        Hanoi(n-1, B, A, C);
    }
}

int main(){
    int n;
    cin>>n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}