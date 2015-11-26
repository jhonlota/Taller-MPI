#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int rank, p, tag = 0;
	int source, dest;
	
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	if (rank == 0) {
		char inmsg[1], outmsg[1];
		strcpy(outmsg, "a");
		source = 1;
		dest = 1;
		MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
		MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
		printf("Mensaje recibido: %s\n", inmsg);
	} else if (rank == 1) {
		char inmsg[1], outmsg[1];
		source = 0;
		dest = 0;
		MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);	
		*outmsg = toupper(*inmsg);
		MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	}

	MPI_Finalize();
}
