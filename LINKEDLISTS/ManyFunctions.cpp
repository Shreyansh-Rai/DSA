#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node(int val)
    {
        data=val;
        next = NULL;
    }
};
Node * addAtBegin(Node * head,int val)
{
    Node* temp = new Node(val);
    temp->next=head;
    return temp;
}
Node * addAtEnd(Node * head, int val)
{
    Node* temp = new Node(val);
    Node * t;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=temp;
    return head;
    //similar approach to add the node to whatever position you want to.
}
Node * delBeg(Node * head)
{
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* delEnd(Node * head)
{
    Node * temp=head->next;
    Node * before= head;
    while(temp->next)
    {
        temp= temp->next;
        before= before->next;
    }
    free(temp);
    before->next=NULL;
    return head;
}
Node* recReverse(Node * head)
{
    if(head && head->next)
    {
        Node* temp = head;
        head= recReverse(head->next);
        head= addAtEnd(head,temp->data);
    }
    return head;
}
Node* iterReverse(Node * head)
{
    Node* p=NULL;
    Node* c=head;
    Node* n= head->next;
    while(n)
    {
        c->next=p;
        p=c;
        c=n;
        n=n->next;
    }
    c->next=p;
    return c;
}
void Travel(Node * head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<" "<<endl;
}
Node * krev(Node* head,int count)
{
    Node* p=NULL;
    Node* c=head;
    Node* n;
    int k=0;
    while(n && k<count)
    {   
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        k++;
    }
    if(head && n)
    {
        head->next=krev(n,count);
    }
    return(p);
}
Node * k2rev( Node*  head, int k)
{
    Node* p = NULL;
    Node* c= head;
    Node* n = c->next;
    int count =0;

    while(n&&count<k)
    {
        c->next=p;
        p=c;
        c=n;
        n=n->next;
    }
    
    if(head && c)
    {
        head->next = krev(c,k);
    }
    return p;
}
int main(){
    Node* root;
    root= addAtBegin(root,5);
    root= addAtBegin(root, 10);
    root= addAtEnd(root,11);
    root= delBeg(root);
    root= addAtBegin(root,4);
    root= delEnd(root);
    Travel(root);
    root= addAtEnd(root,7);
    root= addAtEnd(root,9);
    //4579
    root= recReverse(root);
    Travel(root);
    root= iterReverse(root);
    Travel(root);
    root=krev(root,2);
    Travel(root);
    return 0;
}

