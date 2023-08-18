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





bool similarTree(Node* a, Node* b){

if(a->childs.size()!=b->childs.size())
    return false;

for(int i = 0 ; i<a->childs.size() ; i++){

    bool simChild = similarTree(a->childs[i],b->childs[i]);
    if(simChild == false)
        return false;

}

return true;

}







int main(){
vector<int> arr = {10,20,-1,30,50,-1,60,-1,-1,40,-1,-1};
vector<int> arr2 = {101,201,-1,320,530,-1,660,-1,-1,40,-1,-1};
Node* head = createTree(arr);
Node* head2 = createTree(arr2);
cout<<similarTree(head,head2);




}