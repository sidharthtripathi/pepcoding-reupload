#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Node{
public:
    int data = 0;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data,Node* left = NULL,Node* right = NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }


};


Node* createBtree(vector<int>arr){
if(arr[0] == -1)
    return NULL;

stack <Node*> node;
stack <int> state;

Node* head = new Node(arr[0]);
node.push(head);
state.push(1);


for(int i = 1; i<arr.size() ; i++){

if(arr[i] == -1){
    int topVal = state.top();
    topVal++;
    state.pop();
    state.push(topVal);

    if(topVal == 3){
        state.pop();
        node.pop();
    }
    continue;
}

Node* newnode = new Node(arr[i]);
if(state.top() == 3){
    node.pop();
   state.pop();

}

if(state.top() == 1){
    node.top()->left = newnode;



}
else if(state.top() == 2){
    node.top()->right = newnode;

}

    int topVal = state.top();
    topVal++;
    state.pop();
    state.push(topVal);

    node.push(newnode);
    state.push(1);





}

return head;



}


void printTree(Node* head){
if(head == NULL)
    return;
  
  if(head->left == NULL)
    cout<<"*";
    else
        cout<<head->left->data;
    cout<<" -> ";
    
    cout<<head->data;


    cout<<" <- ";
    if(head->right == NULL)
        cout<<"*";
    else
        cout<<head->right->data;
        cout<<endl;


    printTree(head->left);
    printTree(head->right);


}

vector <int> path;
bool nodeToRoot(Node* head, int target){
if(head==NULL)
    return false;

if(head->data == target){
    path.push_back(head->data);
    return true;
}

bool lc = nodeToRoot(head->left,target);
if(lc){
    path.push_back(head->data);
    return true;
}

bool rc = nodeToRoot(head->right,target);
if(rc){
    path.push_back(head->data);
    return true;
}

return false;





}


int main(){


vector <int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
Node* head = createBtree(arr);
//printTree(head);
nodeToRoot(head,37);


for(int i = 0 ; i<path.size() ; i++)
cout<<path[i]<<" ";



}