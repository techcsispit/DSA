#include<stdlib.h>
#include<stdio.h>
typedef struct Stack{
    int top ; 
    int capacity ;
    int *array ; 
}dstack;

dstack* create_stack(){
    dstack*  p = (dstack*)malloc(sizeof(dstack)) ;
    p->top = - 1 ;
    p->capacity = 1 ; 
    p->array = (int*)malloc(sizeof(int)*p->capacity) ;
}
int isFull(dstack*s){
    return s->top==(s->capacity-1) ;
}
int isEmpty(dstack*s){
    return s->top==-1;
}
void push(dstack* s , int data){
    if(isFull(s)){
        s->capacity =s->capacity*2 ;
        s->array =   (int*)realloc(s->array,sizeof(int)*s->capacity) ;          
    }
    s->array[++s->top] = data ;
}

int pop(dstack*s){
    if(isEmpty(s)){
        printf("UNDERFLOW\n") ; 
        return 0 ; 
    }
    return s->array[s->top--] ;
}

int peek(dstack*s){
    if(isEmpty(s)){
        printf("UNDERFLOW\n") ; 
        return 0 ; 
    }
    return s->array[s->top] ;
}

void print(dstack*s){
    for(int i = 0 ; i<=s->top ; i++){
        printf("%d->",s->array[i]) ;
    }
    printf("\n") ;
}

int main(){
    dstack *s = create_stack() ; 
    push(s,3) ; 
    push(s,4) ;
    push(s,6) ;
    push(s,7) ; 
    print(s) ; 
    pop(s)  ; 
    peek(s)  ; 
    print(s) ; 
}