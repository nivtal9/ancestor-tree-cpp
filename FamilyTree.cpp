//
// Created by nivtal9 & AVI on 11.4.2020.
//

#include "FamilyTree.hpp"
using namespace std;
string family::Tree::relation(string name) {
    int x=0;
    int gender =0;
    string ans="";
    node* rel= relation_search(this->ChildRoot, name, x, gender);
    if(rel!= nullptr) {
        if(x<=2) {
            switch (x) {
                case 0:
                    return "me";
                case 1: {
                    if (gender == 0) {
                        ans = "father";
                        return ans;
                    }
                    if (gender == 1) {
                        ans = "mother";
                        return ans;
                    }
                }
                case 2: {
                    if (gender == 0) {
                        ans = "grandfather";
                        return ans;
                    }
                    if (gender == 1) {
                        ans = "grandmother";
                        return ans;
                    }
                }
            }
        }
        else{
            if(gender==0) ans="grandfather";
            if(gender==1) ans="grandmother";
            while(x>2){
                ans="great-"+ans;
                x--;
            }
        }
    }
    else{
        throw runtime_error("unrelated");
    }
    return ans;
}

string family::Tree::find(string relationStr) {
    if (relationStr == "me") {
        return this->ChildRoot->name;
    }
    if(relationStr=="mother"){
        return find_search(this->ChildRoot,1,1)->name;
    }
    if(relationStr=="father"){
        return find_search(this->ChildRoot,1,0)->name;
    }
    label:
    if(relationStr=="grandmother"){
        return find_search(this->ChildRoot,2,1)->name;
    }
    if(relationStr=="grandfather"){
        return find_search(this->ChildRoot,2,0)->name;
    }
    int x=2;
    while (relationStr != "grandfather" && relationStr != "grandmother") {
        if (relationStr.substr(0, 6) == "great-") {
            x++;
        } else {
            throw runtime_error("The tree cannot handle the '"+relationStr+"' relation");
        }
        relationStr = relationStr.substr(6, relationStr.length() - 1);
    }
    goto label;
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

    node * nodeFound= add_search(this->ChildRoot, ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->father=new node( FatherName);
    }
    return *this;
}

family::Tree &family::Tree::addMother(string ChildName, string MotherName) {
    node* nodeFound= add_search(this->ChildRoot, ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->mother=new node(MotherName);
    }
    return *this;
}

node *family::Tree::add_search(node *t, string key) {
    if ( t->name == key) {
        return t;
    } else {

        if(t->father != nullptr){
            node* ans= add_search(t->father, key);
            if(ans!= nullptr)
                return ans;
        }

        if(t->mother != nullptr) {
            node *ans2 = add_search(t->mother, key);
            if (ans2 != nullptr)
                return ans2;
        }
    }


    return nullptr;
}

//gender == 0 means father
//gender == 1 means mother
//x means the deeper of the relation
node *family::Tree::relation_search(node *t, string key, int & relation, int & gender ) {
    if ( t->name == key) {
        return t;
    } else {
        if(t->father != nullptr){
            gender=0;relation++;
            node* ans= relation_search(t->father, key, relation, gender);
            if(ans!= nullptr)
                return ans;
            else relation--;
        }

        if(t->mother != nullptr) {
            gender=1;relation++;
            node *ans2 = relation_search(t->mother, key, relation, gender);
           if (ans2 != nullptr)
               return ans2;
           else relation--;
       }
   }
   return nullptr;
}

//gender == 0 means father
//gender == 1 means mother
//x means the deeper of the relation
node *family::Tree::find_search(node *t, int relation, int gender) {
    if ( relation == 0) {
        return t;
    } else {
        if(t->father != nullptr){
            relation--;
            node* ans= find_search(t->father, relation, gender);
            if(ans!= nullptr)
                return ans;
            else relation++;
        }

        if(t->mother != nullptr) {
            relation--;
            node *ans2 = find_search(t->mother, relation, gender);
            if (ans2 != nullptr)
                return ans2;
            else relation++;
        }
    }
    return nullptr;
}

