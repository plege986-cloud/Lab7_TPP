
#pragma once

#include <functional>

class IntegrationTask {
public:
    using Function = std::function<double(double)>;

    IntegrationTask(Function function, double a, double b, int steps);

    double midpoint() const;
    double trapezoid() const;
    double simpson() const;

    void setInterval(double a, double b);
    void setSteps(int steps);

private:
    Function function_;
    double a_;
    double b_;
    int steps_;
};
