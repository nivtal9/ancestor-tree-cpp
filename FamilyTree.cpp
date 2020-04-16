//
// Created by nivtal9 & AVI on 11.4.2020.
//

#include "FamilyTree.hpp"
#include <queue>
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
        return "unrelated";
    }
    return ans;
}

string family::Tree::find(string relationStr) {
    int x=2;
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
        return find_search(this->ChildRoot,x,1)->name;
    }
    if(relationStr=="grandfather"){
        return find_search(this->ChildRoot,x,0)->name;
    }
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

//we took the code from:https://www.geeksforgeeks.org/print-level-order-traversal-line-line/
void family::Tree::display() {
    // Base Case
    if (this->ChildRoot == NULL) return;

    // Create an empty queue for level order tarversal
    queue<node *> q;

    // Enqueue Root and initialize height
    q.push(this->ChildRoot);

    string name="";
    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current lelvel.
        int nodeCount = q.size();

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();

            //gender == 0 means father
//gender == 1 means mother
            int gender=0;
            int relation=0;
            string x="grandfather";
            string y="grandmother";
            relation_search(this->ChildRoot,node->name,relation,gender);
            if(relation==0){
                cout << "the name is  :" <<node->name << " "<<endl;
            }
            else if(relation==1 && gender==0){
                cout << "the father is  :" <<node->name << " "<<endl;
            }
            else if(relation==1 && gender==1){
                cout << "the mother is  :" <<node->name << " "<<endl;
            }
            else{
            for (int i = 1; i <relation-1 ; ++i) {
                if(gender==0){
                    x="great-"+x;
                }
                else{
                    y="great-"+y;
                }

            }
            if(gender==0)
                  cout << "the "<<x << " from " <<name<<" side "<<" is  :" <<node->name <<endl;
            else
                cout << "the "<<y << " from " <<name<<" side "<<" is  :" <<node->name <<endl;
            }
            q.pop();
            if (node->mother != NULL)
                q.push(node->mother);
            if (node->father != NULL)
                q.push(node->father);
            nodeCount--;
            if( nodeCount==0)
            name=node->name;
        }
        cout << endl;
    }
}

bool family::Tree::remove(string name) {
    if(name==ChildRoot->name){
        throw runtime_error("you cannot remove the root of the tree");
    }
    node *t=add_remove_search(this->ChildRoot,name);
    if(t!= nullptr){
        deleteTree(&t);
    }
    else{
        return false;
    }
    return true;
}

family::Tree &family::Tree::addFather(string ChildName, string FatherName) {

    node * nodeFound= add_remove_search(this->ChildRoot, ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->father=new node( FatherName);
    }
    return *this;
}

family::Tree &family::Tree::addMother(string ChildName, string MotherName) {
    node* nodeFound= add_remove_search(this->ChildRoot, ChildName);
    if(nodeFound==nullptr){
        throw runtime_error("unrelated");
    }
    else{
        nodeFound->mother=new node(MotherName);
    }
    return *this;
}

node *family::Tree::add_remove_search(node *t, string key) {
    if ( t->name == key) {
        return t;
    } else {

        if(t->father != nullptr){
            node* ans= add_remove_search(t->father, key);
            if(ans!= nullptr)
                return ans;
        }

        if(t->mother != nullptr) {
            node *ans2 = add_remove_search(t->mother, key);
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
            if(relation>1) {
                relation--;
                node *ans = find_search(t->father, relation, gender);
                if (ans != nullptr)
                    return ans;
                //else relation++;
            }
            if(gender==0&&relation==1){
                relation--;
                node *ans = find_search(t->father, relation, gender);
                if (ans != nullptr)
                    return ans;
            }
            else{
                goto label;
            }
        }
        label :
        if(t->mother != nullptr) {
            relation--;
            node *ans2 = find_search(t->mother, relation, gender);
            if (ans2 != nullptr)
                return ans2;
            //else relation++;
        }
    }
    return nullptr;
}

//we took the code to _deleteTree and deleteTree from:https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
void family::Tree::_deleteTree(node *node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    _deleteTree(node->mother);
    _deleteTree(node->father);

    /* then delete the node */
    cout << "Deleting node: " << node->name << endl;
    free(node->mother);
    free(node->father);
    free(node);
}

/* Deletes a tree and sets the root as NULL */
void family::Tree::deleteTree(node **node_ref)
{
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

