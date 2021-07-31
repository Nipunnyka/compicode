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

void rightView(node* root) {
    if(root == NULL) 
        return;
    
    queue<node*> s;
    s.push(root);

    while(!s.empty()) {
        int count = s.size();
        int temp = count;
        while(count) {
            node* t = s.front();
            s.pop();
            
            if(count == temp) {
                cout<<t->key<<" ";
            }
            
            if(t->left)
                s.push(t->left);
            if(t->right)
                s.push(t->right);
                
            count --;
        }
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
	
	int height =0;
	
	rightView(root);
	
    return 0;
}
