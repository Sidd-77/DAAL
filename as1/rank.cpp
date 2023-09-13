#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
    int leftSize;
};
 
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->leftSize = 0;
    return temp;
}

Node* track(Node*& root, int data)
{
    if (!root)
        return newNode(data);

    if (data <= root->data) {
        root->left = track(root->left, data);
        root->leftSize++;
    }
    else
        root->right = track(root->right, data);
    return root;
}

int getRank(Node* root, int x)
{
    if (root->data == x)
        return root->leftSize;

    if (x < root->data) {
        if (!root->left)
            return -1;
        else
            return getRank(root->left, x);
    }

    else {
        if (!root->right)
            return -1;
        else {
            int rightSize = getRank(root->right, x);
              if(rightSize == -1 ) return -1;
            return root->leftSize + 1 + rightSize;
        }
    }
}

int main()
{
    int arr[] = { 5, 1, 4, 4, 5, 9, 7, 13, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = track(root, arr[i]);
    cout << "Rank of " << x << " in stream is: "
         << getRank(root, x) << endl;
    x = 3;
    cout << "Rank of " << x << " in stream is: "
         << getRank(root, x) << endl;
    x = 4;
    cout << "Rank of " << x << " in stream is: "
         << getRank(root, x) << endl;
    return 0;
}

