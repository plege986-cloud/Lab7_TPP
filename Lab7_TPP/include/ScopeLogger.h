
#pragma once

#include <string>
#include <iostream>

class ScopeLogger {
public:
    explicit ScopeLogger(const std::string& name)
        : name_(name)
    {
        std::cout << "[START] " << name_ << '\n';
    }

    ~ScopeLogger() noexcept
    {
        std::cout << "[END] " << name_ << '\n';
    }

    ScopeLogger(const ScopeLogger&) = delete;
    ScopeLogger& operator=(const ScopeLogger&) = delete;

private:
    std::string name_;
};
