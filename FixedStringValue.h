//
// Created by Manuel Rodriguez on 2/22/22.
//

#ifndef HEAPFILE_FIXEDSTRINGVALUE_H
#define HEAPFILE_FIXEDSTRINGVALUE_H
#include <string>
#include "Value.h"

namespace coquisql {
    class FixedStringValue : Value{
    public:
        // Constructor based on length of char array for string
        explicit FixedStringValue(int maxLen);
        // Destructor
        ~FixedStringValue();

        // Returns the value as a string
        const std::string getString() const;

        // Reads the value from a char (byte) array. Length must match length of the value.
        void serializeFromData(char *buf, int length) override;

        // Writes the value to a char (byte) array. Length must match length of the value.
        void serializeToData(char *buf, int length) override;

        // Static builder used to create a FixedStringValue object from a string and maxLength.
        // If the string str is shorted thant maxLength, then empty spaces must be added
        // to reach the max length.
        static FixedStringValue fromString(const std::string& str, int maxLength);

        // Static builder used to create a pointer to a FixedStringValue object from a string and maxLength.
        // If the string str is shorted thant maxLength, then empty spaces must be added
        // to reach the max length.
        static FixedStringValue* buildFromString(const std::string& str, int maxLength);

        // Returns the value as a string
        std::string toString() const override;

    private :
        char *value;
    };
}

#endif //HEAPFILE_FIXEDSTRINGVALUE_H
