
#include <gtest/gtest.h>

#include "IntegrationTask.h"
#include "IntegrationExceptions.h"

TEST(IntegrationTest, MidpointMethod)
{
    IntegrationTask task(
        [](double x) { return x * x; },
        0.0, 1.0, 100
    );

    EXPECT_NEAR(task.midpoint(), 1.0 / 3.0, 0.0001);
}

TEST(IntegrationTest, TrapezoidMethod)
{
    IntegrationTask task(
        [](double x) { return x * x; },
        0.0, 1.0, 100
    );

    EXPECT_NEAR(task.trapezoid(), 1.0 / 3.0, 0.0001);
}

TEST(IntegrationTest, SimpsonMethod)
{
    IntegrationTask task(
        [](double x) { return x * x; },
        0.0, 1.0, 100
    );

    EXPECT_NEAR(task.simpson(), 1.0 / 3.0, 0.000001);
}

TEST(IntegrationTest, InvalidSteps)
{
    EXPECT_THROW(
        IntegrationTask([](double x) { return x * x; },
            0.0, 1.0, 0),
        InvalidStepsException
    );
}

TEST(IntegrationTest, InvalidInterval)
{
    EXPECT_THROW(
        IntegrationTask([](double x) { return x * x; },
            1.0, 0.0, 100),
        InvalidIntervalException
    );
}

TEST(IntegrationTest, SimpsonOddSteps)
{
    IntegrationTask task(
        [](double x) { return x * x; },
        0.0, 1.0, 99
    );

    EXPECT_THROW(task.simpson(), InvalidStepsException);
}

TEST(IntegrationTest, StrongExceptionSafety)
{
    IntegrationTask task(
        [](double x) { return x * x; },
        0.0, 1.0, 100
    );

    EXPECT_THROW(task.setSteps(-5), InvalidStepsException);

    EXPECT_NEAR(task.simpson(), 1.0 / 3.0, 0.000001);
}
