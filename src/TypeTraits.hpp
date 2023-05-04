/*
    TypeTraits.hpp
    ==============
        Type traits implementation.
*/

#pragma once

#include <string>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <utility>
#include <stack>
#include <queue>
#include <iostream>
#include <type_traits>
#include <cstddef>

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::string;
using std::array;
using std::vector;
using std::list;
using std::forward_list;
using std::deque;
using std::map;
using std::multimap;
using std::set;
using std::multiset;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::unordered_multiset;
using std::tuple;
using std::tuple_element_t;
using std::tuple_size_v;
using std::pair;
using std::index_sequence;
using std::make_index_sequence;
using std::declval;
using std::stack;
using std::queue;
using std::priority_queue;
using std::cout;
using std::true_type;
using std::false_type;
using std::is_same_v;
using std::conditional_t;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tag
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct __CommonTag        {};
struct __SequenceTag      {};
struct __MapTag           {};
struct __SetTag           {};
struct __TupleTag         {};
struct __StackTag         {};
struct __QueueTag         {};
struct __PriorityQueueTag {};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Category Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct __CategoryTraits
{
    using __type = __CommonTag;
};


template <typename T, typename Allocator>
struct __CategoryTraits<vector<T, Allocator>>
{
    using __type = __SequenceTag;
};


template <typename T, typename Allocator>
struct __CategoryTraits<deque<T, Allocator>>
{
    using __type = __SequenceTag;
};


template <typename T, typename Allocator>
struct __CategoryTraits<list<T, Allocator>>
{
    using __type = __SequenceTag;
};


template <typename T, typename Allocator>
struct __CategoryTraits<forward_list<T, Allocator>>
{
    using __type = __SequenceTag;
};


template <typename Key, typename T, typename Compare, typename Allocator>
struct __CategoryTraits<map<Key, T, Compare, Allocator>>
{
    using __type = __MapTag;
};


template <typename Key, typename T, typename Compare, typename Allocator>
struct __CategoryTraits<multimap<Key, T, Compare, Allocator>>
{
    using __type = __MapTag;
};


template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_map<Key, T, Hash, KeyEqual, Allocator>>
{
    using __type = __MapTag;
};


template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_multimap<Key, T, Hash, KeyEqual, Allocator>>
{
    using __type = __MapTag;
};


template <typename Key, typename Compare, typename Allocator>
struct __CategoryTraits<set<Key, Compare, Allocator>>
{
    using __type = __SetTag;
};


template <typename Key, typename Compare, typename Allocator>
struct __CategoryTraits<multiset<Key, Compare, Allocator>>
{
    using __type = __SetTag;
};


template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_set<Key, Hash, KeyEqual, Allocator>>
{
    using __type = __SetTag;
};


template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_multiset<Key, Hash, KeyEqual, Allocator>>
{
    using __type = __SetTag;
};


template <typename ...Ts>
struct __CategoryTraits<tuple<Ts...>>
{
    using __type = __TupleTag;
};


template <typename T1, typename T2>
struct __CategoryTraits<pair<T1, T2>>
{
    using __type = __TupleTag;
};


template <typename T, size_t N>
struct __CategoryTraits<array<T, N>>
{
    using __type = __TupleTag;
};


template <typename T, typename Container>
struct __CategoryTraits<stack<T, Container>>
{
    using __type = __StackTag;
};


template <typename T, typename Container>
struct __CategoryTraits<queue<T, Container>>
{
    using __type = __QueueTag;
};


template <typename T, typename Container, typename Compare>
struct __CategoryTraits<priority_queue<T, Container, Compare>>
{
    using __type = __PriorityQueueTag;
};


template <typename T>
using __Category = typename __CategoryTraits<T>::__type;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Is Sub Common Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct __isSubCommonTraits
{
    template <size_t... Is>
    static constexpr bool __isSubCommonTupleHelper(index_sequence<Is...>)
    {
        return (is_same_v<__Category<tuple_element_t<Is, T>>, __CommonTag> && ...);
    }


    static constexpr bool __isSubCommon()
    {
        if constexpr (is_same_v<__Category<T>, __CommonTag>)
        {
            return true;
        }
        else if constexpr (is_same_v<__Category<T>, __TupleTag>)
        {
            return __isSubCommonTupleHelper(make_index_sequence<tuple_size_v<T>>());
        }
        else
        {
            return is_same_v<__Category<typename T::value_type>, __CommonTag>;
        }
    }


    static constexpr bool __value = __isSubCommon();
};


template <typename T>
constexpr bool __isSubCommon = __isSubCommonTraits<T>::__value;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Is Printable Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, decltype(cout << declval<T>(), void()) * = nullptr>
true_type __isPrintableTraits(int);


template <typename T>
false_type __isPrintableTraits(...);


template <typename T>
constexpr bool __isPrintable = decltype(__isPrintableTraits<T>(0))();


}  // End namespace pprint
