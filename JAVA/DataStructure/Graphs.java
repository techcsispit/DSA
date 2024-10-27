// this is the code for Graphs
// for ease of explaination, this has 7 nodes, whose adjacency matrix is given below.
// Thus, this will help u understand how the things work in Graphs

/*THE ADJACENCY MATRIX IS:-
				  Everett		Seattle		North Bend		Spokane		Olympia		Centralia		Portland	
Everett				0			1 			    1 				  1 			    0 			  0 				0
Seattle				0 		0 			    0				    0			      1 			  0				  0
North Bend		0			0			      0				    1 			    0		    	0				  0
Spokane				0			0			      0				    0			      0			    0				  0
OLympia				0			0			      0				    0			      0			    1				  1
Centralia			0			0			      0				    1 			    0			    0				  1 				
Portland			0			0			      0				    0			      0			    0				  0

*/
import java.util.*;

public class Graphs {

    static Scanner obj = new Scanner(System.in);
    static Queue<String> q = new LinkedList<String>();
    static int distance[] = new int[7];  // worst case assumption, it will be a linear linked list thingy
    static String parent[] = new String[7];
    static int visitStatus[] = new int[7];	// 0 => not-visited(white)       1 => visited(gray)			2 => removed(black)	
    static String locations[] = {"everett", "seattle", "north bend", "spokane", "olympia", "centralia", "portland"};
    static LinkedList<String> Placelist[] = new LinkedList[7];
    static ArrayList<String> BFSdQ=new ArrayList<>();

    public static void main(String args[]) {
        run();
    }

    private static void run() {
        // Number of Nodes present: 7
        Arrays.fill(distance, -1);  // all the distances are initially set to -1 == infinity

        // Initialize LinkedLists
        for (int i = 0; i < Placelist.length; i++) {
            Placelist[i] = new LinkedList<String>();
        }

        int adjacency[][] = {
                {0, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 1},
                {0, 0, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0}
        };

        fillLinkedList(adjacency);

        // ASSUMING THAT EVERETT IS THE ENTRY POINT
        System.out.print("Entry Point: ");
        String entryPoint = obj.nextLine();  // takes the input for entry location
        System.out.println("\n\n");
        boolean exists = false;

        for (int i = 0; i < locations.length; i++) {
            if (locations[i].equalsIgnoreCase(entryPoint)) {
                distance[i] = 0;
                exists = true;
                BFSalgo(i);
                break;
            }
        }

        if (!exists) {
            System.out.println("\nNO ENTRY POINT DETECTED!");
            System.out.println("Exiting Code");
            System.exit(0);
        }

        System.out.println("\n\nThe BFS Traversal gave the following as the Answer:- ");
        String result=String.join(", ", BFSdQ);
        System.out.println(result.toUpperCase());

        notVisitedNodes();
    }

    private static void notVisitedNodes(){
        StringBuilder sb=new StringBuilder();
        System.out.print("The Unvisited Nodes in the Graph Traversal are:- ");
        for(int i=0; i<7; i++){
            if(visitStatus[i]==0){
                sb.append(locations[i]);
                sb.append(", ");
            }
        }

        if(sb.length()>0){
            System.out.println(sb.toString().toUpperCase());
        }
        else System.out.println("NULL");
    }

    private static void fillLinkedList(int mat[][]) {
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1) {
                    Placelist[i].add(locations[j]);
                }
            }
        }

        // Print adjacency list representation
        for (int i = 0; i < mat.length; i++) {
            System.out.print(locations[i] + "-> ");
            for (String location : Placelist[i]) {
                System.out.print(location + "-> ");
            }
            System.out.println();
        }
    }

    private static void BFSalgo(int index) {
        q.add(locations[index]);
        visitStatus[index] = 1;  // Mark as visited (gray)
        distance[index] = 0;     // Set distance of starting node to 0

        while (!q.isEmpty()) {
            displayAll();
            System.out.println("\n");

            String currentLocation = q.poll();
            BFSdQ.add(currentLocation);                                         // The answer that will go in the output
            int tempIndex = Arrays.asList(locations).indexOf(currentLocation);  // Although this will be same as index (saw this from stackoverflow)

            // Traverse all adjacent nodes of the dequeued node
            for (String adjacentNode : Placelist[tempIndex]) {
                // Get the index of the adjacent node
                int adjIndex = Arrays.asList(locations).indexOf(adjacentNode);

                if (visitStatus[adjIndex] == 0) {  // If not visited
                    q.add(adjacentNode);           // Enqueue the adjacent node
                    visitStatus[adjIndex] = 1;     // Mark it as visited (gray)
                    distance[adjIndex] = distance[tempIndex] + 1;  // Update distance
                    parent[adjIndex] = currentLocation;  // Set the parent for path reconstruction
                }
            }

            // Once all adjacent nodes are processed, mark the current node as black (fully processed)
            visitStatus[tempIndex] = 2;  // Mark the node as fully processed (black)
        }
    }



    private static void displayAll(){
        Queue<String> q1=new LinkedList<>(q);

        System.out.print("The QUEUE Elements are:- ");
        if(q1.isEmpty()) System.out.println("QUEUE IS EMPTY!");
        else{
            while(!q1.isEmpty()){
                System.out.print(q1.poll()+ " ");
            }
        }

        System.out.println("\nThe Distances are:- ");
        for(int i=0; i<7; i++){
            System.out.print(distance[i]+"  ");
        }

        System.out.print("\nThe Parents are:- ");
        for(int i=0; i<7; i++){
            System.out.print(parent[i]+"  ");
        }

        System.out.print("\nThe Visit-Status' are:- ");
        for(int i=0; i<7; i++){
            System.out.print(visitStatus[i]+"  ");
        }
    }
}
