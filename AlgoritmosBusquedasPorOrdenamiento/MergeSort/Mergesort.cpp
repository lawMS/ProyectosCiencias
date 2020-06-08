#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void Mergelist(int a[],int st1,int end1,int st2,int end2){
	int finalSt=st1;
	int finalEnd=end2;
	int indexC=1;
	int result[finalEnd];
	int i=0;
	while((st1<=end1)&&(st2<=end2)){
		if (a[st1]<a[st2]){
			result[indexC]=a[st1];
			st1=st1+1;
		}else{
			result[indexC]=a[st2];
			st2=st2+1;	
		}
		indexC=indexC+1;
	}
	if(st1<=end1){
		for(i=st1;i<end1;i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}else{
		for(i=st2;i<end2;i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}
	indexC=1;
	for(i=finalSt;i<finalEnd;i++){
		a[i]=result[indexC];
		indexC=indexC+1;
	}
}

void Mergesort(int a[],int f,int l){
	int mid=0;
	if (f<l){
		mid=(f+l)/2;
		Mergesort(a,f,mid);
		Mergesort(a,mid+1,l);
		Mergelist(a,f,mid,mid+1,l);
	}
}



void iniciarDesordenado(){
	int n=10;
	int i;
	int aux=0;
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	while(n<=500){
		int a[n];
		aux=n;
		for(i=0;i<n;i++){
			a[i]=aux;
			aux--;
		}
		QueryPerformanceCounter(&t_ini);
		Mergesort(a,0,n-1);
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%.16g\n", secs * 1000.0);
		n=n+10;
	}
}

int main(){
	iniciarDesordenado();
	return 0;
}
