#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int countPerms(int n) {
    // To avoid the large output value
    int MOD = (int)(1e9 + 7);
 
    // Initialize 2D dp array
    long dp[n + 1][5];
     
    // Initialize dp[1][i] as 1 since
    // string of length 1 will consist
    // of only one vowel in the string
    for(int i = 0; i < 5; i++)
    {
        dp[1][i] = 1;
    }
     
    // Directed graph using the
    // adjacency matrix
    vector<vector<int>> relation = {
        { 1 }, { 0, 2 },
        { 0, 1, 3, 4 },
        { 2, 4 }, { 0 }
    };
 
    // Iterate over the range [1, N]
    for(int i = 1; i < n; i++)
    {
         
        // Traverse the directed graph
        for(int u = 0; u < 5; u++)
        {
            dp[i + 1][u] = 0;
 
            // Traversing the list
            for(int v : relation[u])
            {
                 
                // Update dp[i + 1][u]
                dp[i + 1][u] += dp[i][v] % MOD;
            }
        }
    }
 
    // Stores total count of permutations
    long ans = 0;
 
    for(int i = 0; i < 5; i++)
    {
        ans = (ans + dp[n][i]) % MOD;
    }
 
    // Return count of permutations
    return (int)ans;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = countPerms(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
