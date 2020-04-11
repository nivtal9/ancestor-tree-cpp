//
// Created by nivtal9 & AVI on 11.4.2020.
//

#ifndef ANCESTOR_TREE_FAMILYTREE_HPP
#define ANCESTOR_TREE_FAMILYTREE_HPP

#include <iostream>
using namespace std;

class node{
public:
    string child;
    node *mother;
    node *father;
    node(string Child){
        (*this).child=Child;
        (*this).mother=NULL;
        (*this).father=NULL;
    }
};
namespace family{
    class Tree {
        node *ChildRoot;
    public:
        Tree(string Child){
            node r(Child);
            (*this).ChildRoot=&r;
        }
        Tree& addFather(string ChildName,string FatherName);
        Tree& addMother(string ChildName,string MotherName);
        string relation(string name);
        string find(string relationStr);
        string display();
        bool remove(string name);
    };
}

#endif //ANCESTOR_TREE_FAMILYTREE_HPP
