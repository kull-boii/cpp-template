/*
    Name : Aadi Manchekar

    COMPILE USING :  
    
g++ main.cpp -Wall -Wl,--stack=268435456 -Wextra -std=c++14 -Wconversion -Wshadow -Wduplicated-cond -free -Ofast -fexceptions -ffast-math

./a.out < input.txt
*/

/* -- < Optimizations > -- */
// check once
#pragma GCC optimize("Ofast,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma")

/* -- </Optimizations > -- */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // for pair
#include <iomanip> // for setprecision
#include <cmath>   // for floor, round, ceil, trunc
#include <cstring> // for memset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// 1] find_by_order(k); returns iterator to the kth  element... (logN) func(index) > value
// 2] order_of_key(k); returns the number of element strictly lesser than k... (logN) fucn(value) > index

using namespace std;
#define endl '\n'
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// some bugs
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

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
inline ostream &operator<<(ostream &str, const vector<T> v)
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
inline ostream &operator<<(ostream &str, const pair<T, U> p)
{
    return str << p.first << " " << p.second << endl;
}

template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
int add(int a, int b, int c)
{
    int res = a + b;
    return (res >= c ? res - c : res);
}
int mod_neg(int a, int b, int c)
{
    int res;
    if (abs(a - b) < c)
        res = a - b;
    else
        res = (a - b) % c;
    return (res < 0 ? res + c : res);
}
int mul(int a, int b, int c)
{
    LL res = (LL)a * b;
    return (res >= c ? res % c : res);
}
LL mulmod(LL a, LL b, LL m)
{
    LL q = (LL)(((LD)a * (LD)b) / (LD)m);
    LL r = a * b - q * m;
    if (r > m)
        r %= m;
    if (r < 0)
        r += m;
    return r;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = 0, yy = 1;
    y = 0;
    x = 1;
    while (b)
    {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
template <typename T>
T mod_inverse(T a, T n)
{
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
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

    unsigned long length = min(firstNo.size(), secondNo.size());
    int carry(0), val(0);
    for (unsigned int i = 0; i < length; i++)
    {
        val = firstNo[i] + secondNo[i] + carry;
        carry = val / 10;
        ans.emplace_back(val % 10);
    }
    if (firstNo.size() > length)
    {
        for (unsigned long i = length; i < firstNo.size(); i++)
        {
            val = firstNo[i] + carry;
            carry = val / 10;
            ans.emplace_back(val % 10);
        }
    }
    if (secondNo.size() > length)
    {
        for (unsigned long i = length; i < secondNo.size(); i++)
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

bool isprime(long long n)
{
    if (n < 2)
        return false;
    for (long long x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == x)
            return true;
        bool flag = true;
        long long r = 1;
        long long t = 1;
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
long long fastpow(long long base, long long expo)
{
    long long ret = 1;
    while (expo)
    {
        if (expo & 1)
            (ret *= base) %= mod;
        expo >>= 1;
        (base *= base) %= mod;
    }
    return ret;
}

// mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
// int rng(int lim)
// {
//     uniform_int_distribution<int> uid(0, lim - 1);
//     return uid(rang);
// }
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*  -- </Functions > -- */

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // cout << fixed << setprecision(10);

    // memset(a,0,sizeof(a)); // initialize with 0
    // memset(a,-1,sizeof(a)); // initializing with -1
    // memset(a,0xc0,sizeof(a)); // initializing with negative infinity
    // memset(a,0x3f,sizeof(a)); // initializing with positive infinity

    return 0;
}
