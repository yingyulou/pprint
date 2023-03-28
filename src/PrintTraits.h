/*
    PrintTraits.h
    =============
        Print traits header.
*/

#pragma once

#include <string>
#include <utility>
#include <cstddef>

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::index_sequence;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct __PrintTraits
{
    // Print Common
    template <size_t N, typename T>
    static void __printCommon(const T &val);


    // Print Sequence
    template <size_t N, typename T>
    static void __printSequence(const T &val, const string &startStr, const string &endStr);


    // Print Map
    template <size_t N, typename T>
    static void __printMap(const T &val, const string &startStr, const string &endStr);


    // Print Set
    template <size_t N, typename T>
    static void __printSet(const T &val, const string &startStr, const string &endStr);


    // Print Tuple Helper
    template <size_t N, typename T, size_t... Is>
    static void __printTupleHelper(const T &val, index_sequence<Is...>, const string &endStr);


    // Print Tuple
    template <size_t N, typename T>
    static void __printTuple(const T &val, const string &startStr, const string &endStr);


    // Print Stack Helper
    template <size_t N, typename T>
    static void __printStackHelper(T val, const string &startStr, const string &endStr);


    // Print Stack
    template <size_t N, typename T>
    static void __printStack(const T &val, const string &startStr, const string &endStr);


    // Print Queue
    template <size_t N, typename T>
    static void __printQueue(T val, const string &startStr, const string &endStr);


    // Print Priority Queue
    template <size_t N, typename T>
    static void __printPriorityQueue(const T &val, const string &startStr, const string &endStr);


    // Print
    template <size_t N, typename T>
    static void __print(const T &val, const string &startStr = "", const string &endStr = "");
};


}  // End namespace pprint
