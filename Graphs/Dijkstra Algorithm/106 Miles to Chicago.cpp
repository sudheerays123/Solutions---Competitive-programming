#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
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

vector<double> dist(105,-INF);
vector<pair<ll,double>> adj[105];

void dijkstra(ll s){

    priority_queue<pair<ll,ll>> q;
    vector<bool> visited(105,false);

    dist[s] = 1;
    q.push({1,s});

    while(!q.empty()){

        ll a = q.top().second;
        q.pop();

        if(visited[a] == true) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            ll b = u.first;
            double w = u.second;

            if(dist[a]*w > dist[b]){
                dist[b] = dist[a]*w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main() {

    ll n,m;
    cin in n in m;

    fo(i,0,m-1){
        ll a,b;
        double p;
        cin in a in b in p;

        double x = (double) p/100;

        adj[a-1].pb(mp(b-1,x));
        adj[b-1].pb(mp(a-1,x));
    }

    dijkstra(0);

    cout out fixed out setprecision(6);
    cout out (double)dist[n-1]*100 space "percent";

    return 0;
}
