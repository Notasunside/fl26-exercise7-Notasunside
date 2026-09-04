////////////////////////////////////////////////////////
// ECE 3574 Exercise: CMake using Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include "treap.h"
#include <cassert>    
#include <cstdlib>

TEST_CASE("treap unit test1", "[treap]") {

	struct TreapNode *root = NULL;  //empty tree
	root = insert(root, 50);	//inserts key 50
	
	TreapNode *res = search(root, 50); //search for 50
	REQUIRE(res->key == 50); //check that node returns key 50

}

//a treap combines BST and heap. 
//priorities are random, rotations preserve the bst ordering

// additional test cases. 5 implemented

TEST_CASE("does search for missing key", "[treap]")
{
    struct TreapNode *myroot = NULL;  //empty tree
    myroot = insert(myroot, 50);		//inserts key 50
    REQUIRE(search(myroot, 25) == NULL); //check that search for missing key returns NULL
    myroot = deleteNode(myroot, 50);	//insert uses new so node should eventually be deleted?
}

TEST_CASE("does insert/search for multiple keys", "[treap]")
{
    struct TreapNode *myroot = NULL;

    myroot = insert(myroot, 67);
    myroot = insert(myroot, 68);
    myroot = insert(myroot, 69);
    REQUIRE(search(myroot, 67)!= NULL); //checks it exists for mult keys
    REQUIRE(search(myroot,68) != NULL);
    REQUIRE(search(myroot,69) != NULL);
    myroot = deleteNode(myroot, 67); //free memory
    myroot = deleteNode(myroot, 68);
    myroot = deleteNode(myroot, 69);
}

TEST_CASE("does delete existing key", "[treap]")
{
    struct TreapNode *myroot = NULL;
    myroot = insert(myroot, 67);
    myroot = insert(myroot, 68);
    myroot = insert(myroot, 69);
    myroot =deleteNode(myroot, 67);
    REQUIRE(search(myroot,67) ==NULL); //checks that there is no 67
    REQUIRE(search(myroot, 68) !=NULL);
    REQUIRE(search(myroot, 69) != NULL);

    myroot =deleteNode(myroot, 67); //free memory
    myroot =deleteNode(myroot, 69);
}

TEST_CASE("does delete key that doesnt exist", "[treap]")
{
    struct TreapNode *myroot =NULL;
    myroot = insert(myroot, 67);
    myroot = insert(myroot, 21); 
	//69 is never inserted
    myroot =deleteNode(myroot, 69); 
    REQUIRE(search(myroot, 67) !=NULL);
    REQUIRE(search(myroot, 21) != NULL);
    REQUIRE(search(myroot,69)== NULL); //show that none exists

    myroot =deleteNode(myroot, 67); //free memory
    myroot =deleteNode(myroot, 21);
}
