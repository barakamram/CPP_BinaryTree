#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#pragma once

namespace ariel {

    template <typename T>
    class BinaryTree {
    private:
        struct Node {
            T val;
            Node *right, *left, *parent;
            Node( T val) : val(val), right(nullptr), left(nullptr), parent(nullptr) {}
        };
        Node *root;

    public:
        BinaryTree<T>() : root(nullptr) {}
        BinaryTree<T> add_root(T value) {return *this;}
        BinaryTree<T> add_left(T curr_node, T left_node) { return *this; }
        BinaryTree<T> add_right(T curr_node, T right_node) { return *this; }
        ~BinaryTree<T>(){}

        friend std::ostream& operator<<(std::ostream& os, const BinaryTree& bt){
            return os;
        }

        class iterator {
        protected:
            Node *head;
            
        public:
            iterator(Node *node = nullptr) : head(node) {}
            T &operator*() const { return head->val; }
            T *operator->() const { return &(head->val); }

            iterator &operator++() { return *this; }
            const iterator operator++(int) { return *this; }
            bool operator==(const iterator &ite) const { return head == ite.head; }
            bool operator!=(const iterator &ite) const { return head != ite.head; }

        };
        iterator begin_preorder() { return iterator{root}; }
        iterator end_preorder() { return nullptr; }

        iterator begin_inorder() { return iterator{root}; }
        iterator end_inorder() { return nullptr; }

        iterator begin_postorder() { return iterator{root}; }
        iterator end_postorder() { return nullptr; }

        iterator begin() { return iterator{root}; }
        iterator end() { return nullptr; }

        class preorder : public iterator {
            preorder(Node *node = nullptr) : iterator(node) {}
            preorder &operator++() { return *this; }
            const preorder operator++(int) { return *this; }
        };

        class inorder : public iterator {
            inorder(Node *node = nullptr) : iterator(node) {}
            inorder &operator++() { return *this; }
            const inorder operator++(int) { return *this; }
        };

        class postorder : public iterator {
            postorder(Node *node = nullptr) : iterator(node) {}
            postorder &operator++() { return *this; }
            const postorder operator++(int) { return *this; }
        };
    };
}
