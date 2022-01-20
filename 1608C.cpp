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
        int ax[n], bx[n];
        set<pair<int, int>> a, b;
        set<pair<int, int>>::iterator it;
        for (int i = 0; i < n; i++)
        {
            cin >> ax[i];
            a.insert({ax[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bx[i];
            b.insert({bx[i], i});
        }
        map<int, int> m;
        it = b.end();
        it--;
        int x = ax[(*it).second];
        while (true)
        {
            x = min(ax[(*it).second], x);
            m[ax[(*it).second]] = x;
            if (it == b.begin())
                break;
            it--;
        }
        it = a.end();
        it--;
        vector<int> ans(n);
        x = m[(*it).first];
        for (; (*it).first > x; it--)
        {
            x = min(x, m[(*it).first]);
            ans[(*it).second] = 1;
        }
        ans[(*it).second] = 1;
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
}