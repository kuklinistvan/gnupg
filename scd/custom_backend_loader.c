#include "custom_backend_loader.h"
#include "../common/logging.h"

#include <dlfcn.h>

static int load_function(void * handle, const char * sym, assuan_handler_t * target);

int scd_load_custom_command_implementations(const char * dynamic_module_path, scdaemon_cmd_set * set) {
    void * handle = dlopen(dynamic_module_path, RTLD_NOW);

    if(!handle) {
        log_error("Failed to open module at %s", dynamic_module_path);
        return 1;
    }

    int errc = 0;

    errc += load_function(handle,"custom_cmd_serialno", &(set->cmd_serialno));
    errc += load_function(handle,"custom_cmd_learn", &(set->cmd_learn));
    errc += load_function(handle,"custom_cmd_readcert", &(set->cmd_readcert));
    errc += load_function(handle,"custom_cmd_readkey", &(set->cmd_readkey));
    errc += load_function(handle,"custom_cmd_setdata", &(set->cmd_setdata));
    errc += load_function(handle,"custom_cmd_pksign", &(set->cmd_pksign));
    errc += load_function(handle,"custom_cmd_pkauth", &(set->cmd_pkauth));
    errc += load_function(handle,"custom_cmd_pkdecrypt", &(set->cmd_pkdecrypt));
    errc += load_function(handle,"custom_cmd_getattr", &(set->cmd_getattr));
    errc += load_function(handle,"custom_cmd_setattr", &(set->cmd_setattr));
    errc += load_function(handle,"custom_cmd_writecert", &(set->cmd_writecer));
    errc += load_function(handle,"custom_cmd_writekey", &(set->cmd_writekey));
    errc += load_function(handle,"custom_cmd_genkey", &(set->cmd_genkey));
    errc += load_function(handle,"custom_cmd_random", &(set->cmd_random));
    errc += load_function(handle,"custom_cmd_passwd", &(set->cmd_passwd));
    errc += load_function(handle,"custom_cmd_checkpin", &(set->cmd_checkpin));
    errc += load_function(handle,"custom_cmd_lock", &(set->cmd_lock));
    errc += load_function(handle,"custom_cmd_unlock", &(set->cmd_unlock));
    errc += load_function(handle,"custom_cmd_getinfo", &(set->cmd_getinfo));
    errc += load_function(handle,"custom_cmd_restart", &(set->cmd_restart));
    errc += load_function(handle,"custom_cmd_disconnect", &(set->cmd_disconnec));
    errc += load_function(handle,"custom_cmd_apdu", &(set->cmd_apdu));
    errc += load_function(handle,"custom_cmd_killscd", &(set->cmd_killscd));

    return errc;
}

static int load_function(void * handle, const char * sym, assuan_handler_t * target) {
    *target = dlsym(handle, sym);

    if(!(*target)) {
        log_error("Failed to load symbol %s", sym);
        return 1;
    } else {
        return 0;
    }
}