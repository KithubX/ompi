/*
 * Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
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
#include "ompi/errhandler/errhandler.h"

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_BUILD_MPI_PROFILING
#pragma weak MPI_Pcontrol = PMPI_Pcontrol
#endif

#if OMPI_BUILD_MPI_PROFILING
#define MPI_Pcontrol PMPI_Pcontrol
#endif

static const char FUNC_NAME[] = "MPI_Pcontrol";


int MPI_Pcontrol(const int level, ...)
{
    va_list arglist;

    if (MPI_PARAM_CHECK) {
        OMPI_ERR_INIT_FINALIZE(FUNC_NAME);
    }

    /* Silence some compiler warnings */

    va_start(arglist, level);
    va_end(arglist);

    /* There's nothing to do here */

    return MPI_SUCCESS;
}

