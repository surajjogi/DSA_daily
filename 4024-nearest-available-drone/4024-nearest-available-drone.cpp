class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDist = INT_MAX;
        int ans = -1;
        for (int i = 0; i < drones.size(); i++) {
            int dis =
                abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);
            if (dis <= drones[i][2] && dis < minDist)
            {
                minDist = dis;
                ans = i;
            }
            
        }
        return ans;
    }
};