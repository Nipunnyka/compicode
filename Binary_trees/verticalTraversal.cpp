/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

void verticalTraversal(node* root) {
    if(root == NULL) 
        return;
    
    unordered_map<int, vector<node*>> distanceMap;
    queue<pair<node*, int>> q;
    
    q.push(mp(root, 0));
    
    while(!q.empty()) {
        pair<node*, int> t = q.front();
        q.pop();
        
        if(distanceMap.find(t.se) != distanceMap.end())
            distanceMap[t.se].pb(t.fi);
        else{
            vector<node*> v;
            v.pb(t.fi);
            distanceMap[t.se] = v;
        }
        
        if(t.fi->left)
            q.push(mp(t.fi->left, t.se-1));
            
        if(t.fi->right)
            q.push(mp(t.fi->right, t.se+1));
        
    }
    
    for(auto x: distanceMap) {
        cout<<x.fi<<": ";
        for(auto y: x.se) {
            cout<<y->key<<", ";
        }
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
	
	int height =0;
	
	verticalTraversal(root);
	
    return 0;
}
