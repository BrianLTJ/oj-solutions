/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (22.48%)
 * Total Accepted:    218.8K
 * Total Submissions: 973.1K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool even=((nums1.size()+nums2.size())%2==0);
        int p1=0,p2=0;
        while(p1<nums1.size() && p2<nums2.size() && (p1+p2)<(nums1.size()+nums2.size()-1)/2){
            if(nums1[p1]<nums2[p2]){p1++;}
            else{p2++;}
        }
        if(even){
            return (nums1[p1]+nums2[p2])/2.0;
        } else {
            return (nums1[p1]<nums2[p2]?nums1[p1]:nums2[p2]);
        }
    }
};
