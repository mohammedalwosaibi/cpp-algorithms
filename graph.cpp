#include <vector>
#include <utility>
#include <iostream>

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

void visualize_unweighted_graph(std::vector<std::vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        std::cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            std::cout << adj[i][j];
            if (j != adj[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int n = 5;
    std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 4}, {3, 4}, {1, 3}};
    std::vector<std::vector<int>> adj = unweighted_graph(n, edges);
    visualize_unweighted_graph(adj);
    return 0;
}