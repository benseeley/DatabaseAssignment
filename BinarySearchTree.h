//
// Created by Ben on 11/12/2016.
//

#ifndef DATABASEASSIGNMENT_BINARYTREE_H
#define DATABASEASSIGNMENT_BINARYTREE_H

#endif //DATABASEASSIGNMENT_BINARYTREE_H

#include "stdlib.h"
#include "Sequence.h"
#include "stdexcept"

namespace cpsc350
{
    template <typename Elem>
    class BinarySearchTree
    {

    public:
        class TreeNode //interface to node structure
        {
        private:
            Elem elem_;
            TreeNode* parent_;
            TreeNode* left_;
            TreeNode*right_;
        public:
            TreeNode():elem_(),left_(NULL),right_(NULL),parent_(NULL) {}
            TreeNode(Elem elem):elem_(elem),left_(NULL),right_(NULL),parent_(NULL) {}

            //getters
            Elem&operator*()
            {
                return elem_;
            }

            //setters to handle parent_ child linking
            void setRight(TreeNode* pos)
            {
                right_ = pos;
                pos->parent_ = this;
            }
            void setLeft(TreeNode* pos)
            {
                left_ = pos;
                pos->parent_ = this;
            }

            bool isRoot() const
            {
                return (parent_ == NULL);
            }
            bool isExternal() const
            {
                return left_ == NULL && right_ == NULL;
            }
            friend class BinarySearchTree;

        };

    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(const Elem& elem) throw(std::logic_error);
        void erase(Elem& elem);
        Elem& find(const Elem& elem) throw(std::logic_error);
        void clear();

        int size() const;
        bool empty() const;
        TreeNode* root() const;
        void inOrderPrint() const;
        NodeSequence<Elem>* toSequence() const;

    private:
        int n_; //number of nodes in tree
        TreeNode* root_;
        void inserter(TreeNode* node, const Elem& elem) throw(std::logic_error); //recursive insertion tool
        Elem& finder(TreeNode* node, const Elem& elem) throw(std::logic_error); //recursive find tool
        void clearer(TreeNode* node); //recursive clear tool
        void inOrderPrinter(TreeNode *node) const;
        void preOrderReturner(TreeNode *node, NodeSequence<Elem>* seq) const;
        void erase(const Elem& elem) throw(std::logic_error);

    };


    template <typename Elem>
    BinarySearchTree<Elem>::BinarySearchTree()
    {
        n_ = 0;
        root_ = NULL;
    }

    template <typename Elem>
    BinarySearchTree<Elem>::~BinarySearchTree()
    {
        clear();
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::insert(const Elem &elem) throw(std::logic_error)
    {
        if(root_ == NULL)
        {
            root_ = new TreeNode(elem);
            n_++;
        }
        else
        {
            inserter(root_, elem);
        }
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::inserter(BinarySearchTree<Elem>::TreeNode *node, const Elem &elem) throw(std::logic_error)
    {
        if(elem == node->elem_)
        {
            throw std::logic_error("element already exists in tree");
        }
        else if(elem < node->elem_) //elem is less than current node
        {
            if(node->left_ == NULL) //if node has no left child, insert new node, otherwise make recursive call
            {
                node->setLeft(new TreeNode(elem));
                n_++;
            }
            else
            {
                inserter(node->left_, elem);
            }

        }
        else
        {
            if(node->right_ == NULL)
            {
                node->setRight(new TreeNode(elem));
                n_++;
            }
            else
            {
                inserter(node->right_, elem);
            }
        }
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::erase(Elem& elem)
    {

    }

    template <typename Elem>
    Elem &BinarySearchTree<Elem>::find(const Elem& elem) throw(std::logic_error)
    {
        return finder(root_, elem);
    }

    template <typename Elem>
    Elem &BinarySearchTree<Elem>::finder(BinarySearchTree<Elem>::TreeNode *node, const Elem &elem) throw(std::logic_error)
    {
        if(node == NULL)
        {
            throw std::logic_error("Item not found");
        }
        else if(elem == node->elem_)
        {
            return node->elem_;
        }
        else if(elem < node->elem_)
        {
            finder(node->left_, elem);
        }
        else
        {
            finder(node->right_, elem);
        }
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::clear()
    {
        clearer(root_);
    }

    template <typename Elem>
    int BinarySearchTree<Elem>::size() const
    {
        return n_;
    }

    template <typename Elem>
    bool BinarySearchTree<Elem>::empty() const
    {
        return n_ == 0;
    }

    template <typename Elem>
    typename BinarySearchTree<Elem>::TreeNode* BinarySearchTree<Elem>::root() const
    {
        return root_;
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::clearer(BinarySearchTree<Elem>::TreeNode *node)
    {
        if(node != NULL)
        {
            clearer(node->left_);
            clearer(node->right_);
            delete node;
        }
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::inOrderPrint() const
    {
        inOrderPrinter(root_);
    }


    template <typename Elem>
    void BinarySearchTree<Elem>::inOrderPrinter(BinarySearchTree<Elem>::TreeNode *node) const
    {
        if(node == NULL)
        {
            return;
        }
        else
        {
            inOrderPrinter(node->left_);
            cout << node << endl;
            inOrderPrinter(node->right_);
        }
    }

    template <typename Elem>
    NodeSequence<Elem> *BinarySearchTree<Elem>::toSequence() const
    {
        NodeSequence<Elem>* temp = new NodeSequence<Elem>();

    }

    template <typename Elem>
    void BinarySearchTree<Elem>::preOrderReturner(BinarySearchTree<Elem>::TreeNode *node, NodeSequence<Elem> *seq) const
    {
        if(node == NULL)
        {
            return;
        }
        else
        {
            inOrderPrinter(node->left_);
            seq->insertBack(node->elem_);
            inOrderPrinter(node->right_);
        }
    }
}
