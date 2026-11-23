
#include <iostream>
#include <iomanip>
#include "IntegrationTask.h"
#include "IntegrationExceptions.h"
#include "ScopeLogger.h"

int main()
{
    try {
        ScopeLogger logger("Numerical integration");

        IntegrationTask task(
            [](double x) { return x * x; },
            0.0, 1.0, 100
        );

        std::cout << std::fixed << std::setprecision(8);

        std::cout << "Midpoint:  " << task.midpoint() << '\n';
        std::cout << "Trapezoid: " << task.trapezoid() << '\n';
        std::cout << "Simpson:   " << task.simpson() << '\n';
    }
    catch (const IntegrationException& e) {
        std::cerr << "Integration error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
