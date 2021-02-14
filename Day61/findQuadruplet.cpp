#include <iostream>
#include <algorithm>
using namespace std;

void quadTuple(int arr[], int n, int sum)
{
    // sort the array in ascending order
    sort(arr, arr + n);

    // check if quadruplet is formed by `arr[i]`, `arr[j]`, and a pair from
    for (int i = 0; i <= n - 4; i++)
    {
        for (int j = i + 1; j <= n - 3; j++)
        {
            // `k` stores remaining sum
            int k = sum - (arr[i] + arr[j]);

            // check for sum `k` in subarray `arr[j+1…n)`
            int low = j + 1, high = n - 1;

            while (low < high)
            {
                if (arr[low] + arr[high] < k)
                    low++;

                else if (arr[low] + arr[high] > k)
                    high--;

                // quadruplet with a given sum found
                else
                {
                    cout << arr[i] << " " << arr[j] << " " <<arr[low] << " " << arr[high] <<"\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
    int sum = 20;
    int n = sizeof(arr) / sizeof(arr[0]);
    quadTuple(arr, n, sum);
    return 0;
}

