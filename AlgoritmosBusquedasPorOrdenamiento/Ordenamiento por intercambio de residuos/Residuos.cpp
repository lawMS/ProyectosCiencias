#include<iostream>
#include <ctime>
using namespace std;

unsigned bits(int a, int b, int c){
	return (a>>b)&~(~0<<c);
}

void cambiarResiduos(int arreglo[], int izq, int der, int b){
	int i , j;
	int aux = 0;
	if(der>izq && b>0){
		i = izq;
		j=der;
		while(j!=i){
			while(!bits(arreglo[i],b,1) && i<j){
				i++;
			}
			while(bits(arreglo[j],b,1) && j<i){
				j--;
			}
			//intercambio
			aux = arreglo[i];
	        arreglo[i] = arreglo[j];
	        arreglo[j] = aux;
		}
		if(!bits(arreglo[i],b,1)){
			j++;
		}
		cambiarResiduos(arreglo, izq, j-1, b-1);
		cambiarResiduos(arreglo, j, der, b-1);
	}
}

int main(){	
	int n = 4;
	int array[n];
	unsigned t0, t1;
	clock_t t;
	//Llenado
	cout<<"Arreglo\n";
	for(int i=1;i<=n;i++){
		array[n-i] = i;
	}
	for(int i=0;i<n;i++){
		cout<<i+1<<": "<<array[i]<<endl;
	}
	
	cout<<"Tiempo: ";
	t0=clock();	
	cambiarResiduos(array,1,n,4);
	t1=clock();
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << time << endl;	
}

