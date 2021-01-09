#include <iostream>
#include <vector>
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

int main() {

    tc{
        ll no,n,k;
        cin in no in n in k;

        ll dp[105][105][2];

        // Sub-Problem :

        // dp[i][j][0] = number of x with lenght = i , product = j , ends with 0
        // dp[i][j][1] = number of x with lenght = i , product = j , ends with 1

        // Base case :

        dp[1][0][0] = dp[1][0][1] = 1;
        dp[1][1][0] = dp[1][1][1] = 0;
        dp[1][2][0] = dp[1][2][1] = 0;

        fo(i,2,n){
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
            dp[i][0][1] = dp[i-1][0][0];
        }

        // Recurrence Relation :

        fo(i,2,n){
            fo(j,1,k){
                dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
            }
        }

        cout out no space dp[n][k][0] + dp[n][k][1] nextline;
    }
    return 0;
}
