#ifndef LOG_H
#define LOG_H

#ifdef __cplusplus
extern "C" {
#endif

// Version
#define LOG_VERSION_MAJOR 1
#define LOG_VERSION_MINOR 0
#define LOG_VERSION_PATCH 1

typedef enum {
    LOG_LEVEL_TRACE = 0,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_OFF = 255
} LogLevel;

extern LogLevel log_level;

#define log_trace(...) log_printf(LOG_LEVEL_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_printf(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) log_printf(LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_printf(LOG_LEVEL_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_printf(LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_critical(...) log_printf(LOG_LEVEL_CRITICAL, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_printf(LOG_LEVEL_FATAL, __FILE__, __LINE__, __VA_ARGS__)

int log_printf(LogLevel level, const char *file, int line, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif // LOG_H
