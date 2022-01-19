#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define koko cout << "yes"
#define int long long int
#define mod 1000000007
//#define for(int i, int n) for(int i=0; i<n; i++)

using namespace std;
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const { return a.first > b.first; }
};
int power(int n, int x)
{
    int res = 1;
    while (x > 0)
    {
        if (x % 2 == 0)
        {
            n = (n * n);
            x /= 2;
        }
        else
        {
            x--;
            res = (res * n);
        }
    }
    return res;
}
vector<bool> prim(100000, true);
set<int> primeset;
void prime()
{
    int z;
    for (int i = 2; i <= 100000; i++)
    {
        z = i;
        while (prim[i] && i * z <= 100000)
        {
            prim[i * z] = false;
            z++;
        }
        if (prim[i])
            primeset.insert(i);
    }
}
int binarySmallest(int n, int key, vector<int> &v)
{
    int hi = n, lo = 0, mid = 0;
    while (lo != hi)
    {
        mid = (lo + hi) / 2;

        if (v[mid] >= key)
            hi = mid;

        else
            lo = mid + 1;
    }
    return ((hi + lo) / 2);
}
int binaryBiggest(int n, int key, vector<int> &v)
{
    int hi = n - 1, lo = -1, mid = 0;
    while (lo != hi)
    {
        mid = (lo + hi + 1) / 2;

        if (v[mid] >= key)
            lo = mid;

        else
            hi = mid - 1;
    }
    return ((hi + lo) / 2);
}
vector<int> vist;
bool dfs(int i, int x, vector<int> &tri, vector<vector<int>> &v)
{
    vist[i] = 0;
    if ((int)v[i].size() == 1 && i > 0)
        return true;
    for (int j = 0; j < (int)v[i].size(); j++)
    {
        if (vist[v[i][j]] && (tri[v[i][j]] > (x + 1)) && dfs(v[i][j], x + 1, tri, v))
            return true;
    }
    return false;
}
signed main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vist.clear();
        int n, k;
        cin >> n >> k;
        vist.resize(n, 1);
        queue<pair<int, int>> q;
        vector<int> f(k), tri(n, -1);
        for (int i = 0; i < k; i++)
        {
            cin >> f[i];
            f[i]--;
            q.push({f[i], 0});
            tri[f[i]] = 0;
        }
        vector<vector<int>> v(n);
        int a, b;
        for (int i = 0; i < (n - 1); i++)
        {
            cin >> a >> b;
            a--;
            b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        while (!q.empty())
        {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            for (int i = 0; i < (int)v[a].size(); i++)
            {
                if (tri[v[a][i]] == -1)
                {
                    tri[v[a][i]] = b + 1;
                    q.push({v[a][i], b + 1});
                }
            }
        }
        if (dfs(0, 0, tri, v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}