//
// Created by nivtal9 & AVI on 11.4.2020.
//

#include "FamilyTree.hpp"
using namespace std;
string family::Tree::relation(string name) {
    return "";
}

string family::Tree::find(string relationStr) {
    return "";
}

void family::Tree::display(node *pNode) {
    cout <<  "This is InOrder printing of the Tree: \n" << endl;
    if(!ChildRoot)
    {
        return;
    }
    display(ChildRoot->mother);
    cout << ChildRoot->name << endl;
    display(ChildRoot->father);
}

bool family::Tree::remove(string name) {
    return false;
}

family::Tree &family::Tree::addFather(string ChildName, string FatherName) {
    //Tree &root = *this;
    node* nodeFound=search(this->ChildRoot,ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->father=new node(FatherName);
    }
    return *this;
}

family::Tree &family::Tree::addMother(string ChildName, string MotherName) {
    node* nodeFound=search(ChildRoot,ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->mother=new node(MotherName);
    }
    return *this;
}

node *family::Tree::search(node *root, string key) {
    cout<<root->name<<endl;
    if ( root->name == key) {
        return (node *) root;
    } else {
        search(root->mother,key);
        search(root->father,key);
    }
    return nullptr;
}
