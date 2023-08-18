#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    vector <Node*> childs;    
};

Node* createTree(vector<int> arr){

stack <Node*> st;
// creating the head
if(arr[0] == -1)
return NULL;
Node* head = new Node;
head->data = arr[0];
st.push(head);

// iterating over left overs

for(int i = 1; i<arr.size() ; i++){

if(st.empty()==false and arr[i]==-1){
    st.pop();
    continue;
}
else{
Node* newnode = new Node;
newnode->data = arr[i];

st.top()->childs.push_back(newnode);

st.push(newnode);
}

}

return head;

}


void printTree(Node* head){

if(head == NULL)
    return;

cout<<head->data<<" -> ";
for(int i = 0 ; i<head->childs.size() ; i++){
    cout<<head->childs[i]->data<<",";
}
cout<<endl;

for(int i = 0 ; i<head->childs.size() ; i++){
    printTree(head->childs[i]);
}


}



int size(Node* head){
if(head==NULL)
    return 0;

int count = 0;
for(int i = 0 ; i<head->childs.size() ; i++){
    count = count + size(head->childs[i]);
}

return count + 1;


}


int maximum(Node* head){

int maxi = head->data;

for(int i = 0 ; i< head->childs.size() ; i++){
    int n = maximum(head->childs[i]);
    if(n>maxi)
        maxi = n;
}

return maxi;

}


int height(Node* head){

if(head->childs.size()==0)
    return 0;

int maxH = 0;
for(int i = 0 ; i<head->childs.size() ; i++){

    int h = height(head->childs[i]);
    if(h>maxH)
        maxH = h;
}

return maxH + 1;


}

void traversal(Node* head){

cout<<"Node pre "<<head->data<<endl;

for(int i = 0 ; i<head->childs.size() ; i++){
    cout<<"edge pre "<<head->data<<" - "<<head->childs[i]->data<<endl;
    traversal(head->childs[i]);
    cout<<"edge post "<<head->data<<" - "<<head->childs[i]->data<<endl;
}

cout<<"Node post "<<head->data<<endl;


}

void levelOrderTraversal(Node* head){
if(head == NULL)
    return;

queue<Node*> q;
q.push(head);

while(q.size()!=0){
    cout<<q.front()->data<<" ";
    for(int i = 0 ; i<q.front()->childs.size() ; i++){
        q.push(q.front()->childs[i]);
    }
    q.pop();


}


}


void swap(vector<Node*> &childs , int i , int j){

Node* temp = childs[i];
childs[i] = childs[j];
childs[j] = temp;

}

void mirror(Node* head){
if(head==NULL)
    return;

for(int i = 0 ; i<head->childs.size() ; i++){
    mirror(head->childs[i]);
}

int i = 0 , j = head->childs.size()-1;
while(i<=j){
    swap(head->childs , i,j);
    i++;
    j--;
}

}


void removeLeafs(Node* head){
if(head == NULL)
    return;

for(int i = head->childs.size()-1 ; i>=0 ; i--){

    if(head->childs[i]->childs.size()==0){
        head->childs.erase((head->childs).begin()+i);
    }

    removeLeafs(head->childs[i]);
}

}


bool findVal(Node* head, int target){

if(head->data == target)
    return true;

for(int  i =0 ; i<head->childs.size() ; i++){

    if(findVal(head->childs[i],target))
        return true;
}

return false;

}

void NtoRpath(Node* head,int target , bool &found , vector<int> &path){


    if(head->data == target){
        found = true;
        path.push_back(head->data);
        return;
    }

    for(int i = 0 ; i<head->childs.size() ; i++){
        if(found == false)
        NtoRpath(head->childs[i],target,found,path);

    }

    if(found == true)
        path.push_back(head->data);

}

int main(){
vector<int> arr = {10,20,-1,30,50,-1,60,-1,-1,40,-1,-1};
Node* head = createTree(arr);
// printTree(head);
bool found = false;
vector <int> path = {};
int target; cin>>target;
NtoRpath(head,target,found,path);

for(int i = 0 ; i<path.size() ; i++)
cout<<path[i]<<" ";




}