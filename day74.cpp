#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;   

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }   
};

class BST{
    public:
    Node *root;
    
    BST()
    {
        root = NULL;
    }
    
    Node *createTree(Node *root , int value)
    {
        if(root == NULL)
        {
            return new Node(value);
        }
        else if(root->data >= value)
        {
            root->left = createTree(root->left , value);
        }
        else if(root->data < value)
        {
            root->right = createTree(root->right , value);
        }
        return root;
    }
    
    bool isLeafNode(Node *root)
    {
        if(root == NULL)
        {
            return false;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int sum = 0;
    void leftSum(Node *root)
    {
        if(root == NULL)
        {
            return;
        }
        if(isLeafNode(root->left))
        {
            sum = sum + root->left->data;
        }
        leftSum(root->left);
        leftSum(root->right);
    }
};

int main() {
    int T;
    cin>>T;
    
    int j=0;
    while(j<T)
    {
        BST b;
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0 ; i<n ; i++)
        {
            int value = arr[i];
            cin>>value;
            b.root = b.createTree(b.root , value);
        }
        
        b.leftSum(b.root);
        
        int ans = b.sum;
        cout<<ans<<endl;
        j++;
    }
    return 0;
}