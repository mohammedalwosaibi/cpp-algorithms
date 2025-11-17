#include <vector>

std::vector<std::vector<int>> unweighted_graph(int n, std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(n);

    for (auto& [out, in] : edges) {
        adj[out].push_back(in);
    }

    return adj;
}

int main() {
    return 0;
}