

class Cqueue{
   int a[] ;
   int front = -1;
   int rear = -1;
   Cqueue(){
       a= new int[5] ;
   }

   public boolean isEmpty(){
       return front==-1&&rear==-1 ;
   }
   public boolean isFull(){
       return ((rear+1)%a.length)==front ;
   }

   void push(int data){

       if(isFull()){
           System.out.println("Queue full");
           return ;
       }
       if(isEmpty()){
           front++ ;
       }
       rear = (rear + 1)%a.length ;
       a[rear] = data ;
   }

   int peek(){
       if(isEmpty()){
           System.out.println("Queue is Empty");
           return -1 ;
       }
       return a[front] ;
   }

   int pop(){
       if(isEmpty()){
           System.out.println("Queue is Empty");
           return -1 ;
       }
       int  retur = a[front] ;
       if(front==rear){
           front  = -1 ;
           rear =- 1 ;
           return retur;
       }
       front = (front+1)%a.length ;
       return retur ;
   }

   void print(){

       int f = front ;
       int e = rear ;
       System.out.print("X<-");
       while(e!=f){
           System.out.print(a[f]+"<-");
           f = (f+1)%a.length ;
       }
       if(!isEmpty()){
           System.out.print(a[e]+"<-");
       }
       System.out.println("X");
   }



}
public class tryCQ {
   public static void main(String[] args) {
       Cqueue q = new Cqueue() ;
       q.push(5) ;
       q.push(6) ;
       q.push(7) ;
       q.print();
      System.out.println( q.peek());
      System.out.println( q.pop()) ;
      q.print() ;
      System.out.println( q.pop()) ;
      System.out.println( q.pop()) ;
       q.print();
   }
}
