#ifndef LOGGER_H
#define LOGGER_H

class Logger {
public:
    void init();
    void log(const std::string& message);

private:
    std::ofstream log_file_;
};

#endif  // LOGGER_H