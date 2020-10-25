#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define foo(i,a,b,d) for(ll i = a; i <= b; i+=d)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll ans = -INF;
ll node;
vector<pair<ll,ll>> adj[100005];
vector<bool> visited(100005);

void dfs(ll source,ll path){
	if(visited[source] == true) return;
	visited[source] = true;

	if(path > ans){
		ans = path;
		node = source;
	}

	for(auto i : adj[source]) dfs(i.first,path+i.second);
}

int main() {

	ll n,m;
	cin in n in m;

	fo(i,0,m-1){
		ll u,v,x;
		cin in u in v in x;
		adj[u].pb(mp(v,x));
		adj[v].pb(mp(u,x));
	}

	dfs(0,0);
	ans = -INF;
	visited.clear();
	visited.resize(100005);

	dfs(node,0);

	cout out ans;

	return 0;
}
