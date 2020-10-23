/*
    Name : Aadi Manchekar
*/

/* -- < Optimizations > -- */

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

/* -- </Optimizations > -- */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // for pair
#include <iomanip> // for setprecision
#include <cmath>   // for floor, round, ceil, trunc

using namespace std;
#define endl '\n'

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

template <class T>
inline ostream &operator<<(ostream &str, vector<T> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return str;
}

template <class T>
inline istream &operator>>(istream &str, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return str;
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

/*  -- </Functions > -- */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);

    return 0;
}
