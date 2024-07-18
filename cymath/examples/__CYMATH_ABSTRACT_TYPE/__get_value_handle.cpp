//
// Created by absol on 7/18/2024.
//

#include "../../cymath_type.hpp"
#include <exception>
#include <string>
#include <functional>
#include <stdexcept>

class cymath_type_derived : public cy::__CYMATH_ABSTRACT_TYPE {
private:
    bool isInt = true;
    void *value;

    static void* toInt(void* value) {
        return static_cast<int*>(value);
    }

    static void* toFloat(void* value) {
        return static_cast<float*>(value);
    }

public:
    enum THIS_SUPPORTED_TYPES {
        INT,
        FLOAT
    };

    const std::function<void*(void*)> __get_value_handle(void *type) override {
        auto t = static_cast<THIS_SUPPORTED_TYPES>(reinterpret_cast<intptr_t>(type));
        if (t == INT) {
            return toInt;
        } else if (t == FLOAT) {
            return toFloat;
        } else {
            throw std::runtime_error("Unsupported type: " + std::to_string(t));
        }
    }

    ~cymath_type_derived() override {
        free(value);
    }
};