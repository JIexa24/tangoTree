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
		
  FILE *datamax = fopen("datamax.dat", "a"); //a- to end file
  FILE *datamin = fopen("datamin.dat", "a"); //a- to end file
  
  count = atoi(argv[1]);
  a = (long long*)malloc(count * sizeof(long long));
  
  tangoTree *headTangoTree = NULL;
  headTangoTree = createTangoTree(getrand(-1000000000,1000000000));
	double time = wtime();
	for(long long  i = 0; i < count - 1; i++){
		headTangoTree = initTangoTree(headTangoTree);
	}

	long long col = 0, coll;
	splayTree *headSplayTrees = NULL;
  headSplayTrees = createSplayTrees(headTangoTree);
  
	time = wtime() - time;
	
	printf("\nN=%ld, time = %.12lf", ii, time);
  //printf("--%ld !!!!  %d",ii,headSplayTrees->node->value);

	long long max = a[0],imin = 0;
	long long min = a[0],imax = 0;
	for(long long i = 0; i< ii;i++){
		if (a[i] < min) {
			min = a[i];
			imin = i;
		}
		
		if(a[i] > max){
			max = a[i];
			imax = i;
		}
	}
  double time2 = wtime();

	struct nodeTree *tst = searchValue(max, headSplayTrees);
	
	for(int i = 0; i < 1000; i++){
 	 if(tst != NULL){
  //		printf("\n=%ld=",tst->value);
  	 	restructTree(tst->value, headSplayTrees);
		}
	}
	system("pause");
	
	time2 = wtime() - time2;

	//printf("\nN=%ld,%ld time = %.12lf\n\n ",ii,max, time2);
	fprintf(datamax,"\nN=%ld,%ld %ld time = %.12lf ",ii,max,imax, time2);
	system("pause");
 	double time3 = wtime(); 
	for(int i = 0; i < 1000; i++){
		tst = searchValue(min, headSplayTrees);
  	if(tst != NULL){
  //		printf("\n=%ld=",tst->value);
  	 	restructTree(min, headSplayTrees);
		}
	}
	time3 = wtime() - time3;
	//printf("\nN=%ld,%ld time = %.16lf", ii,min, time3);
	fprintf(datamin,"\nN=%ld,%ld %ld time = %.12lf ",ii,min,imin, time3);

  fclose(datamax);
  fclose(datamin); 
	return 0;
	
}
