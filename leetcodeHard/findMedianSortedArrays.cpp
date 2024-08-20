#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <limits>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // Define a regular recursive function instead of a lambda
        function<int(int, int, int)> f = [&](int i, int j, int k) -> int {
            if (i >= m) return nums2[j + k - 1];
            if (j >= n) return nums1[i + k - 1];
            if (k == 1) return min(nums1[i], nums2[j]);
        
            int p = k / 2;
            int x = (i + p - 1 < m) ? nums1[i + p - 1] : numeric_limits<int>::max();
            int y = (j + p - 1 < n) ? nums2[j + p - 1] : numeric_limits<int>::max();
        
            if (x < y) {
                return f(i + p, j, k - p);
            } else {
                return f(i, j + p, k - p);
            }
        };

        int a = f(0, 0, (m + n + 1) / 2);
        int b = f(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }
};

int main() {
    // Example input
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    // Start time measurement
    auto start_time = high_resolution_clock::now();

    // Call the solution
    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);

    // End time measurement
    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time).count();

    // Output the result and elapsed time
    cout << "Output: " << result << endl;
    cout << "Time: " << elapsed_time << " sec" << endl;

    return 0;
}
