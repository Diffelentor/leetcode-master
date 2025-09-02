#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull mask =
    mt19937_64(chrono::steady_clock::now().time_since_epoch().count())();
const int MAX_N = 1e6 + 5;

ull h[MAX_N];
vector<vector<int>> edge(MAX_N);
set<ull> tree;

ull xor_shift(ull x) {  // 哈希函数，使用XOR_SHIFT进行哈希，背下来就好
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

void gethash(int root, int fa) {
    h[root] = 1;
    // cout << "当前节点: " << root << endl;
    for (int son : edge[root]) {
        if (son == fa) {
            continue;
        }
        gethash(son, root);
        h[root] += xor_shift(
            h[son]);  // 哈希的公式是hash[i]=i.val(没有val就用1替代)+sum(hash[i.son])
    }
    tree.insert(h[root]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        // cout << x << y << endl;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    // cout << "开始哈希" << endl;
    gethash(1, 0);
    cout << tree.size();
    return 0;
}