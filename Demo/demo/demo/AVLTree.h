//Name - Gurkirat Singh Arora
//Date - 22nd July, 2022
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
    bool contains(AVLTreeNode<T1,T2>* temp,const T1 &k);
    void assignheight(AVLTreeNode<T1,T2>* temp);
    AVLTreeNode<T1,T2>* insertRecursive(AVLTreeNode<T1,T2>* r, AVLTreeNode<T1,T2>* new_node);
    int Nodeheight(AVLTreeNode<T1,T2>* x);
    AVLTreeNode<T1,T2>* removeNode(AVLTreeNode<T1,T2> * r,const T1 &v);
    AVLTreeNode<T1,T2>* minValueNode(AVLTreeNode<T1,T2> * temp);
    // Tree attributes go here
    // Your tree MUST have a root node named root
public:
    void* getRoot() const
    {
        return root;
    }; // DO NOT REMOVE
    //POST: root is set to nullptr and the size of AVLTree to 0
    AVLTree (); //Default Constructor
    
    //PARAM: temp - AVLTree to be copied
    //POST: new AVLTree is created that is the deep copy of temp
    AVLTree(const AVLTree<T1,T2> &temp);  //Copy Constructor
    
    //PARAM: temp- AVLTree to be copied
    //POST: dynamic memory of calling object deallocate, calling object is set to a deep copy of temp
    AVLTree<T1,T2>& operator=(const AVLTree<T1,T2> &temp); //Assignment Operator
    
    //POST: dynamic memory associated with object is deallocated
    ~AVLTree<T1,T2>();   //Destructor
    
    //PARAM: key k
    //POST: returns the corresponding value if found else throws a runtime exception
    T2 search (const T1 &k);
    
    //POST: returns the size of the AVLTree
    unsigned int size();
    
    //POST: returns the vector that contains all the values in the tree
    vector<T2> values();
    
    //POST: returns the vector that contains all the keys in the tree
    vector<T1> keys();
    
    //PARAM: key is the first parammeter and value is the second parameter
    //POST: If the tree does not contains a node with the k key then inserts and returns true else returns false
    bool insert(const T1 &k,const T2 &val);
    
    //PARAM; key k
    //POST: removes the key and associated value from the tree, returns true if found, else returns false
    bool remove(const T1 &k);
};

template<class T1, class T2>
AVLTree<T1,T2>::AVLTree () //Default Constructor
{
    root= nullptr;
    tree_size=0;
}

template<class T1, class T2>
AVLTree<T1,T2>::AVLTree(const AVLTree<T1,T2> &temp) //Copy Constructor
{
    root=nullptr;
    if(temp.root==nullptr)
    {
        tree_size=0;
    }
    else
    {
        copy(temp.root);
        tree_size=temp.tree_size;
    }
}

template<class T1, class T2>
AVLTree<T1,T2>& AVLTree<T1,T2>:: operator=(const AVLTree<T1,T2> &temp)  //Assignment Operator
{
    AVLTreeNode<T1,T2>* current= temp.root;
    if(this == &temp)
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
AVLTree<T1,T2>::~AVLTree<T1,T2>()  //Destructor
{
    deleteNode(root);
    tree_size=0;
}
template<class T1,class T2>
bool AVLTree<T1,T2>::insert(const T1 &k,const T2 &val)
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
template<class T1, class T2>
bool AVLTree<T1,T2>:: remove(const T1 &k)
{
    if(contains(root, k)==false)
    {
        return false;
    }
    else
    {
        root= removeNode(root,k);
        assignheight(root);
        tree_size--;
        return true;
    }
}

template<class T1, class T2>
 T2 AVLTree<T1,T2>::search (const T1 &k)
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
 unsigned int AVLTree<T1,T2>::size()
{
    return tree_size;
}
template<class T1,class T2>
void AVLTree<T1,T2>::deleteNode(AVLTreeNode<T1,T2>* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    deleteNode(ptr->left);
    deleteNode(ptr->right);
    delete ptr;
}
template<class T1,class T2>
AVLTreeNode<T1,T2>* AVLTree<T1,T2>::removeNode(AVLTreeNode<T1,T2> * r,const T1 &v) {
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
  if (bf == 2 && getBalancedFactor(r -> left) >= 0)
  {
    return rightRotate(r);
  }
  else if (bf == 2 && getBalancedFactor(r -> left) == -1)
  {
    r -> left = leftRotate(r -> left);
    return rightRotate(r);
  }
  else if (bf == -2 && getBalancedFactor(r -> right) <= 0)
  {
    return leftRotate(r);
  }
  else if (bf == -2 && getBalancedFactor(r -> right) == 1)
  {
    r -> right = rightRotate(r -> right);
    return leftRotate(r);
  }
  return r;
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
    return r;
}
template<class T1,class T2>
bool AVLTree<T1,T2>::contains(AVLTreeNode<T1,T2>* temp,const T1 &k)
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

template<class T1,class T2>
int AVLTree<T1,T2>::Nodeheight(AVLTreeNode<T1,T2>* ptr)
{
    if(ptr == NULL)
    {
        return -1;
    }
   else
   {
       int lh= Nodeheight(ptr->left);
       int rh= Nodeheight(ptr->right);
       if(lh>rh)
       {
           return (lh + 1);
       }
       else
       {
           return (rh + 1);
           
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

template<class T1,class T2>
void AVLTree<T1,T2>:: InorderTraversalvalue(AVLTreeNode<T1,T2>* temp, vector<T2> &v)
{
    if(temp==NULL)
    {
        return;
    }
    InorderTraversalvalue(temp->left, v);
    v.push_back(temp->value);
    InorderTraversalvalue(temp->right, v);
}
template<class T1,class T2>
void AVLTree<T1,T2>:: InorderTraversalkey(AVLTreeNode<T1,T2>* temp, vector<T1> &v)
{
    if(temp==NULL)
    {
        return;
    }
    InorderTraversalkey(temp->left, v);
    v.push_back(temp->key);
    InorderTraversalkey(temp->right, v);
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
