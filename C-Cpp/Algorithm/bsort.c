#include<stdio.h>
void bsort(int a[] ,int n ){ 
    int flag = 1 ;  
    for(int i = 0 ;i<n-1 ; i++){
        flag = 1; 
        for(int j = 0 ; j<n-1-i ; j++){
            if(a[j]>a[j+1]){
                int temp = a[j] ; 
                a[j]=a[j+1] ; 
                a[j+1] = temp ; 
                flag = 0 ; 
            }
        }
        if(flag){
            return ; 
        }
    }
}
int main(){

    int a[] = {5,4,3,2,1} ; 
    bsort(a,5) ; 
    for(int i = 0 ; i<5 ; i++){
        printf("%d ",a[i]);
    }


}