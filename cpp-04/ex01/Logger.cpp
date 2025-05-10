/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:02:07 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/09 19:02:07 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

#include <iostream>

#include "Logger.hpp"

const char* Logger::RESET = "\033[0m";
const char* Logger::GREEN = "\033[32m";
const char* Logger::BLUE = "\033[34m";
const char* Logger::YELLOW = "\033[33m";
const char* Logger::RED = "\033[31m";
const char* Logger::PURPLE = "\033[36m";

LogLevel Logger::_currentLevel = LOG_LEVEL_DEBUG;

Logger::Logger() {}
Logger::Logger(const Logger& other) { (void)other; }
Logger& Logger::operator=(const Logger& other) {
    (void)other;
    return (*this);
}
Logger::~Logger() {}

void     Logger::setLevel(LogLevel level) { _currentLevel = level; }
LogLevel Logger::getLevel() { return _currentLevel; }

std::string Logger::getLevelName(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_DEBUG: return "DEBUG";
        case LOG_LEVEL_INFO: return "INFO";
        case LOG_LEVEL_WARNING: return "WARNING";
        case LOG_LEVEL_ERROR: return "ERROR";
        case LOG_LEVEL_NONE: return "NONE";
        default: return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level < _currentLevel || level >= LOG_LEVEL_NONE) {
        return;
    }

    switch (level) {
        case LOG_LEVEL_DEBUG: break;
        case LOG_LEVEL_INFO: break;
        case LOG_LEVEL_WARNING: {
            std::cout << YELLOW;
            break;
        }
        case LOG_LEVEL_ERROR: {
            std::cout << RED;
            break;
        }
        default: break;
    }
    std::cout << "[" << getLevelName(level) << "] " << message << RESET
              << std::endl;
}

void Logger::debug(const std::string& message) {
    log(LOG_LEVEL_DEBUG, message);
}

void Logger::info(const std::string& msg) { log(LOG_LEVEL_INFO, msg); }
void Logger::warning(const std::string& msg) { log(LOG_LEVEL_WARNING, msg); }
void Logger::error(const std::string& msg) { log(LOG_LEVEL_ERROR, msg); }
