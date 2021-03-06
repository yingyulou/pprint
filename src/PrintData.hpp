/*
    PrintData.hpp
    =============
        Class __PrintData implementation.
*/

#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <iterator>
#include <type_traits>
#include "PrintData.h"
#include "CategoryTag.hpp"
#include "CategoryTraits.h"
#include "SubCategoryTraits.h"
#include "PrintTuple.h"
#include "Util.hpp"
#include "Constants.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::endl;
using std::string;
using std::tuple_size;
using std::next;
using std::enable_if;
using std::is_enum;
using std::is_convertible;


////////////////////////////////////////////////////////////////////////////////
// __Print
////////////////////////////////////////////////////////////////////////////////

template <typename T, int N>
template <typename U>
typename enable_if<is_enum<U>::value>::type
__PrintData<__CommonTag, void, T, N>::__Print(const U &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << typeid(val).name()
         << __TYPE_SEP
         << static_cast<int>(val);
}


template <typename T, int N>
template <typename U>
typename enable_if<is_convertible<U, string>::value>::type
__PrintData<__CommonTag, void, T, N>::__Print(const U &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __STRING_BEGIN
         << val
         << __STRING_END;
}


template <typename T, int N>
template <typename U>
typename enable_if<!is_enum<U>::value && !is_convertible<U, string>::value>::type
__PrintData<__CommonTag, void, T, N>::__Print(const U &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << val;
}


template <int N>
void __PrintData<__CommonTag, void, bool, N>::__Print(bool val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << (val ? __BOOL_TRUE : __BOOL_FALSE);
}


template <int N>
void __PrintData<__CommonTag, void, char, N>::__Print(char val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __CHAR_BEGIN
         << val
         << __CHAR_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__SequenceContainerTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SEQUENCE_CONTAINER_BEGIN
         << endl;

    for (const auto &subVal: val)
    {
        __PrintData<
            SubTag,
            typename __SubCategoryTraits<SubTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(subVal);

        cout << __LINE_END
             << endl;
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SEQUENCE_CONTAINER_END;
}


template <typename T, int N>
void __PrintData<__SequenceContainerTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SEQUENCE_CONTAINER_BEGIN;

    if (!val.empty())
    {
        __PrintData<
            __CommonTag,
            void,
            typename T::value_type,
            0
        >::__Print(val.front());

        for (auto iter = next(val.begin()); iter != val.end(); iter++)
        {
            cout << __VALUE_SPLICE;

            __PrintData<
                __CommonTag,
                void,
                typename T::value_type,
                0
            >::__Print(*iter);
        }
    }

    cout << __SEQUENCE_CONTAINER_END;
}


template <typename T, int N>
void __PrintData<__MapContainerTag, __MapPairTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __MAP_CONTAINER_BEGIN
         << endl;

    for (const auto &subVal: val)
    {
        __PrintData<
            __MapPairTag,
            typename __SubCategoryTraits<__MapPairTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(subVal);

        cout << __LINE_END
             << endl;
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __MAP_CONTAINER_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__SetContainerTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SET_CONTAINER_BEGIN
         << endl;

    for (const auto &subVal: val)
    {
        __PrintData<
            SubTag,
            typename __SubCategoryTraits<SubTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(subVal);

        cout << __LINE_END
             << endl;
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SET_CONTAINER_END;
}


template <typename T, int N>
void __PrintData<__SetContainerTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __SET_CONTAINER_BEGIN;

    if (!val.empty())
    {
        __PrintData<
            __CommonTag,
            void,
            typename T::value_type,
            0
        >::__Print(*val.begin());

        for (auto iter = next(val.begin()); iter != val.end(); iter++)
        {
            cout << __VALUE_SPLICE;

            __PrintData<
                __CommonTag,
                void,
                typename T::value_type,
                0
            >::__Print(*iter);
        }
    }

    cout << __SET_CONTAINER_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__PairTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __PAIR_BEGIN
         << endl;

    __PrintData<

        typename __CategoryTraits<typename T::first_type>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<typename T::first_type>::__Category,
            typename T::first_type
        >::__Category,

        typename T::first_type,

        N + 1

    >::__Print(val.first);

    cout << __LINE_END
         << endl;

    __PrintData<

        typename __CategoryTraits<typename T::second_type>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<typename T::second_type>::__Category,
            typename T::second_type
        >::__Category,

        typename T::second_type,

        N + 1

    >::__Print(val.second);

    cout << __LINE_END
         << endl
         << string(N * __INDENTATION_LEN, __SPACE)
         << __PAIR_END;
}


template <typename T, int N>
void __PrintData<__PairTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __PAIR_BEGIN;

    __PrintData<
        __CommonTag,
        void,
        typename T::first_type,
        0
    >::__Print(val.first);

    cout << __VALUE_SPLICE;

    __PrintData<
        __CommonTag,
        void,
        typename T::second_type,
        0
    >::__Print(val.second);

    cout << __PAIR_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__MapPairTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __MAP_PAIR_BEGIN << endl;

    __PrintData<

        typename __CategoryTraits<typename remove_const<typename T::first_type>::type>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<typename remove_const<typename T::first_type>::type>::__Category,
            typename remove_const<typename T::first_type>::type
        >::__Category,

        typename T::first_type,

        N + 1

    >::__Print(val.first);

    cout << __MAP_PAIR_LINE_END
         << endl;

    __PrintData<

        typename __CategoryTraits<typename T::second_type>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<typename T::second_type>::__Category,
            typename T::second_type
        >::__Category,

        typename T::second_type,

        N + 1

    >::__Print(val.second);

    cout << __LINE_END
         << endl
         << string(N * __INDENTATION_LEN, __SPACE)
         << __MAP_PAIR_END;
}


template <typename T, int N>
void __PrintData<__MapPairTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __MAP_PAIR_BEGIN;

    __PrintData<
        __CommonTag,
        void,
        typename T::first_type,
        0
    >::__Print(val.first);

    cout << __MAP_PAIR_SPLICE;

    __PrintData<
        __CommonTag,
        void,
        typename T::second_type,
        0
    >::__Print(val.second);

    cout << __MAP_PAIR_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__TupleTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __TUPLE_BEGIN
         << endl;

    __PrintTupleMultiLine<T, N, 0, tuple_size<T>::value>::__Print(val);

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __TUPLE_END;
}


template <typename T, int N>
void __PrintData<__TupleTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __TUPLE_BEGIN;

    __PrintTupleOneLine<T, 0, tuple_size<T>::value>::__Print(val);

    cout << __TUPLE_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__StackTag, SubTag, T, N>::__Print(const T &val)
{
    T reverseVal = __reverseStack(val);

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __STACK_BEGIN
         << endl;

    while (!reverseVal.empty())
    {
        __PrintData<
            SubTag,
            typename __SubCategoryTraits<SubTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(reverseVal.top());

        cout << __LINE_END
             << endl;

        reverseVal.pop();
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __STACK_END;
}


template <typename T, int N>
void __PrintData<__StackTag, __CommonTag, T, N>::__Print(const T &val)
{
    T reverseVal = __reverseStack(val);

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __STACK_BEGIN;

    if (!reverseVal.empty())
    {
        __PrintData<
            __CommonTag,
            void,
            typename T::value_type,
            0
        >::__Print(reverseVal.top());

        reverseVal.pop();

        while (!reverseVal.empty())
        {
            cout << __VALUE_SPLICE;

            __PrintData<
                __CommonTag,
                void,
                typename T::value_type,
                0
            >::__Print(reverseVal.top());

            reverseVal.pop();
        }
    }

    cout << __STACK_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__QueueTag, SubTag, T, N>::__Print(T val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __QUEUE_BEGIN
         << endl;

    while (!val.empty())
    {
        __PrintData<
            SubTag,
            typename __SubCategoryTraits<SubTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(val.front());

        cout << __LINE_END
             << endl;

        val.pop();
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __QUEUE_END;
}


template <typename T, int N>
void __PrintData<__QueueTag, __CommonTag, T, N>::__Print(T val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __QUEUE_BEGIN;

    if (!val.empty())
    {
        __PrintData<
            __CommonTag,
            void,
            typename T::value_type,
            0
        >::__Print(val.front());

        val.pop();

        while (!val.empty())
        {
            cout << __VALUE_SPLICE;

            __PrintData<
                __CommonTag,
                void,
                typename T::value_type,
                0
            >::__Print(val.front());

            val.pop();
        }
    }

    cout << __QUEUE_END;
}


template <typename SubTag, typename T, int N>
void __PrintData<__InitializerListTag, SubTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __INITIALIZER_LIST_BEGIN
         << endl;

    for (const auto &subVal: val)
    {
        __PrintData<
            SubTag,
            typename __SubCategoryTraits<SubTag, typename T::value_type>::__Category,
            typename T::value_type,
            N + 1
        >::__Print(subVal);

        cout << __LINE_END
             << endl;
    }

    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __INITIALIZER_LIST_END;
}


template <typename T, int N>
void __PrintData<__InitializerListTag, __CommonTag, T, N>::__Print(const T &val)
{
    cout << string(N * __INDENTATION_LEN, __SPACE)
         << __INITIALIZER_LIST_BEGIN;

    if (val.size())
    {
        __PrintData<
            __CommonTag,
            void,
            typename T::value_type,
            0
        >::__Print(*val.begin());

        for (auto iter = next(val.begin()); iter != val.end(); iter++)
        {
            cout << __VALUE_SPLICE;

            __PrintData<
                __CommonTag,
                void,
                typename T::value_type,
                0
            >::__Print(*iter);
        }
    }

    cout << __INITIALIZER_LIST_END;
}


}  // End namespace pprint
