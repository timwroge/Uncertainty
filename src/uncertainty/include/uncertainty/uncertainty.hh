#pragma once
#include <cmath>
#include <iostream>

namespace uncertainty {

template <typename T>
constexpr T Square(T a){
    return pow(a, 2);
}

template <typename Scalar>
struct Measurement
{

    private:
        Scalar mu;
        Scalar variance;

    public:
        Measurement(Scalar mu, Scalar variance) : mu(mu), variance(variance) {};

        Measurement operator + (const Measurement & B) const {
            return {mu + B.mu, variance + B.variance};
        }

        Measurement operator * (const Scalar & a) const {
            return {a * mu, Square(a) * variance};
        }

        Measurement operator * (const Measurement & B) const {
            auto f = mu * B.mu;
            return {f, Square(f) * (Square(variance / mu) + Square(B.variance / B.mu)) };
        }

        Measurement operator ^ (const Scalar b) const {
            auto f = pow(mu, b);
            return {f, Square ( b * pow(mu, b - 1) * variance ) };
        }


        friend std::ostream& operator << (std::ostream & os, const Measurement m){
            os << m.mu << " ± " << m.variance ;
            return os;
        }

        Scalar Mu(){
            return mu;
        };

        Scalar Variance(){
            return variance;
        };

};

}// namespace uncertainty
