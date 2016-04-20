/* Programa que genera el triangulo de Sierpinski 
 * usando un automata 1-dimensional.
  */

#include <stdio.h>
#define TAM 40
#define N_Ciclos 15

void MostrarF(int a[],int tam);
void Actualiza(int a[],int tam);

int main(void)
{
  int a[TAM],i;

  for (i=0; i<TAM; i++)
    a[i]=0;
  a[TAM/2]=1;
  printf("Generacion  0:  ");
  MostrarF(a,TAM);
  for (i=1; i<= N_Ciclos; i++) {
    Actualiza(a,TAM);
    printf("Generacion %2i:  ",i);
    MostrarF(a,TAM);
  }
  return 0;
}

void Actualiza(int a[], int tam)
{
  int aa[TAM],a_1,a0,a1,i;

  for (i=0; i<tam; i++)
    aa[i]=a[i];
  for (i=1; i<tam-1; i++)
    a[i]=(aa[i-1] && !aa[i] && !aa[i+1])
      || (!aa[i-1] && aa[i+1]);
}

void MostrarF(int a[],int tam)
{
  int i;
  for (i=0; i<tam; i++)
    if (a[i] == 1) printf("*");
    else printf(" ");
  printf("\n");
}