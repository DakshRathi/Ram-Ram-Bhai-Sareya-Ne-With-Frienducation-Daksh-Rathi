class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Sorting points by end values
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

        int arrows = 1;
        int currentEnd = points[0][1];

        for (int i = 1; i < points.size(); ++i) 
        {
            if (points[i][0] > currentEnd)
            {
                arrows++;
                currentEnd = points[i][1];
            }
        }

        return arrows;
    }
};