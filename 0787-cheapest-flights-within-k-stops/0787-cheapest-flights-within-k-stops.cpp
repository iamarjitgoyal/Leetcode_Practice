class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector< pair<int,int> >> graph(n);
        for( auto edge: flights ){
            graph[edge[0]].push_back( {edge[1],edge[2]} );
        }
        
        vector<int> dist(n,pow(10,4)*n) , prev(n);
        dist[src] = 0;
        prev = dist;
        k++;
        while( k-- ){
            for( int i = 0 ; i < n ; i++ ){
                for( int j = 0; j < graph[i].size(); j++ ){
                    int index = graph[i][j].first;
                    int value = graph[i][j].second;
                    // at x'th step there can be more than one updates
                    // so we compare the update value, of the index 
                    // gettting updated 
                    if( dist[ index ] > prev[i] + value ){
                        dist[ index ] = prev[i] + value;
                    }
                }
            }
            prev = dist;
        }
        if( prev[dst] == pow(10,4)*n ){
            return -1;
        }
        return prev[dst];
    }
};
