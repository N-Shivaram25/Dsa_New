#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
…        }

        return result;
    }
};