/*
    CategoryTraits.h
    ================
        Category traits header.
*/

#ifndef __PPRINT_CATEGORY_TRAITS_H
#define __PPRINT_CATEGORY_TRAITS_H

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <cstddef>
#include "CategoryTag.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::array;
using std::deque;
using std::forward_list;
using std::list;
using std::map;
using std::multimap;
using std::set;
using std::multiset;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::unordered_multiset;
using std::vector;
using std::pair;
using std::tuple;
using std::stack;
using std::queue;
using std::priority_queue;


////////////////////////////////////////////////////////////////////////////////
// Class __CategoryTraits
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct __CategoryTraits
{
    typedef __CommonTag __Category;
};


template <typename T, size_t N>
struct __CategoryTraits<array<T, N>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<deque<T>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<forward_list<T>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<list<T>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<vector<T>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename K, typename V>
struct __CategoryTraits<map<K, V>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V>
struct __CategoryTraits<multimap<K, V>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V>
struct __CategoryTraits<unordered_map<K, V>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V>
struct __CategoryTraits<unordered_multimap<K, V>>
{
    typedef __MapContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<set<T>>
{
    typedef __SetContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<multiset<T>>
{
    typedef __SetContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<unordered_set<T>>
{
    typedef __SetContainerTag __Category;
};


template <typename T>
struct __CategoryTraits<unordered_multiset<T>>
{
    typedef __SetContainerTag __Category;
};


template <typename T1, typename T2>
struct __CategoryTraits<pair<T1, T2>>
{
    typedef __PairTag __Category;
};


template <typename... Types>
struct __CategoryTraits<tuple<Types...>>
{
    typedef __TupleTag __Category;
};


template <typename T>
struct __CategoryTraits<stack<T>>
{
    typedef __StackTag __Category;
};


template <typename T>
struct __CategoryTraits<queue<T>>
{
    typedef __QueueTag __Category;
};


template <typename T>
struct __CategoryTraits<priority_queue<T>>
{
    typedef __StackTag __Category;
};


}  // End namespace pprint


#endif  // __PPRINT_CATEGORY_TRAITS_H
