#include <vector>

std::vector<std::vector<int>> unweighted_graph(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(n);

    for (const auto& [out, in] : edges) {
        adj[out].push_back(in);
    }

    return adj;
}

std::vector<std::vector<std::pair<int, int>>> weighted_graph(int n, const std::vector<std::tuple<int, int, int>>& edges) {
    std::vector<std::vector<std::pair<int, int>>> adj(n);

    for (const auto& [out, in, weight] : edges) {
        adj[out].push_back({in, weight});
    }

    return adj;
}

int main() {
    return 0;
}