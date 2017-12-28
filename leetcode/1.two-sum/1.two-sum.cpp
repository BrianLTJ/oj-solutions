/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (36.55%)
 * Total Accepted:    738.1K
 * Total Submissions: 2M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        bool found=false;
        for(i=0;i<(nums.size()-1);i++){
            if(nums[i]<target){
                for(j=i+1;j<nums.size();j++){
                    if(nums[i]+nums[j]==target){
                        found=true;
                        break;
                    }
                }
            }
            if(found) break;
        }
        return {i,j};
    }
};

