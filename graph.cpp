#include <vector>
#include <utility>
#include <tuple>
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

void visualize_unweighted_graph(const std::vector<std::vector<int>>& adj) {
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

void visualize_weighted_graph(const std::vector<std::vector<std::pair<int, int>>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        std::cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            std::cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ")";
            if (j != adj[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int n = 5;
    std::vector<std::tuple<int, int, int>> edges = {{0, 1, 10}, {1, 2, 8}, {2, 4, 6}, {3, 4, 2}, {1, 3, 23}};
    std::vector<std::vector<std::pair<int, int>>> adj = weighted_graph(n, edges);
    visualize_weighted_graph(adj);
    return 0;
}