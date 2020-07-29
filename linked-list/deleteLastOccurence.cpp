#include<bits/stdc++.h>

using namespace std;

struct node{
    int key;
    node* next;
    node(){
        this->key=0;
        this->next=NULL;
    }
};

struct node* newNode(int k){
    node *temp=new node();
    temp->key=k;
    temp->next=NULL;

    return temp;
}

void deleteLast(node **h, int k){
    node **tmp=NULL;
    while(*h!=NULL){
        if((*h)->key==k){
            tmp=h;
        }
        h=&((*h)->next);
    }
    if(*tmp){
        node* tmp2=(*tmp);
        *tmp=tmp2->next;
        free(tmp2);
    }
}

void printLL(node *head){
    while(head!=NULL){
        cout<<(head)->key<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    node* root=newNode(1);
    root->next=newNode(2);
    root->next->next=newNode(3);
    root->next->next->next=newNode(2);
    root->next->next->next->next=newNode(4);
    
    deleteLast(&root, 2);
    printLL(root);


    return 0;
}