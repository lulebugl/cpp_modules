/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:02:07 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/09 19:02:07 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <sstream>
#include <string>

enum LogLevel {
    LOG_LEVEL_DEBUG = 0,    // Most detailed
    LOG_LEVEL_INFO = 1,     // General information
    LOG_LEVEL_WARNING = 2,  // Warning messages
    LOG_LEVEL_ERROR = 3,    // Error messages
    LOG_LEVEL_NONE = 4      // No logging at all
};

class Logger {
   public:
    static const char* RESET;
    static const char* GREEN;
    static const char* BLUE;
    static const char* YELLOW;
    static const char* RED;
    static const char* PURPLE;

    Logger();
    Logger(const Logger& other);
    Logger& operator=(const Logger& other);
    ~Logger();

    static LogLevel getLevel();
    static void     setLevel(LogLevel level);
    static void     enableColors(bool enableColors);

    static void log(LogLevel level, const std::string& message);
    static void log(LogLevel level, const std::stringstream& message);

    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);

    static std::string getLevelName(LogLevel level);

   private:
    static LogLevel _currentLevel;
    static bool     _useColors;
};

#define LOG_DEBUG(msg_expr)                      \
    if (Logger::getLevel() <= LOG_LEVEL_DEBUG) { \
        std::stringstream ss_debug;              \
        ss_debug << msg_expr;                    \
        Logger::debug(ss_debug.str());           \
    }

#define LOG_INFO(msg_expr)                      \
    if (Logger::getLevel() <= LOG_LEVEL_INFO) { \
        std::stringstream ss_info;              \
        ss_info << msg_expr;                    \
        Logger::info(ss_info.str());            \
    }

#define LOG_WARNING(msg_expr)                      \
    if (Logger::getLevel() <= LOG_LEVEL_WARNING) { \
        std::stringstream ss_warning;              \
        ss_warning << msg_expr;                    \
        Logger::warning(ss_warning.str());         \
    }

#define LOG_ERROR(msg_expr)                      \
    if (Logger::getLevel() <= LOG_LEVEL_ERROR) { \
        std::stringstream ss_error;              \
        ss_error << msg_expr;                    \
        Logger::error(ss_error.str());           \
    }

#endif
