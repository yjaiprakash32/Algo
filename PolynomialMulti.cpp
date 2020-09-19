#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


vector<int> solve(vector<int>p, vector<int>q, int n) {
    int m = ceil(n / 2);
    if (p.size() == 1) {
        return vector<int>(1, p[0] * q[0]);
    }
    vector<int> a1;
    for (int i = 0; i < n/2; i++)
        a1.push_back(p[i]);
    vector<int> b1;
    for (int i = 0; i < n/2; i++)
        b1.push_back(q[i]);
    vector<int> a2;
    for (int i = n / 2; i < n; i++)
        a2.push_back(p[i]);
    vector<int> b2;
    for (int i = n / 2; i < n; i++)
        b2.push_back(q[i]);

    vector<int> c1, c2, c3;
    vector<int> add1, add2;
    for (int i = 0; i < m; i++) {
        add1.push_back(a1[i] + a2[i]);
        add2.push_back(b1[i] + b2[i]);
    }
    c1 = solve(a1, b1, n/2);
    c2 = solve(a2, b2, n/2);
    c3 = solve(add1, add2, n/2);
    vector<int>c(2 * n -1);
    fill(c.begin(), c.end(), 0);

    for (int i = 0; i < n - 1; i++) {
        c[i] = c[i] + c1[i];
        c[i + n] = c[i + n] + c2[i];
        c[i + m] = c[i + m] + c3[i] - c1[i] - c2[i];
    }
    return c;

}

int main() {
    cout << "Enter the value of n ";
    int n;
    cin >> n;
    vector<int> v1, v2;
    cout << "enter coefficient of first polynomial(0 in case of no value for that power) ";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    cout << "enter coefficient of second polynomial(0 in case of no value for that power) ";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    vector<int> v3 = solve(v1, v2, n);
    for (int i = 0; i < 2*n-1; i++)
        cout << v3[i] << " ";
}