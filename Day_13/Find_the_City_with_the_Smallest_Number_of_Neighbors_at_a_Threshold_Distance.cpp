class Solution {
    void dijkstra(unordered_map<int, vector<pair<int, int>>>& adj, int src,
                  vector<int>& dis) {
        set<pair<int, int>> st;
        dis[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = st.begin();
            pair<int, int> temp = *it;
            int dist = temp.first;
            int node = temp.second;
            st.erase(it);

            for (pair<int, int> it : adj[node]) {
                int nbrnode = it.first;
                int nbrdist = it.second;

                if (dist + nbrdist < dis[nbrnode]) {
                    // dis[nbrnode]= dist+nbrdist;
                    // st.insert({dis[nbrnode] , nbrnode});
                    auto prev = st.find({dis[nbrnode], nbrnode});
                    if (prev != st.end()) {
                        st.erase(prev);
                    }
                    dis[nbrnode] = dist + nbrdist;
                    st.insert({dis[nbrnode], nbrnode});
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        int ans = 0;
        int count = INT_MAX;


        for (int i = 0; i < n; i++) {
            vector<int> dis(n, INT_MAX);

        dijkstra(adj, i, dis);

            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && abs(dis[i]-dis[j]) <= distanceThreshold) {
                    temp++;
                }
            }
            if (count >= temp) {
                count = temp;
                ans = i;
            }
        }
        return ans;
    }
};