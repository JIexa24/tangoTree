#include "tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long count;

int main(int argc, char *argv[]) {
//srand(time(NULL));
	if(argc < 2) {
		fprintf(stderr, "\nMissing arguments!\n");
		exit(EXIT_FAILURE);
	}
		
  count = atoi(argv[1]);
  
  tangoTree *headTangoTree = NULL;
  headTangoTree = createTangoTree((rand()%(count *2)));

	for(long long  i = 0; i < count - 1; i++){
		headTangoTree = initTangoTree(headTangoTree);
	}
	long long  col = 0,coll;
	splayTree *headSplayTrees = NULL;
  headSplayTrees = createSplayTrees(headTangoTree);
srand(time(NULL));
printf("--%d !!!!  %d",col,headSplayTrees->node->value);
for (long long  i = 0; i < count; i++){
coll = rand()%(count * 2);  
	struct nodeTree *tst = searchValue(coll, headSplayTrees);
	if (tst != NULL) { 
printf("------------------------------------------------------------------------------restr coll %d", coll);
		col++;
   restructTree(tst->value, headSplayTrees);
	}
}
printf("-------%d",col);
	return 0;
	
}
