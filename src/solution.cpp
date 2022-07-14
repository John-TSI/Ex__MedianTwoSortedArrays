#include"../inc/solution.hpp"


double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    auto n1Low{nums1.begin()}, n1High{nums1.end()-1}, n2Low{nums2.begin()}, n2High{nums2.end()-1};
    int totLen = nums1.size() + nums2.size();
    int shifts = totLen/2 - ( (totLen%2) ? 0 : 1 );
    double median{0}, leftOfMedian{0}, rightOfMedian{0};
    bool n1Spent{false}, n2Spent{false};

    int shiftCounter{0};

    // find median for odd total elements
    while(shiftCounter < shifts && totLen%2)
    {
        if(n1Low == n1High){ n1Spent == true; }
        if(n2Low == n2High){ n2Spent == true; }

        if(*n1Low == *n2Low)
        { 
            if(n1Spent)         { ++n2Low; shiftCounter+=2; }
            else if(n2Spent)    { ++n1Low; shiftCounter+=2; }
            else                { ++n1Low; ++n2Low; shiftCounter+=2; } 
        }
        else
        {
            if(n1Spent)         { ++n2Low; ++shiftCounter; }
            else if(n2Spent)    { ++n1Low; ++shiftCounter; }
            else                { (*n1Low < *n2Low) ? ++n1Low : ++n2Low; ++shiftCounter; } 
        }
    }
    if(n1Spent || n2Spent){ median = (n1Spent) ? *n2Low : *n1Low; }
    else{ median = std::min(*n1Low, *n2Low); }


    // find median for even total elements
/*     while(shiftCounter < shifts && !(totLen%2))
    {
        if(n1Low == n1High){ n1Spent == true; }
        if(n2Low == n2High){ n2Spent == true; }

        if(*n1Low == *n2Low) // edit from here
        { 
            if(n1Spent){ ++n2Low; shiftCounter+=2; }
            else if(n2Spent){ ++n1Low; shiftCounter+=2; }
            else{ ++n1Low; ++n2Low; shiftCounter+=2; } 
        }
        else{ (*n1Low < *n2Low) ? ++n1Low : ++n2Low; ++shiftCounter; }
    }
    if(n1Spent || n2Spent){ median = (n1Spent) ? *n2Low : *n1Low; }
    else{ median = std::min(*n1Low, *n2Low); } */

    return median;
}