# Minor edit
#include "utility/db_helper.h"
#include <gtest/gtest.h>

TEST(DBHelperTest, InitSourceConnection) {
    DBHelper db_helper;
    db_helper.init_source_connection("mysql://user:password@localhost/source_db");
    ASSERT_NE(db_helper.get_source_connection(), nullptr);
}

TEST(DBHelperTest, InitTargetConnection) {
    DBHelper db_helper;
    db_helper.init_target_connection("mysql://user:password@localhost/target_db");
    ASSERT_NE(db_helper.get_target_connection(), nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}