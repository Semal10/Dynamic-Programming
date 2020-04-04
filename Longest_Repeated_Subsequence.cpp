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

string s;
lld dp[1001][1001];

//TOP_DOWN
lld longestRepeatedSubsequence(lld i , lld j) {
	lld count = 0;
	if (i < 0 || j < 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j] && i != j) {
		count = max(count, longestRepeatedSubsequence(i - 1, j - 1) + 1);
	}
	else {
		count = max(count, max(longestRepeatedSubsequence(i - 1, j), longestRepeatedSubsequence(i, j - 1)));
	}
	return dp[i][j] = count;
}

int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << longestRepeatedSubsequence(s.length() - 1, s.length() - 1) << endl;

}
