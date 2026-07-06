class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        //custom sort
        auto cmp = [] (vector<int> &arr1, vector<int> &arr2)
        {
            if(arr1[0] == arr2[0])
                return arr1[1] > arr2[1];
            else
                return arr1[0] < arr2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = 0, maxend = INT_MIN;
        for(auto it : intervals)
        {
            if(it[1] > maxend) //outside range
                ans++, maxend = it[1];
        }

        return ans;
    }
};