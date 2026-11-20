

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int dp[100][100] = {0};

    // Build DP Table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i-1] == Y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Print LCS Length
    cout << "LCS Length: " << dp[m][n] << endl;

    // Find LCS String
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs += X[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "LCS: " << lcs << endl;

    return 0;
}
