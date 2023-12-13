#include <iostream>
#define endl "\n"
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
void preorder(BSTNode* rt);
void inorder(BSTNode* rt);
void posorder(BSTNode* rt);


int main(void) {
    int n, p;
    BST* bst = create_bst();
    cin >> n;

    for(int i = 0; i < n; i++) {
        p = 0;
        cin >> p;
        insert(bst, p, p);
    }

    cout << "Pre order :"; preorder(bst->root); cout << endl;
    cout << "In order  :"; inorder(bst->root); cout << endl;
    cout << "Post order:"; posorder(bst->root); cout << endl;
      
    return 0;
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
    if(rt == NULL) {
        return NULL;
    }

    if(rt->key > k) {
        rt->left = removehelp(rt->left, k);
    }
    else if(rt->key < k) {
        rt->right = removehelp(rt->right, k);
    }
    else {
        if(rt->left == NULL) {
            return rt->right;
        }
        else if(rt->right == NULL) {
            return rt->left;
        }
        else { // when both children are not NULL
            BSTNode* temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }

    return rt;
}

BSTNode* getmin(BSTNode* rt) {
    if(rt->left == NULL) {
        return rt;
    }
    return getmin(rt->left);
}

BSTNode* deletemin(BSTNode* rt) {
    if(rt->left == NULL) {
        return rt->right;
    }
    rt->left = deletemin(rt->left);

    return rt;
}

int find(BST* bst, int k) {
    return findhelp(bst->root, k);
}

int findhelp(BSTNode* rt, int k) {
    if(rt == NULL) {
        return NULL;
    }

    if(rt->key > k) {
        return findhelp(rt->left, k);
    }
    else if(rt->key == k) {
        return rt->element;
    }
    else {
        return findhelp(rt->right, k);
    }
}

void preorder(BSTNode* rt) {
    if(rt != NULL) {
        cout << " " << rt->element; // do something with rt
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode* rt) {
    if(rt != NULL) {
        inorder(rt->left);
        cout << " " << rt->element; // do something with rt
        inorder(rt->right);
    }
}

void posorder(BSTNode* rt) {
    if(rt != NULL) {
        posorder(rt->left);
        posorder(rt->right);
        cout << " " << rt->element; // do something with rt
    }
}
