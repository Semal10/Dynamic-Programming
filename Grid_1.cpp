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

lld dp[2001][2001], n, m, c = 0 ;
char  a[1001][1001];

//TOP-DOWN
lld gridOne(lld i, lld j) {
	lld count1 = 0, count2 = 0;
	if (i > n - 1 || j > m - 1) return dp[i][j] = 0;
	if (i == n - 1 && j == m - 1) {
		return dp[i][j] = (count1 + count2 + 1) % MOD;
	}
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i + 1][j] == '.') count1 = max(count1, gridOne(i + 1, j) ) ;
	if (a[i][j + 1] == '.')	count2 = max(count2, gridOne(i, j + 1) ) ;
	return dp[i][j] = (count1 + count2) % MOD;
}

int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lld i, j;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << gridOne(0, 0) << endl;

}
