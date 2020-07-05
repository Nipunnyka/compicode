#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

struct node{


//ASSUMES THAT YBOTH KEYS WILL BE FOUND 

node  findLCA(node *root, int key1, int key2){
    if(root=NULL){
        return NULL;
    }
    if(root->data==key1 || root->data==key2){
        return root;
    }

    node *LCAleft=findLCA(root->left, key1, key2);
    node *LCAright=findLCA(root->right, key1, key2);

    if(LCAleft&&LCAright)
        return root;
    
    return LCAleft==NULL? LCAleft: LCAright;
    
}

    int data;
    node *left, *right;
    node(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};

int main(){
    node *root=new node(5);
    root->left=new node(4);
    root->right=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(0);
    root->right->left=new node(1);


    return 0;
}