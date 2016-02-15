#include <stdio.h>
#include <stdlib.h>

#define ITERS 5

#define NRA 500                 // number of rows in matrix A 
#define NCA 500                 // number of columns in matrix A
#define NCB 500                 // number of columns in matrix B


int main (int argc, char *argv[]) {
  int	i, j, k, iter;
  double **a, **b, **c;
  double *a_block, *b_block, *c_block;

  a = (double **) malloc(NRA*sizeof(double *)); /* matrix a to be multiplied */
  b = (double **) malloc(NCA*sizeof(double *)); /* matrix b to be multiplied */
  c = (double **) malloc(NRA*sizeof(double *)); /* result matrix c */

  a_block = (double *) malloc(NRA*NCA*sizeof(double)); /* Storage for matrices */
  b_block = (double *) malloc(NCA*NCB*sizeof(double));
  c_block = (double *) malloc(NRA*NCB*sizeof(double));

  for (i=0; i<NRA; i++)   /* Initialize pointers to a */
    a[i] = a_block+i*NRA;

  for (i=0; i<NCA; i++)   /* Initialize pointers to b */
    b[i] = b_block+i*NCA;
  
  for (i=0; i<NRA; i++)   /* Initialize pointers to c */
    c[i] = c_block+i*NRA;

    for (i=0; i<NRA; i++) /* last matrix has been initialized */
      for (j=0; j<NCA; j++)
	a[i][j]= (double) (i+j);
    for (i=0; i<NCA; i++)
      for (j=0; j<NCB; j++)
	b[i][j]= (double) (i*j);
    for (i=0; i<NRA; i++)
      for (j=0; j<NCB; j++)
	c[i][j]= 0.0;


    //multiplication ITERS times

    for(iter=0; iter<ITERS; iter++){

      for (i=0; i<NRA; i++) {
        for(j=0; j<NCB; j++) {    
	  for (k=0; k<NCA; k++) {
	    c[i][j] += a[i][k] * b[k][j];
	  }
        }
      }
      printf("Iteration %d of %d\n", iter+1, ITERS);

    }
}
