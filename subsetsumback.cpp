#include <iostream>

using namespace std;

void subsetSum(int *arr, int pos, int sum, int tmpsum, int n, bool &found)
{
    if (sum == tmpsum)
        found = true;

    for (int i = pos; i < n; i++)
    {
        if (tmpsum + arr[i] <= sum)
        {
            tmpsum += arr[i];

            subsetSum(arr, i + 1, sum, tmpsum, n, found);
            tmpsum -= arr[i];
        }
    }
}

int main()
{
    cout << "Enter number of elements in set: ";
    int n;
    cin >> n;

    int set[n];
    cout << "Enter values of set: ";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    cout << "ENter the sum : ";
    int sum;
    cin >> sum;

    bool f = false;
    subsetSum(set, 0, sum, 0, n, f);
    if (f)
        cout << "Found a sum";
    else
        cout << "Not found any sum";
}