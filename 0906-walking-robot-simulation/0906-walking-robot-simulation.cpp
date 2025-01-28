#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentDirection = 0; // Start facing North
        int x = 0, y = 0; // Starting position
        
        // Encode obstacles into a set for O(1) lookup
        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "_" + to_string(obs[1]));
        }
        
        int maxDistanceSquared = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left 90 degrees
                currentDirection = (currentDirection + 3) % 4;
            } else if (command == -1) {
                // Turn right 90 degrees
                currentDirection = (currentDirection + 1) % 4;
            } else {
                // Move forward
                for (int step = 0; step < command; ++step) {
                    int nextX = x + directions[currentDirection].first;
                    int nextY = y + directions[currentDirection].second;
                    
                    // Check if the next position is an obstacle
                    if (obstacleSet.count(to_string(nextX) + "_" + to_string(nextY))) {
                        break; // Stop moving if there's an obstacle
                    }
                    
                    // Update position
                    x = nextX;
                    y = nextY;
                }
                // Update max distance squared
                maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
            }
        }
        
        return maxDistanceSquared;
    }
};
