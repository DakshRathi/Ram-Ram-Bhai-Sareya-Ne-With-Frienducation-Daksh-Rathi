class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);

        int total_diff = 0, excess_fuel = 0, idx = 0, n = gas.size();
        for(int i = 0; i < n; i++)
        {
            total_diff += gas[i] - cost[i];
            excess_fuel += gas[i] - cost[i];
            if(excess_fuel < 0)
            {
                excess_fuel = 0;
                idx = i + 1;
            }
        }
        return (total_diff < 0) ? -1 : idx;
    }
};