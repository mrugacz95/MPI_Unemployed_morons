/* C Example */
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);      /* starts MPI */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);        /* get current process id */
    MPI_Comm_size(MPI_COMM_WORLD, &size);        /* get number of processes */

    std::cout << "Hello world from process " << rank << " of " << size << "\n";

    MPI_Finalize();
    return 0;
}