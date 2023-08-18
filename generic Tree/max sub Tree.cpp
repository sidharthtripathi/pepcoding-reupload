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





bool mirrorTree(Node* a , Node* b){

if(a->childs.size()!=b->childs.size())
    return false;

int n = a->childs.size();
for(int i = 0 ; i<n ; i++){

    bool childMirror = mirrorTree(a->childs[n-1-i],b->childs[i]);
    if(childMirror == false)
        return false;

}

return true;


}



bool sym(Node* head){


bool isSym = mirrorTree(head,head);
return isSym;


}

void move(Node* head, int target , Node* &p , Node* &s , int &state){

if(state == 0 ){
    if(head->data == target){
        state = 1;
    }
    else{
        p = head;
    }
}

else if(state == 1){

s = head;
state = 2;

}


for(int i = 0;i<head->childs.size() ; i++){
    move(head->childs[i],target,p,s,state);
}



}


int maxSubTree(Node* head, int &maxSum , Node* &maxHead){

int sum = 0;
for(int i = 0 ; i<head->childs.size() ; i++){
    sum = sum + maxSubTree(head->childs[i],maxSum,maxHead);

}





sum = head->data + sum;
if(sum>maxSum){
    maxSum = sum;
    maxHead = head;
}

return sum;



}






int main(){
vector<int> arr = {-1000,2,5,-1,-1,3,6,-1,7,-11,-1,12,-1,-1,8,-1,-1,4,10,-1,-1,-1};
Node* head = createTree(arr);
int maxSum = 0;
Node* maxHead = NULL;
maxSubTree(head,maxSum,maxHead);
cout<<maxSum<<" @ "<<maxHead->data;





}