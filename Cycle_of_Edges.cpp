#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n, e;
    cin >> n >> e;
    
    dsuInitialize(n);
    
    int cycleEdges = 0;
    
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        
        int leaderU = dsuFind(u);
        int leaderV = dsuFind(v);
    
        if (leaderU == leaderV) {
            cycleEdges++;
        } else {
            dsuUnionBySize(u, v);
        }
    }
    
    cout << cycleEdges << endl;
    
    return 0;
}
