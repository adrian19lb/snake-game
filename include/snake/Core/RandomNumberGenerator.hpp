#ifndef RANDOMGENERATOR_HPP_INCLUDED
#define RANDOMGENERATOR_HPP_INCLUDED

#include <random>
#include <chrono>
#include <functional>

namespace snake::core {
     
    template<typename T>
    class RandomGenerator {
    public:
        T operator()(T lowerBound, T upperBound) {
            T seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<T> distribution(lowerBound, upperBound);
            T random = distribution(generator);

            return random;
        }
    };
}
#endif // RANDOMGENERATOR_HPP_INCLUDED
