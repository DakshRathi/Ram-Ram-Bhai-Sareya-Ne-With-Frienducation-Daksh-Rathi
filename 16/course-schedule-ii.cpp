class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(numCourses == 1) return {0};
        vector<int> ans, numPrerequis(numCourses);
        vector<vector<int>> nxtCourse(numCourses);
        for(auto i : prerequisites)
        {
            nxtCourse[i[1]].push_back(i[0]);
            numPrerequis[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(numPrerequis[i] == 0) q.push(i);
        }
        while(size(q))
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto nextCourse : nxtCourse[cur]) 
            {
                if(--numPrerequis[nextCourse] == 0) q.push(nextCourse);
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};   
    }
};