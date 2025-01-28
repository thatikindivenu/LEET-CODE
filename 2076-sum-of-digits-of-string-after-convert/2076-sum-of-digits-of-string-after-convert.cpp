#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert string to its integer representation
        string num_str = "";
        for (char c : s) {
            num_str += to_string(c - 'a' + 1); // Convert char to its 1-indexed position
        }

        // Step 2: Perform k transformations by summing digits
        int sum = 0;
        for (char c : num_str) {
            sum += c - '0'; // Initial sum of digits
        }

        while (--k > 0) { // Perform the remaining k-1 transformations
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10; // Add last digit
                sum /= 10;           // Remove last digit
            }
            sum = new_sum;
        }

        return sum;
    }
};
