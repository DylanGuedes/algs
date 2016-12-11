#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
vector<ii> graph[15];
int has_conv[15];
int n, m;
#define rep(i, j, k)for(int i=j;i<k;++i)

ii dijkstra(int origin)
{
        priority_queue<ii, vector<ii>, greater<ii> > myq;
        int dist[15];
        rep(i, 0, n) {
                dist[i] = 0xfffffff;
        }
        dist[origin] = 0;
        myq.push(ii(0, origin));
        while (not myq.empty()) {
                int idx, value;
                tie(value, idx) = myq.top(); myq.pop();
                if (has_conv[idx]) {
                        return ii(idx, dist[idx]);
                }
                for (auto it : graph[idx]) {
                        if (dist[it.second] > it.first+value) {
                                dist[it.second] = it.first+value;
                                myq.push(ii(dist[it.second], it.second));
                        }
                }
        }
        return ii(-1, 0xffffff);
}

int main()
{
        ios::sync_with_stdio(false);
        int origin, destination, weight;
        cin >> n >> m;
        rep(i, 0, n) {
                cin >> has_conv[i];
        }

        rep(i, 0, m) {
                cin >> origin >> destination >> weight;
                graph[origin].push_back(ii(weight, destination));
                graph[destination].push_back(ii(weight, origin));
        }

        cin >> origin;

        ii ans = dijkstra(origin);
        if (ans.first == -1) {
                cout << "Por favor, fale mais próximo ao microfone.\n";
        } else {
                cout << "O nó com decodificação conhecida mais próximo é o " << ans.first <<", com distancia " << ans.second << "\n";
        }
        return 0;
}
