#ifndef INCLUDE_MONTE_CARLO_MODEL_HPP_
#define INCLUDE_MONTE_CARLO_MODEL_HPP_

#include "option_type.hpp"

class MonteCarloModel
{
public:
    // Price a European option using Monte Carlo simulation
    double PriceOption(
        double spot_price,
        double strike_price,
        double risk_free_rate,
        double volatility,
        double years_until_expiry,
        double num_simulations,
        OptionType option_type,
        bool print_debug);
};

#endif //INCLUDE_MONTE_CARLO_MODEL_HPP_