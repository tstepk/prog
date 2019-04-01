#include<iostream>
#include<omp.h>
#include<random>
using namespace std;

void w(long n)
{
	long sum=0;
	cout<<"i= "<<(n/10000000l) <<", Thread id= "<< omp_get_thread_num() << endl;
for(long i=0;i<n;++i)sum+=i;


}

void v(long n)
{
	random_device rd;
	uniform_int_distribution<int> dist(1,20);
	long sum=0;long los=dist(rd);
	cout<<"i= "<< los  <<", Thread id= "<< omp_get_thread_num() << endl;
for(long i=0;i<los*n;++i)sum+=i;
}

int main()
{
const long max=16, factor=10000000l;
//#pragma omp parallel for num_threads(4)
//#pragma omp parallel for schedule(static,1) num_threads(4)
//#pragma omp parallel for schedule(dynamic,1) num_threads(4)
//#pragma omp parallel for schedule(guided,1) num_threads(4)
//#pragma omp parallel for schedule(auto) num_threads(4)
#pragma omp parallel for schedule(runtime) num_threads(4)
	//for(int i=0;i<max;++i)w(i*factor);
	for(int i=0;i<max;++i) v(factor);

}

