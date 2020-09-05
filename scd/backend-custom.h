#include "../common/asshelp.h"

/**
 * Implement this file in a shared library.
 *
 * Load with the --custom-backend option.
 */

static gpg_error_t custom_cmd_serialno (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_learn (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_readcert (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_readkey (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_setdata (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_pksign (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_pkauth (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_pkdecrypt (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_getattr (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_setattr (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_writecert (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_writekey (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_genkey (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_random (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_passwd (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_checkpin (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_lock (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_unlock (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_getinfo (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_restart (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_disconnect (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_apdu (assuan_context_t ctx, char *line);
static gpg_error_t custom_cmd_killscd (assuan_context_t ctx, char *line);
