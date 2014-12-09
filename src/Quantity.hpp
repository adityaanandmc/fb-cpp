#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include "Measurements.hpp"

template <typename T>
struct Quantity {
    /**
     * Destructor
     */
    virtual ~Quantity() {}

    T quantity;
};

#endif /* QUANTITY_HPP */
