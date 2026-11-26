// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

constexpr double WORKDAYS_PER_MONTH = 22.0;

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
     return 8.0 * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount - (before_discount * (discount / 100.0));
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double undiscounted_monthly = daily_rate(hourly_rate) * WORKDAYS_PER_MONTH;
    return static_cast<int>(std::ceil(apply_discount(undiscounted_monthly, discount)));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double discounted_daily = apply_discount(daily_rate(hourly_rate), discount);
    return static_cast<int>(std::floor(budget / discounted_daily));
}