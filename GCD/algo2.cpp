#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int result = 1;
    for (int i = 2; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            result = i;
            while (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            }
        }
    }
    return result;
}
int main(){
    int a,b;
    cin>>a>>b;

    cout<<gcd(a, b)<<endl;
}