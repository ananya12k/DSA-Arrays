#include <iostream>
#include <string>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
    // Create Table for SubProblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If str1 empty. Then add all of str2
            if (i == 0)
                dp[i][j] = j;

            // If str2 empty. Then add all of str1
            else if (j == 0)
                dp[i][j] = i;

            // If character same. Recur for remaining
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i][j - 1],    // Insert
                                   dp[i - 1][j],    // Remove
                                   dp[i - 1][j - 1] // Replace
                               );
        }
    }

    return dp[m][n];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
    cout << editDistDP(str1, str2, str1.length(), str2.length()) << endl;
    return 0;
}