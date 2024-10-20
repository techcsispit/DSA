import java.util.*;

public class MergeSort {

    public static int[] sort(int a[]) {

        if (a.length == 1)
            return a;

        int mid = a.length / 2;
        int a1[] = sort(Arrays.copyOfRange(a, mid, a.length));
        int a2[] = sort(Arrays.copyOfRange(a, 0, mid));
        return merge(a1, a2);
    }

    public static int[] merge(int a[], int b[]) {

        int[] c = new int[a.length + b.length];
        int j = 0;
        int i = 0;
        int x = 0;

        while ((i < a.length) && (j < b.length)) {
            if (a[i] < b[j]) {
                c[x++] = a[i++];
            } else {
                c[x++] = b[j++];
            }
        }
        if (i < a.length) {
            while (i < a.length) {
                c[x++] = a[i++];
            }
        } else {
            while (j < b.length) {
                c[x++] = b[j++];
            }
        }

        return c;
    }

    public static int [] sort(int a[], int l , int h){
        if(l>=h)
        return a ; 
         
        int mid = (l+h)/2 ; 
        sort(a,l,mid) ; 
        sort(a,mid+1,h) ; 
        int i = l ; 
        int j =  mid+1; 
        int x = 0  ; 
        int c[] = new int[h-l+1] ; 
        while((i<=mid)&&(j<=h)){
            if(a[i]>a[j]){
                c[x++] = a[j++] ;  
            }
            else {
                c[x++] = a[i++] ;
            } 
        }

        while(i<=mid){
            c[x++] = a[i++] ;
        }
        while(j<=h){
            c[x++] = a[j++] ;
        }
        x =0 ;
          for(int z = l ; z<=h;z++){
            a[z] = c[x++] ;
          }

        return a ; 
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of terms:");
        int n = in.nextInt();
        int a[] = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the number for index " + i + ": ");
            a[i] = in.nextInt();
        }

        System.out.println("Sorted array: " + Arrays.toString(sort(a,0,a.length-1)));
    }
}
