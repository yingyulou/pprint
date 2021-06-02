/*
    PrintData.h
    ===========
        Class __PrintData header.
*/

#pragma once

#include <string>
#include <type_traits>
#include "CategoryTag.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::enable_if;
using std::is_enum;
using std::is_convertible;


////////////////////////////////////////////////////////////////////////////////
// Class __PrintData
////////////////////////////////////////////////////////////////////////////////

template <typename SelfTag, typename SubTag, typename T, int N>
struct __PrintData;


template <typename T, int N>
struct __PrintData<__CommonTag, void, T, N>
{
    template <typename U>
    static typename enable_if<is_enum<U>::value>::type __Print(const U &val);


    template <typename U>
    static typename enable_if<is_convertible<U, string>::value>::type __Print(const U &val);


    template <typename U>
    static typename enable_if<!is_enum<U>::value && !is_convertible<U, string>::value>::type __Print(const U &val);
};


template <int N>
struct __PrintData<__CommonTag, void, bool, N>
{
    static void __Print(bool val);
};


template <int N>
struct __PrintData<__CommonTag, void, char, N>
{
    static void __Print(char val);
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
