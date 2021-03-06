#include "wt_rust_wrap.h"
int conn_open(char * home, WT_EVENT_HANDLER *event_handler, const char *config, WT_CONNECTION** conn)
{
	return(wiredtiger_open(home, event_handler, config, conn));
}

int conn_close(WT_CONNECTION* conn, const char *config)
{
	return (conn->close(conn, config));
}

int session_open(WT_CONNECTION* conn, WT_EVENT_HANDLER *event_handler, const char *config, WT_SESSION **session)
{
	return (conn->open_session(conn, event_handler, config, session));
}

int session_close(WT_SESSION* session, const char *config) 
{
	return (session->close(session, config));
}

int create_table(WT_SESSION *session, const char *name, const char *config) 
{
	return (session->create(session, name, config));
}

int drop_table(WT_SESSION *session, const char *name, const char *config)
{
        return (session->drop(session, name, config));
}

int cursor_open(WT_SESSION* session, const char *uri, WT_CURSOR *to_dup, const char *config, WT_CURSOR **cursor)
{
	return (session->open_cursor(session, uri, to_dup, config, cursor));
}

int cursor_close(WT_CURSOR *cursor)
{
	return (cursor->close(cursor));
}

int cursor_get_value_i64(WT_CURSOR *cursor, int64_t *value)
{
	return (cursor->get_value(cursor, value));
}

int cursor_get_key_i64(WT_CURSOR *cursor, int64_t *key)
{
	return (cursor->get_key(cursor, key));
}

int cursor_get_value_str(WT_CURSOR *cursor, char **value)
{
        return (cursor->get_value(cursor, value));
}

int cursor_get_key_str(WT_CURSOR *cursor, char **key)
{
        return (cursor->get_key(cursor, key));
}

int cursor_get_value_item(WT_CURSOR *cursor, char **value, int *size)
{
	WT_ITEM item;
	int ret = 0;
        ret = cursor->get_value(cursor, &item);
	if (ret == 0) {
		*value = (char *)item.data;
		*size = (int)item.size;
	}
	return (ret);
}

int cursor_get_key_item(WT_CURSOR *cursor, char **key, int *size)
{
        WT_ITEM item;
        int ret = 0;
        ret = cursor->get_key(cursor, &item);
        if (ret == 0) {
                *key = (char *)item.data;
                *size = (int)item.size;
        }
        return (ret);
}

void cursor_set_value_item(WT_CURSOR *cursor, char *value, int size)
{
        WT_ITEM item;
        item.data = value;
        item.size = (uint32_t)size;

        cursor->set_value(cursor, &item);
}

void cursor_set_key_item(WT_CURSOR *cursor, char *key, int size)
{
        WT_ITEM item;
        item.data = key;
        item.size = (uint32_t)size;

        cursor->set_key(cursor, &item);
}

void cursor_set_value(WT_CURSOR *cursor, void *value) 
{
	cursor->set_value(cursor, value);
}

void cursor_set_key(WT_CURSOR *cursor, void *key)
{
	cursor->set_key(cursor, key);
}

int cursor_insert(WT_CURSOR *cursor)
{
	return (cursor->insert(cursor));
}

int cursor_next(WT_CURSOR *cursor)
{
	return (cursor->next(cursor));
}

int cursor_prev(WT_CURSOR *cursor)
{
	return (cursor->prev(cursor));
}

int cursor_search(WT_CURSOR *cursor)
{
	return (cursor->search(cursor));
}

int cursor_reset(WT_CURSOR *cursor)
{
	return (cursor->reset(cursor));
}
