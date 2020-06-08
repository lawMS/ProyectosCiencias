#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

double diferenciaDeContadorDeRendimiento(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


void quickSort(int a[],int izq,int der){
	int i, j, x , aux; 
	i = izq; 
	j = der; 
	x = a[ der ]; 
    do{ 
        while( (a[i] < x) && (j <= der) )
        { 
            i++;
        } 
 
        while( (x < a[j]) && (j > izq) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = a[i]; a[i] = a[j]; a[j] = aux; 
            i++;  j--; 
        }
         
    }while( i <= j ); 
 
    if( izq < j ) 
        quickSort( a, izq, j ); 
    if( i < der ) 
        quickSort( a, i, der ); 
	
	
}

void inicioEnDesorden(){
	int n=5;
	int i;
	int aux=0;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	while(n<=55){
		int a[n];
		aux=n;
		for(i=0;i<n;i++){
			a[i]=aux;
			aux--;
		}
		QueryPerformanceCounter(&t_ini);
		quickSort(a,0,n-1);
		QueryPerformanceCounter(&t_fin);
		secs = diferenciaDeContadorDeRendimiento(&t_fin, &t_ini);
		char buffer[20];
		itoa(n, buffer,10);
		printf("El tiempo para n =");
		printf(buffer);
		printf(" es :");
		printf("%.16g\n", secs * 1000.0);
		n=n+5;
	}
}

int main(){
	inicioEnDesorden();
	return 0;
}
