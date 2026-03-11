#ifndef SCHEMA_MIGRATION_H
#define SCHEMA_MIGRATION_H

#include <mysql/mysql.h>
#include <string>

class SchemaMigration {
public:
    void migrate_schema(MYSQL* source_connection, MYSQL* target_connection, const std::string& schema);

private:
    void create_tables(MYSQL* target_connection, const std::string& schema);
    void create_indexes(MYSQL* target_connection, const std::string& schema);
};

#endif  // SCHEMA_MIGRATION_H