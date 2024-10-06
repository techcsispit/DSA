#include<stdio.h>
#include<stdlib.h>

#include<conio.h>
#include<inttypes.h>

typedef struct Node{
    int data ; 
    struct Node *npx ;
}Node ;

Node* xor(Node * prev , Node*next){
    return (Node*)((uintptr_t)(prev)^(uintptr_t)(next)) ;
}

Node *tail  ;
Node * head = NULL ;
Node * prev = NULL ;
int size = 0 ;
Node* create(int n){
      Node*node = (Node*)malloc(sizeof(Node)) ;
      node->data = n ; 
     
      if(prev!=NULL)
      prev->npx = xor(prev->npx,node)  ;
      else{
        head = node ;
      }
     
       node->npx  = prev ; 
      prev = node ;
      tail  = node ;
      size++ ;
}
void print() {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

   
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        next = xor(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    printf("END\n");
}

void printrev(){
    Node * next = NULL ; 
    Node * temp = tail ; 
    printf("START "); 
    while(temp!=NULL){
        printf("<- %d ",temp->data) ;
        Node*s = next ; 
        next = temp ; 
        temp = xor(temp->npx , s) ;
    }
    
}
void inserfirst(int n){
      Node*node = (Node*)malloc(sizeof(Node)) ;
      node->data = n ;  
      node->npx = head;
      head->npx = xor(head->npx ,node) ;
      head = node ;
      size++ ;
}
void insertLast(int n){
    Node*node = (Node*)malloc(sizeof(Node)) ;
      node->data = n ;  
      node->npx = tail ; 
    tail->npx = xor(tail->npx,node) ; 
    tail = node ;
    size++ ;
}
void insert(int i , int n){
        if(i==0){
            inserfirst(n) ;
            return ;
        }
        if(i==size-1){
            insertLast(n) ;
            return ;
        }
        Node* temp = head ;
        Node* prev = NULL ;
        while(i-1>0){

        }


}

int main(){
    create(5);
    create(6) ;
    create(7) ;
    print() ;
    printrev() ;

}