class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(int i = 1; i<=n; i++)adj[i] = {};
        for(auto &e: times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int>vis(n+1, 0), dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minq;
        minq.push({0, k});

        while(!minq.empty()){
            auto u = minq.top();
            minq.pop();
            if(vis[u.second])continue;
            vis[u.second] = true;
            dist[u.second] = min(dist[u.second], u.first);
            for(auto v: adj[u.second]){
                if(!vis[v.first]){
                    minq.push({dist[u.second]+v.second, v.first});
                }
            }
        }
        int d = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i])return -1;
            d = max(d, dist[i]);
        }
        return d;
    }
};
