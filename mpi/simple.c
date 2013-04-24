//Program to transfer an element from master to other processors.
#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	//int x=10;
	int rank;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0)
	{
		int x=10;
		printf("At master \n");
		printf("Value of x is %d\n",x);
		MPI_Send(&x,1,MPI_INT,1,2,MPI_COMM_WORLD);
	}
	else
	{
		int x;
		printf("At slave \n");
		MPI_Recv(&x,1,MPI_INT,0,2,MPI_COMM_WORLD,0);
	}
	MPI_Finalize();
	return 0;
}
