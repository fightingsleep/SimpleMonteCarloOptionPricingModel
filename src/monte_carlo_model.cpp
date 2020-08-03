#include "monte_carlo_model.hpp"
#include <random>
#include <cmath>
#include <iostream>

double MonteCarloModel::PriceOption(
    double spot_price,
    double strike_price,
    double risk_free_rate,
    double volatility,
    double years_until_expiry,
    double num_simulations,
    OptionType option_type,
    bool print_debug)
{
    // Create a normal distribution that we can sample our normally distributed stochastic
    // variable from. The distribution has a mean of 0 and standard deviation of 1
    std::normal_distribution<double> norm_dist(0, 1);
    std::default_random_engine gen;

    // Simulate various stock price paths and accumulate their option payoffs
    double payoff_accumulator = 0;
    for (int i = 0; i < num_simulations; i++)
    {
        // Calculate the simulated stock price at expiry
        double stock_price = spot_price * std::exp((risk_free_rate - 0.5 * std::pow(volatility, 2)) *
            years_until_expiry + volatility * std::sqrt(years_until_expiry) * norm_dist(gen));

        if (print_debug)
        {
            std::cout << stock_price << std::endl;
        }

        // Calculate the payoff given the simulated stock price
        if (option_type == CALL)
        {
            payoff_accumulator += std::max(stock_price - strike_price, 0.0);
        }
        else
        {
            payoff_accumulator += std::max(strike_price - spot_price, 0.0);
        }
    }
    
    // Return the average payoff of the option (discount back to today)
    return payoff_accumulator / num_simulations * std::exp(-risk_free_rate * years_until_expiry);
}