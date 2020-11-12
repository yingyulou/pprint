/*
    PrintData.h
    ===========
        Class __PrintData header.
*/

#ifndef __PPRINT_PRINT_DATA_H
#define __PPRINT_PRINT_DATA_H

#include "CategoryTag.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Class __PrintData
////////////////////////////////////////////////////////////////////////////////

template <typename SelfTag, typename SubTag, typename T, int N>
struct __PrintData;


template <typename T, int N>
struct __PrintData<__CommonTag, void, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__SequenceContainerTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__SequenceContainerTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__MapContainerTag, __MapPairTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__SetContainerTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__SetContainerTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__PairTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__PairTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__MapPairTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__MapPairTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__TupleTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__TupleTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__StackTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__StackTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__QueueTag, SubTag, T, N>
{
    static void __Print(T val);
};


template <typename T, int N>
struct __PrintData<__QueueTag, __CommonTag, T, N>
{
    static void __Print(T val);
};


template <typename SubTag, typename T, int N>
struct __PrintData<__InitializerListTag, SubTag, T, N>
{
    static void __Print(const T &val);
};


template <typename T, int N>
struct __PrintData<__InitializerListTag, __CommonTag, T, N>
{
    static void __Print(const T &val);
};


}  // End namespace pprint


#endif  // __PPRINT_PRINT_DATA_H
