//
// Created by Manuel Rodriguez on 2/14/22.
//

#ifndef HEAPFILE_VALUE_H
#define HEAPFILE_VALUE_H

#include <string>

namespace coquisql {
    class Value {

    public:
        // Enum of various Value types
        enum ValueType {
            string, integer
        };

        // Constructor based on value type and length in bytes
        Value(ValueType vType, int len) : valueType(vType), length(len) {

        }

        // Default destructor
        ~Value() = default;

        // maxlength of a value (currently not used)
        static const int MAX_VALUE_LENGTH = 256;

        // Reads the value from a char (byte) array. Length must match length of the value.
        // Virtual method to be implemented by child classes.
        virtual void serializeFromData(char *buf, int length) = 0;

        // Writes the value to a char (byte) array. Length must match length of the value.
        // Virtual method to be implemented by child classes.
        virtual void serializeToData(char *buf, int length) = 0;

        // Returns the value as a string
        // Virtual method to be implemented by child classes.
        virtual std::string toString() const = 0;


        // Returns the value type of this Value.
        inline ValueType getValueType() const {
            return this->valueType;
        };

        // Returns the length of this value in bytes
        inline int getLength() const {
            return this->length;
        }

    protected:
        // the value type
        ValueType valueType;

        // length of the value in bytes.
        int length;

    };

    typedef Value * ValuePtr;

}
#endif //HEAPFILE_VALUE_H
