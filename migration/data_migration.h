#ifndef DATA_MIGRATION_H
#define DATA_MIGRATION_H

#include <mysql/mysql.h>
#include <string>

class DataMigration {
public:
    void migrate_data(MYSQL* source_connection, MYSQL* target_connection, const std::string& data);

private:
    void copy_data(MYSQL* source_connection, MYSQL* target_connection, const std::string& data);
};

#endif  // DATA_MIGRATION_H