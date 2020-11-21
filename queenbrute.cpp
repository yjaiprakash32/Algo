#include <iostream>
#include <algorithm>

using namespace std;

int place(int *arr, int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((arr[i] == arr[pos]) || ((abs(arr[i] - arr[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}
void print_sol(int *arr, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (arr[i] == j)
                cout << ("| Q |");
            else
                cout << ("| * |");
        }
        cout << endl;
    }
}

void queen(int *arr, int n)
{
    int k = 1;
    arr[k] = 0;
    while (k != 0)
    {
        arr[k] = arr[k] + 1;
        while ((arr[k] <= n) && !place(arr, k))
            arr[k]++;
        if (arr[k] <= n)
        {
            if (k == n)
            {
                print_sol(arr, n);
                break;
            }
            else
            {
                k++;
                arr[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    int arr[30];
    queen(arr, n);
}