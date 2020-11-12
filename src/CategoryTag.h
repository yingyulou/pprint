/*
    CategoryTag.h
    =============
        Category tags header.
*/

#ifndef __PPRINT_CATEGORY_TAG_H
#define __PPRINT_CATEGORY_TAG_H

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Category Tag
////////////////////////////////////////////////////////////////////////////////

struct __CommonTag {};
struct __SequenceContainerTag {};
struct __MapContainerTag {};
struct __SetContainerTag {};
struct __PairTag {};
struct __MapPairTag {};
struct __TupleTag {};
struct __StackTag {};
struct __QueueTag {};
struct __InitializerListTag {};


}  // End namespace pprint


#endif  // __PPRINT_CATEGORY_TAG_H
