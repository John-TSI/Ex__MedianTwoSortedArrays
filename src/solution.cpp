#include<limits.h> // INT_MIN, INT_MAX
#include<algorithm> // std::min(), std::max()
#include"../inc/solution.hpp"


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    if(nums1.size() > nums2.size()){ return findMedianSortedArrays(nums2,nums1); }  // ensure smaller vector is first arg for convenience

    int totSize = nums1.size() + nums2.size();
    int partIdx1 = nums1.size()/2, partIdx2 = (int) (totSize + 1)/2 - partIdx1;  // partIdx2 chosen s.t. total #elements on LHS = RHS
    int nums1Left{0}, nums1Right{0}, nums2Left{0}, nums2Right{0}; 
    
    while(true)
    {
        nums1Left = (partIdx1 == 0) ? INT_MIN : nums1[partIdx1-1];
        nums2Left = (partIdx2 == 0) ? INT_MIN : nums2[partIdx2-1];
        nums1Right = (partIdx1 == nums1.size()) ? INT_MAX : nums1[partIdx1];
        nums2Right = (partIdx2 == nums2.size()) ? INT_MAX : nums2[partIdx2];

        if(nums1Left <= nums2Right && nums2Left <= nums1Right)  // partitions successful, compute the median based on total #elements
        {
            double median = (totSize%2) 
            ? std::max(nums1Left, nums2Left)
            : (double) ( std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right) )/2;
            return median;
        }
        else  // shift partIdx1 left if nums1Left too large, shift right if nums1Right too small
        {
            (nums1Left > nums2Right) ? --partIdx1 : ++partIdx1;
            partIdx2 = (int) (totSize + 1)/2 - partIdx1;
        }
    }
}