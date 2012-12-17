
#ifndef _RS_PARSE_BINLOG_H_INCLUDED_
#define _RS_PARSE_BINLOG_H_INCLUDED_

#include <rs_config.h>
#include <rs_core.h>
#include <rs_master.h>

typedef struct {
    int (*header)(rs_request_dump_t *rd);
    int (*query)(rs_request_dump_t *rd);
    int (*filter_data)(rs_request_dump_t *rd);
    int (*create_data)(rs_request_dump_t *rd);
    int (*intvar)(rs_request_dump_t *rd);
    int (*xid)(rs_request_dump_t *rd);
    int (*table_map)(rs_request_dump_t *rd);
    int (*write_rows)(rs_request_dump_t *rd);
    int (*update_rows)(rs_request_dump_t *rd);
    int (*delete_rows)(rs_request_dump_t *rd);
    int (*finish)(rs_request_dump_t *rd);
} rs_binlog_action_t;

#define rs_binlog_header_event          rs_binlog_actions.header 
#define rs_binlog_query_event           rs_binlog_actions.query 
#define rs_binlog_filter_data           rs_binlog_actions.filter_data
#define rs_binlog_create_data           rs_binlog_actions.create_data
#define rs_binlog_intvar_event          rs_binlog_actions.intvar
#define rs_binlog_xid_event             rs_binlog_actions.xid
#define rs_binlog_table_map_event       rs_binlog_actions.table_map
#define rs_binlog_write_rows_event      rs_binlog_actions.write_rows
#define rs_binlog_update_rows_event     rs_binlog_actions.update_rows
#define rs_binlog_delete_rows_event     rs_binlog_actions.delete_rows
#define rs_binlog_flush_event           rs_binlog_actions.flush_event
#define rs_binlog_finish_event          rs_binlog_actions.finish

extern rs_binlog_action_t rs_binlog_actions;

int rs_def_header_handle(rs_request_dump_t *rd);
int rs_def_query_handle(rs_request_dump_t *rd);
int rs_def_intvar_handle(rs_request_dump_t *rd);
int rs_def_xid_handle(rs_request_dump_t *rd);
int rs_def_table_map_handle(rs_request_dump_t *rd);
int rs_def_write_rows_handle(rs_request_dump_t *rd);
int rs_def_update_rows_handle(rs_request_dump_t *rd);
int rs_def_delete_rows_handle(rs_request_dump_t *rd);
int rs_def_finish_handle(rs_request_dump_t *rd);

#endif