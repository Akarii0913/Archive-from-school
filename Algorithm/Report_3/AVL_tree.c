#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE{
    int data, height;
    struct NODE *left, *right;
}NODE;

NODE *search(int key);
NODE *insert(NODE **node, int key);
NODE *rightRotate(NODE **y);
NODE *leftRotate(NODE **y);
NODE *root = NULL;

int keyequal(int a, int b);
int keylt(int a, int b);
int height(NODE *p);
int getBalance(NODE *p);
int max(int a, int b);
void preorder(NODE *p);
void inorder(NODE *p);

int main(void){
    root = insert(&root, 5);
    root = insert(&root, 4);
    root = insert(&root, 3);
    root = insert(&root, 2);
    root = insert(&root, 1);
    inorder(root);
    printf("\n");
    preorder(root);
    return 0;
}

int keyequal(int a, int b){
    if (a == b)
        return 1;
    else
        return 0;
}

int keylt(int a, int b){
    if (a < b)
        return 1;
    else
        return 0;
}

int getBalance(NODE *p){
    return (p == NULL) ? 0 : height(p->left) - height(p->right);
}

int height(NODE *p){
    int left_height;
    int right_height;
    int tree_height;

    if (p == NULL)
        return 0;

    left_height = height(p->left);
    right_height = height(p->right);

    if (left_height > right_height)
        tree_height = left_height;
    else
        tree_height = right_height;

    return tree_height + 1;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

NODE *search(int key){
    NODE *p;
    p = root;
    while (p != NULL){
        if(keyequal(key, p->data))
            return p;       
        else if (keylt(key, p->data))
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

NODE *insert(NODE **node, int key){
    NODE **p, *new;
    int balance;

    p = &(*node);
    if (*p == NULL){
        if ((new = (NODE*)malloc(sizeof(NODE))) == NULL){
            printf("Out of memory!!\n");
            return NULL;
        }
        new->left = NULL;
        new->right = NULL;
        new->data = key;
        *node = new;
        return new;
    }

    else if (keylt(key, (*p)->data))
        (*p)->left = insert(&(*p)->left, key);
    else if(!keylt(key, (*p)->data))
        (*p)->right = insert(&(*p)->right, key);
    else
        return *node;
    
    /* 2. 祖先ノードの高さを更新 */
    (*node)->height = 1 + max(height((*node)->left), height((*node)->right));
    
    /* 3. この祖先ノードのバランスファクタを返す */
    balance = getBalance(*node);

    /*
    平衡していない状態には、4つの場合がある。
    */
    // (左、左):左部分木の左部分木が長い場合
    if(balance > 1 && key < (*node)->left->data){
        return rightRotate(&(*node));
    }

    // (右、右)
    if(balance < -1 && key > (*node)->left->data){
        return leftRotate(&(*node));
    }
    
    // (左、右)
    if (balance > 1 && key > (*node)->left->data){
        (*node)->left = leftRotate(&(*node)->left);
        return rightRotate(&(*node));
    }

    // (右、左)
    if(balance < -1 && key < (*node)->left->data){
        (*node)->right = rightRotate(&(*node)->right);
        return leftRotate(&(*node));
    }

    /* 変更されていない元のノードを返す */
    return *node;
}

void preorder(NODE *p){
    if(p == NULL)
        return ;
    printf("%d\n", p->data);
    preorder(p->left);
    preorder(p->right);
}

void inorder(NODE *p){
    if(p == NULL)
        return ;
    inorder(p->left);
    printf("%d\n", p->data);
    inorder(p->right);
}

/**
* 木を右回転する
* @param y 右回転したい部分木の根
* @return 右回転後の根
**/
NODE *rightRotate(NODE **y){
    NODE *x, *t;

    x = (*y)->left;
    t = x->right;
    x->right = (*y); // 回転を行う
    (*y)->left = t;
    (*y)->height = max(height((*y)->left), height((*y)->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x; // 新しい木の根を返す
}

/**
* 木を左回転する
* @param y 左回転したい部分木の根
* @return 左回転後の根
**/
NODE *leftRotate(NODE **y){ // 実装する
    NODE *x, *t;

    x = (*y)->right;
    t = x->left;
    x->left = (*y); // 回転を行う
    (*y)->right = t;
    (*y)->height = max(height((*y)->left), height((*y)->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x; // 新しい木の根を返す
}