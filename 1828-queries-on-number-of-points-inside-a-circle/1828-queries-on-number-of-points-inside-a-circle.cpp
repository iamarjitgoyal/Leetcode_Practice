class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for (const auto& query : queries) {
            int xj = query[0];
            int yj = query[1];
            int rj = query[2];
            int count = 0;
            for (const auto& point : points) {
                int xi = point[0];
                int yi = point[1];
                if ((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= rj * rj) {
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};