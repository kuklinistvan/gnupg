#pragma once
#include <assuan.h>
#include "command.h"

extern int scd_load_custom_command_implementations(const char * dynamic_module_path, scdaemon_cmd_set * set);