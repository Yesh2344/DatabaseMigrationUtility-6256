# Minor edit
#include "migration/data_migration.h"
#include <mysql/mysql.h>

void DataMigration::migrate_data(MYSQL* source_connection, MYSQL* target_connection, const std::string& data) {
    // Migrate data
    copy_data(source_connection, target_connection, data);
}

void DataMigration::copy_data(MYSQL* source_connection, MYSQL* target_connection, const std::string& data) {
    // Copy data
    std::string query = "SELECT * FROM " + data;
    if (mysql_query(source_connection, query.c_str())) {
        std::cerr << "Failed to select data" << std::endl;
        exit(1);
    }
    MYSQL_RES* result = mysql_use_result(source_connection);
    while (MYSQL_ROW row = mysql_fetch_row(result)) {
        std::string insert_query = "INSERT INTO " + data + " VALUES (";
        insert_query += row[0];
        insert_query += ", ";
        insert_query += row[1];
        insert_query += ")";
        if (mysql_query(target_connection, insert_query.c_str())) {
            std::cerr << "Failed to insert data" << std::endl;
            exit(1);
        }
    }
    mysql_free_result(result);
}