#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {

    fastio;

    ll n , total = 1,x,y;
    vector<vector<ll>> a(100005 , vector<ll>(2));

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> x >> y;
        a[i][1] = x;
        a[i][0] = x+y;
    }

    sort(a.begin() , a.begin()+n);

    ll u = a[0][0];

    for(ll i = 1; i < n; i++){
        if(a[i][1] > u){
            u = a[i][0];
            total++;
        }
    }

    cout << total;

    return 0;
}
