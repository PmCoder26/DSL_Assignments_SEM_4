
/*                          Assignment-3
        Beginning with an empty binary search tree, Construct binary search tree by inserting the
        values in the order given. After constructing a binary tree -
        i. Insert new node.
        ii. Find number of nodes in the longest path from root.
        iii. Minimum data value found in the tree.
        iv. Change a tree so that the roles of the left and right pointers are swapped at every
            node.
        v. Search a value.
*/

#include<iostream>
using namespace std;
#include<queue>

class Node{
public:
    Node* left;
    Node* right;
    int data;
    Node(int data){
        this->left=NULL;
        this->right=NULL;
        this->data=data;
    }
};

class BinarySearchTree{
public:
    Node* root=NULL;
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            if(data<root->data){
                root->left=insert(root->left, data);
            }
            else{
                root->right=insert(root->right, data);
            }
            return root;
        }
    }
    void printTree(Node* root){
        if(root==NULL){
            return;
        }
        else{
            cout<<"************************************************"<<endl;
            queue<Node*> q;
            Node* curr=root;
            q.push(curr);
            q.push(NULL);
            while(!q.empty()){
                Node* temp=q.front();
                q.pop();
                if(temp==NULL){
                    if(q.empty()){
                        break;
                    }
                    else{
                        q.push(NULL);
                        cout<<endl;
                    }
                }
                else{
                    cout<<temp->data<<" ";
                    if(temp->left!=NULL){
                        q.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        q.push(temp->right);
                    }
                }
            }
            cout<<"************************************************"<<endl;
        }
    }
    int minData(Node* root){
        if(root==NULL){
            return INT_MAX;
        }
        else{
            int left=minData(root->left);
            int right=minData(root->right);
            return min(left, min(right, root->data));
        }
    }
    bool search(Node* root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data==key){
            return true;
        }
        else{
            bool left=search(root->left, key);
            bool right=search(root->right, key);
            return left || right;
        }
    }
    int longestPathNodeCount(Node* root){
        if(root==NULL){
            return 0;
        }
        else{
            int left=longestPathNodeCount(root->left);
            int right=longestPathNodeCount(root->right);
            return max(left, right)+1;
        }
    }
    Node* swapNodes(Node* root){
        if(root==NULL){
            return NULL;
        }
        else{
            Node* left= swapNodes(root->left);
            Node* right= swapNodes(root->right);
            root->left=right;
            root->right=left;
            return root;
        }
    }
};


int main(){
    BinarySearchTree bst;

    int res=1;
    while(res==1){
        int choice=-1;
        cout<<"What would you like to perform?"<<endl;
        cout<<"1.Insert a node.\n2.Search a value\n3.Find minimum value."<<endl;
        cout<<"4.Swap nodes.\n5.Print Tree\n"
        <<"6.Find number of nodes in the longest path from root."<<endl;
        cout<<"You response: ";
        cin>>choice;
        if(choice==1){
             int innerChoice=1;
            while(innerChoice==1) {
                cout << "Enter the value: ";
                int v;
                cin >> v;
                bst.root = bst.insert(bst.root, v);
                cout<<"Do you want to continue inserting nodes?(Yes - 1, No - 2)"<<endl;
                cout<<"Your response: ";
                cin>>innerChoice;
            }
        }
        else if(choice==2){
            int v;
            cout<<"Enter the value: ";
            cin>>v;
            if(bst.search(bst.root, v)){
                cout<<"The value exists in the tree"<<endl;
            }
            else{
                cout<<"The value doesn't exist in the tree"<<endl;
            }
        }
        else if(choice==3){
            cout<<"The minimum value in the tree is "<<bst.minData(bst.root)<<endl;
        }
        else if(choice==4){
            cout<<"The tree before swapping is: "<<endl;
            bst.printTree(bst.root);
            bst.swapNodes(bst.root);
            cout<<"The tree after swapping is: "<<endl;
            bst.printTree(bst.root);
        }
        else if(choice==5){
            bst.printTree(bst.root);
        }
        else if(choice==6){
            cout<<"The no.of nodes in the longest path from root is: "<<
            bst.longestPathNodeCount(bst.root)<<endl;
        }
        else{
            cout<<"Invalid choice"<<endl;
        }

        cout<<"Do you want to continue program?(Yes - 1, No - 2)"<<endl;
        cout<<"Your response: ";
        cin>>res;
    }
    return 0;
}
