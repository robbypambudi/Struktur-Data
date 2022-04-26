// Created By Robby Ulung Pambudi
// Disclaimer
// Dont Copy or Share this code

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#define ll long long int

ll a1[1000000], a2[1000000], b1[1000000], b2[1000000];
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

ll max(ll a, ll b)
{
    return (a > b ? a : b);
}

ll min(ll a, ll b)
{
    return (a < b ? a : b);
}

// removeDuplicates
int removeDuplicates(ll arr[], ll n)
{
    if (n == 0 || n == 1)
        return n;

    ll temp[n];
    ll j = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];
    for (ll i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

ll upper_bound(ll arr[], ll n, ll x)
{
    ll l = 0;
    ll h = n;
    while (l < h)
    {
        ll mid = (l + h) / 2;

        if (x >= arr[mid])
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}

ll lower_bound(ll arr[], ll n, ll x)
{
    ll l = 0;
    ll h = n;
    while (l < h)
    {
        ll mid = (l + h) / 2;
        if (x <= arr[mid])
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    ll n, m;

    ll r, c;

    ll ans, kiri, kanan;

    scanf("%lld %lld", &n, &m);
    ll _a1 = 0, _a2 = 0, _b1 = 0, _b2 = 0;

    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld", &r, &c);
        ll a = r + c;
        ll b = r - c;

        // Operation Bit AND
        if (a & 1)
        {
            a1[_a1] = a;
            _a1++;
        }
        else
        {
            a2[_a2] = a;
            _a2++;
        }

        if (b & 1)
        {
            b1[_b1] = b;
            _b1++;
        }
        else
        {
            b2[_b2] = b;
            _b2++;
        }
    }

    qsort(a1, _a1, sizeof(ll), compare);
    qsort(a2, _a2, sizeof(ll), compare);
    qsort(b1, _b1, sizeof(ll), compare);
    qsort(b2, _b2, sizeof(ll), compare);

    _a1 = removeDuplicates(a1, _a1);
    _a2 = removeDuplicates(a2, _a2);
    _b1 = removeDuplicates(b1, _b1);
    _b2 = removeDuplicates(b2, _b2);

    for (int i = 0; i < _a1; ++i)
    {
        int val = a1[i];
        if (val <= n + 1)
        {
            ans += (val - 1);
        }
        else
        {
            ans += (2 * n - val + 1);
        }

        kiri = lower_bound(b1, _b1, max(2 - val, val - 2 * n));
        kanan = upper_bound(b1, _b1, min(2 * n - val, val - 2));
        ans -= (kanan - kiri);
    }

    for (int i = 0; i < _a2; ++i)
    {
        int val = a2[i];
        if (val <= n + 1)
        {
            ans += (val - 1);
        }
        else
        {
            ans += (2 * n - val + 1);
        }

        kiri = lower_bound(b2, _b2, max(2 - val, val - 2 * n));
        kanan = upper_bound(b2, _b2, min(2 * n - val, val - 2));
        ans -= (kanan - kiri);
    }

    for (int i = 0; i < _b1; ++i)
    {
        ans += (n - abs(b1[i]));
    }
    for (int i = 0; i < _b2; ++i)
    {
        ans += (n - abs(b2[i]));
    }

    printf("%lld\n", ans);
}

// Robby Ulung Pambudi