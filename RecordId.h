//
// Created by Manuel Rodriguez on 2/12/22.
//

#ifndef HEAPFILE_RECORDID_H
#define HEAPFILE_RECORDID_H

namespace coquisql {
    typedef int PageId;
    typedef int SlotId;

    typedef struct RecordId {
        // Page id
        PageId  pageNumber;
        // Slot number
        SlotId  slotNumber;

        int operator==(const RecordId &rid) const {
            return (this->pageNumber == rid.pageNumber) &&
                    (this->slotNumber == rid.slotNumber);
        }

        int operator!=(const RecordId &rid) const {
            return (this->pageNumber != rid.pageNumber) ||
                    (this->slotNumber != rid.slotNumber);
        }
    } RecordId;
}
#endif //HEAPFILE_RECORDID_H
