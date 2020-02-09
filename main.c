#include <stdio.h>

#include "queue.h"
#include "bfs_traversal.h"

int main(int argc, char ** argv) {
  queue queue;
  initialize(&queue);

  if(argc == 1) {
	traverse_directory_tree(&queue, ".", argv[0]);
  }
  else {
	traverse_directory_tree(&queue, argv[1], argv[0]);
  }	

  return 0;
}
