#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<int, int>> vpi;
typedef long long LL;

const lld INF = (1ll) << 56;
const long long OO = 2e18;
const double pi = 2 * acos(0.0);

lld n, dp[100001];

//TOP_DOWN
lld downToZeroHackerRank(lld n) {
	lld count = INT_MAX;
	if (n == 0 || n == 1 || n == 2) return dp[n] = n;
	if (dp[n] != -1) return dp[n];
	count = min(count, downToZeroHackerRank(n - 1)) + 1;
	for (lld i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			count = min(count, (downToZeroHackerRank(n / i)) + 1);
		}
	}
	return dp[n] = count;
}


int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << downToZeroHackerRank(n) << endl;

}
