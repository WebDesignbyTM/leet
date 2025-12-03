#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> naturalConnections;
        vector<vector<int>> reverseConnections;
        vector<bool> used;
        queue<int> breadth;
        int crt;
        int res = 0;

        for (int i = 0; i < n; ++i){
            naturalConnections.push_back(vector<int>());
            reverseConnections.push_back(vector<int>());
            used.push_back(false);
        }

        for (int i = 0; i < connections.size(); ++i) {
            naturalConnections[connections[i][0]].push_back(connections[i][1]);
            reverseConnections[connections[i][1]].push_back(connections[i][0]);
        }
        
        breadth.push(0);
        used[0] = true;
        while (!breadth.empty()) {
            crt = breadth.front();
            breadth.pop();

            for (int i = 0; i < naturalConnections[crt].size(); ++i) 
                if (!used[naturalConnections[crt][i]]) {
                    used[naturalConnections[crt][i]] = true;
                    breadth.push(naturalConnections[crt][i]);
                    ++res;
                }

            for (int i = 0; i < reverseConnections[crt].size(); ++i)
                if (!used[reverseConnections[crt][i]]) {
                    used[reverseConnections[crt][i]] = true;
                    breadth.push(reverseConnections[crt][i]);
                }
        }
        
        return res;
    }
};

int main() {
    vector<vector<int>> connections;
    connections.push_back(vector<int>({0, 1}));
    connections.push_back(vector<int>({1, 3}));
    connections.push_back(vector<int>({2, 3}));
    connections.push_back(vector<int>({4, 0}));
    connections.push_back(vector<int>({4, 5}));
    Solution sol;
    cout << sol.minReorder(6, connections);
    return 0;
}