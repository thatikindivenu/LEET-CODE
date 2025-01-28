#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate the total chalk required for one full round
        long long total_chalk = 0;
        for (int c : chalk) {
            total_chalk += c;
        }
        
        // Step 2: Reduce k modulo total_chalk
        k %= total_chalk;
        
        // Step 3: Find the student who will run out of chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // This line will never be reached due to problem constraints
    }
};
