#include <iostream>
#include <vector>

struct TernaryNode {
    size_t height{0};
    size_t weight{0};
    size_t maxHeight{0};

    TernaryNode *left{nullptr};
    TernaryNode *mid{nullptr};
    TernaryNode *right{nullptr};

    bool operator<(const TernaryNode &other) {
        return this->height < other.height &&
               this->weight < other.weight;
    }

    bool operator>(const TernaryNode &other) {
        return this->height > other.height &&
               this->weight > other.weight;
    }
};

TernaryNode* buildTTree(std::vector<std::pair<size_t, size_t> > &staff,
                        size_t index = 0) {

    TernaryNode *node = new TernaryNode();
    node->height = staff[index].first;
    node->weight = staff[index].second;

    if(index == staff.size() - 1) {
        return node;
    }

    TernaryNode *subNode = buildTTree(staff, index + 1);

    if(*subNode < *node) {
        node->left = subNode;
        node->maxHeight = std::max(node->maxHeight, subNode->maxHeight + 1);
    } else if(*subNode > *node) {
        node->right = subNode;
        node->maxHeight = std::max(node->maxHeight, subNode->maxHeight + 1);
    } else {
        node->mid = subNode;
        node->maxHeight = std::max(node->maxHeight, subNode->maxHeight);
    }
}

size_t calcMaxTowerHt(std::vector<std::pair<size_t, size_t> > &staff) {
    TernaryNode *node = buildTTree(staff);
    return node->maxHeight;
}

int main()
{
    std::vector<std::pair<size_t, size_t> > circusStaff{{60, 230}, {50, 130}, {56, 240},
                                                        {52, 220}, {57, 200}, {53, 160},
                                                        {58, 210}, {51, 140}, {55, 180},
                                                        {59, 220}};
    std::cout << calcMaxTowerHt(circusStaff);
    return 0;
}