#include "utility/logger.h"
#include <fstream>

void Logger::init() {
    // Initialize log file
    log_file_.open("log.txt");
}

void Logger::log(const std::string& message) {
    // Log message
    log_file_ << message << std::endl;
}