#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data ; 
    int height ; 
    struct Node * left ; 
    struct Node * right ; 
}Node; 

typedef struct AVL{
    Node * root ;
}AVL;

Node * createNode(int data){
    Node * node = (Node *)malloc(sizeof(Node)) ;
    node->data = data ; 
    node->height = 1 ; 
    node->left = NULL ; 
    node->right = NULL ;
    return node ; 
}

int max(int a, int b){
    if(a>b){
        return a ;
    }
    return b ;
}

int height (Node * node){
   if(node==NULL){
    return 0 ; 
   }
   return 1+max(height(node->left),height(node->right)) ;
}
int balanceFactor(Node *node){
    if(node==NULL)
    return 0 ; 
    return height(node->left) - height(node->right) ;
}

void printTree(Node *node, int level){
    if (node == NULL){
        return ;
    }
    printTree(node->right, level + 1);
    if (level != 0){
        for (int i = 0; i < level - 1; i++){
            printf("|\t\t");
        }
        printf("|------->%d(%d)\n", node->data,balanceFactor(node));
    }
    else{
        printf("%d(%d)\n", node->data,balanceFactor(node));
    }
    printTree(node->left, level + 1);
}


Node * rightRotate(Node * node){
    Node * old = node ; 
    Node * new = node->left ;
    Node * orphan = new->right ;
    new->right = old  ; 
    old->left = orphan ; 
    new->height = max(height(new->left),height(new->right))+1 ;
    old->height = max(height(old->left),height(old->right))+1 ; 
    return new ; 
}
Node * leftRotate(Node * node){
    Node * old = node ; 
    Node * new = node->right ; 
    Node * orphan = new->left ;
    new->left = old ;
    old->right = orphan ; 
    new->height = max(height(new->left),height(new->right))+1 ; 
    old->height = max(height(old->left),height(old->right))+1 ;
    return new ; 
}

Node * insert(Node *root , int  val){
    if(root==NULL){
        return createNode(val) ;
    }
    if((root->data)<val){
        root->right = insert(root->right , val); 
    }else if((root->data)>val){
        root->left = insert(root->left , val) ;
    }else{
        printf("SORRY CANNOT INSERT THE SAME VALUE \n") ;
        return root ; 
    }

    root->height = max(height(root->left),height(root->right))+1;
    int balance = balanceFactor(root) ; 
    if(balance>1&&(root->left->data)>val){
        printf("IMBALANCE AT %d ,  do Right Rotation as LL case\n",root->data) ;
        return rightRotate(root) ;
    }
     if(balance>1&&(root->left->data)<val){
        printf("IMBALANCE AT %d ,  LR case ,first left rotate and then right rotate\n",root->data) ;
        root->left = leftRotate(root->left) ;  
            return rightRotate(root) ;
    }  if(balance<-1&&(root->right->data)<val){
        printf("IMBALANCE AT %d , so RR case do left Rotation \n",root->data) ;
        return leftRotate(root) ;
    } if(balance<-1&&(root->right->data)>val){
        printf("IMBALANCE AT %d , so RL case do first right rotation and then left rotation\n",root->data) ;
        root->right = rightRotate(root->right) ; 
        return leftRotate(root) ;
    }
    return root ;
}
AVL * newAVL(){
    AVL * avl = (AVL *)malloc(sizeof(AVL));
    avl->root = NULL ;
    return avl ;
}
void insertInto(AVL * avl , int data){
    avl->root = insert(avl->root , data); 
    printf("AFTER INSERTING %d\n",data) ;
    printTree(avl->root,0) ; 
}

int main(){
    AVL* avl = newAVL() ; 
    int a[] = {20,45,90,70,10,40,35,30,99,60,50,80} ;
    for(int i = 0 ; i<12;i++){
        insertInto(avl ,a[i]) ;
    }
}
