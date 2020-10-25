/*
    Name : Aadi Manchekar
*/

/* -- < Optimizations > -- */

#pragma GCC optimize("Ofast,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma")

/* -- </Optimizations > -- */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // for pair
#include <iomanip> // for setprecision
#include <cmath>   // for floor, round, ceil, trunc
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// 1] find_by_order(k); returns iterator to the kth  element... (logN) func(index) > value
// 2] order_of_key(k); returns the number of element strictly lesser than k... (logN) fucn(value) > index

using namespace std;
#define endl '\n'

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;
PBDS p_set;

/*
    int range : −2'147'483'648 to 2'147'483'647
    unsigned int range : 0 to 4'294'967'295
    float : 32 bit, 7 decimal digits of precision.
    double : 64 bit, 15 decimal digits of precision.
*/

/*  -- < Global Variables > -- */

const int mod = 1e9 + 7;
const double pi = 3.1415926535897932384626;

/*  -- </Global Variables > -- */

/*  -- < operator overloading > -- */

// for vector
template <class T>
inline istream &operator>>(istream &str, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return str;
}

template <class T>
inline ostream &operator<<(ostream &str, vector<T> v)
{
    for (auto i : v)
        cout << i << " "; // while using with vector<pair> remove " "
    cout << endl;
    return str;
}

// for vector<pair> and pair
template <class T, class U>
inline istream &operator>>(istream &str, pair<T, U> &p)
{
    return str >> p.first >> p.second;
}

template <class T, class U>
inline ostream &operator<<(ostream &str, pair<T, U> p)
{
    return str << p.first << " " << p.second << endl;
}

/*  -- </operator overloading > -- */

/*  -- < Functions > -- */

// Big Ints
void bigInt()
{
    string a;
    string b;
    cin >> a >> b;

    vector<int> firstNo;
    vector<int> secondNo;
    vector<int> ans;

    for (char it : a)
    {
        firstNo.emplace_back(it - '0');
    }

    for (char it : b)
    {
        secondNo.emplace_back(it - '0');
    }

    reverse(firstNo.begin(), firstNo.end());
    reverse(secondNo.begin(), secondNo.end());

    long long length = min(firstNo.size(), secondNo.size());
    int carry(0), val(0);
    for (int i = 0; i < length; i++)
    {
        val = firstNo[i] + secondNo[i] + carry;
        carry = val / 10;
        ans.emplace_back(val % 10);
    }
    if (firstNo.size() > length)
    {
        for (int i = length; i < firstNo.size(); i++)
        {
            val = firstNo[i] + carry;
            carry = val / 10;
            ans.emplace_back(val % 10);
        }
    }
    if (secondNo.size() > length)
    {
        for (int i = length; i < secondNo.size(); i++)
        {
            val = secondNo[i] + carry;
            carry = val / 10;
            ans.emplace_back(val % 10);
        }
    }
    while (carry)
    {
        ans.emplace_back(carry % 10);
        carry /= 10;
    }

    for (auto i = ans.rbegin(); i < ans.rend(); i++)
    {
        cout << *i;
    }
}

// miller rabin

bool isprime(ll n)
{
    if (n < 2)
        return false;
    for (ll x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == x)
            return true;
        bool flag = true;
        ll r = 1;
        ll t = 1;
        while (r <= ((n - 1) >> __builtin_ctzll(n - 1)))
        {
            if (r & ((n - 1) >> __builtin_ctzll(n - 1)))
                t = ((__int128)t * x) % n;
            x = ((__int128)x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1)
            flag = false;
        for (r = 0; r < __builtin_ctzll(n - 1); r++)
        {
            t = ((__int128)t * t) % n;
            if (t == n - 1)
                flag = false;
        }
        if (flag)
            return false;
    }
    return true;
}

// fast power
ll fastpow(ll base, ll expo)
{
    ll ret = 1;
    while (expo)
    {
        if (expo & 1)
            (ret *= base) %= mod;
        expo >>= 1;
        (base *= base) %= mod;
    }
    return ret;
}

/*  -- </Functions > -- */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);

    return 0;
}
