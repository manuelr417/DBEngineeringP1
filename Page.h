//
// Created by Manuel Rodriguez on 2/10/22.
//

#ifndef HEAPFILE_PAGE_H
#define HEAPFILE_PAGE_H

namespace coquisql {
    class Page {

    public :
        // Max page size
        static const int MAX_PAGE_SIZE = 4096;
        // Default Constructor
        Page();
        // Destructor
        ~Page();

        // Initializes the page to all 0.
        void init();

        // Clears the page to all 0.
        void clear();

    protected:
        // array of MAX_PAGE_SIZE bytes
        char data[MAX_PAGE_SIZE];

    };

}
#endif //HEAPFILE_PAGE_H
