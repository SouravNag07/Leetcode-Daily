class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Creating the connected components
        vector<int> comp(n,0); 
        //comp[i] shows vertex i belongs to which connected component

        int comp_id = 0;
        comp[0] = comp_id;

        for(int i=1; i<n; i++)
        {
            //edge does not exists, next connected component
            if(nums[i] - nums[i-1] > maxDiff)
                comp_id++; //increase component id
            //assigning component id to the vertex
            comp[i] = comp_id;
        }

        vector<bool> ans;
        for(auto q : queries)
        {
            int u = q[0], v = q[1];
            //true, if belong to the same component id
            ans.push_back(comp[u] == comp[v]);
        }

        return ans;
    }
};