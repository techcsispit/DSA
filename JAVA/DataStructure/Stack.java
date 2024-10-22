// this is where we are making a Stack using arrayList
// thus, there will be no case of overflow, as it will keep on getting added to the stack
// but there will for sure be the case of underflow, that is being taken care of

import java.util.*;
public class Stack<T extends Comparable<T>>{
    private ArrayList<T> arr;

    public Stack(){
        arr=new ArrayList<>();
    }

    // the thing that is being used can be any data type
    // this is what will enable the users to use Stack<String> or Stack<Integer> and so on

    public void push(T thing){
        arr.add(thing);
    }

    public T pop(){
        if(isEmpty()){
            throw new EmptyStackException();        // this is an exception from the util
        }
        return arr.remove(arr.size()-1);
    }

    public T peek(){
        if(isEmpty()){
            throw new EmptyStackException();
        }
        return arr.get(arr.size()-1);               // we use .get() for returning
    }

    public boolean isEmpty(){
        return arr.isEmpty();
    }

    private int getSize(){
        return arr.size();
    }
}
