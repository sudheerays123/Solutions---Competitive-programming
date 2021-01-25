#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp pake_pair
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

bool IsKPossible(double k , vector<ll> starttime , vector<ll> endtime , ll n){

    double time = 0;
    fo(i,0,n-1){
        if(time < starttime[i]) time = starttime[i] + k;
        else if(time <= endtime[i]) time += k;
        else return false;
    }
    return true;

}

int main() {

    fast;

    tc{

        ll n,d;
        cin in n in d;
        vi c(n+5);
        vi e(n+5);
        fo(i,0,n-1) {
            cin in c[i];
            e[i] = c[i] + d;
        }

        sort(c.begin() , c.begin()+n);
        sort(e.begin() , e.begin()+n);

        double low = 0 , high = 1e10;

        while(high - low > 0.000001){
            double mid = (low+high)/2;

            if(IsKPossible(mid,c,e,n) == true) low = mid;
            else high = mid;
        }

        cout out fixed out setprecision(10);
        cout out low nextline;
    }

    return 0;
}
