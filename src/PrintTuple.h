/*
    PrintTuple.h
    ============
        Class __PrintTupleOneLine and __PrintTupleMultiLine header.
*/

#pragma once

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Class __PrintTupleOneLine
////////////////////////////////////////////////////////////////////////////////

template <typename T, int Idx, int TopIdx>
struct __PrintTupleOneLine
{
    static void __Print(const T &val);
};


template <typename T, int TopIdx>
struct __PrintTupleOneLine<T, TopIdx, TopIdx>
{
    static void __Print(const T &val);
};


////////////////////////////////////////////////////////////////////////////////
// Class __PrintTupleMultiLine
////////////////////////////////////////////////////////////////////////////////

template <typename T, int N, int Idx, int TopIdx>
struct __PrintTupleMultiLine
{
    static void __Print(const T &val);
};


template <typename T, int N, int TopIdx>
struct __PrintTupleMultiLine<T, N, TopIdx, TopIdx>
{
    static void __Print(const T &val);
};


}  // End namespace pprint
