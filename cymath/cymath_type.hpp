//
// Created by absol on 7/18/2024.
//

#ifndef CYMATH_CYMATH_TYPE_HPP
#define CYMATH_CYMATH_TYPE_HPP

#include <functional>

namespace cy {
    /**
 *@brief Is the source of most other value type classes
 *
 * The class __CYMATH_ABSTRACT_TYPE is used by almost every other value like type in cymath. It also is the class most cymath functions use
 *
 */
    class __CYMATH_ABSTRACT_TYPE {
    public:
        virtual const int __cast_int() { return 0; };
        virtual const float __cast_float() { return 0; };
        virtual const double __cast_double() { return 0; };
        virtual const bool __isPrintable() { return true; };
        virtual const char* __cast_string() { return "NO_VALUE"; };

        /**
         * @brief Finds and gets a value handle
         * @param type The type in the appropriate type enum
         * Finds an appropriate value handle, which can then be used process the value into any other value
         * @return The value handle function
         */
        virtual const std::function<void*(void*)> __get_value_handle(void* type) { return nullptr; };
        virtual ~__CYMATH_ABSTRACT_TYPE() = default;
    };
}

#endif //CYMATH_CYMATH_TYPE_HPP
