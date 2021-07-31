/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int leftH = height(root->left) + 1;
    int rightH = height(root->right) + 1;
    
    return max(leftH,rightH);
}

void printCurrentLevel(node* root, int level) {
    //if(root == NULL)
    if(level == 1) {
        cout<<root->key<<" ";
    }
    if(root->left) {
        printCurrentLevel(root->left, level-1);
    }
    if(root->right) {
        printCurrentLevel(root->right, level-1);
    }
}

void levelOrderTraversal(node* root) {
    if(root == NULL) {
        return;
    }
    int h = height(root);
    
    for(int i=1; i<=h; i++) {
        printCurrentLevel(root, i);
        cout<<endl;
    }
    
}

int main()
{
    struct node* root = new node(20); 
	root->left = new node(8); 
	root->left->left = new node(4); 
	root->left->right = new node(12); 
	root->left->right->left = new node(10); 
	root->left->right->right = new node(14); 
	root->right = new node(22); 
	root->right->right = new node(25); 
	
	levelOrderTraversal(root);
	
    return 0;
}
