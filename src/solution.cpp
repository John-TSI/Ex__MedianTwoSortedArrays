#include"../inc/solution.hpp"


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int>::iterator n1Low{nums1.begin()}, n1High{nums1.end()-1}, n2Low{nums2.begin()}, n2High{nums2.end()-1};
    int shifts = ( nums1.size() + nums2.size() )/2 - 1;
    double leftOfMedian{0}, rightOfMedian{0};

    int shiftCounter{0};
    while(n1Low != n1High && n2Low != n2High)
    {
        if(shiftCounter == shifts){ break; }
        else
        {
            if(*n1Low == *n2Low){ ++n1Low; ++n2Low; ++shiftCounter; }
            else
            {
                (*n1Low < *n2Low) ? ++n1Low : ++n2Low;
            }

            if(*n1High == *n2High){ --n1High; --n2High; ++shiftCounter; }
            else
            {
                (*n1High < *n2High) ? --n2High : --n1High;
            }
        }
        ++shiftCounter;
    }
/*     if(n2Low == n2High)
    {
        leftOfMedian = (*n1Low < *n2Low) ? *n1Low : *n2Low;
        rightOfMedian = (*n1High > *n2High) ? *n1High : *n2High;
    }
    else
    {
        leftOfMedian = (*n1Low < *n2Low) ? *n2Low : *n1Low;
        rightOfMedian = (*n1High > *n2High) ? *n2High : *n1High;
    } */
    leftOfMedian = (*n1Low < *n2Low) ? *n1Low : *n2Low;
    rightOfMedian = (*n1High > *n2High) ? *n1High : *n2High;
    return (leftOfMedian + rightOfMedian)/2;
}