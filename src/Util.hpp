/*
    Util.hpp
    ========
        Utility functions implementation.
*/

#ifndef __PPRINT_UTIL_HPP
#define __PPRINT_UTIL_HPP

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Reverse Stack
////////////////////////////////////////////////////////////////////////////////

template <typename T>
T __reverseStack(T oriStack)
{
    T reverseStack;

    while (!oriStack.empty())
    {
        reverseStack.push(oriStack.top());
        oriStack.pop();
    }

    return reverseStack;
}


}  // End namespace pprint


#endif  // __PPRINT_UTIL_HPP
