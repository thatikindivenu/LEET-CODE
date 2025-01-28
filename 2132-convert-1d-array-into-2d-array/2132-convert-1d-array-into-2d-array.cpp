#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the conversion is possible
        if (original.size() != m * n) {
            return {};
        }
        
        vector<vector<int>> result(m, vector<int>(n));
        
        // Fill the 2D array row by row
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i];
        }
        
        return result;
    }
};
