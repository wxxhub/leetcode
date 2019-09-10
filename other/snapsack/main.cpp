#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int weight;
    int profit;
};

struct SearchNode {
    int sum_weight;
    int layer;
    int residual_profit;
};

/*
   []
  /  \
 A   ~A

A: residual_profit = sum_profit
~A: residual_profit = sum_profit  - profit
 */

/*
// 采用插入时排序.
int insertSearchNode(vector<SearchNode> &searchNodes, const vector<Node> &nodes, int layer, int sum_profit, int sum_weight, int M) {
    SearchNode left;
    left.sum_weight = sum_weight + nodes[layer].weight;
    left.layer = layer;
    left.residual_profit = sum_profit;

    SearchNode right;
    right.sum_weight = sum_weight;
    right.layer = layer;
    right.residual_profit = sum_profit - nodes[layer].profit;

    bool left_insert = false;
    bool right_insert = false;
    int size = searchNodes.size();
    for (int i = 0; i < size; ++i) {
        if (!right_insert && searchNodes[i].residual_profit > right.residual_profit) {
            ++size;
            if (right.sum_weight > M) {
                continue;
            }
            vector<SearchNode>::iterator iter = searchNodes.begin() + i;
            searchNodes.insert(iter, 1, right);
            right_insert = true;
        }

        if (!left_insert && searchNodes[i].residual_profit > left.residual_profit) {
            ++size;
            if (left.sum_weight > M) {
                continue;
            }
            vector<SearchNode>::iterator iter = searchNodes.begin() + i;
            searchNodes.insert(iter, 1, left);
            left_insert = true;
        }
    }

    if (!right_insert && right.sum_weight <= M) {
        searchNodes.insert(searchNodes.end(), 1, right);
    }

    if (!left_insert && left.sum_weight <= M) {
        searchNodes.insert(searchNodes.end(), 1, left);
    }
}

// 分支限定法 插入时排序
int branchBrand(const vector<Node> &nodes, int sum_profit, int M) {
    int size = nodes.size();
    vector<SearchNode> searchNodes;
    SearchNode left;
    left.sum_weight = nodes[0].weight;
    left.layer = 0;
    left.residual_profit = sum_profit;

    SearchNode right;
    right.sum_weight = 0;
    right.layer = 0;
    right.residual_profit = sum_profit - nodes[0].profit;

    searchNodes.push_back(right);
    searchNodes.push_back(left);

    SearchNode search_node;
    for (int i = 1; i < size;) {
        search_node = searchNodes[searchNodes.size() - 1];
        searchNodes.pop_back();

        insertSearchNode(searchNodes, nodes, i, search_node.residual_profit, search_node.sum_weight, M);

        i = search_node.layer + 1;
    }

    return search_node.residual_profit;
}
 */

SearchNode popMax(vector<SearchNode> &searchNodes) {
    SearchNode max_node = searchNodes[0];
    int i = 1;
    int delete_site = 0;
    for (; i < searchNodes.size(); ++i) {
        if (max_node.residual_profit < searchNodes[i].residual_profit) {
            max_node = searchNodes[i];
            delete_site = i;
        }
    }

    searchNodes.erase(searchNodes.begin() + delete_site);
    return  max_node;
}

void pushData(vector<SearchNode> &searchNodes, const vector<Node> &nodes, int layer, int sum_profit, int sum_weight, int M) {
    SearchNode left;
    left.sum_weight = sum_weight + nodes[layer].weight;
    left.layer = layer;
    left.residual_profit = sum_profit;

    SearchNode right;
    right.sum_weight = sum_weight;
    right.layer = layer;
    right.residual_profit = sum_profit - nodes[layer].profit;

    if (left.sum_weight <= M)
        searchNodes.push_back(left);

    if (right.sum_weight <= M)
        searchNodes.push_back(right);
}

// 分支限定法 遍历获取最大值
int branchBrand(const vector<Node> &nodes, int sum_profit, int M) {
    int size = nodes.size();
    vector<SearchNode> searchNodes;
    SearchNode left;
    left.sum_weight = nodes[0].weight;
    left.layer = 0;
    left.residual_profit = sum_profit;

    SearchNode right;
    right.sum_weight = 0;
    right.layer = 0;
    right.residual_profit = sum_profit - nodes[0].profit;

    searchNodes.push_back(right);
    searchNodes.push_back(left);

    SearchNode search_node;
    for (int i = 1; i < size;) {
        search_node = popMax(searchNodes);

        pushData(searchNodes, nodes, i, search_node.residual_profit, search_node.sum_weight, M);

        i = search_node.layer + 1;
    }

    return search_node.residual_profit;
}

int process() {
    int M, n;
    int sum_weight = 0;
    int sum_profit = 0;

    cin >> M >> n;

    vector<Node> nodes;

    for (int i = 0; i < n; ++i) {
        Node node;
        cin >> node.weight;
        sum_weight += node.weight;
        nodes.push_back(node);
    }

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].profit;
        sum_profit += nodes[i].profit;
    }

    if (sum_weight <= M) {
        return sum_profit;
    }

    return branchBrand(nodes, sum_profit, M);
}

int main() {
    cout << process() << endl;
    return 0;
}

/*
5
5
3 2 1 3 2
3 3 3 4 4
 */