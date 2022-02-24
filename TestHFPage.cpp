//
// Created by Manuel Rodriguez on 2/23/22.
//

#include <iostream>
#include <string>
#include <random>
#include "Value.h"
#include "IntegerValue.h"
#include "FixedStringValue.h"
#include "Tuple.h"
#include "HFPage.h"

void fillData(std::vector<coquisql::Tuple *>& vector, int len);
void printData(const std::vector<coquisql::Tuple *>& data);

void addData(coquisql::HFPage *pPage, const std::vector<coquisql::Tuple *> &vector);

int getRandom(int start, int end);

void readTuple(int pageId, int slotId, coquisql::HFPage *pPage);

int main() {
    std::cout << "Test HFPage" << std::endl;//

    std::vector<coquisql::Tuple*> data = std::vector<coquisql::Tuple*>();
    fillData(data, 140);
    //printData(data);

    coquisql::HFPage *P = new coquisql::HFPage();
    P->initNewPage(0, 28);
    P->setNextPageId(1);
    P->setPreviousPageId(2);

    std::cout << "Page Id: " << P->getPageId() << ", next PageId: " << P->getNextPageId() <<
        ", prev PageId: " << P->getPreviousPageId() << ", number of slots: " << P->maxCount() <<
        ", current records: " << P->count() << std::endl;

    std::cout << "data.size(): " << data.size() << std::endl;
    addData(P, data);

    int random = getRandom(0, 30);
    std::cout << "Readind tuple: " << random << std::endl;
    readTuple(0, random, P);

    coquisql::RecordId targetId = {0, 2};
    int code = 0;
    std::cout << "Erase record: (0, 2)" << std::endl;
    code = P->deleteRecord(targetId);
    std::cout << "code: " << code << std::endl;
    readTuple(0, 2, P);
    // delete again
    std::cout << "Erase again record: (0, 2)" << std::endl;
    code = P->deleteRecord(targetId);
    std::cout << "code: " << code << std::endl;
    readTuple(0, 2, P);
    std::cout << "Record count: " << P->count() << std::endl;
    data.clear();
    fillData(data, 1);
    addData(P, data);
    readTuple(0, 2, P);



}

void readTuple(int pageId, int slotId, coquisql::HFPage *pPage) {
    coquisql::Tuple *T;
    coquisql::FixedStringValue *F;
    coquisql::RecordId rid = {pageId, slotId};
    int code = 0;

    T = new coquisql::Tuple(3);
    T->addColumn(new coquisql::IntegerValue(0));
    F = coquisql::FixedStringValue::buildFromString("Cambumbo" + std::to_string(-1), 20);
    T->addColumn((coquisql::Value*) F);
    T->addColumn(new coquisql::IntegerValue(-1 * 20));

    std::cout << "Tuple T: " << *T << std::endl;
    code = pPage->readRecord(rid, T);
    if (code ==0){
        std::cout << "Read Tuple T: " << *T << std::endl;
    }
    else {
        std::cout << "Record not found  " << std::endl;
    }
}

int getRandom(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range

    return distr(gen);
}

void addData(coquisql::HFPage *P, const std::vector<coquisql::Tuple *> &vector){
    coquisql::RecordId id = {0, 0};
    std::cout << "Inserting records: " << std::endl;
    for (int i=0; i < vector.size(); ++i){
        id = P->insertRecord(vector[i]);
        std::cout << "(" << id.pageNumber << ", " << id.slotNumber << ")" <<  ", current records: " << P->count() << std::endl;
    }
    std::cout << "Total records: " << P->count() << std::endl;
}

void fillData(std::vector<coquisql::Tuple *>& data, int len) {
    data.clear();
    coquisql::Tuple *T;
    coquisql::FixedStringValue *F;

    for (int i=0; i < len; ++i){
        T = new coquisql::Tuple(3);
        T->addColumn(new coquisql::IntegerValue(i));
        F = coquisql::FixedStringValue::buildFromString("Cambumbo" + std::to_string(i), 20);
        T->addColumn((coquisql::Value*) F);
        T->addColumn(new coquisql::IntegerValue(i * 20));
        data.push_back(T);
    }
}

void printData(const std::vector<coquisql::Tuple *>& data){
    int maxLen = data.size();
    for (int i=0; i < maxLen; ++i){
        std::cout << *(data[i]) << std::endl;
    }

}

