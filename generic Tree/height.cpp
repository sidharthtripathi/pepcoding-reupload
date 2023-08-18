#include <iostream>
#include <vector>
#include <stack>
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

int main(){
vector<int> arr = {1025,20,50,-1,600,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,5100,-1,-1,-1};
Node* head = createTree(arr);

cout<<height(head);


}