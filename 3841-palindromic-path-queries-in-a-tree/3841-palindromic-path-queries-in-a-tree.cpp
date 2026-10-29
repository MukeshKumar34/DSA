
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), pref(n);
        vector<int> bit(n + 2);
        vector<int> mask(n);

        for (int i = 0; i < n; i++)
            mask[i] = 1 << (s[i] - 'a');

        int timer = 0;

        // Iterative DFS: avoids stack overflow on a long chain.
        vector<tuple<int, int, bool>> st;
        st.push_back({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            up[0][u] = p;
            pref[u] = (u == 0 ? 0 : pref[p]) ^ mask[u];

            for (int k = 1; k < LOG; k++)
                up[k][u] = up[k - 1][up[k - 1][u]];

            st.push_back({u, p, true});

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                st.push_back({v, u, false});
            }
        }

        // Fenwick tree with XOR range updates.
        auto add = [&](int idx, int val) {
            for (int i = idx; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto sum = [&](int idx) {
            int res = 0;
            for (int i = idx; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        auto updateSubtree = [&](int u, int delta) {
            add(tin[u], delta);
            add(tout[u] + 1, delta);
        };

        auto getPrefix = [&](int u) {
            return pref[u] ^ sum(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            string arg;

            stringstream ss(q);
            ss >> type >> u >> arg;

            if (type == "update") {
                char c = arg[0];

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                updateSubtree(u, delta);

                mask[u] = newMask;
                s[u] = c;
            } 
            else {
                int v = stoi(arg);
                int w = lca(u, v);

                int pathMask =
                    getPrefix(u) ^
                    getPrefix(v) ^
                    mask[w];

                // At most one set bit means palindrome possible.
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
