#include <iostream>
#define endl "\n"
using namespace std;

typedef struct bstnode {
    int key;
    int element;
    int height;
    int rank = 1; // number of elements to the left
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
int findhelp(BSTNode* rt, int k, BSTNode* parent);
void preorder(BSTNode* rt);
void inorder(BSTNode* rt);
void posorder(BSTNode* rt);
BSTNode* rightRotate(BSTNode* rt);
BSTNode* leftRotate(BSTNode* rt);
int h(BSTNode* rt);
int getBalance(BSTNode* rt);
int max(int n1, int n2);


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
            int index = find(avl, key);
            
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
        rt->left = inserthelp(rt->left, k, e);
    }
    else {
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

int remove(BST* bst, int k) { // not complete
    int temp = findhelp(bst->root, k, bst->root);
    if(temp != -1) {
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
    // needs to be updated
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

int find(BST* bst, int k) {
    return findhelp(bst->root, k, bst->root);
}

int findhelp(BSTNode* rt, int k, BSTNode* parent) {
    if(rt == NULL) {
        return -1;
    }

    if(rt->key > k) {
        return findhelp(rt->left, k, rt);
    }
    else if(rt->key == k) {
        int index;
        if(rt->element != parent->element) {    
            index = rt->rank + parent->rank;
        }
        else {
            index = rt->rank;
        }

        return index;
    }
    else {
        return findhelp(rt->right, k, rt);
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
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    return l;
}

BSTNode* leftRotate(BSTNode* rt) {
    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

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
