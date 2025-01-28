#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Calculate total sum and missing sum
        int totalSum = mean * (n + m);
        int rollSum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = totalSum - rollSum;
        
        // Check if it's possible to construct the missing rolls
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        
        // Create the missing rolls
        vector<int> missing(n, 1);
        missingSum -= n; // Subtract the initial sum of `n` ones
        
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add = min(5, missingSum); // Add up to 5 to keep the value <= 6
            missing[i] += add;
            missingSum -= add;
        }
        
        return missing;
    }
};
