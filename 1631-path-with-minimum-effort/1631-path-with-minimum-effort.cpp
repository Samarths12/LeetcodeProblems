class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int> >, vector<pair<int,pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
        vector<vector<int> > dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto frontNode = pq.top();
            pq.pop();
            int frontNodeDiff = frontNode.first;
            int x = frontNode.second.first;  // x coordinate
            int y = frontNode.second.second; // y coordinate

            if(x == heights.size()-1 && y == heights[0].size() - 1) {
                return dist[x][y];
            }
            //else wale case me sari dirtn me call kro
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0 ; i < 4 ; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < heights.size() && newY >= 0 && newY < heights[0].size()) {
                    int currDiff = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDiff, currDiff);
                    if(newMax < dist[newX][newY]) {
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};