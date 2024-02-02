#include "libze/libze_util.h"

libze_error
libze_plugin_form_namespace(char const plugin_name[static 1], char buf[ZFS_MAXPROPLEN]) {
    if (libze_util_concat(ZE_PROP_NAMESPACE, ".", plugin_name, ZFS_MAXPROPLEN, buf) !=
        LIBZE_ERROR_SUCCESS) {
        return LIBZE_ERROR_MAXPATHLEN;
    }
    return LIBZE_ERROR_SUCCESS;
}

libze_error
libze_plugin_form_property(char const plugin_prefix[static 1], char const plugin_suffix[static 1],
                           char buf[ZFS_MAXPROPLEN]) {
    if (libze_util_concat(plugin_prefix, ":", plugin_suffix, ZFS_MAXPROPLEN, buf) !=
        LIBZE_ERROR_SUCCESS) {
        return LIBZE_ERROR_MAXPATHLEN;
    }
    return LIBZE_ERROR_SUCCESS;
}
