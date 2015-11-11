/*
 * Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2008 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2006      Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include "ompi_config.h"
#include <stdio.h>

#include "ompi/mpi/c/bindings.h"
#include "ompi/runtime/params.h"
#include "ompi/communicator/communicator.h"
#include "ompi/errhandler/errhandler.h"
#include "ompi/memchecker.h"

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_BUILD_MPI_PROFILING
#pragma weak MPI_Comm_test_inter = PMPI_Comm_test_inter
#endif

#if OMPI_BUILD_MPI_PROFILING
#define MPI_Comm_test_inter PMPI_Comm_test_inter
#endif

static const char FUNC_NAME[] = "MPI_Comm_test_inter";


int MPI_Comm_test_inter(MPI_Comm comm, int *flag) {

    MEMCHECKER(
        memchecker_comm(comm);
    );

    if ( MPI_PARAM_CHECK ) {
        OMPI_ERR_INIT_FINALIZE(FUNC_NAME);

        if ( ompi_comm_invalid ( comm ) ) {
             return OMPI_ERRHANDLER_INVOKE ( MPI_COMM_WORLD, MPI_ERR_COMM,
                                             FUNC_NAME);
        }

        if ( NULL == flag ) {
             return OMPI_ERRHANDLER_INVOKE ( comm, MPI_ERR_ARG,
                                             FUNC_NAME);
        }
    }

    *flag = (comm->c_flags & OMPI_COMM_INTER);
    return MPI_SUCCESS;
}
