#include "utility/db_helper.h"
#include <mysql/mysql.h>

void DBHelper::init_source_connection(const std::string& connection_string) {
    // Initialize source connection
    source_connection_ = mysql_init(NULL);
    if (!mysql_real_connect(source_connection_, connection_string.c_str(), NULL, NULL, NULL, 0, NULL, 0)) {
        std::cerr << "Failed to connect to source database" << std::endl;
        exit(1);
    }
}

void DBHelper::init_target_connection(const std::string& connection_string) {
    // Initialize target connection
    target_connection_ = mysql_init(NULL);
    if (!mysql_real_connect(target_connection_, connection_string.c_str(), NULL, NULL, NULL, 0, NULL, 0)) {
        std::cerr << "Failed to connect to target database" << std::endl;
        exit(1);
    }
}

MYSQL* DBHelper::get_source_connection() {
    return source_connection_;
}

MYSQL* DBHelper::get_target_connection() {
    return target_connection_;
}