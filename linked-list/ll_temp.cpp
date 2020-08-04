#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define vi vector<int>
#define vpi vector<pi>
using namespace std;

struct node{
    int key;
    node* next;
    node(int key){
        this->key=key;
        this->next=NULL;
    }
};

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

void printNthLast(node *head, int n){
    node * ptr2=head;
    if(head==NULL){
        cout<<"empty list"<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(ptr2==NULL){
            cout<<"invalid input"<<endl;
            return;
        }
        ptr2=ptr2->next;
    }
    while(ptr2!=NULL){
        head=head->next;
        ptr2=ptr2->next;
    }

    cout<<head->key<<endl;
}

void middleOfLinkedList(node *head){
    node* slow=head;
    node* fast=head;
    if(head!=NULL){
        while(fast->next!=NULL && fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->key<<endl;
    }
}

void swap_singleptr(node *head, int x, int y){
    //find x and y
    node* cur_x=head;
    node* prev_x=NULL;
    while(cur_x && cur_x->key!=x){
        prev_x=cur_x;
        cur_x=cur_x->next;
    }
    node* cur_y=head;
    node* prev_y=NULL;
    while(cur_y && cur_y->key!=y){
        prev_y=cur_y;
        cur_y=cur_y->next;
    }
    if(!(cur_x&& cur_y))
        return;
    
    if(prev_x){
        prev_x->next=cur_y;
    }
    else
        head=cur_y;
    if(prev_y)
        prev_y->next=cur_x;
    else
        head=cur_x;

    node *t=cur_x->next;
    cur_x->next=cur_y->next;
    cur_y->next=t;

    return;
}

node* reverseList(node *head)
{
    if(head->next == NULL || head == NULL)
        return head;
        
    node* tmp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}

node * addFirst(node* head, int val){
    node* newHead=new node(val);
    newHead->next=head;
    return newHead;
}

node * reverseK(node *head, int k){
    //needs to returns new head
    node* newHead=NULL;
    while(head!=NULL && head->next!=NULL){
        if(newHead)
            head=head->next;
        node *root= new node(head->key);
        node *tail=root;
        for(int i=0; i<k-1; i++){
            head=head->next;
            root=addFirst(root, head->key);
        }
        if(newHead==NULL)
            newHead=root;
        else{
            tail->next=root;
        }
    }
    return newHead;
}

node* reverseKUsingStack(node *head, int k){
    stack<node *> myStack;
    node *cur=head;
    node* prev=NULL;
    while(cur!=NULL){
        int count=0;
        while(cur!=NULL && count<k){
            myStack.push(cur);
            cur=cur->next;
            count++;
        }

        if(myStack.size()<k){
            list<node *> l;
            while(myStack.size()){
                node* t=myStack.top();
                myStack.pop();
                l.push_back(t);
            }
            for(auto &e: l)
                myStack.push(e);
        }

        while(myStack.size()>0){
            node* temp=myStack.top();
            myStack.pop();
            if(prev==NULL){
                prev=temp;
                head=prev;
            }
            else{
                prev->next=temp;
                prev=prev->next;
            }
            
        }
    }
    prev->next=NULL;
    return head;
}

node * _reverseOnlyK(node *head, int k){
    node* cur=head;
    node* prev=NULL;
    int count=0;

    stack<node*> myStack;
    while(count<k && cur!=NULL){
        myStack.push(cur);
        cur=cur->next;
        count++;
    }
    if(myStack.size()<k){
        list<node *> l;
        while(myStack.size()){
            node* t=myStack.top();
            myStack.pop();
            l.push_back(t);
        }
        for(auto &e: l)
            myStack.push(e);
    }
    while(myStack.size()){
        node* temp=myStack.top();
        myStack.pop();
        if(prev==NULL){
            prev=temp;
            head=prev;
        }
        else{
            prev->next=temp;
            prev=prev->next;
        }
    }
    prev->next=cur;
    return head;
}

node * _reverseKAlt(node * head, int k){
    //flag: true=>reverse, false=>move k ahead
    node * newHead=NULL;
    node* cur=head;

    while(cur!=NULL){
        node *temp=_reverseOnlyK(cur, k);
        if(newHead==NULL)
            newHead=temp;
        
        else{

        }
        for(int i=0; i<(2*k); i++){

        }
    }
    
    head=_reverseOnlyK(head, k);
    return head;
}

node *reverseKAlt(node *head, int k){
    return _reverseKAlt(head, k);
}

node* _moveKTimes(node *head, int k){
    int count=0;
    while(head!=NULL && count<k){
        head=head->next;
        k++;
    }
    return head;
}

int _recurseAddUtil(node* num1, node* num2){
    if(num1==NULL && num2==NULL){
        return 0;
    }
    int carry=_recurseAddUtil(num1->next, num2->next);
    int ans=num1->key+num2->key+carry;
    num1->key=ans%10;
    return ans/10;
}

int _addSingle(node* num, int carry, int k){
    static int i=0;
    if(i==k-1){
        int ans=num->key+carry;
        num->key=ans%10;
        return (ans/10);
    }
    i++;
    int c=_addSingle(num->next, carry, k);
    int ans=num->key+c;
    num->key=ans%10;
    return ans/10;
}

int addLL(node* num1, node* num2){
    int len1=0, len2=0;
    node* cur=num1;
    node* num1h=num1;
    node* num2h=num2;
    while(cur!=NULL){
        cur=cur->next;
        len1++;
    }
    cur=num2;
    while(cur!=NULL){
        cur=cur->next;
        len2++;
    }

    if(len1>len2){
        num1=_moveKTimes(num1, len1-len2);
        int carry=_recurseAddUtil(num1, num2);
        _addSingle(num1h, carry, len1-len2);
    }
    else if(len2>len1){
        num2=_moveKTimes(num2, len2-len1);
        int carry=_recurseAddUtil(num2, num1);
    }
    
    while(num1h){
        cout<<num1h->key;
        num1h=num1h->next;
    }


}

int main(){
    node* root=new node(1);
    root->next=new node(2);
    root->next->next=new node(3);
    root->next->next->next=new node(2);
    root->next->next->next->next=new node(4);

    node *num1= new node(5);
    num1->next=new node(7);
    num1->next->next=new node(8);
    num1->next->next->next=new node(9);
    num1->next->next->next->next=new node(9);

    node* num2=new node(3);
    num2->next=new node(3);
    num2->next->next=new node(9);
    
    
    addLL(num1, num2);

    return 0;
}

