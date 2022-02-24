//
// Created by Manuel Rodriguez on 2/14/22.
//

#ifndef HEAPFILE_TUPLE_H
#define HEAPFILE_TUPLE_H
#include <vector>
#include <iostream>

#include "Value.h"

namespace coquisql {
    class Tuple {
    public:
        explicit Tuple(int numberOfColumns);
        ~Tuple();
        int getNumberOfColumns() const;
        int getByteSize();

        Tuple& addColumn(Value* value);
        Value::ValueType getColumnType(int columnIndex) const;
        const Value* getColumnValue(int columnIndex) const;
        Tuple& setColumnValue(int columnIndex, Value* newValue);
        void serializeFromData(char *buf, int length);
        void serializeToData(char *buf, int length);
        friend std::ostream& operator<<(std::ostream& os, const Tuple& T);



    private:
        int numberOfColumns;
        std::vector<Value*> columns;

        int computeByteSize() const;
    };
}

#endif //HEAPFILE_TUPLE_H
