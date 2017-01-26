#ifndef TREE_H
#define TREE_H

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

struct nodeTree;

typedef struct TangoTree {
	long long  value;
	struct TangoTree *left;
	struct TangoTree *right;
	int character;
} tangoTree;

tangoTree * createTangoTree(long long  _value);
tangoTree * initTangoTree(tangoTree *_tree);

typedef struct SplayTree {
	struct nodeTree *node;
} splayTree;

struct nodeTree {
 	long long  value;
 	struct nodeTree *right;
 	struct nodeTree *left;
	struct SplayTree *nextTree;
};

splayTree * createSplayTrees(tangoTree *_tangoTree);
struct nodeTree * searchValue(long long  _value, splayTree *_tree);
void restructTree(long long  _value,splayTree *_tree);

#endif
