/*
    PrintTuple.hpp
    ==============
        Class __PrintTupleOneLine and __PrintTupleMultiLine implementation.
*/

#ifndef __PPRINT_PRINT_TUPLE_HPP
#define __PPRINT_PRINT_TUPLE_HPP

#include <iostream>
#include <tuple>
#include "PrintTuple.h"
#include "PrintData.h"
#include "CategoryTraits.h"
#include "SubCategoryTraits.h"
#include "Constants.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Class __PrintTupleOneLine
////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::endl;
using std::get;
using std::tuple_element;


////////////////////////////////////////////////////////////////////////////////
// Class __PrintTupleOneLine
////////////////////////////////////////////////////////////////////////////////

template <typename T, int Idx, int TopIdx>
void __PrintTupleOneLine<T, Idx, TopIdx>::__Print(const T &val)
{
    cout << get<Idx>(val);

    if (Idx + 1 < TopIdx)
    {
        cout << __VALUE_SPLICE;
    }

    __PrintTupleOneLine<T, Idx + 1, TopIdx>::__Print(val);
}


template <typename T, int TopIdx>
void __PrintTupleOneLine<T, TopIdx, TopIdx>::__Print(const T &val) {}


////////////////////////////////////////////////////////////////////////////////
// Class __PrintTupleMultiLine
////////////////////////////////////////////////////////////////////////////////

template <typename T, int N, int Idx, int TopIdx>
void __PrintTupleMultiLine<T, N, Idx, TopIdx>::__Print(const T &val)
{
    __PrintData<

        typename __CategoryTraits<typename tuple_element<Idx, T>::type>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<typename tuple_element<Idx, T>::type>::__Category,
            typename tuple_element<Idx, T>::type
        >::__Category,

        typename tuple_element<Idx, T>::type,

        N + 1

    >::__Print(get<Idx>(val));

    cout << __LINE_END << endl;

    __PrintTupleMultiLine<T, N, Idx + 1, TopIdx>::__Print(val);
}


template <typename T, int N, int TopIdx>
void __PrintTupleMultiLine<T, N, TopIdx, TopIdx>::__Print(const T &val) {}


}  // End namespace pprint


#endif  // __PPRINT_PRINT_TUPLE_HPP
