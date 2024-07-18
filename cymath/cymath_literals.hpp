//
// Created by absol on 7/18/2024.
//

#ifndef CYMATH_CYMATH_LITERALS_HPP
#define CYMATH_CYMATH_LITERALS_HPP

#include "cymath_value.hpp"

/**
 * @file
 * @brief The file containing all cymath literals.
 */

namespace cy {
    /**
     * constructs a cymath-usable int
     * @param value The value to be specified
     * @return a __CYMATH_ABSTRACT_VALUE_NORMAL containing the data of the value
     */
    __CYMATH_ABSTRACT_VALUE_NORMAL operator"" _i(unsigned long long value) {
        int* int_value = new int(static_cast<int>(value));
        return {cy::__CYMATH_ABSTRACT_VALUE_NORMAL::INT, static_cast<void*>(int_value)};
    }

    /**
     * @brief constructs a cymath-usable double
     * @param value The value to be specified
     * @return a __CYMATH_ABSTRACT_VALUE_NORMAL containing the data of the value
     */
    __CYMATH_ABSTRACT_VALUE_NORMAL operator"" _d(long double value) {
        auto* double_value = new double(static_cast<double>(value));
        return {cy::__CYMATH_ABSTRACT_VALUE_NORMAL::DOUBLE, static_cast<void*>(double_value)};
    }
}

#endif //CYMATH_CYMATH_LITERALS_HPP
