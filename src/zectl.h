#ifndef ZECTL_ZECTL_H
#define ZECTL_ZECTL_H

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "libze/libze.h"
#include "libze_util/libze_util.h"

extern const char *ZE_PROGRAM;
extern const char *ZE_PROP_NAMESPACE;

void
ze_usage(void);

libze_error_t
ze_list(libze_handle_t *lzeh, int argc, char **argv);

libze_error_t
ze_create(libze_handle_t *lzeh, int argc, char **argv);

#endif //ZECTL_ZECTL_H
