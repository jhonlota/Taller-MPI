#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, p, tag = 0;
	char inmsg[1], outmsg[1];
	
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	if (rank == 0) {
		MPI_Recv(inmsg, 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status);
		MPI_Send(outmsg, 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		MPI_Recv(inmsg, 1, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);	
		MPI_Send(outmsg, 1, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
	}

	MPI_Finalize();
}
