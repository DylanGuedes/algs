#include <bits/stdc++.h>

using namespace std;

int graph[2020][2020];
int n, m;
int residual[2020][2020];
int visited[2020];
int parent[2020];

#define rep(i, j, k)for(int i=j;i<k;++i)

int bfs(int origin, int destination)
{
        memset(visited, 0, sizeof visited);
        queue<int> myq;
        myq.push(origin);
        visited[origin]=1;
        while (not myq.empty()) {
                int idx = myq.front();
                myq.pop();
                rep(i, 0, n) {
                        if (residual[idx][i] && !visited[i]) {
                                myq.push(i);
                                visited[i]=1;
                                parent[i]=idx;
                        }
                }
        }

        return visited[destination];
}

int ford_fulkerson(int origin, int destination)
{
        rep(i, 0, n) rep(j, 0, n) residual[i][j] = graph[i][j];

        int maxflow = 0;
        while (bfs(origin, destination)) {
                int residual_capacity = 1<<30;
                for (int idx=destination; idx!=origin; idx=parent[idx]) {
                        residual_capacity = min(residual_capacity, residual[parent[idx]][idx]);
                }

                for (int idx=destination; idx!=origin; idx=parent[idx]) {
                        residual[parent[idx]][idx] = max(0, residual[parent[idx]][idx]-residual_capacity);
                        residual[idx][parent[idx]] = residual_capacity;
                }
                maxflow+=residual_capacity;
        }
        return maxflow;
}

int main()
{
        ios::sync_with_stdio(false);
        memset(graph, 0, sizeof graph);
        int origin, destination, weight;

        cin >> n >> m;
        rep(j, 0, m) {
                cin >> origin >> destination >> weight;
                graph[origin][destination] = weight;
        }

        cin >> origin >> destination;

        cout << "max flow: " << ford_fulkerson(origin, destination) << "\n";

        return 0;
}

