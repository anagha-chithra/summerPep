#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefixsum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixsum.resize(n);
        prefixsum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefixsum[right];

        return prefixsum[right] - prefixsum[left - 1];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    NumArray obj(nums);

    int q;
    cin >> q;

    while (q--) {
        int left, right;
        cin >> left >> right;
        cout << obj.sumRange(left, right) << endl;
    }

    return 0;
}