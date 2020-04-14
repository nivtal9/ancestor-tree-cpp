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
   // node &root = *this->ChildRoot;
    node * nodeFound=search(this->ChildRoot,ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->father=new node( FatherName);
    }
    return *this;
}

family::Tree &family::Tree::addMother(string ChildName, string MotherName) {
    node* nodeFound=search(this->ChildRoot,ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->mother=new node(MotherName);
    }
    return *this;
}

node *family::Tree::search(node *t, string key) {
    if ( t->name == key) {
        return t;
    } else {

        if(t->father != nullptr){
            node* ans= search(t->father,key);
            if(ans!= nullptr)
                return ans;
        }

        if(t->mother != nullptr) {
            node *ans2 = search(t->mother, key);
            if (ans2 != nullptr)
                return ans2;
        }
    }


    return nullptr;
}

