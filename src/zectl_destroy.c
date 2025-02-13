#include "zectl.h"

#include <stdio.h>
#include <unistd.h>

libze_error
ze_destroy(libze_handle *lzeh, int argc, char **argv) {
    int opt;
    libze_destroy_options options = {.be_name = NULL, .force = B_FALSE, .destroy_origin = B_TRUE};

    opterr = 0;

    while ((opt = getopt(argc, argv, "F")) != -1) {
        switch (opt) {
            case 'F':
                options.force = B_TRUE;
                break;
            default:
                fprintf(stderr, "%s destroy: unknown option '-%c'\n", ZE_PROGRAM, optopt);
                ze_usage();
                return LIBZE_ERROR_UNKNOWN;
        }
    }

    argc -= optind;
    argv += optind;

    if (argc != 1) {
        fprintf(stderr, "%s destroy: wrong number of arguments\n", ZE_PROGRAM);
        ze_usage();
        return LIBZE_ERROR_UNKNOWN;
    }

    options.be_name = argv[0];

    return libze_destroy(lzeh, &options);
}
