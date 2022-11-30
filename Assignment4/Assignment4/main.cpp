// Basic test program for AVL Tree
// Author: John Edgar
// Date: July 2022

#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include "AVLTree.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::vector;
using std::queue;
 
void a4marking();
template <class K, class V>
bool checkAVLTree(const AVLTree<K, V>& tree);

// https://stackoverflow.com/questions/4426474/is-passing-pointer-argument-pass-by-value-in-c#:~:text=Pointers%20are%20passed%20by%20value,point%20to%20the%20old%20object.
 
void testDefaultConstructor();
void testCopyConstructor();
void testAssignmentOperator();
void testRemoveNodeBST();
void testLeftRotateInsert();
void testRightRotateInsert();
void testLeftRightRotateInsert();
void testRightLeftRotateInsert();
void testDelete();
void testRemoveLeaf();
void testRemoveNodeTwoChildren();
void testRemoveNodeOneChild();
template <class K, class V>
void printLevelOrder(AVLTreeNode<K,V>* node);
void printKeys(vector<unsigned> keys);
        
int main()
{
    // a4marking();
    testDefaultConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testRemoveNodeBST();
    testLeftRotateInsert();
    testRightRotateInsert();
    testLeftRightRotateInsert();
    testRightLeftRotateInsert();
    testDelete();
    testRemoveLeaf();
    testRemoveNodeTwoChildren();
    testRemoveNodeOneChild();
}

void a4marking()
{
    AVLTree<int, int> aspen;
    // Method return values
    bool success = aspen.insert(1, 2);
    int result = aspen.search(1);
    checkAVLTree<int, int>(aspen);
    success = aspen.remove(1);
    vector<int> v2 = aspen.values();
    vector<int> k1 = aspen.keys();
    AVLTree<int, int> larch(aspen);
    aspen = larch;
    cout << endl << "end a4 test" << endl;
}
template <class K, class V>
bool checkAVLTree(const AVLTree<K, V>& tree)
{
    AVLTreeNode<K, V>* nd = (AVLTreeNode<K, V>*)tree.getRoot();
    cout << "height = " << nd->height << endl;
    return false;
}

void testDefaultConstructor() {
    cout << "====================== Default construtor ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a;
    bool removed = a.remove(1);
    if (removed) cout << "Error: Tree should be empty" << endl;
    else cout << "Passed: Tree empty" << endl;
    unsigned value;
    try {
        value = a.search(1);
    } catch(runtime_error const &) {
        cout << "Passed: Exception thrown when searching non-existent key" << endl;
    }
    vector<unsigned> values = a.values();
    if (values.size() == 0) cout << "Passed: No values in the tree" << endl;
    else cout << "Error: There should be no values" << endl;
    vector<unsigned> keys = a.keys();
    if (keys.size() == 0) cout << "Passed: No keys in the tree" << endl;
    else cout << "Error: There should be no keys" << endl;
    if (a.size() == 0) cout << "Passed: Tree is empty" << endl;
    else cout << "Error: Size should be empty" << endl;
    if (a.getRoot() == nullptr) cout << "Passed: Root node is nullptr" << endl;
    else cout << "Error: Empty tree should be nullptr" << endl;
    cout << "========================================================================================" << endl;

}

void testCopyConstructor() {
    cout << "====================== Copy construtor ======================" << endl << endl;
    // insert: 10 5 15 12 18
    AVLTree<unsigned,unsigned> avl;
    avl.insert(10, 1);
    avl.insert(5, 2);
    avl.insert(15, 3);
    avl.insert(12, 4);
    avl.insert(18, 5);

    cout << "size of tree: " << avl.size() << endl;
    AVLTree<unsigned,unsigned> avl2(avl);
   
    vector<unsigned> keys = avl.keys();
    vector<unsigned> keys2 = avl2.keys();
     
    cout << "inorder: " << endl;
     
    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }

    cout << endl;
  
    cout << "copied inorder: " << endl;
     
    for (unsigned int i = 0; i < keys2.size(); i++) {
        cout << keys2[i] << " ";
    }
    cout << endl;

    cout << "Removing nodes from original" << endl;
    avl.remove(10);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(5);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(15);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(12);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(18);
    // keys = avl.keys();
    // printKeys(keys);
 
    cout << "inorder: " << endl;
    keys = avl.keys();
    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }

    cout << endl;

    cout << "copied inorder: " << endl;
    
    for (unsigned int i = 0; i < keys2.size(); i++) {
        cout << keys2[i] << " ";
    }
    cout << endl;

    AVLTreeNode<unsigned,unsigned>* root = (AVLTreeNode<unsigned,unsigned>*)avl2.getRoot();
    printLevelOrder(root);

    cout << "========================================================================================" << endl;
}

void testAssignmentOperator() {
    cout << "====================== Assignment operator ======================" << endl << endl;
    // insert: 10 5 15 12 18
    AVLTree<unsigned,unsigned> avl;
    avl.insert(10, 1);
    avl.insert(5, 2);
    avl.insert(15, 3);
    avl.insert(12, 4);
    avl.insert(18, 5);

    cout << "size of tree: " << avl.size() << endl;
    AVLTree<unsigned,unsigned> avl2 = avl;
    
    vector<unsigned> keys = avl.keys();
    vector<unsigned> keys2 = avl2.keys();
     
    cout << "inorder: " << endl;
     
    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }

    cout << endl;
  
    cout << "assigned inorder: " << endl;
     
    for (unsigned int i = 0; i < keys2.size(); i++) {
        cout << keys2[i] << " ";
    }
    cout << endl;

    cout << "Removing nodes from original" << endl;
    avl.remove(10);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(5);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(15);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(12);
    // keys = avl.keys();
    // printKeys(keys);
    avl.remove(18);
    // keys = avl.keys();
    // printKeys(keys);
 
    cout << "inorder: " << endl;
    keys = avl.keys();
    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }

    cout << endl;

    cout << "assigned inorder: " << endl;
    
    for (unsigned int i = 0; i < keys2.size(); i++) {
        cout << keys2[i] << " ";
    }
    cout << endl;

    AVLTreeNode<unsigned,unsigned>* root = (AVLTreeNode<unsigned,unsigned>*)avl2.getRoot();
    printLevelOrder(root);

    cout << "========================================================================================" << endl;
}

void testRemoveNodeBST() {
    // Node doesn't exist
    cout << "====================== Removing a node that doesn't exist ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a0;
    vector<unsigned> v0 = a0.keys();
    printKeys(v0);
    a0.remove(1);
    v0 = a0.keys();
    printKeys(v0);
    cout << "Expected output: " << endl;
    cout << "========================================================================================" << endl;


    // Remove single root node:
    cout << "====================== Remove a root node as the only node in the AVLTree<unsigned,unsigned> ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(10, 1);
    vector<unsigned> v1 = a1.keys();
    printKeys(v1);
    a1.remove(10);
    v1 = a1.keys();
    printKeys(v1);
    cout << "Expected output: " << endl;
    cout << "========================================================================================" << endl;

    
    // Remove root node w/ left child
    cout << "====================== Remove root node w/ left child ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a2;
    a2.insert(10, 1);
    a2.insert(5, 2);
    a2.insert(3, 3);
    a2.insert(6, 4);
    a2.insert(8, 5);
    vector<unsigned> v2 = a2.keys();
    printKeys(v2);
    a2.remove(10);
    v2 = a2.keys();
    printKeys(v2);
    cout << "Expected output: 3 5 6 8" << endl;
    cout << "========================================================================================" << endl;

    // Remove root node w/ right child
    cout << "====================== Remove root node w/ right child ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a3;
    a3.insert(10, 1);
    a3.insert(20, 2);
    a3.insert(15, 3);
    a3.insert(30, 4);
    a3.insert(25, 5);
    vector<unsigned> v3 = a3.keys();
    printKeys(v3);
    a3.remove(10);
    v3 = a3.keys();
    printKeys(v3);
    cout << "Expected output: 15 20 25 30" << endl;
    cout << "========================================================================================" << endl;
 
    cout << "====================== Remove root node w/ left and right child ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a4;
    a4.insert(10, 1);
    a4.insert(5, 2);
    a4.insert(20, 3);
    a4.insert(3, 4);
    a4.insert(6, 5);
    a4.insert(15, 6);
    a4.insert(30, 7);
    a4.insert(25, 8);
    a4.insert(8, 9);
    a4.insert(7, 10);
    vector<unsigned> v4 = a4.keys();
    printKeys(v4);
    a4.remove(10);
    v4 = a4.keys();
    printKeys(v4);
    cout << "Expected output: 3 5 6 7 8 15 20 25 30" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove leaf node (right child) ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a5;
    a5.insert(20, 1);
    a5.insert(10, 2);
    a5.insert(30, 3);
    a5.insert(5, 4);
    a5.insert(15, 5);
    a5.insert(25, 6);
    a5.insert(35, 7);
    vector<unsigned> v5 = a5.keys();
    printKeys(v5);
    a5.remove(35);
    v5 = a5.keys();
    printKeys(v5);
    cout << "Expected output: 5 10 15 20 25 30" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove leaf node (left child) ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a6;
    a6.insert(20, 1);
    a6.insert(10, 2);
    a6.insert(30, 3);
    a6.insert(5, 4);
    a6.insert(15, 5);
    a6.insert(25, 6);
    a6.insert(35, 7);
    vector<unsigned> v6 = a6.keys();
    printKeys(v6);
    a6.remove(25);
    v6 = a6.keys();
    printKeys(v6);
    cout << "Expected output: 5 10 15 20 30 35" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node from parent node left - parent has no right subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a7;
    a7.insert(20, 1);
    a7.insert(10, 2);
    a7.insert(5, 3);
    a7.insert(2, 4);
    a7.insert(1, 5);
    a7.insert(3, 6);
    vector<unsigned> v7 = a7.keys();
    printKeys(v7);
    a7.remove(5);
    v7 = a7.keys();
    printKeys(v7);
    cout << "Expected output: 1 2 3 10 20" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node from parent node right - parent has no right subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a8;
    a8.insert(20, 1);
    a8.insert(10, 2);
    a8.insert(15, 3);
    a8.insert(13, 4);
    a8.insert(11, 5);
    a8.insert(14, 6);
    vector<unsigned> v8 = a8.keys();
    printKeys(v8);
    a8.remove(15);
    v8 = a8.keys();
    printKeys(v8);
    cout << "Expected output: 10 11 13 14 20" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node from parent node left - parent has no left subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a9;
    a9.insert(20, 1);
    a9.insert(10, 2);
    a9.insert(15, 3);
    a9.insert(18, 4);
    a9.insert(16, 5);
    a9.insert(19, 6);
    vector<unsigned> v9 = a9.keys();
    printKeys(v9);
    a9.remove(15);
    v9 = a9.keys();
    printKeys(v9);
    cout << "Expected output: 10 16 18 19 20" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node from parent node right - parent has no left subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a10;
    a10.insert(20, 1);
    a10.insert(10, 2);
    a10.insert(5, 3);
    a10.insert(8, 4);
    a10.insert(9, 5);
    vector<unsigned> v10 = a10.keys();
    printKeys(v10);
    a10.remove(5);
    v10 = a10.keys();
    printKeys(v10);
    cout << "Expected output: 8 9 10 20" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node w/ 2 children in left subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a11;
    a11.insert(47, 1);
    a11.insert(32, 2);
    a11.insert(63, 3);
    a11.insert(19, 4);
    a11.insert(41, 5);
    a11.insert(54, 6);
    a11.insert(10, 7);
    a11.insert(23, 8);
    a11.insert(37, 9);
    a11.insert(44, 10);
    a11.insert(53, 11);
    a11.insert(59, 12);
    a11.insert(96, 13);
    a11.insert(7, 14);
    a11.insert(12, 15);
    a11.insert(30, 16);
    a11.insert(57, 17);
    a11.insert(91, 18);
    a11.insert(97, 19);
    vector<unsigned> v11 = a11.keys();
    printKeys(v11);
    a11.remove(32);
    v11 = a11.keys();
    printKeys(v11);
    cout << "Expected output: 7 10 12 19 23 30 37 41 44 47 53 54 57 59 63 91 96 97" << endl;
    cout << "========================================================================================" << endl;

    cout << "====================== Remove node w/ 2 children in right subtree ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a12;
    a12.insert(47, 1);
    a12.insert(32, 2);
    a12.insert(63, 3);
    a12.insert(19, 4);
    a12.insert(41, 5);
    a12.insert(54, 6);
    a12.insert(10, 7);
    a12.insert(23, 8);
    a12.insert(37, 9);
    a12.insert(44, 10);
    a12.insert(53, 11);
    a12.insert(59, 12);
    a12.insert(96, 13);
    a12.insert(7, 14);
    a12.insert(12, 15);
    a12.insert(30, 16);
    a12.insert(57, 17);
    a12.insert(91, 18);
    a12.insert(97, 19);
    vector<unsigned> v12 = a12.keys();
    printKeys(v12);
    a12.remove(63);
    v12 = a12.keys();
    printKeys(v12);
    cout << "Expected output: 7 10 12 19 23 30 32 37 41 44 47 53 54 57 59 91 96 97" << endl;
    cout << "========================================================================================" << endl;
}

void testLeftRotateInsert() {
    cout << "====================== Left rotations on insert ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(30, 2);
    a1.insert(40, 3);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 30 - 1, 20 - 0, 40 - 0" << endl;

    AVLTree<unsigned,unsigned> a2;
    a2.insert(20, 1);
    a2.insert(10, 2);
    a2.insert(30, 3);
    a2.insert(35, 4);
    a2.insert(40, 5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 20 - 2, 10 - 0, 35 - 1, 30 - 0, 40 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(20, 1);
    a3.insert(30, 2);
    a3.insert(10, 3);
    a3.insert(15, 4);
    a3.insert(18, 5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 20 - 2, 15 - 1, 30 - 0, 10 - 0, 18 - 0" << endl;
    cout << "========================================================================================" << endl;
}

void testRightRotateInsert() {
    cout << "====================== Right rotations on insert ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(10, 2);
    a1.insert(5, 3);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 10 - 1, 5 - 0, 20 - 0" << endl;

    AVLTree<unsigned,unsigned> a2;
    a2.insert(30, 1);
    a2.insert(10, 2);
    a2.insert(50, 3);
    a2.insert(8, 4);
    a2.insert(5, 5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 30 - 2, 8 - 1, 50 - 0, 5 - 0, 10 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(30, 1);
    a3.insert(20, 2);
    a3.insert(50, 3);
    a3.insert(10, 4);
    a3.insert(25, 5);
    a3.insert(80, 6);
    a3.insert(24, 7);
    a3.insert(23, 8);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 30 - 3, 20 - 2, 50 - 1, 10 - 0, 24 - 1, 80 - 0, 23 - 0, 25 - 0" << endl;

    AVLTree<unsigned,unsigned> a4;
    a4.insert(20, 1);
    a4.insert(10, 2);
    a4.insert(30, 3);
    a4.insert(5, 4);
    a4.insert(15, 5);
    a4.insert(50, 6);
    a4.insert(3, 7);
    a4.insert(1, 8);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    cout << "Expected output: 20 - 3, 10 - 2, 30 - 1, 3 - 1, 15 - 0, 50 - 0, 1 - 0, 5 - 0" << endl;

    // AVLTree<unsigned,unsigned> a5;
    // a5.insert(30, 1);
    // a5.insert(20, 2);
    // a5.insert(50, 3);
    // a5.insert(10, 4);
    // a5.insert(25, 5);
    // a5.insert(80, 6);
    // a5.insert(24, 7);
    // a5.insert(23, 8);
    // printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a5.getRoot());
    // cout << "Expected output: 30 - 3, 20 - 2, 50 - 1, 10 - 0, 24 - 1, 80 - 0, 23 - 0, 25 - 0" << endl;
    cout << "========================================================================================" << endl;
}

void testLeftRightRotateInsert() {
    cout << "====================== Left right rotations on insert ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(10, 2);
    a1.insert(15, 3);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 15 - 1, 10 - 0, 20 - 0" << endl;

    AVLTree<unsigned,unsigned> a2;
    a2.insert(20, 1);
    a2.insert(30, 2);
    a2.insert(10, 3);
    a2.insert(5, 4);
    a2.insert(50, 5);
    a2.insert(9, 6);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 20 - 2, 9 - 1, 30 - 1, 5 - 0, 10 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(30, 1);
    a3.insert(20, 2);
    a3.insert(50, 3);
    a3.insert(10, 4);
    a3.insert(25, 5);
    a3.insert(80, 6);
    a3.insert(5, 7);
    a3.insert(15, 8);
    a3.insert(12, 9);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 30 - 3, 15 - 2, 50 - 1, 10 - 1, 20 - 1, 80 - 0, 5 - 0, 12 - 0, 25 - 0" << endl;

    AVLTree<unsigned,unsigned> a4;
    a4.insert(30, 1);
    a4.insert(20, 2);
    a4.insert(50, 3);
    a4.insert(80, 4);
    a4.insert(10, 5);
    a4.insert(25, 6);
    a4.insert(5, 7);
    a4.insert(15, 8);
    a4.insert(16, 9);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    cout << "Expected output: 30 - 3, 15 - 2, 50 - 1, 10 - 1, 20 - 1, 80 - 0, 5 - 0, 16 - 0, 25 - 0" << endl;
    cout << "========================================================================================" << endl;
}

void testRightLeftRotateInsert() {
    cout << "====================== Right left rotations on insert ======================" << endl << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(30, 2);
    a1.insert(25, 3);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 25 - 1, 20 - 0, 30 - 0" << endl;
  
    AVLTree<unsigned,unsigned> a2;
    a2.insert(20, 1);
    a2.insert(10, 2);
    a2.insert(30, 3);
    a2.insert(50, 4);
    a2.insert(5, 5);
    a2.insert(35, 6);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 20 - 2, 10 - 1, 35 - 1, 5 - 0, 30 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(20, 1);
    a3.insert(10, 2);
    a3.insert(30, 3);
    a3.insert(5, 4);
    a3.insert(25, 5);
    a3.insert(50, 6);
    a3.insert(60, 7);
    a3.insert(55, 8);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 20 - 3, 10 - 1, 30 - 2, 5 - 0, 25 - 0, 55 - 1, 50 - 0, 60 - 0" << endl;
    cout << "========================================================================================" << endl;
}

void testDelete() {
    AVLTree<unsigned,unsigned> a1;
    a1.insert(44, 1);
    a1.insert(17, 2);
    a1.insert(78, 3);
    a1.insert(32, 4);
    a1.insert(50, 5);
    a1.insert(88, 6);
    a1.insert(48, 7);
    a1.insert(62, 8);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    a1.remove(32);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());

    AVLTree<unsigned,unsigned> a2;
    a2.insert(50, 1);
    a2.insert(25, 2);
    a2.insert(75, 3);
    a2.insert(10, 4);
    a2.insert(30, 5);
    a2.insert(60, 6);
    a2.insert(80, 7);
    a2.insert(5, 8);
    a2.insert(15, 9);
    a2.insert(27, 10);
    a2.insert(55, 11);
    a2.insert(1, 12);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    a2.remove(80);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
}

void testRemoveLeaf() {
    cout << "====================== Rotations - remove leaf ======================" << endl << endl;
    // All done on right subtree from root
    cout << "Left rotations" << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(10, 2);
    a1.insert(40, 3);
    a1.insert(5, 4);
    a1.insert(30, 5);
    a1.insert(50, 6);
    a1.insert(25, 7);
    a1.insert(35, 8);
    a1.insert(45, 9);
    a1.insert(55, 10);
    a1.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 40 - 3, 20 - 2, 50 - 1, 10 - 0, 30 - 1, 45 - 0, 55 - 0, 25 - 0, 35 - 0" << endl;
  
    AVLTree<unsigned,unsigned> a2;
    a2.insert(20, 1);
    a2.insert(10, 2);
    a2.insert(40, 3);
    a2.insert(5, 4);
    a2.insert(30, 5);
    a2.insert(50, 6);
    a2.insert(45, 9);
    a2.insert(55, 10);
    a2.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 40 - 2, 20 - 1, 50 - 1, 10 - 0, 30 - 0, 45 - 0, 55 - 0" << endl;

    cout << "Left right rotations" << endl;
    AVLTree<unsigned,unsigned> a12;
    a12.insert(20, 1);
    a12.insert(10, 2);
    a12.insert(40, 3);
    a12.insert(5, 4);
    a12.insert(15, 5);
    a12.insert(50, 6);
    a12.insert(12, 7);
    a12.insert(18, 8);
    a12.remove(50);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a12.getRoot());
    cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 12 - 0, 18 - 0, 40 - 0" << endl;

    AVLTree<unsigned,unsigned> a13;
    a13.insert(20, 1);
    a13.insert(10, 2);
    a13.insert(40, 3);
    a13.insert(5, 4);
    a13.insert(15, 5);
    a13.insert(50, 6);
    a13.insert(18, 8);
    a13.remove(50);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a13.getRoot());
    cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 18 - 0, 40 - 0" << endl;

    cout << "Right rotations" << endl;
    AVLTree<unsigned,unsigned> a10;
    a10.insert(20, 1);
    a10.insert(10, 2);
    a10.insert(50, 3);
    a10.insert(60, 8);
    a10.insert(5, 4);
    a10.insert(15, 5);
    a10.insert(1, 6);
    a10.insert(6, 7);
    a10.insert(12, 9);
    a10.insert(18, 10);
    a10.remove(60);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a10.getRoot());
    cout << "Expected output: 10 - 3, 5 - 1, 20 - 2, 1 - 0, 6 - 0, 15 - 1, 50 - 0, 12 - 0, 18 - 0" << endl;

    AVLTree<unsigned,unsigned> a11;
    a11.insert(20, 1);
    a11.insert(10, 2);
    a11.insert(50, 3);
    a11.insert(60, 8);
    a11.insert(5, 4);
    a11.insert(15, 5);
    a11.insert(1, 6);
    a11.insert(6, 7);
    a11.remove(60);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a11.getRoot());
    cout << "Expected output: 10 - 2, 5 - 1, 20 - 1, 1 - 0, 6 - 0, 15 - 0, 50 - 0" << endl;

    cout << "Right left rotations" << endl;
    AVLTree<unsigned,unsigned> a3;
    a3.insert(20, 1);
    a3.insert(10, 2);
    a3.insert(40, 3);
    a3.insert(5, 4);
    a3.insert(30, 5);
    a3.insert(50, 6);
    a3.insert(25, 9);
    a3.insert(35, 10);
    a3.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 35 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a4;
    a4.insert(20, 1);
    a4.insert(10, 2);
    a4.insert(40, 3);
    a4.insert(5, 4);
    a4.insert(30, 5);
    a4.insert(50, 6);
    a4.insert(25, 9);
    a4.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a5;
    a5.insert(20, 1);
    a5.insert(10, 2);
    a5.insert(40, 3);
    a5.insert(5, 4);
    a5.insert(30, 5);
    a5.insert(50, 6);
    a5.insert(25, 9);
    a5.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a5.getRoot());
    cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a6;
    a6.insert(20, 1);
    a6.insert(10, 2);
    a6.insert(40, 3);
    a6.insert(5, 4);
    a6.insert(30, 5);
    a6.insert(50, 6);
    a6.insert(35, 9);
    a6.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a6.getRoot());
    cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 35 - 0, 50 - 0" << endl;

    cout << "========================================================================================" << endl;
}

void testRemoveNodeTwoChildren() {
    cout << "====================== Rotations - remove node w/ two children ======================" << endl << endl;
    cout << "Root node" << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(10, 2);
    a1.insert(30, 3);
    a1.insert(25, 4);
    a1.insert(50, 5);
    a1.remove(20);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 30 - 2, 10 - 1, 50 - 0, 25 - 0" << endl;

    AVLTree<unsigned,unsigned> a2;
    a2.insert(15, 1);
    a2.insert(10, 2);
    a2.insert(30, 3);
    a2.insert(5, 4);
    a2.insert(12, 5);
    a2.insert(50, 6);
    a2.insert(1, 7);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    a2.remove(15);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 12 - 2, 5 - 1, 30 - 1, 1 - 0, 10 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(20, 1);
    a3.insert(10, 2);
    a3.insert(30, 3);
    a3.insert(5, 4);
    a3.insert(25, 5);
    a3.insert(50, 6);
    a3.insert(21, 7);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    a3.remove(20);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 25 - 2, 10 - 1, 30 - 1, 5 - 0, 21 - 0, 50 - 0" << endl;

    cout << "Non-root node w/ 2 children node" << endl;
    AVLTree<unsigned,unsigned> a4;
    a4.insert(20, 1);
    a4.insert(10, 2);
    a4.insert(30, 3);
    a4.insert(5, 4);
    a4.insert(15, 5);
    a4.insert(50, 6);
    a4.insert(18, 7);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    a4.remove(10);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    cout << "Expected output: 20 - 2, 15 - 1, 30 - 1, 5 - 0, 18 - 0, 50 - 0" << endl;

    AVLTree<unsigned,unsigned> a5;
    a5.insert(20, 1);
    a5.insert(5, 2);
    a5.insert(30, 3);
    a5.insert(1, 4);
    a5.insert(15, 5);
    a5.insert(50, 6);
    a5.insert(12, 7);
    a5.remove(5);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a5.getRoot());
    cout << "Expected output: 20 - 2, 12 - 1, 30 - 1, 1 - 0, 15 - 0, 50 - 0" << endl;
    // cout << "========================================================================================" << endl;
}

void testRemoveNodeOneChild() {
    cout << "====================== Rotations - remove node w/ one child ======================" << endl << endl;
    cout << "Removing node w/ one child" << endl;
    AVLTree<unsigned,unsigned> a1;
    a1.insert(20, 1);
    a1.insert(10, 2);
    a1.insert(30, 3);
    a1.insert(5, 4);
    a1.insert(25, 5);
    a1.insert(40, 6);
    a1.insert(28, 7);
    a1.remove(10);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a1.getRoot());
    cout << "Expected output: 25 - 2, 20 - 1, 30 - 1, 5 - 0, 28 - 0, 40 - 0" << endl;

    AVLTree<unsigned,unsigned> a2;
    a2.insert(20, 1);
    a2.insert(10, 2);
    a2.insert(30, 3);
    a2.insert(5, 4);
    a2.insert(25, 5);
    a2.insert(40, 6);
    a2.insert(35, 7);
    a2.remove(10);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a2.getRoot());
    cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 5 - 0, 25 - 0, 35 - 0" << endl;

    AVLTree<unsigned,unsigned> a3;
    a3.insert(20, 1);
    a3.insert(10, 2);
    a3.insert(30, 3);
    a3.insert(5, 4);
    a3.insert(15, 5);
    a3.insert(40, 6);
    a3.insert(1, 7);
    a3.insert(18, 8);
    a3.remove(30);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a3.getRoot());
    cout << "Expected output: 10 - 3, 5 - 1, 20 - 2, 1 - 0, 15 - 1, 40 - 0, 18 - 0" << endl;

    AVLTree<unsigned,unsigned> a4;
    a4.insert(20, 1);
    a4.insert(10, 2);
    a4.insert(30, 3);
    a4.insert(5, 4);
    a4.insert(15, 5);
    a4.insert(40, 6);
    a4.insert(18, 8);
    a4.remove(30);
    printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a4.getRoot());
    cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 18 - 0, 40 - 0" << endl;

    cout << "========================================================================================" << endl;
}





void printKeys(vector<unsigned> keys) {
    cout << "Actual output: ";
    for (unsigned int i = 0; i < keys.size(); i++) {
        cout << keys[i] << " ";
    }

    cout << endl;
}

template <class K, class V>
void printLevelOrder(AVLTreeNode<K,V>* node) {
    queue<AVLTreeNode<unsigned,unsigned>*> q;
    q.push(node);
    while (!q.empty()) {
        AVLTreeNode<unsigned,unsigned>* front = q.front();
        cout << "node: " << front->key << " height: " << front->height << endl;
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
        q.pop();
    }
}

//// Basic test program for AVL Tree
//// Author: John Edgar
//// Date: July 2022
//#define RED "\033[31m"   /* Red */
//#define GREEN "\033[32m" /* Green */
//#define RESET "\033[0m"
//
//#include <vector>
//#include <queue>
//#include <iostream>
//#include <stdexcept>
//#include "AVLTree.h"
//
//using std::cout;
//using std::endl;
//using std::queue;
//using std::runtime_error;
//using std::vector;
//
//struct height_key
//{
//    unsigned key;
//    int height;
//};
//typedef struct height_key height_key;
//
//void a4marking();
//template <class K, class V>
//bool checkAVLTree(const AVLTree<K, V> &tree);
//
//// https://stackoverflow.com/questions/4426474/is-passing-pointer-argument-pass-by-value-in-c#:~:text=Pointers%20are%20passed%20by%20value,point%20to%20the%20old%20object.
//
//void testDefaultConstructor();
//void testCopyConstructor();
//void testAssignmentOperator();
//void testRemoveNodeBST();
//void testLeftRotateInsert();
//void testRightRotateInsert();
//void testLeftRightRotateInsert();
//void testRightLeftRotateInsert();
//void testDelete();
//void testRemoveLeaf();
//void testRemoveNodeTwoChildren();
//void testRemoveNodeOneChild();
//template <class K, class V>
//void printLevelOrder(AVLTreeNode<K, V> *node);
//void printKeys(vector<unsigned> keys);
//template <class K, class V>
//vector<height_key> getHeightKeys(AVLTreeNode<K, V> *node);
//void checkCase(vector<height_key> heightKeysResult, vector<height_key> heightKeysExpected);
//void checkCaseBasicVectors(vector<unsigned> Result, vector<unsigned> Expected);
//
//int main()
//{
//    a4marking();
//   testDefaultConstructor();
//   testCopyConstructor();
//   testAssignmentOperator();
//   testRemoveNodeBST();
//    testLeftRotateInsert();
//   testRightRotateInsert();
//    testLeftRightRotateInsert();
//    testRightLeftRotateInsert();
//   testDelete();
//    testRemoveLeaf();
//  testRemoveNodeTwoChildren();
//    testRemoveNodeOneChild();
//}
//
//template <class K, class V>
//vector<height_key> getHeightKeys(AVLTreeNode<K, V> *node)
//{
//    vector<height_key> heightKeys;
//    if (node != nullptr)
//    {
//        heightKeys.push_back(height_key{node->key, static_cast<int>(node->height)});
//        vector<height_key> leftHeightKeys = getHeightKeys(node->left);
//        heightKeys.insert(heightKeys.end(), leftHeightKeys.begin(), leftHeightKeys.end());
//        vector<height_key> rightHeightKeys = getHeightKeys(node->right);
//        heightKeys.insert(heightKeys.end(), rightHeightKeys.begin(), rightHeightKeys.end());
//    }
//    return heightKeys;
//}
//
//void checkCase(vector<height_key> heightKeysResult, vector<height_key> heightKeysExpected)
//{
//    bool pass;
//    if (heightKeysResult.size() != heightKeysExpected.size())
//    {
//        pass = false;
//    }
//    else
//    {
//        for (unsigned i = 0; i < heightKeysResult.size(); i++)
//        {
//            for (unsigned j = 0; j < heightKeysExpected.size(); j++)
//            {
//                if (heightKeysResult[i].key == heightKeysExpected[j].key && heightKeysResult[i].height == heightKeysExpected[j].height)
//                {
//                    pass = true;
//                    break;
//                }
//                else
//                {
//                    pass = false;
//                }
//            }
//        }
//    }
//    if (pass)
//    {
//        cout << GREEN << "Test passed" << endl;
//    }
//    else
//    {
//        cout << RED << "Test failed" << endl;
//    }
//    cout << RESET;
//}
//
//void checkCaseBasicVectors(vector<unsigned> Result, vector<unsigned> Expected)
//{
//    bool pass = false;
//    if (Result.size() == Expected.size())
//    {
//        for (int i = 0; i < Result.size(); i++)
//        {
//            if (Result[i] == Expected[i])
//            {
//                pass = true;
//            }
//            else
//            {
//                pass = false;
//                break;
//            }
//        }
//    }
//    if (pass)
//    {
//        cout << GREEN << "Test passed" << endl;
//    }
//    else
//    {
//        cout << RED << "Test failed" << endl;
//    }
//    cout << RESET;
//}
//
//void a4marking()
//{
//    AVLTree<int, int> aspen;
//    // Method return values
//    bool success = aspen.insert(1, 2);
//    int result = aspen.search(1);
//    checkAVLTree<int, int>(aspen);
//    success = aspen.remove(1);
//    vector<int> v2 = aspen.values();
//    vector<int> k1 = aspen.keys();
//    AVLTree<int, int> larch(aspen);
//    aspen = larch;
//    cout << endl
//         << "end a4 test" << endl;
//}
//template <class K, class V>
//bool checkAVLTree(const AVLTree<K, V> &tree)
//{
//    AVLTreeNode<K, V> *nd = (AVLTreeNode<K, V> *)tree.getRoot();
//    cout << "height = " << nd->height << endl;
//    return false;
//}
//
//void testDefaultConstructor()
//{
//    cout << "====================== Default construtor ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a;
//    bool removed = a.remove(1);
//    if (removed)
//        cout << RED << "Error: Tree should be empty" << endl;
//    else
//        cout << GREEN << "Passed: Tree empty" << endl;
//    cout << RESET;
//    unsigned value;
//    try
//    {
//        value = a.search(1);
//    }
//    catch (runtime_error const &)
//    {
//        cout << GREEN << "Passed: Exception thrown when searching non-existent key" << endl;
//    }
//    cout << RESET;
//    vector<unsigned> values = a.values();
//    if (values.size() == 0)
//        cout << GREEN << "Passed: No values in the tree" << endl;
//    else
//        cout << RED << "Error: There should be no values" << endl;
//    cout << RESET;
//    vector<unsigned> keys = a.keys();
//    if (keys.size() == 0)
//        cout << GREEN << "Passed: No keys in the tree" << endl;
//    else
//        cout << RED << "Error: There should be no keys" << endl;
//    cout << RESET;
//    if (a.size() == 0)
//        cout << GREEN << "Passed: Tree is empty" << endl;
//    else
//        cout << RED << "Error: Size should be empty" << endl;
//    cout << RESET;
//    if (a.getRoot() == nullptr)
//        cout << GREEN << "Passed: Root node is nullptr" << endl;
//    else
//        cout << RED << "Error: Empty tree should be nullptr" << endl;
//    cout << RESET;
//    cout << "========================================================================================" << endl;
//}
//
//void testCopyConstructor()
//{
//    cout << "====================== Copy constructor ======================" << endl
//         << endl;
//    // insert: 10 5 15 12 18
//    AVLTree<unsigned, unsigned> avl;
//    avl.insert(10, 1);
//    avl.insert(5, 2);
//    avl.insert(15, 3);
//    avl.insert(12, 4);
//    avl.insert(18, 5);
//    cout<<"yes";
//    // cout << "size of tree: " << avl.size() << endl;
//    AVLTree<unsigned, unsigned> avl2(avl);
//    vector<unsigned> keys = avl.keys();
//    vector<unsigned> keys2 = avl2.keys();
//
//    // cout << "inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys.size(); i++)
//    // {
//    //     cout << keys[i] << " ";
//    // }
//
//    // cout << endl;
//
//    // cout << "copied inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys2.size(); i++)
//    // {
//    //     cout << keys2[i] << " ";
//    // }
//    // cout << endl;
//
//    cout << "Testing if copied tree is the same as the original" << endl;
//    checkCaseBasicVectors(keys, keys2);
//    // cout << "size of tree: " << avl.size() << endl;
//    // cout << "size of assigned tree: " << avl2.size() << endl;
//
//    cout << "Removing nodes from original" << endl;
//    avl.remove(10);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(5);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(15);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(12);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(18);
//    // keys = avl.keys();
//    // printKeys(keys);
//
//    // cout << "inorder: " << endl;
//    // keys = avl.keys();
//    // for (unsigned int i = 0; i < keys.size(); i++)
//    // {
//    //     cout << keys[i] << " ";
//    // }
//
//    // cout << endl;
//
//    // cout << "copied inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys2.size(); i++)
//    // {
//    //     cout << keys2[i] << " ";
//    // }
//    // cout << endl;
//
//    // cout << "size of tree: " << avl.size() << endl;
//    // cout << "size of assigned tree: " << avl2.size() << endl;
//    if (keys2.size() == 0)
//    {
//        cout << RED << "Error: Inorder is empty" << endl;
//    }
//    else
//    {
//        cout << GREEN << "Passed: Inorder is not empty" << endl;
//    }
//    cout << RESET;
//
//    // AVLTreeNode<unsigned, unsigned> *root = (AVLTreeNode<unsigned, unsigned> *)avl2.getRoot();
//    // printLevelOrder(root);
//
//    cout << "========================================================================================" << endl;
//}
//
//void testAssignmentOperator()
//{
//    cout << "====================== Assignment operator ======================" << endl
//         << endl;
//    // insert: 10 5 15 12 18
//    AVLTree<unsigned, unsigned> avl;
//    avl.insert(10, 1);
//    avl.insert(5, 2);
//    avl.insert(15, 3);
//    avl.insert(12, 4);
//    avl.insert(18, 5);
//
//    AVLTree<unsigned, unsigned> avl2 = avl;
//
//    vector<unsigned> keys = avl.keys();
//    vector<unsigned> keys2 = avl2.keys();
//
//    // cout << "inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys.size(); i++)
//    // {
//    //     cout << keys[i] << " ";
//    // }
//
//    // cout << endl;
//
//    // cout << "assigned inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys2.size(); i++)
//    // {
//    //     cout << keys2[i] << " ";
//    // }
//    // cout << endl;
//
//    cout << "Testing if copied tree is the same as the original" << endl;
//    checkCaseBasicVectors(keys, keys2);
//    // cout << "size of tree: " << avl.size() << endl;
//    // cout << "size of assigned tree: " << avl2.size() << endl;
//
//    cout << "Removing nodes from original" << endl;
//    avl.remove(10);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(5);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(15);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(12);
//    // keys = avl.keys();
//    // printKeys(keys);
//    avl.remove(18);
//    // keys = avl.keys();
//    // printKeys(keys);
//
//    // cout << "inorder: " << endl;
//    // keys = avl.keys();
//    // for (unsigned int i = 0; i < keys.size(); i++)
//    // {
//    //     cout << keys[i] << " ";
//    // }
//
//    // cout << endl;
//
//    // cout << "assigned inorder: " << endl;
//
//    // for (unsigned int i = 0; i < keys2.size(); i++)
//    // {
//    //     cout << keys2[i] << " ";
//    // }
//    // cout << endl;
//
//    // cout << "size of tree: " << avl.size() << endl;
//    // cout << "size of assigned tree: " << avl2.size() << endl;
//    if (keys2.size() == 0)
//    {
//        cout << RED << "Error: Inorder is empty" << endl;
//    }
//    else
//    {
//        cout << GREEN << "Passed: Inorder is not empty" << endl;
//    }
//    cout << RESET;
//    // AVLTreeNode<unsigned, unsigned> *root = (AVLTreeNode<unsigned, unsigned> *)avl2.getRoot();
//    // printLevelOrder(root);
//
//    cout << "========================================================================================" << endl;
//}
//
//void testRemoveNodeBST()
//{
//    // Node doesn't exist
//    cout << "====================== Removing a node that doesn't exist ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a0;
//    vector<unsigned> v0 = a0.keys();
//    // printKeys(v0);
//    a0.remove(1);
//    v0 = a0.keys();
//    // printKeys(v0);
//    if (v0.size() == 0)
//        cout << GREEN << "Passed: No keys in the tree" << endl;
//    else
//        cout << RED << "Error: There should be no keys" << endl;
//    cout << RESET;
//    // cout << "Expected output: " << endl;
//    cout << "========================================================================================" << endl;
//
//    // Remove single root node:
//    cout << "====================== Remove a root node as the only node in the AVLTree<unsigned,unsigned> ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(10, 1);
//    vector<unsigned> v1 = a1.keys();
//    // printKeys(v1);
//    a1.remove(10);
//    v1 = a1.keys();
//    // printKeys(v1);
//    // cout << "Expected output: " << endl;
//    if (v1.size() == 0)
//        cout << GREEN << "Passed: No keys in the tree" << endl;
//    else
//        cout << RED << "Error: There should be no keys" << endl;
//    cout << RESET;
//    cout << "========================================================================================" << endl;
//
//    // Remove root node w/ left child
//    cout << "====================== Remove root node w/ left child ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(10, 1);
//    a2.insert(5, 2);
//    a2.insert(3, 3);
//    a2.insert(6, 4);
//    a2.insert(8, 5);
//    vector<unsigned> v2 = a2.keys();
//    // printKeys(v2);
//    a2.remove(10);
//    v2 = a2.keys();
//    // printKeys(v2);
//    // cout << "Expected output: 3 5 6 8" << endl;
//    checkCaseBasicVectors(v2, vector<unsigned>{3, 5, 6, 8});
//    cout << "========================================================================================" << endl;
//
//    // Remove root node w/ right child
//    cout << "====================== Remove root node w/ right child ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(10, 1);
//    a3.insert(20, 2);
//    a3.insert(15, 3);
//    a3.insert(30, 4);
//    a3.insert(25, 5);
//    vector<unsigned> v3 = a3.keys();
//    // printKeys(v3);
//    a3.remove(10);
//    v3 = a3.keys();
//    // printKeys(v3);
//    // cout << "Expected output: 15 20 25 30" << endl;
//    checkCaseBasicVectors(v3, vector<unsigned>{15, 20, 25, 30});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove root node w/ left and right child ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(10, 1);
//    a4.insert(5, 2);
//    a4.insert(20, 3);
//    a4.insert(3, 4);
//    a4.insert(6, 5);
//    a4.insert(15, 6);
//    a4.insert(30, 7);
//    a4.insert(25, 8);
//    a4.insert(8, 9);
//    a4.insert(7, 10);
//    vector<unsigned> v4 = a4.keys();
//    // printKeys(v4);
//    a4.remove(10);
//    v4 = a4.keys();
//    // printKeys(v4);
//    // cout << "Expected output: 3 5 6 7 8 15 20 25 30" << endl;
//    checkCaseBasicVectors(v4, vector<unsigned>{3, 5, 6, 7, 8, 15, 20, 25, 30});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove leaf node (right child) ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a5;
//    a5.insert(20, 1);
//    a5.insert(10, 2);
//    a5.insert(30, 3);
//    a5.insert(5, 4);
//    a5.insert(15, 5);
//    a5.insert(25, 6);
//    a5.insert(35, 7);
//    vector<unsigned> v5 = a5.keys();
//    // printKeys(v5);
//    a5.remove(35);
//    v5 = a5.keys();
//    // printKeys(v5);
//    // cout << "Expected output: 5 10 15 20 25 30" << endl;
//    checkCaseBasicVectors(v5, vector<unsigned>{5, 10, 15, 20, 25, 30});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove leaf node (left child) ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a6;
//    a6.insert(20, 1);
//    a6.insert(10, 2);
//    a6.insert(30, 3);
//    a6.insert(5, 4);
//    a6.insert(15, 5);
//    a6.insert(25, 6);
//    a6.insert(35, 7);
//    vector<unsigned> v6 = a6.keys();
//    // printKeys(v6);
//    a6.remove(25);
//    v6 = a6.keys();
//    // printKeys(v6);
//    // cout << "Expected output: 5 10 15 20 30 35" << endl;
//    checkCaseBasicVectors(v6, vector<unsigned>{5, 10, 15, 20, 30, 35});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node from parent node left - parent has no right subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a7;
//    a7.insert(20, 1);
//    a7.insert(10, 2);
//    a7.insert(5, 3);
//    a7.insert(2, 4);
//    a7.insert(1, 5);
//    a7.insert(3, 6);
//    vector<unsigned> v7 = a7.keys();
//    // printKeys(v7);
//    a7.remove(5);
//    v7 = a7.keys();
//    // printKeys(v7);
//    // cout << "Expected output: 1 2 3 10 20" << endl;
//    checkCaseBasicVectors(v7, vector<unsigned>{1, 2, 3, 10, 20});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node from parent node right - parent has no right subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a8;
//    a8.insert(20, 1);
//    a8.insert(10, 2);
//    a8.insert(15, 3);
//    a8.insert(13, 4);
//    a8.insert(11, 5);
//    a8.insert(14, 6);
//    vector<unsigned> v8 = a8.keys();
//    // printKeys(v8);
//    a8.remove(15);
//    v8 = a8.keys();
//    // printKeys(v8);
//    // cout << "Expected output: 10 11 13 14 20" << endl;
//    checkCaseBasicVectors(v8, vector<unsigned>{10, 11, 13, 14, 20});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node from parent node left - parent has no left subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a9;
//    a9.insert(20, 1);
//    a9.insert(10, 2);
//    a9.insert(15, 3);
//    a9.insert(18, 4);
//    a9.insert(16, 5);
//    a9.insert(19, 6);
//    vector<unsigned> v9 = a9.keys();
//    // printKeys(v9);
//    a9.remove(15);
//    v9 = a9.keys();
//    // printKeys(v9);
//    // cout << "Expected output: 10 16 18 19 20" << endl;
//    checkCaseBasicVectors(v9, vector<unsigned>{10, 16, 18, 19, 20});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node from parent node right - parent has no left subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a10;
//    a10.insert(20, 1);
//    a10.insert(10, 2);
//    a10.insert(5, 3);
//    a10.insert(8, 4);
//    a10.insert(9, 5);
//    vector<unsigned> v10 = a10.keys();
//    // printKeys(v10);
//    a10.remove(5);
//    v10 = a10.keys();
//    // printKeys(v10);
//    // cout << "Expected output: 8 9 10 20" << endl;
//    checkCaseBasicVectors(v10, vector<unsigned>{8, 9, 10, 20});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node w/ 2 children in left subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a11;
//    a11.insert(47, 1);
//    a11.insert(32, 2);
//    a11.insert(63, 3);
//    a11.insert(19, 4);
//    a11.insert(41, 5);
//    a11.insert(54, 6);
//    a11.insert(10, 7);
//    a11.insert(23, 8);
//    a11.insert(37, 9);
//    a11.insert(44, 10);
//    a11.insert(53, 11);
//    a11.insert(59, 12);
//    a11.insert(96, 13);
//    a11.insert(7, 14);
//    a11.insert(12, 15);
//    a11.insert(30, 16);
//    a11.insert(57, 17);
//    a11.insert(91, 18);
//    a11.insert(97, 19);
//    vector<unsigned> v11 = a11.keys();
//    // printKeys(v11);
//    a11.remove(32);
//    v11 = a11.keys();
//    // printKeys(v11);
//    // cout << "Expected output: 7 10 12 19 23 30 37 41 44 47 53 54 57 59 63 91 96 97" << endl;
//    checkCaseBasicVectors(v11, vector<unsigned>{7, 10, 12, 19, 23, 30, 37, 41, 44, 47, 53, 54, 57, 59, 63, 91, 96, 97});
//    cout << "========================================================================================" << endl;
//
//    cout << "====================== Remove node w/ 2 children in right subtree ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a12;
//    a12.insert(47, 1);
//    a12.insert(32, 2);
//    a12.insert(63, 3);
//    a12.insert(19, 4);
//    a12.insert(41, 5);
//    a12.insert(54, 6);
//    a12.insert(10, 7);
//    a12.insert(23, 8);
//    a12.insert(37, 9);
//    a12.insert(44, 10);
//    a12.insert(53, 11);
//    a12.insert(59, 12);
//    a12.insert(96, 13);
//    a12.insert(7, 14);
//    a12.insert(12, 15);
//    a12.insert(30, 16);
//    a12.insert(57, 17);
//    a12.insert(91, 18);
//    a12.insert(97, 19);
//    vector<unsigned> v12 = a12.keys();
//    // printKeys(v12);
//    a12.remove(63);
//    v12 = a12.keys();
//    // printKeys(v12);
//    // cout << "Expected output: 7 10 12 19 23 30 32 37 41 44 47 53 54 57 59 91 96 97" << endl;
//    checkCaseBasicVectors(v12, vector<unsigned>{7, 10, 12, 19, 23, 30, 32, 37, 41, 44, 47, 53, 54, 57, 59, 91, 96, 97});
//    cout << "========================================================================================" << endl;
//}
//
//void testLeftRotateInsert()
//{
//    cout << "====================== Left rotations on insert ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(30, 2);
//    a1.insert(40, 3);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 30 - 1, 20 - 0, 40 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{20, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(20, 1);
//    a2.insert(10, 2);
//    a2.insert(30, 3);
//    a2.insert(35, 4);
//    a2.insert(40, 5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 20 - 2, 10 - 0, 35 - 1, 30 - 0, 40 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{35, 1});
//    expected.push_back(height_key{30, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(20, 1);
//    a3.insert(30, 2);
//    a3.insert(10, 3);
//    a3.insert(15, 4);
//    a3.insert(18, 5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 20 - 2, 15 - 1, 30 - 0, 10 - 0, 18 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{15, 1});
//    expected.push_back(height_key{30, 0});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{18, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//    cout << "========================================================================================" << endl;
//}
//
//void testRightRotateInsert()
//{
//    cout << "====================== Right rotations on insert ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(10, 2);
//    a1.insert(5, 3);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 10 - 1, 5 - 0, 20 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{20, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(30, 1);
//    a2.insert(10, 2);
//    a2.insert(50, 3);
//    a2.insert(8, 4);
//    a2.insert(5, 5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 30 - 2, 8 - 1, 50 - 0, 5 - 0, 10 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{8, 1});
//    expected.push_back(height_key{50, 0});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{10, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(30, 1);
//    a3.insert(20, 2);
//    a3.insert(50, 3);
//    a3.insert(10, 4);
//    a3.insert(25, 5);
//    a3.insert(80, 6);
//    a3.insert(24, 7);
//    a3.insert(23, 8);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 30 - 3, 20 - 2, 50 - 1, 10 - 0, 24 - 1, 80 - 0, 23 - 0, 25 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{30, 3});
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{50, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{24, 1});
//    expected.push_back(height_key{80, 0});
//    expected.push_back(height_key{23, 0});
//    expected.push_back(height_key{25, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(20, 1);
//    a4.insert(10, 2);
//    a4.insert(30, 3);
//    a4.insert(5, 4);
//    a4.insert(15, 5);
//    a4.insert(50, 6);
//    a4.insert(3, 7);
//    a4.insert(1, 8);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    // cout << "Expected output: 20 - 3, 10 - 2, 30 - 1, 3 - 1, 15 - 0, 50 - 0, 1 - 0, 5 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    expected.push_back(height_key{20, 3});
//    expected.push_back(height_key{10, 2});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{3, 1});
//    expected.push_back(height_key{15, 0});
//    expected.push_back(height_key{50, 0});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{5, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    // AVLTree<unsigned,unsigned> a5;
//    // a5.insert(30, 1);
//    // a5.insert(20, 2);
//    // a5.insert(50, 3);
//    // a5.insert(10, 4);
//    // a5.insert(25, 5);
//    // a5.insert(80, 6);
//    // a5.insert(24, 7);
//    // a5.insert(23, 8);
//    // printLevelOrder((AVLTreeNode<unsigned,unsigned>*)a5.getRoot());
//    // cout << "Expected output: 30 - 3, 20 - 2, 50 - 1, 10 - 0, 24 - 1, 80 - 0, 23 - 0, 25 - 0" << endl;
//    cout << "========================================================================================" << endl;
//}
//
//void testLeftRightRotateInsert()
//{
//    cout << "====================== Left right rotations on insert ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(10, 2);
//    a1.insert(15, 3);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 15 - 1, 10 - 0, 20 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{15, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{20, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(20, 1);
//    a2.insert(30, 2);
//    a2.insert(10, 3);
//    a2.insert(5, 4);
//    a2.insert(50, 5);
//    a2.insert(9, 6);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 20 - 2, 9 - 1, 30 - 1, 5 - 0, 10 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{9, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(30, 1);
//    a3.insert(20, 2);
//    a3.insert(50, 3);
//    a3.insert(10, 4);
//    a3.insert(25, 5);
//    a3.insert(80, 6);
//    a3.insert(5, 7);
//    a3.insert(15, 8);
//    a3.insert(12, 9);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 30 - 3, 15 - 2, 50 - 1, 10 - 1, 20 - 1, 80 - 0, 5 - 0, 12 - 0, 25 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{30, 3});
//    expected.push_back(height_key{15, 2});
//    expected.push_back(height_key{50, 1});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{80, 0});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{12, 0});
//    expected.push_back(height_key{25, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(30, 1);
//    a4.insert(20, 2);
//    a4.insert(50, 3);
//    a4.insert(80, 4);
//    a4.insert(10, 5);
//    a4.insert(25, 6);
//    a4.insert(5, 7);
//    a4.insert(15, 8);
//    a4.insert(16, 9);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    // cout << "Expected output: 30 - 3, 15 - 2, 50 - 1, 10 - 1, 20 - 1, 80 - 0, 5 - 0, 16 - 0, 25 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    expected.push_back(height_key{30, 3});
//    expected.push_back(height_key{15, 2});
//    expected.push_back(height_key{50, 1});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{80, 0});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{16, 0});
//    expected.push_back(height_key{25, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "========================================================================================" << endl;
//}
//
//void testRightLeftRotateInsert()
//{
//    cout << "====================== Right left rotations on insert ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(30, 2);
//    a1.insert(25, 3);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 25 - 1, 20 - 0, 30 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{25, 1});
//    expected.push_back(height_key{20, 0});
//    expected.push_back(height_key{30, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(20, 1);
//    a2.insert(10, 2);
//    a2.insert(30, 3);
//    a2.insert(50, 4);
//    a2.insert(5, 5);
//    a2.insert(35, 6);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 20 - 2, 10 - 1, 35 - 1, 5 - 0, 30 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{35, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{30, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(20, 1);
//    a3.insert(10, 2);
//    a3.insert(30, 3);
//    a3.insert(5, 4);
//    a3.insert(25, 5);
//    a3.insert(50, 6);
//    a3.insert(60, 7);
//    a3.insert(55, 8);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 20 - 3, 10 - 1, 30 - 2, 5 - 0, 25 - 0, 55 - 1, 50 - 0, 60 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{20, 3});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{55, 1});
//    expected.push_back(height_key{50, 0});
//    expected.push_back(height_key{60, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "========================================================================================" << endl;
//}
//
//void testDelete()
//{
//    cout << "====================== Deleting Nodes ======================" << endl
//         << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(44, 1);
//    a1.insert(17, 2);
//    a1.insert(78, 3);
//    a1.insert(32, 4);
//    a1.insert(50, 5);
//    a1.insert(88, 6);
//    a1.insert(48, 7);
//    a1.insert(62, 8);
//     printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    a1.remove(32);
//     printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{44, 1});
//    expected.push_back(height_key{17, 0});
//    expected.push_back(height_key{78, 1});
//    expected.push_back(height_key{50, 2});
//    expected.push_back(height_key{88, 0});
//    expected.push_back(height_key{48, 0});
//    expected.push_back(height_key{62, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << endl
//         << "Part 2:" << endl;
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(50, 1);
//    a2.insert(25, 2);
//    a2.insert(75, 3);
//    a2.insert(10, 4);
//    a2.insert(30, 5);
//    a2.insert(60, 6);
//    a2.insert(80, 7);
//    a2.insert(5, 8);
//    a2.insert(15, 9);
//    a2.insert(27, 10);
//    a2.insert(55, 11);
//    a2.insert(1, 12);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    a2.remove(80);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    //  vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    //  vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{25, 3});
//    expected.push_back(height_key{10, 2});
//    expected.push_back(height_key{50, 2});
//    expected.push_back(height_key{5, 1});
//    expected.push_back(height_key{15, 0});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{60, 1});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{27, 0});
//    expected.push_back(height_key{55, 0});
//    expected.push_back(height_key{75, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//    cout << "========================================================================================" << endl;
//}
//
//void testRemoveLeaf()
//{
//    cout << "====================== Rotations - remove leaf ======================" << endl
//         << endl;
//    // All done on right subtree from root
//    cout << "Left rotations" << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(10, 2);
//    a1.insert(40, 3);
//    a1.insert(5, 4);
//    a1.insert(30, 5);
//    a1.insert(50, 6);
//    a1.insert(25, 7);
//    a1.insert(35, 8);
//    a1.insert(45, 9);
//    a1.insert(55, 10);
//    a1.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 40 - 3, 20 - 2, 50 - 1, 10 - 0, 30 - 1, 45 - 0, 55 - 0, 25 - 0, 35 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{40, 3});
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{50, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{45, 0});
//    expected.push_back(height_key{55, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{35, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(20, 1);
//    a2.insert(10, 2);
//    a2.insert(40, 3);
//    a2.insert(5, 4);
//    a2.insert(30, 5);
//    a2.insert(50, 6);
//    a2.insert(45, 9);
//    a2.insert(55, 10);
//    a2.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 40 - 2, 20 - 1, 50 - 1, 10 - 0, 30 - 0, 45 - 0, 55 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{40, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{50, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{30, 0});
//    expected.push_back(height_key{45, 0});
//    expected.push_back(height_key{55, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "Left right rotations" << endl;
//    AVLTree<unsigned, unsigned> a12;
//    a12.insert(20, 1);
//    a12.insert(10, 2);
//    a12.insert(40, 3);
//    a12.insert(5, 4);
//    a12.insert(15, 5);
//    a12.insert(50, 6);
//    a12.insert(12, 7);
//    a12.insert(18, 8);
//    a12.remove(50);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a12.getRoot());
//    // cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 12 - 0, 18 - 0, 40 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a12.getRoot());
//    expected.push_back(height_key{15, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{12, 0});
//    expected.push_back(height_key{18, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a13;
//    a13.insert(20, 1);
//    a13.insert(10, 2);
//    a13.insert(40, 3);
//    a13.insert(5, 4);
//    a13.insert(15, 5);
//    a13.insert(50, 6);
//    a13.insert(18, 8);
//    a13.remove(50);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a13.getRoot());
//    // cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 18 - 0, 40 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a13.getRoot());
//    expected.push_back(height_key{15, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{18, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "Right rotations" << endl;
//    AVLTree<unsigned, unsigned> a10;
//    a10.insert(20, 1);
//    a10.insert(10, 2);
//    a10.insert(50, 3);
//    a10.insert(60, 8);
//    a10.insert(5, 4);
//    a10.insert(15, 5);
//    a10.insert(1, 6);
//    a10.insert(6, 7);
//    a10.insert(12, 9);
//    a10.insert(18, 10);
//    a10.remove(60);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a10.getRoot());
//    // cout << "Expected output: 10 - 3, 5 - 1, 20 - 2, 1 - 0, 6 - 0, 15 - 1, 50 - 0, 12 - 0, 18 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a10.getRoot());
//    expected.push_back(height_key{10, 3});
//    expected.push_back(height_key{5, 1});
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{6, 0});
//    expected.push_back(height_key{15, 1});
//    expected.push_back(height_key{50, 0});
//    expected.push_back(height_key{12, 0});
//    expected.push_back(height_key{18, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a11;
//    a11.insert(20, 1);
//    a11.insert(10, 2);
//    a11.insert(50, 3);
//    a11.insert(60, 8);
//    a11.insert(5, 4);
//    a11.insert(15, 5);
//    a11.insert(1, 6);
//    a11.insert(6, 7);
//    a11.remove(60);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a11.getRoot());
//    // cout << "Expected output: 10 - 2, 5 - 1, 20 - 1, 1 - 0, 6 - 0, 15 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a11.getRoot());
//    expected.push_back(height_key{10, 2});
//    expected.push_back(height_key{5, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{6, 0});
//    expected.push_back(height_key{15, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "Right left rotations" << endl;
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(20, 1);
//    a3.insert(10, 2);
//    a3.insert(40, 3);
//    a3.insert(5, 4);
//    a3.insert(30, 5);
//    a3.insert(50, 6);
//    a3.insert(25, 9);
//    a3.insert(35, 10);
//    a3.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 35 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{40, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{35, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(20, 1);
//    a4.insert(10, 2);
//    a4.insert(40, 3);
//    a4.insert(5, 4);
//    a4.insert(30, 5);
//    a4.insert(50, 6);
//    a4.insert(25, 9);
//    a4.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    // cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{40, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a5;
//    a5.insert(20, 1);
//    a5.insert(10, 2);
//    a5.insert(40, 3);
//    a5.insert(5, 4);
//    a5.insert(30, 5);
//    a5.insert(50, 6);
//    a5.insert(25, 9);
//    a5.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a5.getRoot());
//    // cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 25 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a5.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{40, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a6;
//    a6.insert(20, 1);
//    a6.insert(10, 2);
//    a6.insert(40, 3);
//    a6.insert(5, 4);
//    a6.insert(30, 5);
//    a6.insert(50, 6);
//    a6.insert(35, 9);
//    a6.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a6.getRoot());
//    // cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 10 - 0, 35 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a6.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{40, 1});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{35, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "========================================================================================" << endl;
//}
//
//void testRemoveNodeTwoChildren()
//{
//    cout << "====================== Rotations - remove node w/ two children ======================" << endl
//         << endl;
//    cout << "Root node" << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(10, 2);
//    a1.insert(30, 3);
//    a1.insert(25, 4);
//    a1.insert(50, 5);
//    a1.remove(20);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 30 - 2, 10 - 1, 50 - 0, 25 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{50, 0});
//    expected.push_back(height_key{25, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(15, 1);
//    a2.insert(10, 2);
//    a2.insert(30, 3);
//    a2.insert(5, 4);
//    a2.insert(12, 5);
//    a2.insert(50, 6);
//    a2.insert(1, 7);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    a2.remove(15);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 12 - 2, 5 - 1, 30 - 1, 1 - 0, 10 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{12, 2});
//    expected.push_back(height_key{5, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{10, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(20, 1);
//    a3.insert(10, 2);
//    a3.insert(30, 3);
//    a3.insert(5, 4);
//    a3.insert(25, 5);
//    a3.insert(50, 6);
//    a3.insert(21, 7);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    a3.remove(20);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 25 - 2, 10 - 1, 30 - 1, 5 - 0, 21 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{25, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{21, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    cout << "Non-root node w/ 2 children node" << endl;
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(20, 1);
//    a4.insert(10, 2);
//    a4.insert(30, 3);
//    a4.insert(5, 4);
//    a4.insert(15, 5);
//    a4.insert(50, 6);
//    a4.insert(18, 7);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    a4.remove(10);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    // cout << "Expected output: 20 - 2, 15 - 1, 30 - 1, 5 - 0, 18 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{15, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{18, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a5;
//    a5.insert(20, 1);
//    a5.insert(5, 2);
//    a5.insert(30, 3);
//    a5.insert(1, 4);
//    a5.insert(15, 5);
//    a5.insert(50, 6);
//    a5.insert(12, 7);
//    a5.remove(5);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a5.getRoot());
//    // cout << "Expected output: 20 - 2, 12 - 1, 30 - 1, 1 - 0, 15 - 0, 50 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // vector<height_key> expected;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a5.getRoot());
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{12, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{15, 0});
//    expected.push_back(height_key{50, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//    cout << "========================================================================================" << endl;
//}
//
//void testRemoveNodeOneChild()
//{
//    cout << "====================== Rotations - remove node w/ one child ======================" << endl
//         << endl;
//    cout << "Removing node w/ one child" << endl;
//    AVLTree<unsigned, unsigned> a1;
//    a1.insert(20, 1);
//    a1.insert(10, 2);
//    a1.insert(30, 3);
//    a1.insert(5, 4);
//    a1.insert(25, 5);
//    a1.insert(40, 6);
//    a1.insert(28, 7);
//    a1.remove(10);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    // cout << "Expected output: 25 - 2, 20 - 1, 30 - 1, 5 - 0, 28 - 0, 40 - 0" << endl;
//    vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a1.getRoot());
//    vector<height_key> expected;
//    expected.push_back(height_key{25, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{30, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{28, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a2;
//    a2.insert(20, 1);
//    a2.insert(10, 2);
//    a2.insert(30, 3);
//    a2.insert(5, 4);
//    a2.insert(25, 5);
//    a2.insert(40, 6);
//    a2.insert(35, 7);
//    a2.remove(10);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    // cout << "Expected output: 30 - 2, 20 - 1, 40 - 1, 5 - 0, 25 - 0, 35 - 0" << endl;
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a2.getRoot());
//    expected.push_back(height_key{30, 2});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{40, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{25, 0});
//    expected.push_back(height_key{35, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a3;
//    a3.insert(20, 1);
//    a3.insert(10, 2);
//    a3.insert(30, 3);
//    a3.insert(5, 4);
//    a3.insert(15, 5);
//    a3.insert(40, 6);
//    a3.insert(1, 7);
//    a3.insert(18, 8);
//    a3.remove(30);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // vector<height_key> store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    // cout << "Expected output: 10 - 3, 5 - 1, 20 - 2, 1 - 0, 15 - 1, 40 - 0, 18 - 0" << endl;
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a3.getRoot());
//    expected.push_back(height_key{10, 3});
//    expected.push_back(height_key{5, 1});
//    expected.push_back(height_key{20, 2});
//    expected.push_back(height_key{1, 0});
//    expected.push_back(height_key{15, 1});
//    expected.push_back(height_key{40, 0});
//    expected.push_back(height_key{18, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//
//    AVLTree<unsigned, unsigned> a4;
//    a4.insert(20, 1);
//    a4.insert(10, 2);
//    a4.insert(30, 3);
//    a4.insert(5, 4);
//    a4.insert(15, 5);
//    a4.insert(40, 6);
//    a4.insert(18, 8);
//    a4.remove(30);
//    // printLevelOrder((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    store = getHeightKeys((AVLTreeNode<unsigned, unsigned> *)a4.getRoot());
//    // cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 18 - 0, 40 - 0" << endl;
//    expected.push_back(height_key{15, 2});
//    expected.push_back(height_key{10, 1});
//    expected.push_back(height_key{20, 1});
//    expected.push_back(height_key{5, 0});
//    expected.push_back(height_key{18, 0});
//    expected.push_back(height_key{40, 0});
//    checkCase(store, expected);
//    expected.clear();
//    store.clear();
//    // cout << "Expected output: 15 - 2, 10 - 1, 20 - 1, 5 - 0, 18 - 0, 40 - 0" << endl;
//
//    cout << "========================================================================================" << endl;
//}
//
//void printKeys(vector<unsigned> keys)
//{
//    cout << "Actual output: ";
//    for (unsigned int i = 0; i < keys.size(); i++)
//    {
//        cout << keys[i] << " ";
//    }
//
//    cout << endl;
//}
//
//template <class K, class V>
//void printLevelOrder(AVLTreeNode<K, V> *node)
//{
//    queue<AVLTreeNode<unsigned, unsigned> *> q;
//    q.push(node);
//    while (!q.empty())
//    {
//        AVLTreeNode<unsigned, unsigned> *front = q.front();
//        cout << "node: " << front->key << " height: " << front->height << endl;
//        if (front->left)
//            q.push(front->left);
//        if (front->right)
//            q.push(front->right);
//        q.pop();
//    }
//}
//
//
////#include <vector>
////#include <iostream>
////#include<string>
////#include "AVLTree.h"
////using std::cout;
////using std::endl;
////using std::vector;
////using std::string;
////using std::cin;
////
////int main() {
////  AVLTree<int,string> obj;
////  int option, val;
////
////  do {
////    cout << "What operation do you want to perform? " <<
////      " Select Option number. Enter 0 to exit." << endl;
////    cout << "1. Insert Node" << endl;
////    cout << "2. Search Node" << endl;
////    cout << "3. Delete Node" << endl;
////    cout << "4. Print/Traversal AVL Tree values" << endl;
////    cout << "5. Height of Tree" << endl;
////    cout << "6. Clear Screen" << endl;
////    cout << "0. Exit Program" << endl;
////
////    cin >> option;
////    //Node n1;
////    AVLTreeNode<int,string> * new_node = new AVLTreeNode(0,"Z");
////
////    switch (option) {
////    case 0:
////      break;
////    case 1:
////      cout << "AVL INSERT" << endl;
////      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
////      cin >> val;
////      new_node -> value = val;
////      obj.root = obj.insert(obj.root, new_node);
////      cout << endl;
////      break;
////    case 2:
////      cout << "SEARCH" << endl;
////      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
////      cin >> val;
////      //new_node = obj.iterativeSearch(val);
////      new_node = obj.recursiveSearch(obj.root, val);
////      if (new_node != NULL) {
////        cout << "Value found" << endl;
////      } else {
////        cout << "Value NOT found" << endl;
////      }
////      break;
////    case 3:
////      cout << "DELETE" << endl;
////      cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
////      cin >> val;
////      new_node = obj.recursiveSearch(obj.root, val);
////      if (new_node != NULL) {
////        obj.root = obj.deleteNode(obj.root, val);
////        cout << "Value Deleted" << endl;
////      } else {
////        cout << "Value NOT found" << endl;
////      }
////      break;
////    case 4:
////      cout << "PRINT 2D: " << endl;
////      obj.print2D(obj.root, 5);
////      cout << endl;
////      //cout <<"Print Level Order BFS: \n";
////      //obj.printLevelOrderBFS(obj.root);
////      //cout <<endl;
////      //          cout <<"PRE-ORDER: ";
////      //          obj.printPreorder(obj.root);
////      //          cout<<endl;
////      //          cout <<"IN-ORDER: ";
////      //          obj.printInorder(obj.root);
////      //          cout<<endl;
////      //          cout <<"POST-ORDER: ";
////      //          obj.printPostorder(obj.root);
////      break;
////    case 5:
////      cout << "TREE HEIGHT" << endl;
////      cout << "Height : " << obj.height(obj.root) << endl;
////      break;
////    case 6:
////      system("cls");
////      break;
////    default:
////      cout << "Enter Proper Option number " << endl;
////    }
////
////  } while (option != 0);
////
////  return 0;
////}
//
//
//
//
//
//
//
//
//
//
////// Basic test program for AVL Tree
////// Author: John Edgar
////// Date: July 2022
////#include <vector>
////#include <iostream>
////#include<string>
////#include "AVLTree.h"
////using std::cout;
////using std::endl;
////using std::vector;
////using std::string;
////void a4marking();
////template <class K, class V>
////bool checkAVLTree(const AVLTree <K, V>& tree);
////int main()
////{
////    AVLTree<int,string> x;
////    x.insert(5,"Five");
////    x.insert(10,"Ten");
////    x.insert(8,"Eight");
////    AVLTree<int,string> y=x;
////    AVLTreeNode<int,string>* temp= getRoot();
////    cout<<y.search(5);
////  //  cout<<y.search (10);
////    //a4marking();
////    cout << endl;
////}
////void a4marking()
////{
////    AVLTree<int, int> aspen;
////    checkAVLTree<int, int>(aspen);
////    // Method return values
//////    bool success = aspen.insert(1, 2);
//////    success = aspen.remove(1);
//////    int result = aspen.search(1);
//// //   vector<int> v2 = aspen.values();
////  //  vector<int> k1 = aspen.keys();
////    AVLTree<int, int> larch(aspen);
////    aspen = larch;
////    cout << endl << "end a4 test" << endl;
////}
////template <class K, class V>
////bool checkAVLTree(const AVLTree<K, V>& tree)
////{
////    AVLTreeNode<int, int>* nd = (AVLTreeNode<int, int>*)tree.getRoot();
////    cout << "height = " << nd->height << endl;
////    return false;
////}
////
