//
// Created by Ben on 11/12/2016.
//

#ifndef DATABASEASSIGNMENT_BINARYTREE_H
#define DATABASEASSIGNMENT_BINARYTREE_H

#include "stdlib.h"
#include "Sequence.h"
#include "stdexcept"

#endif //DATABASEASSIGNMENT_BINARYTREE_H



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
        BinarySearchTree(const BinarySearchTree& tree);
        ~BinarySearchTree();

        void insert(const Elem& elem) throw(std::logic_error);
        void erase(const Elem& elem) throw(std::logic_error);
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
        TreeNode* finder(TreeNode* node, const Elem& elem) throw(std::logic_error); //recursive find tool
        void clearer(TreeNode* node); //recursive clear tool
        void inOrderPrinter(TreeNode *node) const;
        void preOrderReturner(TreeNode *node, NodeSequence<Elem>* seq) const;
        TreeNode* eraser(TreeNode *node, const Elem& elem) throw(std::logic_error);
        TreeNode* minNode(TreeNode* node);

    };


    template <typename Elem>
    BinarySearchTree<Elem>::BinarySearchTree()
    {
        n_ = 0;
        root_ = NULL;
    }

    template <typename Elem>
    BinarySearchTree<Elem>::BinarySearchTree(const BinarySearchTree &tree)
    {
        NodeSequence<Elem>* nodeSequence = tree.toSequence();
        for(int i = 0; i < nodeSequence->size(); ++i)
        {
            this->insert(nodeSequence[i]);
        }
        delete nodeSequence;
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
            n_++;
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
    Elem &BinarySearchTree<Elem>::find(const Elem& elem) throw(std::logic_error)
    {
        return finder(root_, elem)->elem_;
    }

    template <typename Elem>
    typename BinarySearchTree<Elem>::TreeNode* BinarySearchTree<Elem>::finder(BinarySearchTree<Elem>::TreeNode *node, const Elem &elem) throw(std::logic_error)
    {
        if(node == NULL)
        {
            throw std::logic_error("Item does not exist");
        }
        else if(elem == node->elem_)
        {
            return node;
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
            cout << node->elem_ << endl;
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


    template <typename Elem>
    typename BinarySearchTree<Elem>::TreeNode *BinarySearchTree<Elem>::minNode(BinarySearchTree<Elem>::TreeNode *node)
    {
        TreeNode* current = node;

        while (current->left_ != NULL)
        {
            current = current->left_;
        }
        return current;
    }

    template <typename Elem>
    void BinarySearchTree<Elem>::erase(const Elem &elem) throw(std::logic_error)
    {
        try
        {
            find(elem);
        }
        catch (std::logic_error)
        {
            throw std::logic_error("Item does not exist");
        }
        eraser(root(), elem);
    }

    template <typename Elem>
    typename BinarySearchTree<Elem>::TreeNode* BinarySearchTree<Elem>::eraser(BinarySearchTree::TreeNode *node, const Elem& elem) throw(std::logic_error)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(elem < node->elem_)
        {
            node->setLeft(eraser(node->left_, elem));
        }
        else if (elem > node->elem_)
        {
            node->setRight(eraser(node->right_, elem));
        }

        else
        {
            if (node->left_ == NULL)
            {
                TreeNode* temp = node->right_;
                delete node;
                return temp;
            }
            else if(node->right_ == NULL)
            {
                TreeNode* temp = node->left_;
                delete node;
                return temp;
            }

            TreeNode* temp = minNode(node->right_);

            node->elem_ = temp->elem_;

            node->setRight(eraser(node->right_, temp->elem_));
        }
        return node;
    }
}
