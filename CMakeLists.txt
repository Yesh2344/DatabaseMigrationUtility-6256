cmake_minimum_required(VERSION 3.10)
project(db_migration_utility)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(db_migration_utility main.cpp utility/db_helper.cpp utility/config_helper.cpp utility/logger.cpp migration/schema_migration.cpp migration/data_migration.cpp)
target_link_libraries(db_migration_utility mysqlcppconn)