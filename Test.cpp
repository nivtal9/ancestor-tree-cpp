//
// Created by nivtal9 & AVI on 11.4.2020.
//
#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>

using namespace std;

family::Tree T("Niv");
family::Tree x("avi");

TEST_CASE("create tree test"){
    CHECK_NOTHROW(x.addFather("avi", "mark"));
    CHECK_NOTHROW(x.addMother("avi", "ema"));
    CHECK_NOTHROW(x.addFather("mark", "moshe"));
    CHECK_NOTHROW(x.addMother("mark", "anya"));
    CHECK_NOTHROW(x.addFather("ema", "michael"));
    CHECK_NOTHROW(x.addMother("ema", "masha"));
    CHECK_NOTHROW(x.addMother("masha", "ester"));

    CHECK_THROWS(x.addFather("avi", "dror"));
    CHECK_THROWS(x.addMother("mark", "rachel"));
    CHECK_THROWS(x.addFather("shay", "mark"));
    CHECK_THROWS(x.addMother("mark", ""));
    CHECK_THROWS(x.addMother("", "anya"));
//
    CHECK_NOTHROW(T.addFather("Niv","Itzik"));
    CHECK_NOTHROW(T.addMother("Niv","Tali"));
    CHECK_NOTHROW(T.addMother("Tali","Tzvia"));
    CHECK_NOTHROW(T.addFather("Tali","David"));
    CHECK_NOTHROW(T.addFather("Itzik","Nissim"));
    CHECK_NOTHROW(T.addMother("Itzik","Hashiba"));
    CHECK_THROWS(T.addFather("Niv","Niv"));
    CHECK_THROWS(T.addFather("Niv","Tali"));
    CHECK_THROWS(T.addFather("Nissim",""));
    CHECK_THROWS(T.addMother("","nevermind"));
    CHECK_NOTHROW(T.addFather("Nissim","Massaod"));

}
family::Tree T2("itay");
TEST_CASE("relation test"){

    CHECK_NOTHROW(x.relation("mark"));
    CHECK_NOTHROW(x.relation("ema")==string("mother"));
    CHECK_NOTHROW(x.relation("moshe"));
    CHECK_NOTHROW(x.relation("anya")==string("grandmother"));
    CHECK_NOTHROW(x.relation("michael"));
    CHECK_NOTHROW(x.relation("masha")==string("grandmother"));
    CHECK(x.relation("ester")==string("great-grandmother"));

    CHECK_FALSE(x.relation("ester")==string("great-grandfather"));
    CHECK_FALSE(x.relation("mark")==string("mother"));

    CHECK_THROWS(x.relation(""));
    CHECK_THROWS(x.relation("father"));
    CHECK_THROWS(x.relation("dror"));
    CHECK_THROWS(x.relation("reuven"));
 //
    CHECK_NOTHROW(T2.addFather("Yaakov","Itzik"));
    CHECK_NOTHROW(T2.addMother("Yaakov","Tali"));
    CHECK_NOTHROW(T2.addMother("Tali","Tzvia"));
    CHECK_NOTHROW(T2.addFather("Tali","David"));
    CHECK_NOTHROW(T2.addFather("Itzik","Nissim"));
    CHECK_NOTHROW(T2.addMother("Itzik","Hashiba"));
    CHECK(T2.relation("Hashiba")==string("grandmother"));
    CHECK(T2.relation("Nissim")==string("grandfather"));
    CHECK(T2.relation("Tali")==string("mother"));
    CHECK_THROWS(T2.relation("Niv"));
    CHECK_THROWS(T2.relation(""));
    CHECK(T2.relation("David")==string("grandfather"));


}

family::Tree x2("meital");
family::Tree T3("Roi");
TEST_CASE("find test"){
    CHECK_NOTHROW(x2.addFather("meital", "mark"));
    CHECK_NOTHROW(x2.addFather("mark", "moshe"));
    CHECK_NOTHROW(x2.addMother("mark", "anya"));

    CHECK(x.find("father")==string("mark"));
    CHECK(x.find("mother")==string("ema"));
    CHECK(x.find("grandfather")==string("michael"));
    CHECK(x.find("grandmother")==string("masha"));
    CHECK(x.find("father")==string("mark"));

    CHECK_THROWS(x2.find("mother"));
    CHECK(x2.find("grandmother")==string("anya"));
//
    CHECK_NOTHROW(T3.addFather("Roi","Itzik"));
    CHECK_NOTHROW(T3.addMother("Roi","Tali"));
    CHECK_NOTHROW(T3.addMother("Tali","Tzvia"));
    CHECK_NOTHROW(T3.addFather("Tali","David"));
    CHECK_NOTHROW(T3.addFather("Itzik","Nissim"));
    CHECK_NOTHROW(T3.addMother("Itzik","Hashiba"));
    CHECK(T3.find("father")==string("Itzik"));
    CHECK_THROWS(T3.find("great-great-grandmother"));
    CHECK_THROWS(T3.find("great-great-grandfather"));
    CHECK(T3.find("grandfather")==string("David"));
    CHECK(T3.find("grandmother")==string("Tzvia"));

}
family::Tree x3("ortal");
family::Tree T4("Noa");
TEST_CASE("remove test"){

    CHECK_NOTHROW(x3.addFather("ortal", "mark"));
    CHECK_NOTHROW(x3.addMother("ortal", "ema"));
    CHECK_NOTHROW(x3.addFather("mark", "moshe"));
    CHECK_NOTHROW(x3.addMother("mark", "anya"));
    CHECK_NOTHROW(x3.addFather("ema", "michael"));
    CHECK_NOTHROW(x3.addMother("ema", "masha"));
    CHECK_NOTHROW(x3.addMother("masha", "ester"));

    CHECK_NOTHROW(x3.remove("ester"));
    CHECK_NOTHROW(x3.remove("masha"));

    CHECK_THROWS(x3.remove("ester"));
    CHECK_THROWS(x3.remove(""));
    CHECK_THROWS(x3.remove("boaz"));
//
    CHECK_NOTHROW(T4.addFather("Noa","Itzik"));
    CHECK_NOTHROW(T4.addMother("Noa","Tali"));
    CHECK_NOTHROW(T4.addMother("Tali","Tzvia"));
    CHECK_NOTHROW(T4.addFather("Tali","David"));
    CHECK_NOTHROW(T4.addFather("Itzik","Nissim"));
    CHECK_NOTHROW(T4.addMother("Itzik","Hashiba"));
    CHECK_THROWS(T4.remove(""));
    CHECK_THROWS(T4.remove("Niv"));
    CHECK_THROWS(T4.remove("grandfather"));
    CHECK_NOTHROW(T4.remove("Tali"));
    CHECK_THROWS(T4.remove("David"));
    CHECK_NOTHROW(T4.remove("Noa"));
    CHECK_THROWS(T4.remove("Itzik"));




}