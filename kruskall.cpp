#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define FOR(i, j, k)for(int i=j;i<k;++i)

using namespace std;

int ranks[100000];
int parent[100000];

struct edge {
    int x, y, z;
};

vector<edge> edges;

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int union_find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x]=union_find(parent[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        parent[rooty] = rootx;
    } else {
        ranks[rooty]++;
        parent[rootx] = rooty;
    }
}

int main()
{
    int n;
    int m, origin, destination, weight;
    while (cin >> n >> m) {
        edge e;
        FOR(i, 0, m) {
            scanf("%d", &e.x);
            scanf("%d", &e.y);
            scanf("%d", &e.z);
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), myfunc);
        FOR(i, 0, m+2) {
            parent[i] = i;
        }
        memset(ranks, 0, sizeof ranks);

        int edges_size = edges.size();
        vector<edge> mst;
        FOR(i, 0, edges_size) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                mst.push_back(edges[i]);
            }
        }

        printf("mst:\n");
        for (auto it : mst) {
            printf("[%d] -> [%d] = %d\n", it.x, it.y, it.z);
        }
    }
    return 0;
}
