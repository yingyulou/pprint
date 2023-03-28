/*
    CategoryTraits.h
    ================
        Category traits header.
*/

#pragma once

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
#include <initializer_list>
#include <cstddef>
#include "CategoryTag.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
using std::initializer_list;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class __CategoryTraits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


template <typename T, typename Alloc>
struct __CategoryTraits<deque<T, Alloc>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T, typename Alloc>
struct __CategoryTraits<forward_list<T, Alloc>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T, typename Alloc>
struct __CategoryTraits<list<T, Alloc>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename T, typename Alloc>
struct __CategoryTraits<vector<T, Alloc>>
{
    typedef __SequenceContainerTag __Category;
};


template <typename K, typename V, typename Compare, typename Alloc>
struct __CategoryTraits<map<K, V, Compare, Alloc>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V, typename Compare, typename Alloc>
struct __CategoryTraits<multimap<K, V, Compare, Alloc>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct __CategoryTraits<unordered_map<K, V, Hash, Pred, Alloc>>
{
    typedef __MapContainerTag __Category;
};


template <typename K, typename V, typename Hash, typename Pred, typename Alloc>
struct __CategoryTraits<unordered_multimap<K, V, Hash, Pred, Alloc>>
{
    typedef __MapContainerTag __Category;
};


template <typename T, typename Compare, typename Alloc>
struct __CategoryTraits<set<T, Compare, Alloc>>
{
    typedef __SetContainerTag __Category;
};


template <typename T, typename Compare, typename Alloc>
struct __CategoryTraits<multiset<T, Compare, Alloc>>
{
    typedef __SetContainerTag __Category;
};


template <typename T, typename Hash, typename Pred, typename Alloc>
struct __CategoryTraits<unordered_set<T, Hash, Pred, Alloc>>
{
    typedef __SetContainerTag __Category;
};


template <typename T, typename Hash, typename Pred, typename Alloc>
struct __CategoryTraits<unordered_multiset<T, Hash, Pred, Alloc>>
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


template <typename T, typename Container>
struct __CategoryTraits<stack<T, Container>>
{
    typedef __StackTag __Category;
};


template <typename T, typename Container>
struct __CategoryTraits<queue<T, Container>>
{
    typedef __QueueTag __Category;
};


template <typename T, typename Container, typename Compare>
struct __CategoryTraits<priority_queue<T, Container, Compare>>
{
    typedef __StackTag __Category;
};


template <typename T>
struct __CategoryTraits<initializer_list<T>>
{
    typedef __InitializerListTag __Category;
};


}  // End namespace pprint
