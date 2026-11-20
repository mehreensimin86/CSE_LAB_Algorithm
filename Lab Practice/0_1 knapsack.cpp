

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int wt[100], val[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int dp[101][101] = {0};

    // DP Table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i-1] <= w)
            {
                dp[i][w] = max(
                    val[i-1] + dp[i-1][w-wt[i-1]],
                    dp[i-1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    return 0;
}
