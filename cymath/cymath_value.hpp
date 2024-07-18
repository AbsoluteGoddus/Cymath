//
// Created by absol on 7/18/2024.
//

#ifndef CYMATH_CYMATH_VALUE_HPP
#define CYMATH_CYMATH_VALUE_HPP

#include "cymath_type.hpp"
#include <iostream>

/**
 * @file
 * @brief The file containing the std cymath_value type
 */

namespace cy {
    /**
     * @brief Base value class
     *
     * Used to save, get and manage Normal value types (Int, Float, Double)
     */
    class __CYMATH_ABSTRACT_VALUE_NORMAL : public __CYMATH_ABSTRACT_TYPE {
    public:
        /**
         * @brief Every possible type that this class can be
         */
        enum VALUE_TYPES {
            INT,
            FLOAT,
            DOUBLE
        };

        /**
         *
         * @param type The type of the value, in index form according to VALUE_TYPES
         * @param value The value to be stored
         */
        __CYMATH_ABSTRACT_VALUE_NORMAL(size_t type, void* value) {
            __set_data({static_cast<VALUE_TYPES>(type), value});
        }

        /**
         *
         * @param data a std::pair<size_t, void*> contain the value to be stored
         */
        __CYMATH_ABSTRACT_VALUE_NORMAL(std::pair<size_t, void*> data) {
            __set_data({static_cast<VALUE_TYPES>(data.first), data.second});
        }

        const std::function<void*(void*)> __get_value_handle(void* type) override {
            auto t = static_cast<VALUE_TYPES>(reinterpret_cast<size_t>(type));

            if (t > 2) {
                throw std::runtime_error("Wrong value type: " + std::to_string(reinterpret_cast<size_t>(type)));
            }

            switch (t) {
                case INT:
                    return function_handle_int;
                case FLOAT:
                    return function_handle_float;
                case DOUBLE:
                    return function_handle_double;
                default:
            }
        }

        /**
         * @brief Sets the data that the object contains.
         * @param data A std::pair<VALUE_TYPES, void*> containing the data to be stored
         */
        void __set_data(std::pair<VALUE_TYPES, void*> data) {
            _type = data.first;
            _value = data.second;
        }

        const std::pair<size_t, void*> __get_cast_info() override {
            return {_type, _value};
        };

        ~__CYMATH_ABSTRACT_VALUE_NORMAL() override {
            free(_value);
        }

    private:
        void* _value;
        VALUE_TYPES _type;

        static void* function_handle_int(void* value) {
            return static_cast<int*>(value);
        }

        static void* function_handle_float(void* value) {
            if (sizeof(float) < 4) {
                std::cerr << "Float size of system is smaller than 4. This could lead to issues" << std::endl;
            }
            return static_cast<float*>(value);
        }

        static void* function_handle_double(void* value) {
            if (sizeof(double) < 8) {
                std::cerr << "Double size of system is smaller than 8. This could lead to issues" << std::endl;
            }
            return static_cast<double*>(value);
        }
    };
}

#endif //CYMATH_CYMATH_VALUE_HPP
