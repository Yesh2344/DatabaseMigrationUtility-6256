#include "utility/config_helper.h"

void ConfigHelper::parse_args(int argc, char* argv[]) {
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--source") {
            source_connection_string_ = argv[i + 1];
        } else if (std::string(argv[i]) == "--target") {
            target_connection_string_ = argv[i + 1];
        } else if (std::string(argv[i]) == "--schema") {
            schema_ = argv[i + 1];
        } else if (std::string(argv[i]) == "--data") {
            data_ = argv[i + 1];
        }
    }
}

std::string ConfigHelper::get_source_connection_string() {
    return source_connection_string_;
}

std::string ConfigHelper::get_target_connection_string() {
    return target_connection_string_;
}

std::string ConfigHelper::get_schema() {
    return schema_;
}

std::string ConfigHelper::get_data() {
    return data_;
}