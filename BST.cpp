#include <iostream>
using namespace std;

typedef struct bstnode {
    int key;
    int element;
    struct bstnode* left; // left child
    struct bstnode* right; // right child
} BSTNode;

typedef struct {
    BSTNode* root;
    int nodecount; // number of elements
} BST;

BSTNode* create_bstnode(int k, int e);
BST* create_bst();
void insert(BST* bst, int k, int e);
BSTNode* inserthelp(BSTNode* rt, int k, int e);
int remove(BST* bst, int k);
BSTNode* removehelp(BSTNode* rt, int k);
BSTNode* getmin(BSTNode* rt);
BSTNode* deletemin(BSTNode* rt);
int find(BST* bst, int k);
int findhelp(BSTNode* rt, int k);


int main(void) {

}


BSTNode* create_bstnode(int k, int e) {
    BSTNode* n = (BSTNode *) new int;
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

BST* create_bst() {
    BST* bst = (BST *) new int;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

void insert(BST* bst, int k, int e) {
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

BSTNode* inserthelp(BSTNode* rt, int k, int e) {
    if(rt == NULL) {
        return create_bstnode(k, e);
    }
    
    if(rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
    }
    else {
        rt->right = inserthelp(rt->right, k, e);
    }
    
    return rt;
}

int remove(BST* bst, int k) {
    int temp = findhelp(bst->root, k);
    if(temp != NULL) {
        bst->root = removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

BSTNode* removehelp(BSTNode* rt, int k) {

}

BSTNode* getmin(BSTNode* rt) {

}

BSTNode* deletemin(BSTNode* rt) {

}

int find(BST* bst, int k) {

}

int findhelp(BSTNode* rt, int k) {

}
