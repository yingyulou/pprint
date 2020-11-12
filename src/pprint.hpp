/*
    pprint.hpp
    ==========
        print function implementation.
*/

#ifndef __PPRINT_PPRINT_HPP
#define __PPRINT_PPRINT_HPP

#include <iostream>
#include <initializer_list>
#include "CategoryTraits.h"
#include "SubCategoryTraits.h"
#include "PrintData.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::endl;
using std::initializer_list;


////////////////////////////////////////////////////////////////////////////////
// print
////////////////////////////////////////////////////////////////////////////////

void print() {}


template <typename T, typename... Types>
void print(const T &val, const Types &... Args)
{
    __PrintData<

        typename __CategoryTraits<T>::__Category,

        typename __SubCategoryTraits<
            typename __CategoryTraits<T>::__Category,
            T
        >::__Category,

        T,

        0

    >::__Print(val);

    cout << endl;

    print(Args...);
}


template <typename T, typename... Types>
void print(initializer_list<T> &&val, const Types &... Args)
{
    print(val, Args...);
}


}  // End namespace pprint


#endif  // __PPRINT_PPRINT_HPP
