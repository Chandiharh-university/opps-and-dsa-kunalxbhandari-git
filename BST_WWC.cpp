#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // Create a new node if root is empty
    }

    if (value < root->data) {
        root->left = insert(root->left, value); // Insert into the left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Insert into the right subtree
    }

    return root; // Return unchanged root
}

// Function to perform in-order traversal (Left -> Root -> Right)
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false; // Value not found
    }

    if (root->data == value) {
        return true; // Value found
    } else if (value < root->data) {
        return search(root->left, value); // Search in the left subtree
    } else {
        return search(root->right, value); // Search in the right subtree
    }
}

// Function to find the minimum value in the BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root; // Tree is empty
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value); // Search in the left subtree
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value); // Search in the right subtree
    } else {
        // Node to be deleted found

        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Main function to demonstrate BST operations
int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Search for a value
    int valueToSearch = 40;
    if (search(root, valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the BST." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the BST." << endl;
    }

    // Delete a node
    int valueToDelete = 50;
    root = deleteNode(root, valueToDelete);
    cout << "In-order Traversal after deleting " << valueToDelete << ": ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
