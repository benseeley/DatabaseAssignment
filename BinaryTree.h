//
// Created by Ben on 11/12/2016.
//

#ifndef DATABASEASSIGNMENT_BINARYTREE_H
#define DATABASEASSIGNMENT_BINARYTREE_H

#endif //DATABASEASSIGNMENT_BINARYTREE_H

#include "stdlib.h"

namespace cpsc350
{
    template <typename Elem>
    class BinaryTree
    {
    protected:
        struct Node
        {
            Elem elem;
            Node* par;
            Node* left;
            Node* right;
            Node() : elem(), par(NULL), left(NULL), right(NULL) {}
        };

    public:
        class Position
        {
        private:
            Node* node_;
        public:
            Position(Node* node = NULL);
            Position()

        };
    };
}
