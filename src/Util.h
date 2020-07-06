/*
    Util.h
    ======
        Utility functions define.
*/

#ifndef __PPRINT_UTIL_H
#define __PPRINT_UTIL_H

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


#endif  // __PPRINT_UTIL_H
