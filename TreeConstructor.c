/*Tree Constructor

Examples
Input: {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"}
Output: true
Input: {"(1,2)", "(3,2)", "(2,12)", "(5,2)"}
Output: false

*/

#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define PAIR_NUM        (2)
#define CHILD_POS       (1)
#define PARENT_POS      (3)
// number of nodes in Graph chosen arbitarily
#define GRAPH_NODES     (100)  
#define CHILD_PER_NODE  (2)

// define the data structure to store the vertices
struct Graph {
  struct Node* head[GRAPH_NODES];
};

// define struct to store the adjacency of nodes
struct Node {
  int dest;
  struct Node* next;
};
// define struct to store the nodes
struct Edge {
  int src, dest;
};

void parseArrayValues(char* strArr[], int* lPair){
  lPair[0] = strArr[0][CHILD_POS] - '0'; //string to integer
  lPair[1] = strArr[0][PARENT_POS] - '0'; // string to integer
}

// create a directed graph and return the pointer to base vertex
struct Graph* createGraph(struct Edge edges[], int size){
  // allocate memeory for graph 
  struct Graph* graph = malloc(sizeof(struct Graph));

  for(unsigned int i = 0; i < GRAPH_NODES; i++){
    graph->head[i] = NULL;
  }

  for (unsigned int i = 0; i < size; i++)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;

		// point new node to current head
		newNode->next = graph->head[src];

		// point head pointer to new node
		graph->head[src] = newNode;
	}

  return graph;
}

// function that checks all the vertices if they are connected with
// more than two vertices then it is not a binary tree
bool isBinaryTree(struct Graph* graph){  
  int table[GRAPH_NODES] = {0};

  for(unsigned int i = 0; i < GRAPH_NODES; i++){
    struct Node* ptr = graph->head[i];
    while(ptr != NULL){
      table[ptr->dest]++;
      if(table[ptr->dest] > CHILD_PER_NODE){
        return false;
      }
      ptr = ptr->next;
    }
  }
  return true;
} 

void TreeConstructor(char * strArr[], int arrayLength) {
  struct Edge edges[arrayLength];
  int pair[PAIR_NUM];

  for(unsigned int i = 0; i < arrayLength; i++){
    parseArrayValues(&strArr[i], pair);
    //check for the initialization ?
    edges[i].src = pair[0];
    edges[i].dest = pair[1];
  }

  // utility function to test the parsing functionality
  // for(unsigned int i = 0; i < arrayLength; i++){
  //   printf("(%d -> %d\n", edges[i].src, edges[i].dest);
  // }

  // create the directed graph
  struct Graph* graph = createGraph(edges, arrayLength);

  // Now, print if the graph is constructed as expected
  // for (unsigned int i = 0; i < N ; i++){
  //   struct Node* node = graph->head[i];
  //   while(node != NULL){
  //      printf("(%d -> %d\n", i, node->dest);     
  //      node = node ->next;
  //   }
  // }

  // verify whether the directed graph is a Binary Tree or not
  if(isBinaryTree(graph))
    printf("true");
  else
    printf("false");  
  
  // code goes here  
  // printf("%s", strArr[0]);
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  char * A[] = gets(stdin);
  int arrayLength = sizeof(A)/sizeof(A[0]);
  TreeConstructor(A, arrayLength);
  return 0;    
}
