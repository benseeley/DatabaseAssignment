//
// Created by Ben on 11/11/2016.
//

#ifndef DATABASEASSIGNMENT_DLINKEDLIST_H
#define DATABASEASSIGNMENT_DLINKEDLIST_H

#endif //DATABASEASSIGNMENT_DLINKEDLIST_H

#include <iostream>

namespace cpsc350
{
    template <typename Elem>
    class DLinkedList
    {
    private:
        struct Node
        {
            Elem elem;
            Node* prev;
            Node* next;
            Node() : elem(), prev(NULL), next(NULL) {}
        };
    public:
        class DLinkedIterator //iterator for DLinkedList
        {
        public:
            Elem& operator*()
            { return node_->elem; }
            bool operator==(const DLinkedIterator& pos) const
            { return node_ == pos.node_; }
            bool operator!=(const DLinkedIterator& pos) const
            { return node_ != pos.node_; }
            DLinkedIterator& operator++()
            {
                node_ = node_->next;
                return *this;
            }
            DLinkedIterator& operator--()
            {
                node_ = node_->prev;
                return *this;
            }
            friend class DLinkedList;

        private:
            Node* node_;
            DLinkedIterator(Node* u)
            { node_ = u; }
        };

    public:
        DLinkedList();
        virtual ~DLinkedList();
        DLinkedList(const DLinkedList<Elem>& list);
        int size() const;
        bool empty() const;
        DLinkedIterator begin() const;
        DLinkedIterator end() const;
        Elem& front() const { return trailer_->prev->elem; }
        Elem& back() const { return header_->next->elem; }
        void insertFront(const Elem& elem);
        void insertBack(const Elem& elem);
        void insert(const DLinkedIterator& pos, const Elem& elem); //inserts e before p
        void eraseFront() throw(std::logic_error);
        void eraseBack() throw(std::logic_error);
        void erase(const DLinkedIterator& pos);

    private:
        int n_;
        Node* header_;
        Node* trailer_;

    };

    template <typename Elem>
    DLinkedList<Elem>::DLinkedList()
    {
        n_ = 0;
        header_ = new Node;
        trailer_ = new Node;
        header_->next = trailer_;
        trailer_->prev = header_;
    }

    template <typename Elem>
    DLinkedList<Elem>::~DLinkedList()
    {
        while(!empty())
        {
            eraseFront();
        }
        delete header_;
        delete trailer_;

    }

    template <typename Elem>
    DLinkedList<Elem>::DLinkedList(const DLinkedList<Elem>& list)
    {
        n_ = 0;
        header_ = new Node;
        trailer_ = new Node;
        header_->next = trailer_;
        trailer_->prev = header_;
        for(DLinkedIterator elem = this->begin(); elem != this->end(); ++elem)
        {
            this->insertBack(elem);
        }
    }



    template <typename Elem>
    int DLinkedList<Elem>::size() const
    { return n_; }

    template <typename Elem>
    bool DLinkedList<Elem>::empty() const
    { return (n_ == 0); }

    template <typename Elem>
    typename DLinkedList<Elem>::DLinkedIterator DLinkedList<Elem>::begin() const
    {

        return DLinkedIterator(header_->next); }

    template <typename Elem>
    typename DLinkedList<Elem>::DLinkedIterator DLinkedList<Elem>::end() const
    {

        return DLinkedIterator(trailer_); }

    template <typename Elem>
    void DLinkedList<Elem>::insert(const DLinkedList<Elem>::DLinkedIterator &pos, const Elem& elem)
    {
        Node* w = pos.node_;

        Node* u = w->prev;
        if(u != header_){std::cout << u << std::endl;
            std::cout << header_ << std::endl;}


        Node* v = new Node;

        v->elem = elem;

        v->next = w;
        w->prev = v;

        v->prev = u;
        u->next = v;

        n_++;


    }

    template <typename Elem>
    void DLinkedList<Elem>::insertFront(const Elem& elem)
    {
        insert(begin(), elem);
    }

    template <typename Elem>
    void DLinkedList<Elem>::insertBack(const Elem& elem)
    {
        insert(end(), elem);
    }

    template <typename Elem>
    void DLinkedList<Elem>::erase(const DLinkedList<Elem>::DLinkedIterator &pos)
    {
        Node* v = pos.node_;
        Node* w = v->next;
        Node* u = v->prev;
        u->next = w; w->prev = u;
        delete v;
        n_--;
    }

    template <typename Elem>
    void DLinkedList<Elem>::eraseFront() throw(std::logic_error)
    {
        if(!empty())
        {
            erase(begin());
        }
        else
        {
            throw std::logic_error("List is empty");
        }
    }

    template <typename Elem>
    void DLinkedList<Elem>::eraseBack() throw(std::logic_error)
    {
        if(!empty())
        {
            erase(--end());
        }
        else
        {
            throw std::logic_error("List is empty");
        }

    }

}

