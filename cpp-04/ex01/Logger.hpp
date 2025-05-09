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
    Logger();
    Logger(const Logger& other);
    Logger& operator=(const Logger& other);
    ~Logger();

    static void     setLevel(LogLevel level);
    static LogLevel getLevel();

    static void log(LogLevel level, const std::string& message);

    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);

    static std::string getLevelName(LogLevel level);

   private:
    static LogLevel _currentLevel;
};

#define LOG_DEBUG(msg)                           \
    if (Logger::getLevel() <= LOG_LEVEL_DEBUG) { \
        Logger::debug(msg);                      \
    }

#define LOG_INFO(msg)                           \
    if (Logger::getLevel() <= LOG_LEVEL_INFO) { \
        Logger::info(msg);                      \
    }

#define LOG_WARNING(msg)                           \
    if (Logger::getLevel() <= LOG_LEVEL_WARNING) { \
        Logger::warning(msg);                      \
    }

#define LOG_ERROR(msg)                           \
    if (Logger::getLevel() <= LOG_LEVEL_ERROR) { \
        Logger::error(msg);                      \
    }

#endif
