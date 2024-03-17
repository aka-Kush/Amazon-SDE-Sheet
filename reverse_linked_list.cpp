#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }    
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* array2LL(vector<int>& vec){
    Node* head = new Node(vec[0]);
    Node* mover = head;
    for(int i  = 1; i<vec.size(); i++){
        Node* temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseLL(Node* head){

    Node* curr = head;
    Node* back = NULL;
    while(curr != NULL){
        Node* front = curr->next;
        curr->next = back;
        back = curr;
        curr = front;
    }
    return back;    
}

int main()
{
    vector<int> vec = {2,5,1,10,7};
    Node* ll = array2LL(vec);
    print(reverseLL(ll));
}