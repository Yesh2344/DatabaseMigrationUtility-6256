#include <iostream>
#include "utility/db_helper.h"
#include "utility/config_helper.h"
#include "utility/logger.h"
#include "migration/schema_migration.h"
#include "migration/data_migration.h"

int main(int argc, char* argv[]) {
    // Parse command line arguments
    ConfigHelper config_helper;
    config_helper.parse_args(argc, argv);

    // Initialize logger
    Logger logger;
    logger.init();

    // Initialize database connections
    DBHelper db_helper;
    db_helper.init_source_connection(config_helper.get_source_connection_string());
    db_helper.init_target_connection(config_helper.get_target_connection_string());

    // Migrate schema
    SchemaMigration schema_migration;
    schema_migration.migrate_schema(db_helper.get_source_connection(), db_helper.get_target_connection(), config_helper.get_schema());

    // Migrate data
    DataMigration data_migration;
    data_migration.migrate_data(db_helper.get_source_connection(), db_helper.get_target_connection(), config_helper.get_data());

    return 0;
}