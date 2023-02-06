class TopVotedCandidate {
    vector<int> winner, times;
public:
    int win = -1, winCount = 0;
    unordered_map<int, int> record;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for(int i = 0; i < persons.size(); i++){
            record[persons[i]]++;
            if(win == -1){
                win = persons[i];
                winCount = 1;
            }
            else if(winCount <= record[persons[i]]){
                win = persons[i];
                winCount = record[persons[i]];
            }
            winner.emplace_back(win);
            this->times.emplace_back(times[i]);
        }
    }
    int q(int t){
        int index = upper_bound(times.begin(), times.end(), t) - times.begin();
        return winner[index - 1];
    }
};