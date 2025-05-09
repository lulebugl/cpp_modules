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

LogLevel Logger::_currentLevel = LOG_LEVEL_INFO;

Logger::Logger() {
    std::cout << "Default Logger constructor called" << std::endl;
}

Logger::Logger(const Logger& other) {
    std::cout << "Logger Copy constructor called" << std::endl;
    (void)other;
}

Logger& Logger::operator=(const Logger& other) {
    LOG_DEBUG("Logger Assignment operator called");
    if (this != &other) {
    }
    return (*this);
}

Logger::~Logger() { std::cout << "Logger Destructor called" << std::endl; }

void Logger::setLevel(LogLevel level) { _currentLevel = level; }

LogLevel Logger::getLevel() { return _currentLevel; }

std::string Logger::getLevelName(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_INFO:
            return "INFO";
        case LOG_LEVEL_WARNING:
            return "WARNING";
        case LOG_LEVEL_ERROR:
            return "ERROR";
        case LOG_LEVEL_NONE:
            return "NONE";
        default:
            return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level >= _currentLevel && level < LOG_LEVEL_NONE) {
        std::cout << "[" << getLevelName(level) << "] " << message << std::endl;
    }
}

void Logger::debug(const std::string& message) {
    log(LOG_LEVEL_DEBUG, message);
}

void Logger::info(const std::string& message) { log(LOG_LEVEL_INFO, message); }

void Logger::warning(const std::string& message) {
    log(LOG_LEVEL_WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LOG_LEVEL_ERROR, message);
}
