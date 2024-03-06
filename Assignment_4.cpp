/*
                    Assignment-4
    Problem Statement:
        A Dictionary stores keywords & its meanings.
        Provide facility for adding new keywords,
        deleting keywords, updating values of any entry.
        Provide facility to display whole data
        sorted in ascending/Descending order.
        Also find how many maximum comparisons may
        require for finding any keyword.
        Use Binary Search Tree for implementation.
 */

#include "iostream"
using namespace std;


class Word{
public:
    string name;
    string meaning;
public:
    Word(string name, string meaning){
        this->name=name;
        this->meaning=meaning;
    }
    void print(){
        cout<<"Name: "<<name<<", "<<"Meaning: "<<meaning<<endl;
    }
};

class Node{
public:
    Word* word;
    Node* left;
    Node* right;
    Node(Word* word){
        this->word=word;
        this->left=NULL;
        this->right=NULL;
    }
};

class Dictionary{
public:
    Node* root;
    Dictionary(){
        root=NULL;
    }
    Node* insertWord(Node* root, Word* word){
        if(root==NULL){
            return new Node(word);
        }
        else{
            if(word->name < root->word->name){
                root->left=insertWord(root->left, word);
            }
            else{
                root->right=insertWord(root->right, word);
            }
            return root;
        }
    }
    Node* deleteHelper(Node* root, Node* subRoot){
        if(root==NULL){
            return subRoot;
        }
        else{
            root->left = deleteHelper(root->left, subRoot);
            return root;
        }
    }
    Node* deleteWord(Node* root, string wordName){
        if(root==NULL){
            return root;
        }
        if(root->word->name==wordName){
            Node* right=root->right;
            Node* left=root->left;
            free(root);
            return deleteHelper(right, left);
        }
        else{
            if(wordName < root->word->name) {
                root->left = deleteWord(root->left, wordName);
            }
            else{
                root->right = deleteWord(root->right, wordName);
            }
            return root;
        }
    }
    void updateMeaning(Node* root, string wordName, string meaning){
        if(root==NULL){
            return;
        }
        if(root->word->name==wordName){
            root->word->meaning=meaning;
        }
        else{
            if(wordName<root->word->name){
                updateMeaning(root->left, wordName, meaning);
            }
            else{
                updateMeaning(root->right, wordName, meaning);
            }
        }
    }
    void findWord(Node* root, string wordName, int comparisons){
        if(root==NULL){
            cout<<"No such word exist!"<<endl;
            return;
        }
        if(root->word->name == wordName){
            cout<<wordName<<" found in "<<comparisons+1<<
                " comparisons!"<<endl;
            return;
        }
        else{
            if(wordName<root->word->name){
                findWord(root->left, wordName, comparisons+1);
            }
            else{
                findWord(root->right, wordName, comparisons+1);
            }
        }
    }
    void printWordsInAscending(Node* root){
        if(root==NULL){
            return;
        }
        else{
            printWordsInAscending(root->left);
            root->word->print();
            printWordsInAscending(root->right);
        }
    }
    void printWordsIntDescending(Node* root){
        if(root==NULL){
            return;
        }
        else{
            printWordsIntDescending(root->right);
            root->word->print();
            printWordsIntDescending(root->left);
        }
    }
};

int main(){
    Dictionary dict=Dictionary();
    int res=1;
    while(res==1){
        int choice=-1;
        cout<<"What would you like to perform?"<<endl;
        cout<<"1.Insert word.\n2.Delete word.\n3.Print in ascending order."<<endl;
        cout<<"4.Print in descending order.\n5.Find keyword.\n6.Update meaning"<<endl;
        cout<<"Your response: ";
        cin>>choice;
        if(choice==1){
            int innerChoice=1;
            while(innerChoice==1) {
                string name = "";
                string meaning = "";
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter meaning: ";
                cin >> meaning;
                dict.root = dict.insertWord(dict.root, new Word(name, meaning));
                cout<<"Do you want to continue inserting?(Yes - 1, No - 2)"<<endl;
                cout<<"Your response: ";
                cin>>innerChoice;
            }
        }
        else if(choice==2){
            string name="";
            cout<<"Enter word name:";
            cin>>name;
            dict.root=dict.deleteWord(dict.root, name);
        }
        else if(choice==3){
            cout<<"The words and their meanings in ascending order :"<<endl;
            dict.printWordsInAscending(dict.root);
        }
        else if(choice==4){
            cout<<"The words and their meanings in descending order :"<<endl;
            dict.printWordsIntDescending(dict.root);
        }
        else if(choice==5){
            string name="";
            cout<<"Enter word name: ";
            cin>>name;
            dict.findWord(dict.root, name, 0);
        }
        else if(choice==6){
            string name="";
            string meaning="";
            cout<<"Enter word name: ";
            cin>>name;
            cout<<"Enter new meaning: ";
            cin>>meaning;
            dict.updateMeaning(dict.root, name, meaning);
        }
        else{
            cout<<"Invalid choice!"<<endl;
        }
        cout<<"Do you want to continue the program? (Yes - 1, No - 2)"<<endl;
        cout<<"Your response: ";
        cin>>res;
    }
    return 0;
}
