#include "tree.h"

#include <sys/time.h>
#include <stdio.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long count;
long long ii;

long long *a;


int main(int argc, char *argv[]) {
srand(time(NULL));
	if(argc < 2) {
		fprintf(stderr, "\nMissing arguments!\n");
		exit(EXIT_FAILURE);
	}
		
  count = atoi(argv[1]);
  a = (long long*)malloc(count * sizeof(long long));
  
  tangoTree *headTangoTree = NULL;
  headTangoTree = createTangoTree((rand()%(count *2 - 1) + 1));

	for(long long  i = 0; i < count - 1; i++){
		headTangoTree = initTangoTree(headTangoTree);
	}
	long long coll;
	splayTree *headSplayTrees = NULL;
  headSplayTrees = createSplayTrees(headTangoTree);
srand(time(NULL));
printf("--%ld !!!!  %d",ii,headSplayTrees->node->value);

double time = wtime();
for (long long  i = 0; i < count; i++){
coll = rand()%(count * 2);  
	struct nodeTree *tst = searchValue(coll, headSplayTrees);
	if (tst != NULL) { 
//printf("------------------------------------------------------------------------------restr coll %d", coll);
		col++;
   restructTree(tst->value, headSplayTrees);
	}
}
time = wtime() - time;
printf("\nN=%ld, time = %.12lf", count, time);
printf("\n-------%d\n\n",col);

long long max = a[0];
long long min = a[0];
for(long long i = 0; i< ii;i++){
	if (a[i] < min) {
		min = a[i];
	}
	if(a[i] > max){
		max = a[i];
	}
}
  time=wtime();
	struct nodeTree *tst = searchValue(max, headSplayTrees);
  if(tst != NULL){
  	printf("koko");
			}restructTree(tst->value, headSplayTrees);
time = wtime() - time;
printf("\nN=%ld,%ld time = %.12lf\n\n ", count,max, time);
 time = wtime(); 
	tst = searchValue(min, headSplayTrees);
   if(tst != NULL){
  	printf("koko");
			}restructTree(tst->value, headSplayTrees);
  
time = wtime() - time;
printf("\nN=%ld,%ld time = %.12lf", count,min, time);

	return 0;
	
}
