#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
#define int long long
#define endl "\n"
using namespace __gnu_pbds;

int mod = 1e9 + 7;
const int sz = 1e5 + 10;
int dp[sz][30][2];
int n, k;
string s;

int solve(int i, int misMatchCount, bool smallerOrNot)
{

    if (misMatchCount < 0)
        return 0;
    if (i == n)
    {
        return ((misMatchCount == 0) and (smallerOrNot == true));
    }
    if (dp[i][misMatchCount][smallerOrNot] != -1)
    {
        return dp[i][misMatchCount][smallerOrNot];
    }

    int ans = 0;
    if (smallerOrNot)
    {
        for (auto ch = 'a'; ch <= 'z'; ch++)
        {
            ans += solve(i + 1, misMatchCount - (ch != s[i]), true);
            ans %= mod;
        }
    }
    else
    {
        for (auto ch = 'a'; ch <= s[i]; ch++)
        {
            ans += solve(i + 1, misMatchCount - (ch != s[i]), (ch < s[i]));
            ans %= mod;
        }
    }
    return dp[i][misMatchCount][smallerOrNot] = ans;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < n + 5; i++)
        {
            for (int j = 0; j <= k + 5; j++)
            {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }

        cout << solve(0, k, false) << endl;
    }

    return 0;
}