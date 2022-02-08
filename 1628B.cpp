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
        string s[n];
        map<string, int> m;
        map<char, int> mx;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            m[s[i]]++;
        }
        bool ans = false, b = false;
        string x, y;
        for (int i = 0; i < n && !ans; i++)
        {
            x = "";
            y = "";
            b = true;
            mx.clear();
            for (int j = 0; j < ((int)s[i].size()) / 2; j++)
            {
                if (s[i][j] != s[i][(int)s[i].size() - j - 1])
                    b = false;
            }
            if (b)
            {
                ans = true;
                break;
            }
            x = s[i];
            if ((int)x.size() == 2)
            {
                y += x[0];
                if (m[y] > 0)
                {
                    ans = true;
                    break;
                }
                y = "";
                y += x[1];
                y += x[0];
                if (m[y] > 0)
                {
                    ans = true;
                    break;
                }
                for (int j = 0; j < 26; j++)
                {
                    if (m[(char)(j + 97) + y])
                    {
                        ans = true;
                        break;
                    }
                }
            }
            else
            {
                y = "";
                y += x[2];
                y += x[1];
                y += x[0];
                if (m[y] > 0)
                {
                    ans = true;
                    break;
                }
                y = "";
                y += x[1];
                y += x[0];
                if (m[y] > 0)
                {
                    ans = true;
                    break;
                }
                if (x[1] == x[2])
                {
                    y = "";
                    y += x[0];
                    if (m[y] > 0)
                    {
                        ans = true;
                        break;
                    }
                }
            }
            m[s[i]]--;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
