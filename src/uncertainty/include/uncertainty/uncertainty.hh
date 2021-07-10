#pragma once
#include <cmath>

namespace uncertainty {

template <typename T>
constexpr T Square(T a){
    return pow(a, 2);
}

template <typename Scalar>
struct Measurement
{

    public:
        Measurement(Scalar mu, Scalar variance) : mu(mu), variance(variance) {};

        Measurement operator + (const Measurement & B) const {
            return {mu + B.mu, variance + other.variance};
        }

        Measurement operator * (const Scalar & a) const {
            return {mu, Square(a) * variance};
        }

        Measurement operator * (const Measurement & B) const {
            constexpr auto f = mu * B.mu
            return {f, Square(f) * (Square(variance / mu) + Square(B.variance / B.mu)) };
        }

        Measurement operator ^ (const Scalar b) const {
            constexpr auto f = pow(mu, b);
            return {f, Square ( b * pow(mu, b - 1) * variance ) };
        }

    private:
            Scalar mu;
            Scalar variance;
}

}// namespace uncertainty
