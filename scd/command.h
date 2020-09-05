#pragma once

#include <assuan.h>

typedef struct {
    const char *name;
    assuan_handler_t handler;
    const char * const help;
} assuan_cmd_triplet;

typedef struct {
    assuan_handler_t cmd_serialno;
    assuan_handler_t cmd_learn;
    assuan_handler_t cmd_readcert;
    assuan_handler_t cmd_readkey;
    assuan_handler_t cmd_setdata;
    assuan_handler_t cmd_pksign;
    assuan_handler_t cmd_pkauth;
    assuan_handler_t cmd_pkdecrypt;
    assuan_handler_t cmd_getattr;
    assuan_handler_t cmd_setattr;
    assuan_handler_t cmd_writecer;
    assuan_handler_t cmd_writekey;
    assuan_handler_t cmd_genkey;
    assuan_handler_t cmd_random;
    assuan_handler_t cmd_passwd;
    assuan_handler_t cmd_checkpin;
    assuan_handler_t cmd_lock;
    assuan_handler_t cmd_unlock;
    assuan_handler_t cmd_getinfo;
    assuan_handler_t cmd_restart;
    assuan_handler_t cmd_disconnec;
    assuan_handler_t cmd_apdu;
    assuan_handler_t cmd_killscd;
} scdaemon_cmd_set;
