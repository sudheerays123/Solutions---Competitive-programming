#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main() {

    fastio;

    ll n,m,q,a,b,c,d;
    vector<vector<ll>> grid(1005, vector<ll>(1005));
    
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1 ; j <= m; j++){
            cin >> grid[i][j];
            grid[i][j] = grid[i-1][j] + grid[i][j-1] + grid[i][j] - grid[i-1][j-1];
        }
    }
    cin >> q;
    for(ll qu = 0 ; qu < q; qu++){
        cin >> a >> b >> c >> d;
        cout << grid[c][d] - grid[a-1][d] - grid[c][b-1] + grid[a-1][b-1] << "\n";
    }

    return 0;
}
