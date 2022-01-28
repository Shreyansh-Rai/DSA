#include<iostream>

#include<stack>

#include<vector>

#include<iostream>

#include<string>

#include<unordered_map>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
void Travel(Node * root)
{   
    int hardstop=1000;

    while(root!=NULL and hardstop)
    {
        cout<<root->data<<endl;
        root=root->next;
        hardstop--;
    }
}
int FloydCycle(Node * root)
{
    Node * slow = root;
    Node * fast=root;
    while(slow!=NULL || fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
void CycleRemover(Node * head)
{
    Node *slow=head;
    Node *fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
           // cout<<slow->data<<endl;
            break;
        }
    }
    
    slow=head;
    while(true)
    {
        if(slow->next == fast->next)
        {
            fast->next = NULL;
            break;
        }
        slow=slow->next;
        fast=fast->next;
    }
}
int main(){
    Node* n1 = new Node(11);
    Node* n2 = new Node(12);
    Node* n3 = new Node(13);
    Node* n4 = new Node(14);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n2;
    Travel(n1);
    cout<<"Cycle found: "<< FloydCycle(n1)<<endl;
    CycleRemover(n1);
    Travel(n1);
    
    return 0;
}
