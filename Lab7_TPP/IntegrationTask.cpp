
#include "include/IntegrationTask.h"
#include "include/IntegrationExceptions.h"

#include <cmath>
#include <utility>

IntegrationTask::IntegrationTask(
    Function function, double a, double b, int steps)
    : function_(std::move(function)), a_(a), b_(b), steps_(steps)
{
    if (!function_)
        throw CalculationException();

    if (!std::isfinite(a_) || !std::isfinite(b_) || a_ >= b_)
        throw InvalidIntervalException();

    if (steps_ <= 0)
        throw InvalidStepsException();
}

void IntegrationTask::setInterval(double a, double b)
{
    if (!std::isfinite(a) || !std::isfinite(b) || a >= b)
        throw InvalidIntervalException();

    a_ = a;
    b_ = b;
}

void IntegrationTask::setSteps(int steps)
{
    if (steps <= 0)
        throw InvalidStepsException();

    steps_ = steps;
}

double IntegrationTask::midpoint() const
{
    const double h = (b_ - a_) / steps_;
    double sum = 0.0;

    for (int i = 0; i < steps_; ++i) {
        const double x = a_ + (i + 0.5) * h;
        const double value = function_(x);

        if (!std::isfinite(value))
            throw CalculationException();

        sum += value;
    }

    const double result = sum * h;

    if (!std::isfinite(result))
        throw CalculationException();

    return result;
}

double IntegrationTask::trapezoid() const
{
    const double h = (b_ - a_) / steps_;
    double sum = 0.0;

    for (int i = 0; i <= steps_; ++i) {
        const double x = a_ + i * h;
        const double value = function_(x);

        if (!std::isfinite(value))
            throw CalculationException();

        sum += (i == 0 || i == steps_) ? value / 2.0 : value;
    }

    const double result = sum * h;

    if (!std::isfinite(result))
        throw CalculationException();

    return result;
}

double IntegrationTask::simpson() const
{
    if (steps_ % 2 != 0)
        throw InvalidStepsException();

    const double h = (b_ - a_) / steps_;
    double sum = 0.0;

    for (int i = 0; i <= steps_; ++i) {
        const double x = a_ + i * h;
        const double value = function_(x);

        if (!std::isfinite(value))
            throw CalculationException();

        const int coefficient =
            (i == 0 || i == steps_) ? 1 : (i % 2 == 0 ? 2 : 4);

        sum += coefficient * value;
    }

    const double result = sum * h / 3.0;

    if (!std::isfinite(result))
        throw CalculationException();

    return result;
}
