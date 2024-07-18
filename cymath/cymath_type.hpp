//
// Created by absol on 7/18/2024.
//

#ifndef CYMATH_CYMATH_TYPE_HPP
#define CYMATH_CYMATH_TYPE_HPP

#include <functional>

/**
 * @file
 * @brief The file containing the base class for cymath types
 */

namespace cy {
    /**
 *@brief Is the source of most other value type classes
 *
 * The class __CYMATH_ABSTRACT_TYPE is used by almost every other value like type in cymath. It also is the class most cymath functions use
 *
 */
    class __CYMATH_ABSTRACT_TYPE {
    public:
        /**
         * @brief Checks whether the type is castale to an int or not
         *
         * @return Returns if the type is castable to an int
         */
        virtual const bool __is_castable_int() { return true; };

        /**
         * @brief Function to cast the abstract value of a type into a real one
         *
         * @return The Integer representation of the value
         */
        virtual const int __cast_int() { return 0; };

        /**
         * @brief Checks whether the type is castale to a float or not
         *
         * @return Returns if the type is castable to a float
         */
        virtual const bool __is_castable_float() { return true; };

        /**
         * @brief Function to cast the abstract value of a type into a real one
         *
         * @return The float representation of the value
         */
        virtual const float __cast_float() { return 0; };

        /**
         * @brief Checks whether the type is castale to a double or not
         *
         * @return Returns if the type is castable to a double
         */
        virtual const bool __is_castable_double() { return true; };

        /**
         * @brief Function to cast the abstract value of a type into a real one
         *
         * @return The double representation of the value
         */
        virtual const double __cast_double() { return 0; };

        /**
         * @brief Checks whether the type is castale to a string or not
         *
         * @return Returns if the type is castable to a string
         */
        virtual const bool __is_printable() { return true; };

        /**
         * @brief Function to cast the abstract value of a type into a real one
         *
         * @return The c-style string representation of the value
         */
        virtual const char* __cast_string() { return "NO_VALUE"; };

        /**
         * @brief Finds and gets a value handle
         *
         * Finds an appropriate value handle, which can then be used process the value into any other value
         *
         * @param type The type in the appropriate type enum
         * @return The value handle function
         *
         *
         */
        virtual const std::function<void*(void*)> __get_value_handle(void* type) { return nullptr; };

        /**
         * @brief Function to get the cast info needed for casting
         *
         * @return a std::pair, containing the idx of the appropriate value type and the void ptr containing the value
         */
        virtual const std::pair<size_t, void*> __get_cast_info() { return std::pair<size_t, void*>(-1, nullptr); };

        virtual ~__CYMATH_ABSTRACT_TYPE() = default;
    };
}

#endif //CYMATH_CYMATH_TYPE_HPP
