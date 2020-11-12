/*
    pprint.hpp
    ==========
        print function implementation.
*/

#ifndef __PPRINT_PPRINT_HPP
#define __PPRINT_PPRINT_HPP

#include <iostream>
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


}  // End namespace pprint


#endif  // __PPRINT_PPRINT_HPP
