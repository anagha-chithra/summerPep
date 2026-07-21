#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for (int num : nums) {
            if (num == 0)
                zero++;
            else if (num == 1)
                one++;
            else if (num == 2)
                two++;
        }

        int index = 0;

        for (int i = 0; i < zero; i++)
            nums[index++] = 0;

        for (int i = 0; i < one; i++)
            nums[index++] = 1;

        for (int i = 0; i < two; i++)
            nums[index++] = 2;
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
    obj.sortColors(nums);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}