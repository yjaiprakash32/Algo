#include <iostream>

using namespace std;

bool isSubsetsum(int *set, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (set[n - 1] > sum)
        return isSubsetsum(set, n - 1, sum);

    return isSubsetsum(set, n - 1, sum) || isSubsetsum(set, n - 1, sum - set[n - 1]);
}

int main()
{
    int n;
    cout << "Enter number of elements ";
    cin >> n;
    cout << "Enter the sum: ";
    int sum;
    cin >> sum;
    int set[n];
    cout << "Enter values in set: ";
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    if (isSubsetsum(set, n, sum))
    {
        cout << "Found";
    }
    else
    {

        cout << "Not found";
    }
}