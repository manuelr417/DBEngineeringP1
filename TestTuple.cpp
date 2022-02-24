// Created by Manuel Rodriguez on 2/22/22.
//
#include <iostream>
#include <string>
#include "Value.h"
#include "IntegerValue.h"
#include "FixedStringValue.h"
#include "Tuple.h"



int main() {
    std::cout << "Test Values" << std::endl;//

    int len = 0;

    coquisql::Tuple T = coquisql::Tuple(2);

    T.addColumn(new coquisql::IntegerValue(20));
    coquisql::FixedStringValue F = coquisql::FixedStringValue::fromString("Cambumbo", 10);
    T.addColumn((coquisql::Value*) &F);
    std::cout <<"T: " << T << std::endl;
    std::cout << "T.byteSize(): " << T.getByteSize() << std::endl;

    const coquisql::Value *V = T.getColumnValue(0);

    std::cout << "col[0]: " << ((coquisql::IntegerValue *) V)->getInteger() << std::endl;
    V = T.getColumnValue(1);
    std::cout << "col[1]: " << ((coquisql::FixedStringValue *) V)->getString() << std::endl;

    len = T.getByteSize();
    char *buf = new char[len+10];
    memset(buf, 0, len);

    T.serializeToData(buf, len);
    coquisql::Tuple T2 = coquisql::Tuple(2);
    T2.addColumn(new coquisql::IntegerValue(0));
    coquisql::FixedStringValue F2 = coquisql::FixedStringValue::fromString("Joe", 10);
    T2.addColumn((coquisql::Value*) &F2);
    std::cout <<"T2: " << T2 << std::endl;

    T2.serializeFromData(buf, len);
    std::cout << "New T2: " << T2 << std::endl;


    int pageSize = 4096;
    int fixedRecordLength = 28;

    int recordLengthAndSlot = fixedRecordLength + 1;
    // substract bytes use for page ids and slot count
    pageSize -= 3 * sizeof(int);
    std::cout << "pageSize: " << pageSize << std::endl;
    std::cout << "recordLengthAndSlot: " << recordLengthAndSlot << std::endl;

    // now compute floor of remaining space
    int slots = (int) round(floor(pageSize / recordLengthAndSlot));
    std::cout << "pageSize / recordLengthAndSlot: " << (pageSize / recordLengthAndSlot) << std::endl;

    std::cout << "floor(pageSize / recordLengthAndSlot): " << floor(pageSize / recordLengthAndSlot) << std::endl;

    std::cout << "slots: " << slots << std::endl;

    std::string s = "Cambumbo" + std::to_string(2);
    std::cout << "s: " << s << std::endl;

}