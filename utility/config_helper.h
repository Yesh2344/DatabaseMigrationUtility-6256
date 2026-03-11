#ifndef CONFIG_HELPER_H
#define CONFIG_HELPER_H

#include <string>

class ConfigHelper {
public:
    void parse_args(int argc, char* argv[]);
    std::string get_source_connection_string();
    std::string get_target_connection_string();
    std::string get_schema();
    std::string get_data();

private:
    std::string source_connection_string_;
    std::string target_connection_string_;
    std::string schema_;
    std::string data_;
};

#endif  // CONFIG_HELPER_H