//
// Created by creator on 11/16/16.
//

#include "bst_test.h"
#include "BinarySearchTree.h"
#include "iostream"

void bst_test::testObj() {
    cpsc350::BinarySearchTree<Student>* bst = new cpsc350::BinarySearchTree<Student>();

    Student s("Steve1", "Feshman", "Com Sci", 4.0, 0);

    bst->insert(s);
    Student s2 = bst->find(s);

    cout << s2.toString();

}

bst_test::bst_test() {

}

bst_test::~bst_test() {

}
