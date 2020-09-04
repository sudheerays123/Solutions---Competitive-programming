#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

int main() {

    ll test;
    cin >> test;

    while(test--){

        ll n,a,b,d,f;

        cin >> n >> a;
        cout << (2*(ll)pow(10,n))+a << "\n" << flush;
        cin >> b;
        cout <<((ll)pow(10,n))-b << "\n" << flush;
        cin >> d;
        cout <<((ll)pow(10,n)) - d << "\n" << flush;
        cin >> f;
        if(f == 1) continue;
        else return 0;
    }

    return 0;
}
