 fgdvvvvvvvvvv ////////////////////////////////////////////////////////
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

	struct TreapNode *root = NULL; 
	root = insert(root, 50);
	
	TreapNode *res = search(root, 50);
	REQUIRE(res->key == 50);

}
TEST_CASE("treap unit test2", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	REQUIRE(search(root, 20)->key == 20);
	REQUIRE(search(root, 30)->key == 30);
	REQUIRE(search(root, 40)->key == 40);
	REQUIRE(search(root, 50)->key == 50);
	REQUIRE(search(root, 60)->key == 60);
	REQUIRE(search(root, 70)->key == 70);
	REQUIRE(search(root, 80)->key == 80);
}
TEST_CASE("treap unit test3", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 


	REQUIRE(search(root, 20) == NULL);
	REQUIRE(search(root, 30) == NULL);
	REQUIRE(search(root, 50) == NULL);
	REQUIRE(search(root, 60) == NULL);
	REQUIRE(search(root, 40) == NULL);
} 
TEST_CASE("treap unit test4", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 0); 
	root = insert(root, -10); 
	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, -20);  

	REQUIRE(search(root, 0)->key == 0);
	REQUIRE(search(root, -10)->key == -10);
	REQUIRE(search(root, 20)->key == 20);
	REQUIRE(search(root, 10)->key == 10);
	REQUIRE(search(root, -20)->key == -20);
}
TEST_CASE("treap unit test5", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 0); 
	root = insert(root, -10); 
	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, -20);  
	root = deleteNode(root, 0);
	root = deleteNode(root, -10);


	REQUIRE(search(root, 0) == NULL);
	REQUIRE(search(root, -10) == NULL);
	REQUIRE(search(root, 20) != NULL);
	REQUIRE(search(root, 10) != NULL);
	REQUIRE(search(root, -20) != NULL);
}
TEST_CASE("treap unit test6", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 0); 
	root = insert(root, -10); 
	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, -20);  
	root = insert(root, 30);
	root = insert(root, 60);
	root = insert(root, 90);

	root = deleteNode(root, 0);
	REQUIRE(search(root, 0) == NULL);

	root = deleteNode(root, -10);
	REQUIRE(search(root, -10) == NULL);

	root = deleteNode(root, 20);
	REQUIRE(search(root, 20) == NULL);

	root = deleteNode(root, 10);
	REQUIRE(search(root, 10) == NULL);

	root = deleteNode(root, -20);
	REQUIRE(search(root, -20) == NULL);

	REQUIRE(search(root, 30) != NULL);
	REQUIRE(search(root, 60) != NULL);
	REQUIRE(search(root, 90) != NULL);
}