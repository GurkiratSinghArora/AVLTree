#include<iostream>
#include<stdexcept>
#include<vector>
using std:: runtime_error;
using std::vector;
using std::cout;
// AVL Node Class
template<class T1,class T2> //T1 = node's key ,T2 = value
class AVLTreeNode
{
public:
    T1 key;
    T2 value;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode* parent;
    unsigned int height;
   // Should have attributes named:
   // parent - pointer to parent
   // left - pointer to left child
   // right - pointer to right child
   // key - node's key
   // value - node's value
   // height - node's height
   // Constructors ...
    AVLTreeNode(T1 k, T2 val)
    {
        key = k;
        value = val;
        left= nullptr;
        right= nullptr;
        parent = nullptr;
        height = 0;
    }
};
// AVL Tree class
template<class T1,class T2> //T1 = node's key ,T2 = value
class AVLTree
{
private:
    AVLTreeNode<T1,T2>* root;
    unsigned int tree_size;
    void InorderTraversalvalue(AVLTreeNode<T1,T2>* temp, vector<T2> &v);
    void InorderTraversalkey(AVLTreeNode<T1,T2>* temp, vector<T1> &v);
    void copy(AVLTreeNode<T1,T2>* temp);
    void deleteNode(AVLTreeNode<T1,T2>* ptr );
    int getBalancedFactor(AVLTreeNode<T1,T2>* temp);
    AVLTreeNode<T1,T2>* rightRotate(AVLTreeNode<T1,T2>* temp);
    AVLTreeNode<T1,T2>* leftRotate(AVLTreeNode<T1,T2>* temp);
    bool contains(AVLTreeNode<T1,T2>* temp, T1 k);
    void assignheight(AVLTreeNode<T1,T2>* temp);
    AVLTreeNode<T1,T2>* insertRecursive(AVLTreeNode<T1,T2>* r, AVLTreeNode<T1,T2>* new_node);
    int Nodeheight(AVLTreeNode<T1,T2>* x);
    AVLTreeNode<T1,T2>* removeNode(AVLTreeNode<T1,T2> * r, T1 v);
    AVLTreeNode<T1,T2>* minValueNode(AVLTreeNode<T1,T2> * temp);
    // Tree attributes go here
    // Your tree MUST have a root node named root
public:
    void* getRoot() const
    {
        return root;
    }; // DO NOT REMOVE
    AVLTree (); //Default Constructor
    AVLTree(const AVLTree<T1,T2> &temp);  //Copy Constructor
    AVLTree<T1,T2>& operator=(const AVLTree<T1,T2> &temp); //Assignment Operator
    ~AVLTree<T1,T2>();   //Destructor
    T2 search (T1 k);
    unsigned int size();
    vector<T2> values();
    vector<T1> keys();
    bool insert(T1 k, T2 val);
    bool remove(T1 k);
};
template<class T1, class T2>
 unsigned int AVLTree<T1,T2>::size()
{
    return tree_size;
}

template<class T1, class T2>
AVLTree<T1,T2>::AVLTree () //Default Constructor
{
    root= nullptr;
    tree_size=0;
}
template<class T1, class T2>
AVLTree<T1,T2>::AVLTree(const AVLTree<T1,T2> &temp) //Copy Constructor
{
    //if(temp.root==nullptr)
    //{
        root=nullptr;
        //tree_size=0;
    //}
    //else
    //{
        copy(temp.root);
        tree_size=temp.tree_size;
    //}
}
template<class T1, class T2>
AVLTree<T1,T2>& AVLTree<T1,T2>:: operator=(const AVLTree<T1,T2> &temp)  //Assignment Operator
{
    AVLTreeNode<T1,T2>* current= temp.root;
    if(root == current)
    {
        return *this;
    }
    if(root != nullptr)
    {
       deleteNode(root);
    }
    copy(current);
    tree_size=temp.tree_size;
    return *this;
}
template<class T1, class T2>
bool AVLTree<T1,T2>:: remove(T1 k)
{
    if(contains(root, k)==false)
    {
        return false;
    }
    else
    {
        root= removeNode(root,k);
        assignheight(root);
        return true;
    }
}

template<class T1, class T2>
AVLTree<T1,T2>::~AVLTree<T1,T2>()  //Destructor
{
    deleteNode(root);
    tree_size=0;
}
template<class T1,class T2>
void AVLTree<T1,T2>::deleteNode(AVLTreeNode<T1,T2>* ptr)
{
    if(ptr==NULL)
        return;
    //if(ptr->left!=NULL)
        deleteNode(ptr->left);
    //if(ptr->right!=NULL)
        deleteNode(ptr->right);
    delete ptr;
}
template<class T1,class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>::removeNode(AVLTreeNode<T1,T2> * r, T1 v) {
  // base case
  if (r == NULL)
  {
    return NULL;
  }
  else if (v < r -> key)
  {
    r->left=removeNode(r->left,v);
  }
  else if (v > r -> key)
  {
    r->right =removeNode(r ->right,v);
  }
  else
  {
    if (r -> left == NULL && r->right!=NULL)
    {
        AVLTreeNode<T1,T2>* temp =r->right;
        temp->parent = r->parent;
        delete r;
        return temp;
    }
    else if (r->right==NULL && r->left!=NULL)
    {
        AVLTreeNode<T1,T2>* temp =r ->left;
        temp->parent= r->parent;
        delete r;
        return temp;
    }
    else if(r->right!=NULL && r->left!=NULL)
    {
        AVLTreeNode<T1,T2>* temp = minValueNode(r -> right);
        r->key= temp->key;
        r -> value = temp -> value;
        r->height= temp->height;
        r -> right = removeNode(r -> right, temp -> key);
    }
    else
    {
        delete r;
        return NULL;
    }
  }
  assignheight(r);
  int bf = getBalancedFactor(r);
  // Left Left Imbalance/Case or Right rotation
  if (bf == 2 && getBalancedFactor(r -> left) >= 0)
    return rightRotate(r);
  // Left Right Imbalance/Case or LR rotation
  else if (bf == 2 && getBalancedFactor(r -> left) == -1) {
    r -> left = leftRotate(r -> left);
    return rightRotate(r);
  }
  // Right Right Imbalance/Case or Left rotation
  else if (bf == -2 && getBalancedFactor(r -> right) <= 0)
    return leftRotate(r);
  // Right Left Imbalance/Case or RL rotation
  else if (bf == -2 && getBalancedFactor(r -> right) == 1) {
    r -> right = rightRotate(r -> right);
    return leftRotate(r);
  }
  //assignheight(r);
  tree_size--;
  return r;
}
template<class T1,class T2>
bool AVLTree<T1,T2>::insert(T1 k, T2 val)
{
    AVLTreeNode<T1,T2>* temp;
    temp = root;
    if(contains(root,k)==true)
    {
        return false;
    }
    AVLTreeNode<T1,T2>* x= new AVLTreeNode<T1,T2>(k,val);
    root= insertRecursive(root, x);
    assignheight(root);
    tree_size++;
    return true;
}
template<class T1,class T2>
int AVLTree<T1,T2>::getBalancedFactor(AVLTreeNode<T1, T2> *temp)
{
    if(temp==NULL)
    {
        return -1;
    }
    return Nodeheight(temp->left) - Nodeheight(temp->right);
}
//template<class T1,class T2>
//int AVLTree<T1,T2>::getBalancedFactor(AVLTreeNode<T1,T2>* temp)
//{
//    if(temp==NULL)
//    {
//        return -1;
//    }
//    if(temp->left==NULL && temp->right==NULL)
//    {
//        return 0;
//    }
//    else if(temp->left==NULL)
//    {
//        return (-1 - temp->right->height);
//    }
//    else if( temp->right==NULL)
//    {
//        return (temp->left->height +1);
//    }
//    else
//        return (temp->left->height - temp->right->height);
//}
template<class T1, class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>::insertRecursive(AVLTreeNode<T1,T2>* r, AVLTreeNode<T1,T2>* new_node)
{
    if(r==NULL)
    {
        r= new_node;
        return r;
    }
    if(new_node->key < r->key)
    {
        new_node->parent=r;
        r->left=insertRecursive(r->left,new_node);
    }
    else if (new_node->key > r->key)
    {
        new_node->parent=r;
        r->right=insertRecursive(r->right,new_node);
    }
    assignheight(root);
    int bf=getBalancedFactor(r);
    if(bf> 1 && new_node->key < r->left->key)
    {
        return rightRotate(r);
    }
    if(bf< -1 && new_node->key> r->right->key)
    {
        return leftRotate(r);
    }
    if(bf > 1 && new_node->key > r->left->key)
    {
        r->left= leftRotate(r->left);
        return rightRotate(r);
    }
    if(bf<-1 && new_node->key < r->right->key)
    {
        r->right= rightRotate(r->right);
        return leftRotate(r);
    }
    //assignheight(root);
    return r;
}
template<class T1,class T2>
bool AVLTree<T1,T2>::contains(AVLTreeNode<T1,T2>* temp, T1 k)
{
    if(temp==nullptr)
    {
        return false;
    }
    if(temp->key==k)
    {
        return true;
    }
    if(temp->key > k)
    {
        temp=temp->left;
        return contains(temp,k);
    }
    else
    {
        temp=temp->right;
        return contains(temp,k);
    }
}
template<class T1, class T2>
void AVLTree<T1,T2>::copy(AVLTreeNode<T1,T2>* current)
{
    if(current==NULL)
    {
        return;
    }
    insert(current->key,current->value);
    copy(current->left);
    copy(current->right);
}
template<class T1, class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>::rightRotate(AVLTreeNode<T1,T2>* x)
{
    AVLTreeNode<T1,T2>* y = x->left;
    AVLTreeNode<T1,T2>* t= y->right;
    y->right=x;
    x->left=t;
    return y;
}
template<class T1, class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>::leftRotate(AVLTreeNode<T1,T2>* x)
{
    AVLTreeNode<T1,T2>* y = x->right;
    AVLTreeNode<T1,T2>* t= y->left;
    y->left=x;
    x->right=t;
    return y;
}
template<class T1, class T2>
 T2 AVLTree<T1,T2>::search (T1 k)
{
     AVLTreeNode<T1,T2>* temp;
     temp = root;
     while(temp!=nullptr)
     {
         if(temp->key==k)
         {
             return temp->value;
         }
         if(temp->key > k)
         {
             temp= temp->left;
         }
         else if(temp->key < k)
         {
             temp = temp->right;
         }
     }
     throw runtime_error("Key Not Found");
 }
template<class T1,class T2>
int AVLTree<T1,T2>::Nodeheight(AVLTreeNode<T1,T2>* r)
{
    if(r == NULL)
        return -1;
   else
   {
       int lheight= Nodeheight(r->left);
       int rheight= Nodeheight(r->right);
       if(lheight>rheight)
       {
           return (lheight + 1);
       }
       else
       {
           return (rheight + 1);
           
       }
   }
}
template<class T1,class T2>
void AVLTree<T1,T2>::assignheight(AVLTreeNode<T1,T2>* temp)
{
    if(temp==NULL)
    {
        return;
    }
    assignheight(temp->left);
    assignheight(temp->right);
    temp->height=Nodeheight(temp);
}
//template<class T1,class T2>
//int setheight(AVLTreeNode<T1,T2>* temp)
//{
//    if(temp->left==NULL && temp->right==NULL)
//    {
//        return 0;
//    }
//    if(temp->left!=NULL && temp->right==NULL)
//    {
//        return setheight(temp->left)+1;
//    }
//    if(temp->left==NULL && temp->right!=NULL)
//    {
//         return setheight(temp->right)+1;
//    }
//    if(setheight(temp->left) >= setheight(temp->right))
//    {
//        return setheight(temp->left)+1;
//    }
//    else
//    {
//        return setheight(temp->right)+1;
//    }
//}

template<class T1,class T2>
void AVLTree<T1,T2>:: InorderTraversalvalue(AVLTreeNode<T1,T2>* temp, vector<T2> &v)
{
    if(temp==NULL)
        return;
    InorderTraversalvalue(temp->left, v);
    v.push_back(temp->value);
    InorderTraversalvalue(temp->right, v);
}
template<class T1,class T2>
void AVLTree<T1,T2>:: InorderTraversalkey(AVLTreeNode<T1,T2>* temp, vector<T1> &v)
{
    if(temp==NULL)
        return;
    InorderTraversalkey(temp->left, v);
    v.push_back(temp->key);
    InorderTraversalkey(temp->right, v);
}
template<class T1, class T2>
vector<T2> AVLTree<T1,T2>:: values()
{
    AVLTreeNode<T1,T2>* temp;
    temp=root;
    vector<T2> v;
    if(root==NULL)
    {
       return v;
    }
    InorderTraversalvalue(temp,v);
    return v;
}
template<class T1, class T2>
vector<T1> AVLTree<T1,T2>:: keys()
{
    AVLTreeNode<T1,T2>* temp;
    temp=root;
    vector<T1> v;
    if(root==NULL)
    {
       return v;
    }
    InorderTraversalkey(temp,v);
    return v;
}
template<class T1, class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>:: minValueNode(AVLTreeNode<T1,T2> * temp)
{
    AVLTreeNode<T1,T2>* current= temp;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
