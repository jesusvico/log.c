#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "../include/log.h"

LogLevel log_level = 0;

static const char* log_level_to_string(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_TRACE: return "TRACE";
        case LOG_LEVEL_DEBUG: return "DEBUG";
        case LOG_LEVEL_INFO:  return "INFO";
        case LOG_LEVEL_WARN:  return "WARN";
        case LOG_LEVEL_ERROR: return "ERROR";
        case LOG_LEVEL_CRITICAL: return "CRITICAL";
        case LOG_LEVEL_FATAL: return "FATAL";
        default:        return "UNKNOWN";
    }
}

static const char* log_get_timestamp(char* buffer, size_t buffer_size) {
    // buffer_size should be at least 20 bytes
    if(buffer_size < 20) {
        buffer = NULL;
        return buffer;
    }

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    if (t != NULL) {
        strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", t);
    } else {
        snprintf(buffer, buffer_size, "0000-00-00 00:00:00");
    }

    return buffer;
}

int log_printf(LogLevel level, const char *file, int line, const char* format, ...) {

    if(log_level > level || log_level == LOG_LEVEL_OFF) return 0;

    FILE* output = (level < LOG_LEVEL_WARN) ? stdout : stderr;

    char time_buffer[20];
    int chars = fprintf(output, "%s [%s] %s:%d - ",
        log_get_timestamp(time_buffer, sizeof(time_buffer)),
        log_level_to_string(level),
        file,
        line);

    va_list args;
    va_start(args, format);
    chars += vfprintf(output, format, args);
    va_end(args);

    chars += fprintf(output, "\n");

    return chars;
}
