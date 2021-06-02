/*
    Util.hpp
    ========
        Utility functions implementation.
*/

#pragma once

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
