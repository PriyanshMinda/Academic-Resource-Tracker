#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 6;
unordered_set<int> primesFound;
vector<vector<int>> graph;
vector<int> values;
vector<bool> isPrime(1000000, true);

void buildSieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 1000000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < 1000000; j += i)
                isPrime[j] = false;
        }
    }
}

void dfs(int node, int num, int depth) {
    if (depth > MAX_DIGITS)
        return;

    num = num * 10 + values[node];
    if (num >= 2 && isPrime[num])
        primesFound.insert(num);

    for (int neighbor : graph[node]) {
        dfs(neighbor, num, depth + 1);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    values.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> values[i];

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    buildSieve();
    dfs(1, 0, 1);

    cout << primesFound.size() << endl;
    return 0;
}