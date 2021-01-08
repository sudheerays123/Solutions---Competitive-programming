#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 0x3f3f3f3f3f
 
ll dist(ll x1 , ll x2 , ll y1 , ll y2){
 
    ll x = (x1-x2)*(x1-x2);
    ll y = (y1-y2)*(y1-y2);
 
    return ( x+y );
}
 
int main() {
 
    fastio;
 
    ll n,m;
    ll a[1005][2];
    ll b[1005][2];
    ll dp[1005][1005][2];
 
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    for(ll i = 1; i <= m; i++) cin >> b[i][0] >> b[i][1];
 
    // OPTIMAL SUB-PROBLEM :
 
    // dp[i][j][0] = minimum energy needed with already first i h cows , first j g cows and going to the h cow
    // dp[i][j][1] = minimum energy needed with already first i h cows , first j g cows and going to the g cow
 
    // BASE CASE :
 
    for(ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }
 
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[1][0][0] = 0;
 
    
    // RECURSIVE RELATION :
 
    
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= m; j++){
 
            // dp[i][j][0] :
            if(i > 1) dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][0] + dist(a[i-1][0] , a[i][0] , a[i-1][1] , a[i][1]));
            if(i > 1 && j >= 1 ) dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][1] + dist(b[j-1][0] , a[i][0] , b[j-1][1] , a[i][1]));
 
            // dp[i][j][1] :
 
            if(j > 1 ) dp[i][j][1] = min(dp[i][j][1] , dp[i][j-1][0] + dist(a[j-1][0] , b[j][0] , a[j-1][1] , b[j][1]));
            if(j > 1 ) dp[i][j][1] = min(dp[i][j][1] , dp[i][j-1][1] + dist(b[j-1][0] , b[j][0] , b[j-1][1] , b[j][1]));
 
        }
    }
 
    // OPTIMAL SOLUTION :
 
 
    cout << dp[n-1][m-1][0];
 
    return 0;
}
