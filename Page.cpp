//
// Created by Manuel Rodriguez on 2/10/22.
//
#include <cstring>
#include "Page.h"
namespace coquisql {

    Page::Page(){
        this->init();
    }
    Page::~Page(){
        this->clear();
    }
    void Page::init() {
        this->clear();
    }
    void Page::clear() {
        memset((void *) this->data, 0, Page::MAX_PAGE_SIZE);
    }
}
