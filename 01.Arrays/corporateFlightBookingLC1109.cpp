#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);

        for (auto &booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];

            diff[first - 1] += seats;
            if (last < n)
                diff[last] -= seats;
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> bookings(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }

    Solution obj;
    vector<int> ans = obj.corpFlightBookings(bookings, n);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}