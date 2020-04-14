//
// Created by nivtal9 & AVI on 11.4.2020.
//

#include "FamilyTree.hpp"
using namespace std;
int family::Tree::relation(string name) {
    int x=0;
    search2(this->ChildRoot, name, x);
return x;
}

string family::Tree::find(string relationStr) {
    return "";
}

void family::Tree::display(node *pNode) {
    // cout <<  "This is InOrder printing of the Tree: \n" << endl;
    if(pNode== nullptr) {
        cout << "the name of the root is :"<< ChildRoot->name << endl;
        string child=ChildRoot->name;
        if (this->ChildRoot->mother != nullptr) {
            display(ChildRoot->mother);
            cout << child << " mom is:  " << ChildRoot->mother->name << endl;

        }
        if (this->ChildRoot->father != nullptr) {
            display(ChildRoot->father);
            cout << child << " dad is:  " << ChildRoot->father->name << endl;
        }
    }
    else{
        if (pNode->mother != nullptr) {
            display(pNode->mother);
            cout << pNode->name << endl;

        }
        if (pNode->father != nullptr) {
            display(pNode->father);
            cout << pNode->name << endl;
        }

    }



    //display(ChildRoot->mother);
    //cout << ChildRoot->name << endl;
   // display(ChildRoot->father);
}

bool family::Tree::remove(string name) {
    return false;
}

family::Tree &family::Tree::addFather(string ChildName, string FatherName) {

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

node *family::Tree::search2(node *t, string key,int & relation ) {
    if ( t->name == key) {
        return t;
    } else {

        if(t->father != nullptr){
            relation++;
            node* ans= search2(t->father,key,relation);
            if(ans!= nullptr)
                return ans;
            else relation--;
        }

        if(t->mother != nullptr) {
            relation++;
            node *ans2 = search2(t->mother, key,relation);
           if (ans2 != nullptr)
               return ans2;
           else relation--;
       }
   }


   return nullptr;
}

