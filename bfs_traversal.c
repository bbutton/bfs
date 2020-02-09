#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>

#include "queue.h"

bool is_special_directory(const char * dir_name) {
  if(strncmp(dir_name, ".", 1) == 0 || (strncmp(dir_name, "..", 2) == 0)) return true;
  
  return false;
}

char * safe_append_directories(char * parent, char * child) {
  int len_parent = strnlen(parent, 1024);
  int len_child = strnlen(child, 1024);
  int mem_needed = len_parent + len_child + 1 + 1;
  char * dir_path = (char *)malloc(mem_needed);
  strncpy(dir_path, parent, len_parent + 1);
  strncat(dir_path, "/", 2);
  strncat(dir_path, child, len_child + 1);

  return dir_path;
}

void traverse_directory_tree(queue * queue, char * root_path, char * exe_name) {
  char * saved_root_path = (char *)malloc(strnlen(root_path, 1024));
  strncpy(saved_root_path, root_path, 1024);
  
  enqueue(queue, saved_root_path);
  while(empty(queue) == false) {
	char * dir_node = dequeue(queue);
	
	DIR * directory = opendir(dir_node);
	struct dirent * dir_entry = NULL;
	
	if(directory == NULL) {
	  printf("%s is not a directory!\n", dir_node);
	  perror(exe_name);
	  exit(1);
	}
	
	while((dir_entry = readdir(directory)) != NULL) {
	  if(is_special_directory(dir_entry->d_name)) continue;
	  printf("%s/%s\n", dir_node, dir_entry->d_name);

	  if(dir_entry->d_type == DT_DIR) {
		// finish refactoring to get this out of this function
		int len_parent = strnlen(dir_node, 1024);
		int len_current = strnlen(dir_entry->d_name, 1024);
		int mem_needed = len_parent + len_current + 1 + 1;
		char * dir_path = (char *)malloc(mem_needed);
		strncpy(dir_path, dir_node, len_parent + 1);
		strncat(dir_path, "/", 2);
		strncat(dir_path, dir_entry->d_name, len_current + 1);
		
		enqueue(queue, dir_path);
	  }
	}

	closedir(directory);

	free(dir_node);
  }
}

  /*
breadthfirst ( root )
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
