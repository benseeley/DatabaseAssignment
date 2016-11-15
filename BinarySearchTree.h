//
// Created by Ben on 11/12/2016.
//

#ifndef DATABASEASSIGNMENT_BINARYTREE_H
#define DATABASEASSIGNMENT_BINARYTREE_H

#endif //DATABASEASSIGNMENT_BINARYTREE_H

#include "stdlib.h"

namespace cpsc350
{
    template <typename Key, typename Value>
    class BinarySearchTree
    {
    protected:
        struct Node
        {
            Value elem;
            Node* par;
            Node* left;
            Node* right;
            Node() : elem(), par(NULL), left(NULL), right(NULL) {}
        };

    public:
        class TreeNode
        {
        public:
            Node* node_;

            TreeNode(Node* node = NULL)
            { node_ = node; }

            //getters
            Value&operator*()
            {
                return node_->elem;
            }
            TreeNode left() const
            {
                return TreeNode(node_->left);
            }
            TreeNode right() const
            {
                return TreeNode(node_->right);
            }
            TreeNode parent() const
            {
                return TreeNode(node_->par);
            }

            void setRight(TreeNode* pos)
            {
                node_->right = pos->node_;
                pos->node_->par = node_;

            }
            void setLeft(TreeNode* pos)
            {
                node_->right = pos->node_;
                pos->node_->par = node_;
            }
            bool isRoot() const
            {
                return (node_->par == NULL);
            }
            bool isExternal() const
            {
                return node_->left == NULL && node_->right == NULL;
            }
            friend class BinarySearchTree;

        };

    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(Value&);
        void erase();

        Value& find();





        int size() const;
        bool empty() const;
        TreeNode root() const;

    private:
        Node*

    };
}
