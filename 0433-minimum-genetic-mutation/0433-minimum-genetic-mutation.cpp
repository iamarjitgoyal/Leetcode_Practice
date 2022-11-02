class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        vector<char> choice = {'A', 'C', 'G', 'T'};
        int count = 0;
        unordered_set<string> bn;
        unordered_set<string> visited;
        for(auto a : bank)
            bn.insert(a);
        q.push(start);
        visited.insert(start);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                if(q.front() == end)
                    return count;
                for(int i=0; i<8; i++)
                {
                    string tempMut = q.front();
                    for(int j = 0; j<4; j++)
                    {
                        tempMut[i] = choice[j];
                        if(visited.find(tempMut) == visited.end() && bn.find(tempMut) != bn.end())
                        {
                            q.push(tempMut);
                            visited.insert(tempMut);
                        }     
                    }
                }
                q.pop();
            }
            count++;
        }
        return -1;
    }
};
