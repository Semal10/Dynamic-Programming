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
lld dp[1001][1001], dp1[1001][1001];

//TOP_DOWN
lld longestPalindromeSubsequence(lld i, lld j) {
	lld count = 0;
	if (i > j) return dp[i][j] = 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j]) {
		if (i == j) {
			return dp[i][j] = longestPalindromeSubsequence(i + 1, j - 1) + 1;
		}
		else return dp[i][j] = longestPalindromeSubsequence(i + 1, j - 1) + 2 ;
	}
	else {
		count = max(count, max(longestPalindromeSubsequence(i + 1, j), longestPalindromeSubsequence(i, j - 1)));
	}
	return dp[i][j] = count;
}

//BOTTOM-UP
lld longestPalindromeSubsequenceDynamic(lld n) {
	for (lld i = 1; i <= n; i++) {
		for (lld j = 1; j <= n; j++) {
			if (s[i - 1] == s[j - 1]) {
				if (i == j) dp1[i][j] = dp1[i - 1][j - 1] + 1;
				else dp1[i][j] = dp1[i - 1][j - 1] + 2;
			}
			else {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
			}
		}
	}
	return dp1[n][n];
}


int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lld i, j;
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << longestPalindromeSubsequence(0, s.length() - 1) << endl;
}
