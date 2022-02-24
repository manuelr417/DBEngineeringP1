//
// Created by Manuel Rodriguez on 2/10/22.
//

#ifndef HEAPFILE_HFPAGE_H
#define HEAPFILE_HFPAGE_H
#include <vector>
#include "Page.h"
#include "RecordId.h"
#include "Tuple.h"

namespace coquisql {
    class HFPage : public Page {

    public:

        // Default Constructor
        HFPage() : Page(){

        }
        // Destructor
        ~HFPage() = default;

        // Initializes a new page with a page id and size of records (fixed size)
        void initNewPage(PageId pageId, int fixedRecordLength);

        //Load the page from a buffer. length must
        //be equal to the maxpage size
        int load(PageId pageId, char *buf, int length);

        //Load the page from a buffer. length must
        //be equal to the maxpage size
        int put(char *buf, int length);

        // get the PageId of this page
        PageId getPageId() const;

        // get the PageId of the page after this
        PageId getNextPageId() const;

        // get the PageId of the page before this
        PageId getPreviousPageId() const;

        // set the PageId of the page after this
        void setNextPageId(PageId pageNo);

        // get the PageId of the page before this
        void setPreviousPageId(PageId pageNo);

        // Inserts a new record at new first available slot in the page.
        // Returns the record id of the newly inserted record.
        RecordId insertRecord(Tuple *newTuple);

        // Deletes a record from the page based on its recordId
        // Returns 0 if the record is deleted, -1 if the recordIs is not valid, or
        // -2 if the record was already deleted.
        int deleteRecord(const RecordId& recordId);

        // Updates a record from the page based on its recordId and new Tuples
        // Returns 0 if the record is updated, -1 if the recordIs is not valid, or
        // -2 if the record id gives a slot where no record is stored.
        int updateRecord(const RecordId& recordId, Tuple *srcTuple);

        // Reads a record from the page based on its recordId and stores in dstTuple pointer.
        // Returns 0 if the record is read, -1 if the recordIs is not valid, or
        // -2 if the record id gives a slot where no record is stored.
        int readRecord(const RecordId& recordId, Tuple *dstTuple);

        // removes all records from the page, but not the page header data In essense, the page is
        // empty of data
        void clearData();

        // returns the number of slots that are empty and available for use.
        int getAvailableSpace() const;

        // Returns the number of tuples currently stored
        int count() const;

        // Returns the  maximum number of tuples that can be stored.
        int maxCount() const;


        // Returns true if this page is empty
        bool isEmpty() const;

        // Return the fixed byte size of the page
        int maxByteSize() const;

    private :
        // Position of next page int
        static const int NEXT_PAGE_OFFSET = MAX_PAGE_SIZE - sizeof(int);
        // Position of previous page int
        static const int PREV_PAGE_OFFSET = MAX_PAGE_SIZE - 2 * sizeof(int);
        // Position of number of slots int
        static const int NUM_RECORDS_OFFSET = MAX_PAGE_SIZE - 3 *sizeof(int);
        // Position of first element in slot vector
        static const int SLOT_OFFSET = MAX_PAGE_SIZE - (3 *sizeof(int) + 1);
        // Value to indicate that a page ID value has not been set
        static const int PAGE_ID_NOT_SET = -1;

        //set the number of records in page
        void setSize(int newSize);
        // static method to compute max number of records (slots) in the page
        static int computeMaxNumberOfRecords(int fixedRecordLength) ;

        // Next page id  - convenience field . Must be kept synchronized with vale in byte array
        int nextPageId{};
        // This page id
        int pageId{};
        // previous page id - convenience field . Must be kept synchronized with vale in byte array
        int prevPageId{};

        // Returns the index of the first slot vector entry with a value of 0.
        int getFirstAvailableSlot();
    };

}
#endif //HEAPFILE_HFPAGE_H
