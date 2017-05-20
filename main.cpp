/* C Example */
#include <mpi.h>
#include "Configuration.h"

int main(int argc, char *argv[]) {
    int rank, size, timestamp;


    Configuration::loadConfiguration();

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "Hello world from process " << rank << " of " << size << "\n";

    MPI_Finalize();
    return 0;
}