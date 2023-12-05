#include <bits/stdc++.h>

using namespace std;

class Tree {
private:
  int data;
  Tree *left;
  Tree *right;

public:
  Tree *createNode(int data) {
    Tree *temp = new Tree;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }

  Tree *insertNode(Tree *root, int data) {
    if (root == NULL) {
      return createNode(data);
    }

    if (data < root->data) {
      root->left = insertNode(root->left, data);
    } else if (data > root->data) {
      root->right = insertNode(root->right, data);
    }

    return root;
  }

}; // bst implementation, not finished yet

int main() { return 0; }