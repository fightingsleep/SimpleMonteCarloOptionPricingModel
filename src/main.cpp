#include <memory>
#include <iostream>
#include "monte_carlo_model.hpp"

int main(int argc, char *argv[])
{
    // Read the user input from stdin
    double spot_price, strike_price, years_until_expiry, volatility, risk_free_rate;
    int num_simulations, option_type;
    bool print_debug = false;
    std::cout << "Stock spot price (ex: 20): ";
    std::cin >> spot_price;
    std::cout << "Option strike price (ex: 21): ";
    std::cin >> strike_price;
    std::cout << "Option term in years (ex: 0.5): ";
    std::cin >> years_until_expiry;
    std::cout << "Option volatility (ex: 0.1): ";
    std::cin >> volatility;
    std::cout << "Risk free interest rate (ex: 0.05): ";
    std::cin >> risk_free_rate;
    std::cout << "Option type (0 = CALL, 1 = PUT): ";
    std::cin >> option_type;
    std::cout << "Number of simulations (ex: 2000): ";
    std::cin >> num_simulations;
    std::cout << "Print simulated stock prices? (0 = NO, 1 = YES): ";
    std::cin >> print_debug;

    // Compute the option value using Monte Carlo simulation
    auto model = std::make_shared<MonteCarloModel>();
    double option_value =
        model->PriceOption(
            spot_price,
            strike_price,
            risk_free_rate,
            volatility,
            years_until_expiry,
            num_simulations,
            static_cast<OptionType>(option_type),
            print_debug);

    std::cout << "Option value: " << option_value << std::endl;
}