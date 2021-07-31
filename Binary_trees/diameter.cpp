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

int diameter(node* root, int &h) {
    if(root == NULL) {
        h=0;
        return 0;
    }
    int lh=0, rh=0;
    
    int ldiameter = diameter(root->left, lh);
    int rdiameter = diameter(root->right, rh);
    
    h = max(lh, rh) + 1;
    
    return max(lh+rh+1, max(ldiameter, rdiameter));
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
	
	int height =0;
	
	cout<<diameter(root, height);
	
    return 0;
}
