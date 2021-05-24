/*
    Constants.h
    ===========
        Constants define.
*/

#ifndef __PPRINT_CONSTANTS_H
#define __PPRINT_CONSTANTS_H

#include <string>

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;


////////////////////////////////////////////////////////////////////////////////
// Format Constants
////////////////////////////////////////////////////////////////////////////////

const char   __SPACE                    = ' ';
const int    __INDENTATION_LEN          = 4;
const string __VALUE_SPLICE             = ", ";
const char   __LINE_END                 = ',';
const string __TYPE_SEP                 = "::";
const char   __STRING_BEGIN             = '"';
const char   __STRING_END               = '"';
const string __BOOL_TRUE                = "true";
const string __BOOL_FALSE               = "false";
const char   __CHAR_BEGIN               = '\'';
const char   __CHAR_END                 = '\'';
const char   __SEQUENCE_CONTAINER_BEGIN = '[';
const char   __SEQUENCE_CONTAINER_END   = ']';
const char   __MAP_CONTAINER_BEGIN      = '{';
const char   __MAP_CONTAINER_END        = '}';
const char   __SET_CONTAINER_BEGIN      = '{';
const char   __SET_CONTAINER_END        = '}';
const char   __PAIR_BEGIN               = '(';
const char   __PAIR_END                 = ')';
const char   __MAP_PAIR_BEGIN           = '(';
const char   __MAP_PAIR_END             = ')';
const string __MAP_PAIR_SPLICE          = ": ";
const char   __MAP_PAIR_LINE_END        = ':';
const char   __TUPLE_BEGIN              = '(';
const char   __TUPLE_END                = ')';
const char   __STACK_BEGIN              = '[';
const char   __STACK_END                = ']';
const char   __QUEUE_BEGIN              = '[';
const char   __QUEUE_END                = ']';
const char   __INITIALIZER_LIST_BEGIN   = '{';
const char   __INITIALIZER_LIST_END     = '}';


}  // End namespace pprint


#endif  // __PPRINT_CONSTANTS_H
