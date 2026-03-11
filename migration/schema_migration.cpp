#include "migration/schema_migration.h"
#include <mysql/mysql.h>

void SchemaMigration::migrate_schema(MYSQL* source_connection, MYSQL* target_connection, const std::string& schema) {
    // Migrate schema
    create_tables(target_connection, schema);
    create_indexes(target_connection, schema);
}

void SchemaMigration::create_tables(MYSQL* target_connection, const std::string& schema) {
    // Create tables
    std::string query = "CREATE TABLE " + schema + ".table_name (";
    query += "id INT PRIMARY KEY, ";
    query += "name VARCHAR(255)";
    query += ")";
    if (mysql_query(target_connection, query.c_str())) {
        std::cerr << "Failed to create table" << std::endl;
        exit(1);
    }
}

void SchemaMigration::create_indexes(MYSQL* target_connection, const std::string& schema) {
    // Create indexes
    std::string query = "CREATE INDEX index_name ON " + schema + ".table_name (name)";
    if (mysql_query(target_connection, query.c_str())) {
        std::cerr << "Failed to create index" << std::endl;
        exit(1);
    }
}