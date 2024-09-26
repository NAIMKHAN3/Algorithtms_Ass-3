#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5 + 5;
int parent[N];
int groupSize[N];

void dsuInitialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        groupSize[i] = 1;
    }
}

int dsuFind(int node) {
    if (parent[node] == -1)
        return node;
    return parent[node] = dsuFind(parent[node]);
}

void dsuUnionBySize(int node1, int node2) {
    int leaderA = dsuFind(node1);
    int leaderB = dsuFind(node2);
    if (leaderA != leaderB) {
        if (groupSize[leaderA] > groupSize[leaderB]) {
            parent[leaderB] = leaderA;
            groupSize[leaderA] += groupSize[leaderB];
        } else {
            parent[leaderA] = leaderB;
            groupSize[leaderB] += groupSize[leaderA];
        }
    }
}

class Edge {
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    while (e--) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    dsuInitialize(n);

    sort(edges.begin(), edges.end(), cmp);

    ll totalCost = 0;
    ll edgesUsed = 0;

    for (Edge ed : edges) {
        int leaderU = dsuFind(ed.u);
        int leaderV = dsuFind(ed.v);

        if (leaderU != leaderV) {
            dsuUnionBySize(ed.u, ed.v);
            totalCost += ed.w;
            edgesUsed++;
        }
    }

    if (edgesUsed == n - 1) {
        cout << totalCost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
