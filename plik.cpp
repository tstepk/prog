#include<iostream>
#include<omp.h>
using namespace std;
static long num_steps=300000000;
double step;
const unsigned num_threads=2
;

int main(){
	int i,nthreads;
	double pi;
			//liczba krokow / przedzial calkowania / pętla po 1=0 do i<num_steps
	double sum[num_threads][8];
	step=1.0/(double)num_steps;
	

	omp_set_num_threads(num_threads);
#pragma omp parallel
{
	int i,id,nthrds;
	double x;
	id=omp_get_thread_num();
	nthrds=omp_get_num_threads();
	if(id==0) nthreads=nthrds;


	for(i=id,sum[id][0]=0.0;i<num_steps;i+=nthrds)
	{
		x=(i+0.5)*step; 
		sum[id][0]+=(4.0/(1.0+x*x));
		
		
	}
}
	for(i=0,pi=0.0;i<nthreads;++i)pi+=step*sum[i][0];

cout<<"PI = "<< pi<<endl;
}
//kompilacja :  g++ plik.cpp -o prog
//uruchomienie ./prog
