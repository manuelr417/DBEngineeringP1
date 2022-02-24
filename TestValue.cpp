//
// Created by Manuel Rodriguez on 2/22/22.
//

#include <iostream>
#include <string>
#include "Value.h"
#include "IntegerValue.h"
#include "FixedStringValue.h"

int main() {
    std::cout << "Test Values" << std::endl;

    coquisql::IntegerValue intVal = coquisql::IntegerValue(20);

    std::cout << "IntegerValue intVal: " << intVal.getInteger() << std::endl;

    int temp = 100;
    intVal.serializeFromData((char *) &temp, coquisql::IntegerValue::INT_LENGTH);
    std::cout << "Changed IntegerValue intVal: " << intVal.getInteger() << std::endl;
    int temp2 = 0;

    std::cout << "before -> temp2: " << temp2 << std::endl;
    intVal.serializeToData((char *) &temp2, coquisql::IntegerValue::INT_LENGTH);
    std::cout << "after -> temp2: " << temp2 << std::endl;

    char buf[6];
    memset(buf, 0, 6);

    coquisql::FixedStringValue fixedStr = coquisql::FixedStringValue(10);
    std::string str3 = "Manuel";
    fixedStr.serializeFromData((char *) str3.c_str(), str3.length());
    std::cout << "fixedStr: " << fixedStr.getString() << "-" << std::endl;

    char buf2[10];
    memset(buf2, 0, 10);
    fixedStr.serializeToData(buf2, 10);
    std::cout << "buf2: " << buf2 << std::endl;

    return 0;
}
