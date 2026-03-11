# Database Migration Utility
[![Build Status](https://travis-ci.org/db-migration-utility/db-migration-utility.svg?branch=main)](https://travis-ci.org/db-migration-utility/db-migration-utility)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

A C++ database migration utility that enables easy migration of database schema and data.

## Installation
To install the database migration utility, follow these steps:
1. Clone the repository: `git clone https://github.com/db-migration-utility/db-migration-utility.git`
2. Navigate to the project directory: `cd db-migration-utility`
3. Build the project: `cmake . && make`
4. Run the utility: `./db_migration_utility`

## Usage
The utility can be used to migrate database schema and data. The following commands are available:
- `--help`: Displays the help menu
- `--source`: Specifies the source database connection string
- `--target`: Specifies the target database connection string
- `--schema`: Specifies the schema to migrate
- `--data`: Specifies the data to migrate

Example usage: