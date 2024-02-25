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

#include<iostream>
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
            if(word->name<root->word->name){
                root->left=insertWord(root->left, word);
            }
            else{
                root->right=insertWord(root->right, word);
            }
            return root;
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
            return deleteHelper(root->right, root->left);
        }
        else{
            root->left=deleteWord(root->left, wordName);
            root->right=deleteWord(root->right, wordName);
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
        }
        if(root->word->name==wordName){
            cout<<wordName<<" found in "<<comparisons+1<<
            " comparisons!"<<endl;
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
};



int main(){

    Word* words[10];
    words[0]=new Word("Innovation", " Introducing new ideas or methods.");
    words[1]=new Word("Sustainability", "Sustainability.");
    words[2]=new Word("Empathy", "Understanding and sharing others' feelings.");
    words[3]=new Word("Resilience", "Quick recovery from difficulties.");
    words[4]=new Word("Diversity", "Variety within a group or system.");
    words[5]=new Word("Efficiency", "Accomplishing tasks with minimal waste.");
    words[6]=new Word("Collaboration", "Working together to create something.");
    words[7]=new Word("Adaptability", "Adjusting to new conditions.");
    words[8]=new Word("Integrity", "Honesty and strong moral principles.");
    words[9]=new Word("Communication", "Sharing or exchanging information.");

    Dictionary dict=Dictionary();

    // inserting the words with their meanings in BST.
    for(int x=0; x<10; x++){
        dict.root=dict.insertWord(dict.root, words[x]);
    }

    // printing the words in ascending order with their meanings.
//    cout<<"The words of the dictionary in the ascending order are: "<<endl;
//    dict.printWordsInAscending(dict.root);

    // printing the words in descending order with their meanings.
//    cout<<"The words of the dictionary in the ascending order are: "<<endl;
//    dict.printWordsIntDescending(dict.root);

    // deleting the word from the dictionary.
//    cout<<"The words before deleting:"<<endl;
//    dict.printWordsInAscending(dict.root);
//    dict.deleteWord(dict.root, "Efficiency");
//    cout<<"******************************************"<<endl;
//    cout<<"The words after deleting:"<<endl;
//    dict.printWordsInAscending(dict.root);

    // updating the meaning of the word.
//    cout<<"The words with their meanings before updating:"<<endl;
//    dict.printWordsInAscending(dict.root);
//    dict.updateMeaning(dict.root, "Empathy","Sharing others' emotions, understanding their perspective.");
//    cout<<"The words with their meanings after updating:"<<endl;
//    dict.printWordsInAscending(dict.root);

    // finding the word in dictionary.
//    dict.findWord(dict.root, "Collaboration", 0);   // exists in dictionary.
//    dict.findWord(dict.root, "Feelings", 0);        // doesn't exist in dictionary.

    return 0;
}
