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

vi dist(370,INF);
vector<pair<ll,ll>> adj[370];

void dijkstra(ll s){

    vector<bool> visited(370);
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

    ll n,m,k;
    cin in n in m in k;

    vi prize(m+5);
    fo(i,0,m-1) cin in prize[i];

    fo(i,0,k-1){
        ll x,y,p;
        cin in x in y in p;
        adj[x-1].pb(mp(y-1,p));
        adj[y-1].pb(mp(x-1,p));
    }

    ll start;
    cin in start;

    dijkstra(start-1);

    ll ans = -INF;

    fo(i,0,m-1){
        if(dist[prize[i]-1] == INF){
            cout out "It is not fault of sponsor...";
            return 0;
        }
        mmax(ans,dist[prize[i]-1]);
    }


    cout out "The good sponsor!\n" out ans;

    return 0;
}
