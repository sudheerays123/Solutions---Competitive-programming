#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vi dist(105,INF);
vector<pair<ll,ll>> adj[105];

void dijkstra(ll s){

    vector<bool> visited(105);
    priority_queue<pair<ll,ll>> q;

    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){

        ll a = q.top().second;
        q.pop();
        if(visited[a] == true) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            ll w = u.second;

            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }
    }

}

int main() {

    ll n,start,end;
    cin in n in start in end;
    start--;
    end--;

    fo(i,0,n-1){
        fo(j,0,n-1){
            ll x;
            cin in x;

            if(x == -1) continue;
            adj[i].pb(mp(j,x));
        }
    }

    dijkstra(start);

    if(dist[end] == INF) cout out "-1";
    else cout out dist[end];

    return 0;
}
