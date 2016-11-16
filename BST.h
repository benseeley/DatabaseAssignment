//
// Created by Ben on 11/15/2016.
//

#ifndef DATABASEASSIGNMENT_BST_H
#define DATABASEASSIGNMENT_BST_H

#include "stdlib.h"

template <typename Elem>
class BST
{
private:
    struct TreeNode
    {
        Elem elem;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        TreeNode(Elem data):elem(data),left(NULL),right(NULL),parent(NULL){}
    };



public:

    BST();
    ~BST();


};


#endif //DATABASEASSIGNMENT_BST_H
