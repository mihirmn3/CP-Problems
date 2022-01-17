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
signed main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        set<pair<int, int>> s, ss;
        set<pair<int, int>>::iterator it;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            s.insert({(*i).first, (*i).second});
            if ((*i).second > 1)
                ss.insert({-(*i).first, (*i).second});
        }
        int ans = 0, x;
        bool b = false;
        for (int i = 0; i <= n; i++)
        {
            if (i > 0 && m[i - 1] == 0)
            {
                it = ss.lower_bound({-(i - 1), (int)0});
                if (it == ss.end())
                    b = true;
                else
                {
                    x = -(*it).first;
                    ss.erase(it);
                    // s.erase({x, m[x]});
                    m[x]--;
                    if (m[x] > 1)
                        ss.insert({-x, m[x]});
                    // s.insert({x, m[x]});
                    ans += (i - 1) - x;
                }
            }
            if (b)
                cout << "-1 ";
            else
                cout << ans + m[i] << " ";
        }
        cout << "\n";
    }
}