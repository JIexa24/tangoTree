#include "tree.h"
extern long long count;
extern long long ii;
extern long long *a;

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

tangoTree * createTangoTree(long long  _value)
{
	
	a[ii++] = _value;
	
//	printf("\n%d", _value);
	tangoTree *_tangoTree = (tangoTree *)malloc(sizeof(tangoTree));
	if(_tangoTree == NULL) exit(1);
			
  _tangoTree->character = -1;
	_tangoTree->value = _value; 
  _tangoTree->left = NULL;
  _tangoTree->right = NULL;
  
//printf("\n%d",_value);
	return _tangoTree;
}

tangoTree * initTangoTree(tangoTree *_tree)
{
	
	long long  _value = getrand(-1000000000,1000000000);
	if (_tree == NULL) {
		_tree = createTangoTree(_value);
	} else {
		int isLeft = 0;
		
		tangoTree *cursor = _tree;
		tangoTree *prev = NULL;
		
		while (cursor != NULL) {
			prev = cursor;
			if (_value <= cursor->value) {
			  cursor = cursor->left;
			  isLeft = 1;
			} else if (_value > cursor->value){
			  cursor = cursor->right;
				isLeft = 0;
			} 
		}
			if (isLeft == 1) {
				prev->left = createTangoTree(_value);

				if (prev->right != NULL) {
					prev->character = RIGHT;	
				}
				if (prev->right == NULL) {
					prev->character = LEFT;	
				}
 			} else if (isLeft == 0) {
				prev->character = RIGHT;
				prev->right = createTangoTree(_value);
			}
		
	}
	return _tree;
}

//----------------------------------------------------------------------------//

splayTree * createSplayTrees(tangoTree *_tangoTree)
{
	splayTree *_tree = (splayTree *)malloc(sizeof(splayTree));	
	if(_tree == NULL) exit(1);
	
	splayTree *cursorSplay = _tree;
	tangoTree *cursorTango = _tangoTree;
	struct nodeTree *cursorNode = NULL;
	struct nodeTree *prev = NULL;
	
	int isLeft = 0;
	int flg = 0;
	
	_tree->node = (struct nodeTree *)malloc(sizeof(struct nodeTree));
	if(_tree->node == NULL) exit(1);

	_tree->node->value = _tangoTree->value;
	_tree->node->left = NULL;
	_tree->node->right = NULL;
	_tree->node->nextTree = NULL;
	
	while (1) {	
	  //cursorSplay = _tree;	

	    cursorNode = _tree->node;
	  while (cursorNode != NULL) {
			prev = cursorNode;
			if (cursorNode->value > cursorTango->value) {
			  cursorNode = cursorNode->left;
			  isLeft = 1;
			} else if (cursorNode->value < cursorTango->value){	
				isLeft = 0;
			  cursorNode = cursorNode->right;
			} else {
				isLeft = -1;
				break;
			}
		}
		
	  if (flg == 1) {
	  	
			if (isLeft) {
				prev->left = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(prev->left == NULL) exit(1);
					prev->left->value = cursorTango->value;
				prev->right = NULL;
				prev->left->left = NULL;
				prev->left->right = NULL;
				prev->left->nextTree = NULL;
				cursorNode = prev->left;
			} else {
				prev->right = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(prev->right == NULL) exit(1);
				prev->right->value = cursorTango->value;
				prev->left = NULL;
				prev->right->right = NULL;
				prev->right->left = NULL;
				prev->right->nextTree = NULL;
				cursorNode = prev->right;
			}
		}
		
		flg = 1;
		
		if (cursorTango->character == -1) {
			break;
		}
		
		if (cursorTango->character == RIGHT) {
			
			if (cursorTango->left != NULL) {
				cursorNode->nextTree = createSplayTrees(cursorTango->left);
			}
			cursorTango = cursorTango->right;
		} else if (cursorTango->character == LEFT){
			
  		if (cursorTango->right != NULL) {
				cursorNode->nextTree = createSplayTrees(cursorTango->right);
			}
			cursorTango = cursorTango->left;
		}
	}
	
	int i = 0;
	int ctr = rand()%4;
	int vect = rand()%2;
	
	while (i < ctr) {
		
		if (_tree->node->left == NULL && _tree->node->right != NULL) {
			
			if (_tree->node->right->left == NULL){
				_tree->node->right->left = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(_tree->node->right->left == NULL) exit(1);
				_tree->node->right->left->left = NULL;
				_tree->node->right->left->right = NULL;
				_tree->node->right->left->nextTree = _tree->node->nextTree;
				_tree->node->right->left->value = _tree->node->value;
				
				struct nodeTree *tmp;
				tmp = _tree->node;
				_tree->node = _tree->node->right;
				free(tmp); 
			}
		} else if (_tree->node->right == NULL && _tree->node->left != NULL) {
			
			if (_tree->node->left->right == NULL){
				_tree->node->left->right = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(_tree->node->left->right == NULL) exit(1);
				_tree->node->left->right->left = NULL;
				_tree->node->left->right->right = NULL;
				_tree->node->left->right->nextTree = _tree->node->nextTree;
				_tree->node->left->right->value = _tree->node->value;
				
				struct nodeTree *tmp;
				tmp = _tree->node;
				_tree->node = _tree->node->left;
				free(tmp); 
			}
		} else if (_tree->node->left != NULL && _tree->node->right != NULL) {
			
			if (_tree->node->right->left == NULL && vect == LEFT) {
				_tree->node->right->left = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(_tree->node->right->left == NULL) exit(1);
				_tree->node->right->left->left = _tree->node->left;
				_tree->node->right->left->right = NULL;
				_tree->node->right->left->nextTree = _tree->node->nextTree;
				_tree->node->right->left->value = _tree->node->value;
				
				struct nodeTree *tmp;
				tmp = _tree->node;
				_tree->node = _tree->node->right;
				free(tmp); 
			} else if (_tree->node->left->right == NULL && vect == RIGHT) {
				_tree->node->left->right = (struct nodeTree *)malloc(sizeof(struct nodeTree));
				if(_tree->node->left->right == NULL) exit(1);
				_tree->node->left->right->left = NULL;
				_tree->node->left->right->right = _tree->node->right;
				_tree->node->left->right->nextTree = _tree->node->nextTree;
				_tree->node->left->right->value = _tree->node->value;
				
				struct nodeTree *tmp;
				tmp = _tree->node;
				_tree->node = _tree->node->left;
				free(tmp); 
			}
		}
		i++;
	}
	return _tree;
}

struct nodeTree * searchValue(long long  _value, splayTree *_tree)
{
  struct nodeTree *cursor = _tree->node;
	int searchSuccess = 0;
	while (1) {
		
		if(cursor==NULL){
			searchSuccess = 0;
			break;
		}
    if(cursor != NULL)
		if (cursor->left == NULL && cursor->right == NULL &&_value != cursor->value) {
      if(cursor->nextTree !=NULL){
			  if(cursor->nextTree->node ==NULL){
			searchSuccess = 0;
			break;
				} 
			}
		}
		
		if (_value == cursor->value) {
			searchSuccess = 1;
			break;
		}
		
		if (_value < cursor->value) {
			if(cursor->left != NULL) {

					cursor = cursor->left;
			} else {
				if (cursor->nextTree != NULL) {
					cursor = cursor->nextTree->node;
				} else {
					searchSuccess = 0;
					break;
				}
			}
		} else if (_value > cursor->value) {
			if(cursor->right != NULL) {

					cursor = cursor->right;
			} else {
				if (cursor->nextTree != NULL) {

					cursor = cursor->nextTree->node;
				} else {
					searchSuccess = 0;
					break;
				}
			}
		}
	}	
	
	if (searchSuccess == 1) {
		return cursor;
	} 
	
	return NULL;
}

void restructTree(long long  _value,splayTree *_tree)
{
	
  struct nodeTree *cursor = _tree->node;
  struct nodeTree *tmp = NULL;
  
	while (1) {
		if (cursor->left == NULL && cursor->right == NULL && cursor->nextTree == NULL &&_value != cursor->value) {
			break;
		}
		
		if (_value == cursor->value) {
			break;
		}
		
		if (_value < cursor->value) {
			if (cursor->left != NULL) {
				cursor = cursor->left;
					continue;
			} else {
				if (cursor->nextTree != NULL){
					tmp = cursor->nextTree->node;
					cursor->nextTree->node = cursor->right;
					cursor->left = tmp;
					
					cursor = cursor->left;
					continue;
				} else {
					break;
				}
			}
		} else if (_value > cursor->value) {
			if (cursor->right != NULL) {
					cursor = cursor->right;
					continue;
			} else {
				if (cursor->nextTree != NULL){
					tmp = cursor->nextTree->node;
					cursor->nextTree->node = cursor->left;
					cursor->right = tmp;
					
					cursor = cursor->right;
										continue;

				} else {
					break;
				}
			}
		}

	}
}	
