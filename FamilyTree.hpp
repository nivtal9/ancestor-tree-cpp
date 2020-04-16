//
// Created by nivtal9 & AVI on 11.4.2020.
//

#ifndef ANCESTOR_TREE_FAMILYTREE_HPP
#define ANCESTOR_TREE_FAMILYTREE_HPP

#include <iostream>
using namespace std;

class node{
public:
    string name;
    node *mother;
    node *father;
    node(string name){
        (*this).name=name;
        (*this).mother= nullptr;
        (*this).father= nullptr;
    }
};
namespace family{
    class Tree {

    public:
        node *ChildRoot;
        Tree(string Child){
           this->ChildRoot=new node(Child);
            //(*this).ChildRoot=&r;
            //cout<<ChildRoot->name<<endl;
        }
        Tree& addFather(string ChildName,string FatherName);
        Tree& addMother(string ChildName,string MotherName);
        string relation(string name);
        string find(string relationStr);
        void display();
        bool remove(string name);
        node* add_remove_search(node* t, string key);
        node* relation_search(node* t, string key, int& relation, int &gender);
        node* find_search(node* t, int relation, int gender);
        void deleteTree(node** node_ref);
        void _deleteTree(node* node);
    };
}

#endif //ANCESTOR_TREE_FAMILYTREE_HPP
