#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n1, n2;
    cout << "Enter two numbers : ";
    cin >> n1 >> n2;
    int l1 = n1.length();
    int l2 = n2.length();
    if (l1 > l2)
    {
        swap(n1, n2);
        swap(l1, l2);
    }

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    string ans = "";
    int carry = 0;

    for (int i = 0; i < l1; i++)
    {
        int temp = ((n1[i] - '0') + (n2[i] - '0') + carry);
        ans.push_back(temp % 10 + '0');
        carry = temp / 10;
    }
    for (int i = l1; i < l2; i++)
    {
        int temp = ((n2[i] - '0') + carry);
        ans.push_back(temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry)
        ans.push_back(carry + '0');

    reverse(ans.begin(), ans.end());
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    cout << n1 << " + " << n2 << " = " << ans << endl;
}
