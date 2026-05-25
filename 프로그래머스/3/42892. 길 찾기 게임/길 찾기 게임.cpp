#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    int x, y;
    Node* left = nullptr;
    Node* right = nullptr;
};

bool cmp(const Node& a, const Node& b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void InsertNode(Node* parent, Node* child)
{
    if(child->x < parent->x)
    {
        if(parent->left == nullptr)
            parent->left = child;
        else
            InsertNode(parent->left, child);
    }
    else
    {
        if(parent->right == nullptr)
            parent->right = child;
        else
            InsertNode(parent->right, child);
    }
}

void Preorder(Node* root, vector<int>& res)
{
    if(root == nullptr) return;
    res.push_back(root->id);
    Preorder(root->left, res);
    Preorder(root->right, res);
}

void Postorder(Node* root, vector<int>& res)
{
    if(root == nullptr) return;
    Postorder(root->left, res);
    Postorder(root->right, res);
    res.push_back(root->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int n = nodeinfo.size();
    vector<Node> nodes(n);
    for(int i=0; i<n; i++)
        nodes[i] = {i+1, nodeinfo[i][0], nodeinfo[i][1]};

    sort(nodes.begin(), nodes.end(), cmp);
    Node* root = &nodes[0];
    
    for(int i=1; i<n; i++)
        InsertNode(root, &nodes[i]);        

    vector<int> pre;
    vector<int> post;
    Preorder(root, pre);
    Postorder(root, post);
    return {pre, post};
}