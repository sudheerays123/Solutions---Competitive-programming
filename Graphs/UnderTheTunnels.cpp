#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define INF LLONG_MAX

vector<bool> visited(1005);
vector<ll> dist(1005);
ll n,k;
vector<vector<ll>> adjm(1005+5 , vector<ll> (1005+5));
vector<ll> adj[1005+5];

void dijkstra(ll s) {

    for (ll i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    priority_queue<pair<ll,ll>> q;
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {

        ll y = q.top().second;
        q.pop();

        if (visited[y] == true) continue;
        visited[y] = true;

        for(auto u : adj[y]){

            if (dist[y] + 1 < dist[u]) {
                dist[u] = dist[y] + 1;
                q.push(make_pair(-dist[u], u));
            }
        }
    }
}

int main(){

    ll test;
    cin >> test;

    while(test--){

        string s;
        cin >> n >> k;

        for(ll i = 0; i < n; i++){
            cin >> s;
            for(ll j = 0; j < n; j++){
                if(abs(i-j) <= k && s[j] == '1' && i != j ) adjm[i][j] = 1;
                else adjm[i][j] = 0;
            }
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j  < n; j++){
                if(adjm[i][j] == 1) adj[i].push_back(j);
            }
        }

        dijkstra(0);

        if(dist[n-1] == INF) cout << "-1\n";
        else cout << dist[n-1] << "\n";

        for(ll i = 0; i < n ;i++) adj[i].clear();
    }

    return 0;
}



