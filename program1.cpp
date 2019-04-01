#include<iostream>
#include<omp.h>
using namespace std;


static long num_steps=300000000;
const unsigned num_threads=8;
int main()
{

double pi=0.0,nthreads;
double step=1.0/(double)num_steps;
omp_set_num_threads(num_threads);
#pragma omp parallel
{
	int i,id,nthrds;
	double x,sum;
	id=omp_get_thread_num();
	nthrds=omp_get_num_threads();
	if(id==0) nthreads=nthrds;


	for(i=id,sum=0.0;i<num_steps;i+=nthrds)
	{
		x=(i+0.5)*step; 
		sum+=(4.0/(1.0+x*x));
		
		
	}
	sum=sum*step;
	#pragma atomic
	pi+=sum;
}
	

cout<<"PI = "<< pi<<endl;


};
