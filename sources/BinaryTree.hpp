#include <iostream>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace ariel {

template <typename T>
class BinaryTree {
  private:
  struct Node{
    explicit Node(T val): value(val){}
    T value;
    Node *left = nullptr, *right = nullptr;
  };
  Node * find_node( T & val, Node * node){
          if(node == nullptr) { return nullptr;}
          if(node->value == val) { return node;}
          Node *_left = find_node(val,node->left);
          if(_left!=nullptr) { return _left;}
          Node *_right = find_node(val,node->right);
          return _right;
  }

  	void copy_children(const Node& from, Node& to){
  		if(from.right!=nullptr) {
  			to.right = new Node(from.right->value);
  			copy_children(*from.right, *to.right);
  		}
  		if(from.left!=nullptr) {
  			to.left = new Node(from.left->value);
  			copy_children(*from.left, *to.left);
  		}
  	}
  Node * root = nullptr;
  map<T,Node *> map;

  public:
    BinaryTree() = default;

    BinaryTree(const BinaryTree<T> & other){
        std::cout << "/* message */" << '\n';
            if(other.root!=nullptr) {
              root = new Node(other.root->value);
              copy_children(*other.root, *root);
            }
    }
	BinaryTree(BinaryTree<T> && other) noexcept {
  		std::cout << "/* message */" << '\n';
  		root = other.root;
  		other.root = nullptr;
	}
  BinaryTree& operator=(BinaryTree other){
     std::cout << "/* message */" << '\n';
     if(this == &other){
         return *this;
     }
     if(root != nullptr){
         delete this->root;
     }
     root = new Node(other.root->value);
     copy_children(*other.root, *this->root);
     return *this;
  }
  BinaryTree& operator=(BinaryTree&& other) noexcept{
       std::cout << "/* message */" << '\n';
       *this->root = other.root;
  }
  BinaryTree& add_root(T val);
  BinaryTree& add_left(T parent,T _left);
  BinaryTree& add_right(T parent,T _right);
  ~BinaryTree() {};

  class iterator{
  private:
    void inorder(Node* n){
      if(n == nullptr){return ;}
      inorder(n->left);
      list.push_back(n);
      inorder(n->right);
    }

    void preorder(Node* n){
      if(n == nullptr){return ;}
      list.push_back(n);
      preorder(n->left);
      preorder(n->right);
    }

    void postorder(Node* n){
      if(n == nullptr){return ;}
      postorder(n->left);
      postorder(n->right);
      list.push_back(n);
    }

  public:
    Node * curr;
    list<Node*> list;
    iterator():curr(nullptr){}
    explicit iterator(Node* tmp):curr(tmp){}
    iterator(Node* root ,int type){
  	  if (root == nullptr)
  	  {
  		  curr = nullptr;
  		  return;
  	  }
  	  switch (type){
  		  case 1:
  			  inorder(root);
  			  curr = *list.begin();
  			  break;
  		  case 2:
  			  preorder(root);
  			  curr = *list.begin();
  			  break;
  		  case 3:
  			  postorder(root);
  			  curr = *list.begin();
  			  break;
  	  }
    }

  T &operator*() const {
          return curr->value;
  }
  T *operator->() const {
          return &(curr->value);
  }
  iterator &operator++(){
      if(list.size()>=2){
        list.erase(list.begin());
        curr = *list.begin();
      }
      else{curr =nullptr;}
    return *this;
  }

   iterator operator++(int){
    iterator temp(*list.begin());
    ++*this;
    return temp;
  }

  bool operator==(const iterator &other) const {
    return curr == nullptr;
  }

  bool operator!=(const iterator &other) const {
    return !(*this == other);
  }

  };
  iterator begin(){
    return iterator(root,1);
  }
  iterator end(){
    return iterator();
  }
  iterator begin_inorder(){
    return iterator(root,1);
  }
  iterator end_inorder(){
    return iterator();
  }
  iterator begin_preorder(){
    return iterator(root,2);
  }
  iterator end_preorder(){
    return iterator();
  }
  iterator begin_postorder(){
    return iterator(root,3);
  }
  iterator end_postorder(){
    return iterator();
  }
  friend ostream& operator<<(ostream& os, const BinaryTree<T>& bt){
    for (auto& n: bt.map){
        os << ' ' << n.first;
     }
    return os;
  }
};
  template <typename T>
  BinaryTree<T>& BinaryTree<T>::add_root(T val){
    if(root == nullptr){
      root=new Node(val);
    }
    else{
      root->value=val;
    }
    return *this;
  }
  template <typename T>
  BinaryTree<T>& BinaryTree<T>::add_left(T parent,T _left){
    Node * n = find_node(parent,root);
    if(n==nullptr){  throw invalid_argument{" node not exist"};}
    if(n->left ==nullptr){
      n->left = new Node(_left);
    }
    else{
      n->left ->value = _left;
    }
    return *this;
  }
  template <typename T>
  BinaryTree<T>& BinaryTree<T>::add_right(T parent,T _right){
    Node * n = find_node(parent,root);
    if(n==nullptr){  throw invalid_argument{" node not exist"};}
    if(n->right ==nullptr){
      n->right = new Node(_right);
    }
    else{
      n->right ->value = _right;
    }
    return *this;
  }
}
