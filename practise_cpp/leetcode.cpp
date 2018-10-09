
#include <iostream>
#include <vector>
using namespace std;

/* 4.求两个排序数组的中位数 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int m = nums1.size();
    int n = nums2.size();
    
    if (0 == m && 0 == n)
        return 0.0;
    
    vector<int> result;
    int mloop = 0, nloop = 0;
    
    while (mloop != m && nloop != n)
    {
        if (nums1[mloop] < nums2[nloop])
            result.push_back(nums1[mloop++]);
        else
            result.push_back(nums2[nloop++]);
    }

    if (mloop != m)
        result.insert(result.begin() + mloop + nloop, nums1.begin() + mloop, nums1.end());
    else
        result.insert(result.begin() + mloop + nloop, nums2.begin() + nloop, nums2.end());

    if (((m + n) & 0x1) == 0x1)
        return result[(m + n) / 2];
    else
        return (result[((m + n) / 2)] + result[(m + n) / 2 - 1]) / 2.0;
}


int main()
{
	vector<int> a;
	vector<int> b;
	a.push_back(1);
	b.push_back(2);
	b.push_back(3);
	cout << findMedianSortedArrays(a, b) << endl;
    return 1;
}
