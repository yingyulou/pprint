/*
    PrintTraits.hpp
    ===============
        Print traits implementation.
*/

#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <type_traits>
#include <cstddef>
#include "PrintTraits.h"
#include "TypeTraits.hpp"
#include "Util.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::string;
using std::get;
using std::tuple_size_v;
using std::index_sequence;
using std::make_index_sequence;
using std::underlying_type_t;
using std::is_same_v;
using std::is_convertible_v;
using std::is_enum_v;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Common
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printCommon(const T &val)
{
    cout << string(N * 4, ' ');

    if constexpr (is_same_v<T, bool>)
    {
        cout << (val ? "true" : "false");
    }
    else if constexpr (is_same_v<T, char>)
    {
        cout << '\'' << val << '\'';
    }
    else if constexpr (is_convertible_v<T, string>)
    {
        cout << '"' << val << '"';
    }
    else if constexpr (is_enum_v<T>)
    {
        cout << __getTypeName(val) << "::" << (underlying_type_t<T>)val;
    }
    else if constexpr (__isPrintable<T>)
    {
        cout << val;
    }
    else
    {
        cout << '<' << __getTypeName(val) << ", " << &val << '>';
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Sequence
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printSequence(const T &val, const string &startStr, const string &endStr)
{
    if constexpr (__isSubCommon<T>)
    {
        cout << string(N * 4, ' ') << startStr;

        if (!val.empty())
        {
            auto iter = val.begin();

            __print<0>(*iter);

            for (iter++; iter != val.end(); iter++)
            {
                __print<0>(*iter, ", ");
            }
        }

        cout << endStr;
    }
    else
    {
        cout << string(N * 4, ' ') << startStr << '\n';

        for (auto &i: val)
        {
            __print<N + 1>(i, "", ",\n");
        }

        cout << string(N * 4, ' ') << endStr;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Map
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printMap(const T &val, const string &startStr, const string &endStr)
{
    cout << string(N * 4, ' ') << startStr << '\n';

    for (auto &i: val)
    {
        __print<N + 1>(i, "", ",\n");
    }

    cout << string(N * 4, ' ') << endStr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Set
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printSet(const T &val, const string &startStr, const string &endStr)
{
    __printSequence<N>(val, startStr, endStr);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Tuple Helper
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T, size_t... Is>
void __PrintTraits::__printTupleHelper(const T &val, index_sequence<Is...>, const string &endStr)
{
    (__print<N>(get<Is>(val), "", endStr), ...);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Tuple
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printTuple(const T &val, const string &startStr, const string &endStr)
{
    if constexpr (__isSubCommon<T>)
    {
        cout << string(N * 4, ' ') << startStr;

        if constexpr (tuple_size_v<T>)
        {
            __printTupleHelper<0>(val, make_index_sequence<tuple_size_v<T> - 1>(), ", ");

            __print<0>(get<tuple_size_v<T> - 1>(val));
        }

        cout << endStr;
    }
    else
    {
        cout << string(N * 4, ' ') << startStr << '\n';

        __printTupleHelper<N + 1>(val, make_index_sequence<tuple_size_v<T>>(), ",\n");

        cout << string(N * 4, ' ') << endStr;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Stack Helper
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printStackHelper(T val, const string &startStr, const string &endStr)
{
    if constexpr (__isSubCommon<T>)
    {
        cout << string(N * 4, ' ') << startStr;

        if (!val.empty())
        {
            __print<0>(val.top());
            val.pop();
        }

        for (; !val.empty(); val.pop())
        {
            __print<0>(val.top(), ", ");
        }

        cout << endStr;
    }
    else
    {
        cout << string(N * 4, ' ') << startStr << '\n';

        for (; !val.empty(); val.pop())
        {
            __print<N + 1>(val.top(), "", ",\n");
        }

        cout << string(N * 4, ' ') << endStr;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Stack
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printStack(const T &val, const string &startStr, const string &endStr)
{
    __printStackHelper<N>(__reverseStack(val), startStr, endStr);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Queue
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printQueue(T val, const string &startStr, const string &endStr)
{
    if constexpr (__isSubCommon<T>)
    {
        cout << string(N * 4, ' ') << startStr;

        if (!val.empty())
        {
            __print<0>(val.front());
            val.pop();
        }

        for (; !val.empty(); val.pop())
        {
            __print<0>(val.front(), ", ");
        }

        cout << endStr;
    }
    else
    {
        cout << string(N * 4, ' ') << startStr << '\n';

        for (; !val.empty(); val.pop())
        {
            __print<N + 1>(val.front(), "", ",\n");
        }

        cout << string(N * 4, ' ') << endStr;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print Priority Queue
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__printPriorityQueue(const T &val, const string &startStr, const string &endStr)
{
    __printStackHelper<N>(val, startStr, endStr);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <size_t N, typename T>
void __PrintTraits::__print(const T &val, const string &startStr, const string &endStr)
{
    cout << startStr;

    if constexpr (is_same_v<__Category<T>, __CommonTag>)
    {
        __printCommon<N>(val);
    }
    else if constexpr (is_same_v<__Category<T>, __SequenceTag>)
    {
        __printSequence<N>(val, "[", "]");
    }
    else if constexpr (is_same_v<__Category<T>, __MapTag>)
    {
        __printMap<N>(val, "{", "}");
    }
    else if constexpr (is_same_v<__Category<T>, __SetTag>)
    {
        __printSet<N>(val, "{", "}");
    }
    else if constexpr (is_same_v<__Category<T>, __TupleTag>)
    {
        __printTuple<N>(val, "(", ")");
    }
    else if constexpr (is_same_v<__Category<T>, __StackTag>)
    {
        __printStack<N>(val, "[", "]");
    }
    else if constexpr (is_same_v<__Category<T>, __QueueTag>)
    {
        __printQueue<N>(val, "[", "]");
    }
    else if constexpr (is_same_v<__Category<T>, __PriorityQueueTag>)
    {
        __printPriorityQueue<N>(val, "[", "]");
    }

    cout << endStr;
}


}  // End namespace pprint
