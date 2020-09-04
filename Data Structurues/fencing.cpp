#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll r,c,n,x,y;
ll answer = 0 , best = 0;
map<pair<ll,ll> , bool >  grid;
map<pair<ll,ll> , bool > visit;

void dfs(ll x , ll y) {

    if(visit[{x,y}]) return;
    visit[make_pair(x,y)] = true;

    ll count = 0;
    if (grid.find({x + 1, y}) != grid.end()) count++;
    if (grid.find({x-1,y}) != grid.end()) count++;
    if (grid.find({x,y+1}) != grid.end()) count++;
    if (grid.find({x,y-1}) != grid.end()) count++;

    answer += 4 - count;

    if (grid.find({x + 1,y}) != grid.end()) dfs(x + 1, y);
    if (grid.find({x-1,y}) != grid.end()) dfs(x - 1, y);
    if (grid.find({x, y+1}) != grid.end()) dfs(x, y + 1);
    if (grid.find({x,y-1}) != grid.end()) dfs(x, y - 1);

}

int main() {

    fastio;

    ll test;
    cin >> test;

    for(ll t = 0; t < test; t++) {

        best = 0;
        cin >> r >> c >> n;
        for (ll i = 0; i < n; i++) {
            cin >> x >> y;
            grid[make_pair(x - 1, y - 1)] = true;
            visit[make_pair(x - 1, y - 1)] = false;
        }

        for (auto i : grid) {

            if (visit[i.first]) continue;
            answer = 0;
            dfs(i.first.first, i.first.second);
            best += answer;
        }

        cout << best << "\n";

        grid.clear();
        visit.clear();
    }

    return 0;
}
