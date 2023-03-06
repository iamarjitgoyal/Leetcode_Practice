class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int, int>> exam_scores;
        for (int i = 0; i < score.size(); i++) {
            exam_scores.push_back(make_pair(score[i][k], i));
        }
        sort(exam_scores.rbegin(), exam_scores.rend());
        vector<vector<int>> result;
        for (int i = 0; i < exam_scores.size(); i++) {
            result.push_back(score[exam_scores[i].second]);
        }
        return result;
    }
};
