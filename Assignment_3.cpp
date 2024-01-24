
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
#include<math.h>

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
            return root=new Node(data);
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
    bst.root=bst.insert(bst.root, 40);
    bst.root=bst.insert(bst.root, 30);
    bst.root=bst.insert(bst.root, 25);
    bst.root=bst.insert(bst.root, 35);
    bst.root=bst.insert(bst.root, 50);
    bst.root=bst.insert(bst.root, 45);
    bst.root=bst.insert(bst.root, 60);

//    bst.printTree(bst.root);

    // minimum element.
//    cout<<bst.minData(bst.root);

    // searching an element.
//    cout<<"The presence of key consists is: "<<bst.search(bst.root, 60);

    // max no.of nodes of longest path.
//    cout<<"The no.of nodes of the longest path is: "<<bst.longestPathNodeCount(bst.root);

    // swapping the nodes of the tree.
//    cout<<"The tree before swapping: "<<endl;
//    bst.printTree(bst.root);
//    cout<<endl;
//    cout<<"The tree after swapping is: "<<endl;
//    bst.printTree(bst.swapNodes(bst.root));

}

















