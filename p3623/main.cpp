#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long r1, r2;
        long long result = 0;
        map<int, long long> rows;
        vector<long long> partial_sums;

        for (int i = 0; i < points.size(); ++i) {
            if (rows.find(points[i][1]) == rows.end()) {
                rows[points[i][1]] = 0;
            }
            ++rows[points[i][1]];
        }

        for (auto it = rows.rbegin(); it != rows.rend(); ++it) {
            partial_sums.push_back(result);
            r1 = it->second * (it->second - 1) / 2;
            result += r1;
            result %= MOD;
        }

        result = 0;

        auto jt = partial_sums.rbegin();
        for (auto it = rows.begin(); it != rows.end(); ++it, ++jt) {
            r1 = (it->second * (it->second - 1) / 2) % MOD;
            result += r1 * *jt;
            result %= MOD;
        }

        return result;
    }
};

int main() {
    vector<vector<int>> input;
    input.push_back(vector<int>({1, 0}));
    input.push_back(vector<int>({2, 0}));
    input.push_back(vector<int>({3, 0}));
    input.push_back(vector<int>({2, 2}));
    input.push_back(vector<int>({3, 2}));

    // input.push_back(vector<int>({0, 0}));
    // input.push_back(vector<int>({1, 0}));
    // input.push_back(vector<int>({0, 1}));
    // input.push_back(vector<int>({2, 1}));

    Solution sol;
    cout << sol.countTrapezoids(input);

    return 0;
}