#include <iostream>
#include <tuple>
using namespace std;
typedef long long ll;

tuple<ll, ll, ll> inv(ll a, ll b) {
    tuple<ll, ll, ll> A = make_tuple(a, 1, 0);
    tuple<ll, ll, ll> B = make_tuple(b, 0, 1);

    while(get<0>(B) != 0) {
        ll s0, t0, r0, s1, t1, r1;
        tuple<ll, ll, ll> tmp;

        tie(r0, s0, t0) = A;
        tie(r1, s1, t1) = B;

        ll q = r0 / r1;
        get<0>(tmp) = r0 % r1;
        get<1>(tmp) = s0 - s1 * q;
        get<2>(tmp) = t0 - t1 * q;

        A = B;
        B = tmp;
    }
    return A;
}


int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        ll a; ll b; cin >> a >> b;
        ll gcd, s, t;
        tie(gcd, s, t) = inv(a, b);
        while(b*t <= a) {
            t += a;
        }
        if(gcd != 1 || t > 1e9) {
            cout << "IMPOSSIBLE" << "\n";
        }
        else {
            cout << t << "\n";
        }

    }
}