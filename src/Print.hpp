/*
    Print.hpp
    =========
        Print function implementation.
*/

#pragma once

#include <iostream>
#include <type_traits>
#include "PrintTraits.h"
#include "TypeTraits.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::cout;
using std::is_same_v;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Print
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print() {}


template <typename T, typename... Ts>
void print(const T &val, const Ts &... vals)
{
    if constexpr (is_same_v<__MergeCategory<__Category<T>, __Category<Ts>...>, __CommonTag>)
    {
        __PrintTraits::__print<0>(val);

        (__PrintTraits::__print<0>(vals, " "), ...);

        cout << "\n";
    }
    else
    {
        __PrintTraits::__print<0>(val, "", "\n");

        (__PrintTraits::__print<0>(vals, "", "\n"), ...);
    }
}


}  // End namespace pprint
