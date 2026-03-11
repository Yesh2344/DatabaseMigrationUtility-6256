#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <mysql/mysql.h>
#include <string>

class DBHelper {
public:
    void init_source_connection(const std::string& connection_string);
    void init_target_connection(const std::string& connection_string);
    MYSQL* get_source_connection();
    MYSQL* get_target_connection();

private:
    MYSQL* source_connection_;
    MYSQL* target_connection_;
};

#endif  // DB_HELPER_H