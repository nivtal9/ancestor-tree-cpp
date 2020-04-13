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
        node *ChildRoot;
    public:
        Tree(string Child){
            node r(Child);
            (*this).ChildRoot=&r;
            //cout<<ChildRoot->name<<endl;
        }
        Tree& addFather(string ChildName,string FatherName);
        Tree& addMother(string ChildName,string MotherName);
        string relation(string name);
        string find(string relationStr);
        void display(node *pNode);
        bool remove(string name);
        node* search(node *root, string key);
    };
}

#endif //ANCESTOR_TREE_FAMILYTREE_HPP
