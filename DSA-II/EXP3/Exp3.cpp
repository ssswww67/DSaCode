// Traversal

#include<iostream>
#include<stack>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* createTree() {
    int data;
    cout << "Enter the Value (-1 for no Node): ";
    cin >> data;
    if (data == -1) return NULL;
    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = createTree();
    cout << "Enter right child of " << data << endl;
    root->right = createTree();
    return root;
}
void inorderRecursive(Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}
void preorderRecursive(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}
void postorderRecursive(Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}
// Inorder Traversal (Left -> Root -> Right) Non-Recursive
void inorderNonRecursive(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
// Preorder Traversal (Root -> Left -> Right) Non-Recursive
void preorderNonRecursive(Node* root) {
    if (root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}
// Postorder Traversal (Left -> Right -> Root) Non-Recursive
void postorderNonRecursive(Node* root) {
    if (root == nullptr) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
int main() {
    Node* root = createTree();
    // 10 1 7 -1 -1 5 15 -1 -1 -1 2 9 -1 19 -1 -1 11 -1 -1
    cout << "\nPrinting Recursive Inorder Traversal : " << endl;
    inorderRecursive(root);
    cout << "\n\nPrinting Recursive Preoder Traversal : " << endl;
    preorderRecursive(root);
    cout << "\n\nPrinting Recursive Postorder Traversal : " << endl;
    postorderRecursive(root);
    cout << "\n\nPrinting Non-Recursive Inorder Traversal : " << endl;
    inorderNonRecursive(root);
    cout << "\n\nPrinting Non-Recursive Preoder Traversal : " << endl;
    preorderNonRecursive(root);
    cout << "\n\nPrinting Non-Recursive Postorder Traversal : " << endl;
    postorderNonRecursive(root);
    return 0;
}