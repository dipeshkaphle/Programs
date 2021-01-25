#include <cassert>
#include <iostream>
#include <numeric>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> struct node {
  T data;
  node<T> *left;
  node<T> *right;
  node<T> *parent;
  unsigned int height;
  node(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->height = 0;
  }
};

template <typename T> class BST {
public:
  BST() { root = NULL; }

  BST(initializer_list<T> &&arr) {
    root = NULL;
    for (T const &x : arr)
      this->insert(x);
  }

  BST(vector<T> &arr) {
    root = NULL;
    for (T const &x : arr)
      this->insert(x);
  }

  BST(BST<T> &a) {
    root = NULL;
    *this = a;
  }
  BST(BST<T> &&a) {
    root = NULL;
    *this = move(a);
    a.root = NULL;
  }

  ~BST() {
    this->freeAll();
    cout << "Freed" << endl;
  }

  void insert(T data) {
    if (this->root == NULL) {
      this->root = new node<T>(data);
    } else {
      this->root = this->addToNode(this->root, data);
      this->root->height = this->getMaxHeight(this->root) + 1;
      this->root->parent = NULL;
    }
  }

  void delete_node(T data) {
    if (search(data) == NULL) {
      return;
    } else {
      root = this->remove(this->root, data);
      if (root)
        root->parent = NULL;
    }
  }
  node<T> *search(T data) {
    node<T> *tmp = this->root;
    if (root == nullptr)
      return nullptr;
    if (root->data == data)
      return tmp;
    while (1) {
      if (tmp == NULL)
        return NULL;
      if (tmp->data == data)
        return tmp;
      if (data > tmp->data)
        tmp = tmp->right;
      else
        tmp = tmp->left;
    }
  }

  void inorder() {
    this->inord(this->root);
    cout << endl;
  }

  void postOrder() {
    this->postOrd(this->root);
    cout << endl;
  }

  void preOrder() {
    this->preOrd(this->root);
    cout << endl;
  }

  vector<T> getAllElements() { return this->getElems(root); }

  BST<T> &operator=(BST<T> &a) { // copy semantics
    if (this->root == a.root)
      return *this;
    auto arr = move(a.getAllElements());
    this->freeAll();
    this->root = NULL;
    for (auto const &x : arr)
      this->insert(x);
    return *this;
  }

  BST<T> &operator=(BST<T> &&a) {
    if (this->root == a.root)
      return *this;
    this->root = a.root;
    a.root = NULL;
    return *this;
  }

private:
  node<T> *root;

  node<T> *remove(node<T> *a, T data) {
    node<T> *tmp;
    if (a == NULL)
      return NULL;
    int cmp = data - a->data;
    if (cmp < 0) {
      a->left = this->remove(a->left, data);
      if (a->left)
        a->left->parent = a;
    } else if (cmp > 0) {
      a->right = this->remove(a->right, data);
      if (a->right)
        a->right->parent = a;
    } else {
      if (a->left == NULL) {
        tmp = a->right;
        delete a;
        return tmp;
      } else if (a->right == NULL) {
        tmp = a->left;
        delete a;
        return tmp;
      } else {
        T successor = this->getMin(a->right);
        a->data = successor;
        a->right = this->remove(a->right, successor);
        if (a->right)
          a->right->parent = a;
      }
    }
    a->height = this->getMaxHeight(a) + 1;
    return this->balance(a);
  }

  T getMin(node<T> *a) {
    if (a->left == NULL) {
      return a->data;
    }
    return this->getMin(a->left);
  }

  node<T> *balance(node<T> *a) {
    int bf = this->getBalance(a);
    if (bf == 2) {
      if (this->getBalance(a->left) >= 0) {
        return this->rightRotate(a);
      } else {
        a->left = this->leftRotate(a->left);
        a->left->parent = a;
        return this->rightRotate(a);
      }
    } else if (bf == -2) {
      if (this->getBalance(a->right) <= 0) {
        return this->leftRotate(a);
      } else {
        a->right = this->rightRotate(a->right);
        a->right->parent = a;
        return this->leftRotate(a);
      }
    }
    return a;
  }

  node<T> *addToNode(node<T> *a, T val) {
    if (!a) {
      return (new node<T>(val));
    }
    bool keyWentToLeft = (val > a->data) ? false : true;
    if (!keyWentToLeft) {
      a->right = this->addToNode(a->right, val);
      if (a->right)
        a->right->parent = a;
    } else {
      a->left = this->addToNode(a->left, val);
      if (a->left)
        a->left->parent = a;
    }
    a->height = 1 + this->getMaxHeight(a);
    return this->balance(a);
  }
  int getMaxHeight(node<T> *a) {
    int tmp1 = getHeight(a->left);
    int tmp2 = getHeight(a->right);
    return (tmp1 > tmp2) ? tmp1 : tmp2;
  }
  int getHeight(node<T> *a) {
    if (a == NULL)
      return -1;
    else
      return a->height;
  }
  int getBalance(node<T> *a) {
    if (a == NULL)
      return 0;
    return (this->getHeight(a->left) - this->getHeight(a->right));
  }
  node<T> *leftRotate(node<T> *a) {
    node<T> *x = a->right;
    node<T> *y = a;
    node<T> *tmp = x->left;
    x->left = y;
    y->right = tmp;
    if (tmp)
      tmp->parent = y;
    y->height = this->getMaxHeight(y) + 1;
    x->height = this->getMaxHeight(x) + 1;
    return x;
  }
  node<T> *rightRotate(node<T> *a) {
    node<T> *x = a->left;
    node<T> *y = a;
    node<T> *tmp = x->right;
    x->right = y;
    y->left = tmp;
    if (tmp)
      tmp->parent = y;
    y->height = this->getMaxHeight(y) + 1;
    x->height = this->getMaxHeight(x) + 1;
    return x;
  }

  void inord(node<T> *a) {
    if (a) {
      inord(a->left);
      cout << a->data << " ";
      inord(a->right);
    }
  }
  void postOrd(node<T> *a) {
    if (a) {
      this->postOrd(a->left);
      this->postOrd(a->right);
      cout << a->data << " ";
    }
  }
  void preOrd(node<T> *a) {
    if (a) {
      cout << a->data << " ";
      this->preOrd(a->left);
      this->preOrd(a->right);
    }
  }

  vector<T> getElems(node<T> *a) {
    vector<T> res;
    if (a) {
      vector<T> l = move(getElems(a->left));
      vector<T> r = move(getElems(a->right));
      l.push_back(a->data);
      if (!r.empty())
        l.insert(l.end(), r.begin(), r.end());
      res = move(l);
    }
    return res;
  }

  void freeAll() {
    if (!root)
      return;
    unordered_set<node<T> *> visited;
    stack<node<T> *> s;
    s.push(root);
    visited.insert(root);
    node<T> *tmp;
    while (!s.empty()) {
      tmp = s.top();
      s.pop();
      if (tmp->left && visited.find(tmp->left) == visited.end())
        s.push(tmp->left);
      if (tmp->right && visited.find(tmp->right) == visited.end())
        s.push(tmp->right);
      visited.erase(tmp);
      delete tmp;
    }
  }
};

int main() {
  BST<int> a{{11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31}};
  // for(auto i: {11,6,8,19,4,10,5,17,43,49,31}){
  //     a.insert(i);
  // }
  char x;
  int val;
  node<int> *searchRes;
  string tmp;
  auto arr = a.getAllElements();
  for (auto y : arr)
    cout << y << " ";
  cout << endl;
  auto b{move(a)};
  b.inorder();
  a.inorder();
  auto c = b;
  c.inorder();
  vector<int> y(10000000);
  iota(y.begin(), y.end(), 1);
  BST<int> d(y);
  for (auto x : y)
    d.delete_node(x);
  cout << "Done " << endl;
  //	cin.get();

  //    try
  //    {
  //        throwsError(c);
  //    }
  //    catch(const std::exception& e)
  //    {
  //        std::cerr << e.what() << '\n';
  //    }
  // while(1){
  //     cin>>x;
  //     if(x=='a'){
  //         cout<<"Enter val to insert: ";
  //         cin>>val;
  //         a.insert(val);
  //     }else if(x=='b'){
  // 		cout<<"Inorder: ";
  //         a.inorder();
  // 		cout<<"PreOrder : ";
  //         a.preOrder();
  // 		cout<<"PostOrder : ";
  //         a.postOrder();
  //     }else if(x=='c'){
  //         cin>>val;
  //         a.delete_node(val);
  //     }else if(x=='d'){
  //         cin>>val;
  //         searchRes=a.search(val);
  //         if(searchRes){
  //             cout<<val<<" Found in tree"<<endl;
  //         }else{
  //             cout<<"Not Found"<<endl;
  //         }
  //     }else{
  //         break;
  //     }

  // }
}
