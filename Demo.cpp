/**
 * Demo for Family Tree
 *
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    family::Tree T ("Maya");
    T.addMother("Maya", "Anat").addFather("Maya", "Rami")
            .addMother("Anat", "Rivka").addFather("Anat", "Yoni")
            .addMother("Yoni", "Vered").addFather("Yoni", "Shlomi")
            .addFather("Rami", "David");

    try{(T.remove("Maya"));} //try to remove the root --> exception
    catch(exception e)
    {cout<<"niv1\n"<<endl;}

    assert((T.find("grandfather") == string("David") || T.find("grandfather") == string("Yoni")));

    assert(T.find("father") == string("Rami"));
    T.remove("Rami");
    //T.display();
    try{(T.find("father"));}
    catch(exception e)
    {cout<<"niv2\n"<<endl;}
    try {
        assert(T.find("grandfather") ==string("Yoni")); //because David has removed from the tree while removing Rami

        assert(T.find("great-grandmother") == string("Vered"));
        assert(T.find("great-grandfather") == string("Shlomi"));
    }catch(exception e){
        cout<<"nivtal\n"<<endl;
    }
    T.remove("Vered");
    try{(T.find("great-grandmother"));}
    catch(exception e)
    {cout<<"niv3\n"<<endl;}
    T.remove("Yoni");
    try{(T.find("great-grandfather"));}
    catch(exception e)
    {cout<<"niv4\n"<<endl;}
    try {T.find(T.find("grandfather"));}
    catch(exception e)
    {cout<<"niv5\n"<<endl;}

    T.addFather("Anat", "Nir"); //we've removed Yoni, sowe can add new father to Anat now
    assert(T.find("grandfather") == string("Nir"));
    assert(T.find("grandmother") == string("Rivka"));
    T.remove("Rivka");
    try{(T.find("grandmother"));}
    catch(exception e)
    {cout<<"niv6\n"<<endl;}
    T.remove("Anat");
    try{(T.find("grandfather"));}
    catch(exception e)
    {cout<<"niv7\n"<<endl;}
    try{(T.find("mother"));}
    catch(exception e)
    {cout<<"niv8\n"<<endl;}
}