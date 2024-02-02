#include <iostream>
#define endl "\n"
using namespace std;

typedef struct bstnode {
    int key;
    int element;
    int height;
    int rank = 1; // number of elements to the left
    int size = 1;
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
BSTNode* getmin(BSTNode* rt);
BSTNode* deletemin(BSTNode* rt);
int find(BST* bst, int k, int rank);
int findhelp(BSTNode* rt, int k, int rank);
void preorder(BSTNode* rt);
void inorder(BSTNode* rt);
void posorder(BSTNode* rt);
BSTNode* rightRotate(BSTNode* rt);
BSTNode* leftRotate(BSTNode* rt);
int h(BSTNode* rt);
int getBalance(BSTNode* rt);
int max(int n1, int n2);
int size(BSTNode* rt);


int main(void) {
    int q;
    BST* avl = create_bst();
    cin >> q;

    for(int i = 0; i < q; i++) {
        int comando, key;
        cin >> comando;

        if(comando == 1) {
            cin >> key;
            insert(avl, key, key);
        }
        else if(comando == 2) {
            cin >> key;
            int rank = 0;
            int index = find(avl, key, rank);
            
            if(index != -1) {
                cout << index << endl;
            }
            else {
                cout << "Data tidak ada" << endl;
            }
        }
    }
    
    
    return 0;
}


BSTNode* create_bstnode(int k, int e) {
    BSTNode* n = new BSTNode;
    n->key = k;
    n->element = e;
    n->height = 0;
    n->left = n->right = NULL;
    return n;
}

BST* create_bst() {
    BST* bst = new BST;
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
        rt->rank++;
        rt->size++;
        rt->left = inserthelp(rt->left, k, e);
    }
    else {
        rt->size++;
        rt->right = inserthelp(rt->right, k, e);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if(balance < -1 && k >= rt->right->key) {
        return leftRotate(rt);
    }
    if(balance > 1 && k < rt->left->key) {
        return rightRotate(rt);
    }
    if(balance > 1 && k >= rt->left->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && k < rt->right->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
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

int find(BST* bst, int k, int rank) {
    return findhelp(bst->root, k, rank);
}

int findhelp(BSTNode* rt, int k, int rank) {
    if(rt == NULL) {
        return -1;
    }

    if(rt->key > k) {
        return findhelp(rt->left, k, rank);
    }
    else if(rt->key == k) {
        rank += size(rt->left) + 1;
         
        return rank;
    }
    else {
        rank += size(rt->left) + 1;

        return findhelp(rt->right, k, rank);
    }
}

void preorder(BSTNode* rt) {
    if(rt != NULL) {
        cout << rt->element << " "; // do something with rt
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode* rt) {
    if(rt != NULL) {
        inorder(rt->left);
        cout << rt->element << " "; // do something with rt
        inorder(rt->right);
    }
}

void posorder(BSTNode* rt) {
    if(rt != NULL) {
        posorder(rt->left);
        posorder(rt->right);
        cout << rt->element << " "; // do something with rt
    }
}

BSTNode* rightRotate(BSTNode* rt) {
    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    rt->rank -= rt->left->rank;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    rt->size = 1 + size(rt->left) + size(rt->right);
    l->height = max(h(l->left), h(l->right)) + 1;
    l->size = 1 + size(l->left) + size(l->right);

    return l;
}

BSTNode* leftRotate(BSTNode* rt) {
    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    rt->right->rank += rt->rank;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    rt->size = 1 + size(rt->left) + size(rt->right);
    r->height = max(h(r->left), h(r->right)) + 1;
    r->size = 1 + size(r->left) + size(r->right);

    return r; 
}

int h(BSTNode* rt) {
    if(rt == NULL) {
        return -1;
    }

    return rt->height;
}

int getBalance(BSTNode* rt) {
    if(rt == NULL) {
        return 0;
    }

    return h(rt->left) - h(rt->right);
}

int max(int n1, int n2) {
    if(n1 >= n2) {
        return n1;
    }
    else {
        return n2;
    }
}

int size(BSTNode* rt) {
    if(rt == NULL) {
        return 0;
    }
    return rt->size;
}
