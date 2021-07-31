#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define pb push_back

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

bool isBalanced(node* root, int &h) {
    if(root == NULL) {
        h=0;
        return true;
    }
    
    int lh=0, rh=0;
    bool l = isBalanced(root->left, lh);
    bool r = isBalanced(root->right, rh);
    
    h=max(rh, lh) + 1;
    
    if(abs(rh-lh)>=2)
        return false;
    
    return l && r;
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
	
	cout<<isBalanced(root, height);
	
    return 0;
}
