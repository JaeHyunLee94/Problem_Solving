#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int findt(vector<int>& tree, int a) {
    if (tree[a] == a) return a;
    else {
        int y = findt(tree, tree[a]);
        tree[a] = y;
        return y;
    }
}



void uniont(vector<int>& tree, int a, int b) {
    int aroot = findt(tree, a);
    int broot = findt(tree, b);
    if (aroot == broot) return;
    else tree[aroot] = broot;

}



struct edge {
    int ver1;
    int ver2;
    int weight;
};


bool operator < (const edge& a, const edge& b) {
    return a.weight > b.weight;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, ver1, ver2, weight, cnt = 0, ans = 0;
    cin >> V >> E;

    priority_queue<edge> pq;
    vector<int> parent(V + 1,0);
    for (int i = 1; i <= V; i++) parent[i] = i;

    for (int i = 0; i < E; i++) {
        cin >> ver1 >> ver2 >> weight;
        pq.push(edge{ ver1,ver2,weight });
    }

    while(cnt<V-1) {
        edge next = pq.top();
        pq.pop();
        if (findt(parent, next.ver1) != findt(parent, next.ver2)) {
            uniont(parent, next.ver1, next.ver2);
            cnt++;
            ans += next.weight;
        }

    }


    cout << ans << '\n';




    return 0;
}
