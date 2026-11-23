
#pragma once

#include <stdexcept>
#include <string>

class IntegrationException : public std::runtime_error {
public:
    explicit IntegrationException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidIntervalException : public IntegrationException {
public:
    InvalidIntervalException()
        : IntegrationException("Invalid integration interval") {
    }
};

class InvalidStepsException : public IntegrationException {
public:
    InvalidStepsException()
        : IntegrationException("Number of steps must be positive") {
    }
};

class CalculationException : public IntegrationException {
public:
    CalculationException()
        : IntegrationException("Integration calculation failed") {
    }
};
