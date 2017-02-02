#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)
#define pb push_back

int n, m, edges;
vector<int> graph[300];
int pair_u[300];
int pair_v[300];

int bfs()
{
        queue<int> myq;
        int dist[300];
        rep(i, 0, n) {
                if (pair_u[i] == -1<<30) {
                        dist[i] = 0;
                        myq.push(i);
                } else {
                        dist[i] = 1<<30;
                }
        }
}

int hopcroft_karp()
{
        rep(i, 0, n) {
                pair_u[i] = -1<<30;
        }

        rep(i, m, n+m) {
                pair_v[i] = -1<<30;
        }

        int matching = 0;

        while (bfs()) {
                rep(i, 0, n) {
                        if (pair_u[i] == -1<<30) {
                                if (dfs(i)) {
                                        matching += 1;
                                }
                        }
                }
        }

        return matching;
}

int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        cin >> edges;

        int origin, destination;
        rep(i, 0, edges) {
                cin >> origin >> destination;
                graph[origin-1].pb(destination-1+m);
                graph[destination-1].pb(origin-1+m);
        }

        cout << hopcroft_karp() << "\n";
        return 0;
}
