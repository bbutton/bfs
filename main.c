#include <stdio.h>

#include "queue.h"
#include "bfs_traversal.h"

int main(int argc, char ** argv) {
  queue queue;
  initialize(&queue);

  printf("Beginnning traversal at %s\n", argv[1]);
  
  traverse_directory_tree(&queue, argv[1], argv[0]);

  printf("ended traversal\n");

  return 0;
}



/*
 * breadthfirst ( root )
{
    enqueue ( root );
    while ( ! empty ( queue ) )
    {
next = dequeue ( queue );
for each node directly below next {
 } }
visit ( node );
if ( isa_directory ( node ) )
    enqueue ( node );
}
 */
