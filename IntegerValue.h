//
// Created by Manuel Rodriguez on 2/14/22.
//

#ifndef HEAPFILE_INTEGERVALUE_H
#define HEAPFILE_INTEGERVALUE_H

#include "Value.h"
namespace coquisql {
    class IntegerValue : public Value {
    public:
        // Lenght of integer in bytes
        static const int INT_LENGTH = 4;

        // Constructor based on a value to store
        explicit IntegerValue(int value) ;

        // Default constructor
        ~IntegerValue()= default;

        // Returns the integer value
        int getInteger() const;

        // Reads the value from a char (byte) array. Length must match length of the value.
        void serializeFromData(char *buf, int length) override;

        // Writes the value to a char (byte) array. Length must match length of the value.
        void serializeToData(char *buf, int length) override;

        // Returns the value as a string.
        std::string toString() const override;
    private :
        // stored int value
        int value;
    };
}

#endif //HEAPFILE_INTEGERVALUE_H
