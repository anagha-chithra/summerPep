#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int summax = 0;
        int summin = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (summax < 0)
                summax = 0;
            if (summin > 0)
                summin = 0;

            summax += nums[i];
            summin += nums[i];

            mini = min(mini, summin);
            maxi = max(maxi, summax);
        }

        if (maxi < 0)
            return maxi;

        return max(maxi, totalSum - mini);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.maxSubarraySumCircular(nums);

    return 0;
}