# Liblog

Minimal logging library for C

## Features

- Minimal API (single header)
- Seven log levels (`TRACE` to `FATAL`)
- Easy to integrate
- C and C++ compatible
- Macros for convenience

## Installation

Since the library consists of just one .c and one .h file, you can simply drop them into your project.

Alternatively, you can build and install the library:
```bash
make
sudo make install
```

## Usage

### Include the Header File
```c
#include "log.h"
```

### Log messages
There are multiple macros you can use for logging:
```c
log_trace(const char *format, ...);
log_debug(const char *format, ...);
log_info(const char *format, ...);
log_warn(const char *format, ...);
log_error(const char *format, ...);
log_critical(const char *format, ...);
log_fatal(const char *format, ...);
```

For example:
```c
#include "log.h"

int main() {
    log_level = LOG_LEVEL_DEBUG;

    log_info("App started");
    log_debug("x = %d", 42);
    log_error("Something went wrong");

    return 0;
}
```

### Set the Log Level
There are multiple logs levels:
```c
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
```

Only messages at or above the current `log_level` will be printed.
```c
log_level = LOG_LEVEL_INFO; // Only INFO and above will be logged
```

To disable logging entirely:
```c
log_level = LOG_LEVEL_OFF; // Turn off logs
```
