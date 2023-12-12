#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *right, *left;
    TreeNode(int n)
    {
        data = n;
        left = right = NULL;
    }
};
class BinarySearchTree
{
private:
    TreeNode *root;

public:
    // Constructor
    BinarySearchTree()
    {
        root = NULL;
    }

    // Insert a value into the BST
    void insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        TreeNode *current = root;
        while (current != NULL)
        {
            if (value < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            else if (value > current->data)
            {
                if (current->right == nullptr)
                {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
            else
            {
                // Duplicate values are not allowed in BST
                delete newNode;
                break;
            }
        }
    }

    bool searchInBST(int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != nullptr)
            {
                if (data > temp->data)
                {
                    temp = temp->right;
                }
                else if (data < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    return true; // Node found
                }
            }
        }
        return false; // Node not found
    }
    void inOrderTraversalHelper(TreeNode *root)
    {
        // LNR -->> left print node and move to right node
        if (root != NULL)
        {
            inOrderTraversalHelper(root->left);
            cout << root->data << " ";
            inOrderTraversalHelper(root->right);
        }
    }
    void inOrderTraversal()
    {
        inOrderTraversalHelper(root);
    }
    void preOrderTraversalHelper(TreeNode *root)
    {
        // NLR -->> print Node move to left and move to right node
        if (root != NULL)
        {
            cout << root->data << " ";
            postOrderTraversalHelper(root->left);
            postOrderTraversalHelper(root->right);
        }
    }
    void preOrderTraversal()
    {
        preOrderTraversalHelper(root);
    }
    void postOrderTraversalHelper(TreeNode *root)
    {
        // LRN -->> move to left and move to right node print Node
        if (root != NULL)
        {
            postOrderTraversalHelper(root->left);
            postOrderTraversalHelper(root->right);
            cout << root->data << " ";
        }
    }
    void postOrderTraversal()
    {
        postOrderTraversalHelper(root);
    }
    void levelOrderTraversal()
    {
        if (root == nullptr)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
};

int main()
{
    BinarySearchTree b1;
    b1.insert(50);
    b1.insert(30);
    b1.insert(70);
    b1.insert(20);
    b1.insert(40);
    b1.insert(60);
    b1.insert(80);
    int n = 100;
    if (b1.searchInBST(n))
    {
        cout << n << " Found" << endl;
    }
    else
    {
        cout << n << " is Not Found" << endl;
    }
    cout << "\n\nPrinting Level Order Traversal" << endl;
    b1.levelOrderTraversal();
    cout << "\n\nPrinting InOrder Traversal" << endl;
    b1.inOrderTraversal();
    cout << "\n\nPrinting PostOrder Traversal" << endl;
    b1.postOrderTraversal();
    cout << "\n\nPrinting PreOrder Traversal" << endl;
    b1.preOrderTraversal();

    return 0;
}
