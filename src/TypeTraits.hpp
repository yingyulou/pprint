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
    typedef __CommonTag __type;
};


template <typename T, typename Allocator>
struct __CategoryTraits<vector<T, Allocator>>
{
    typedef __SequenceTag __type;
};


template <typename T, typename Allocator>
struct __CategoryTraits<deque<T, Allocator>>
{
    typedef __SequenceTag __type;
};


template <typename T, typename Allocator>
struct __CategoryTraits<list<T, Allocator>>
{
    typedef __SequenceTag __type;
};


template <typename T, typename Allocator>
struct __CategoryTraits<forward_list<T, Allocator>>
{
    typedef __SequenceTag __type;
};


template <typename Key, typename T, typename Compare, typename Allocator>
struct __CategoryTraits<map<Key, T, Compare, Allocator>>
{
    typedef __MapTag __type;
};


template <typename Key, typename T, typename Compare, typename Allocator>
struct __CategoryTraits<multimap<Key, T, Compare, Allocator>>
{
    typedef __MapTag __type;
};


template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_map<Key, T, Hash, KeyEqual, Allocator>>
{
    typedef __MapTag __type;
};


template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_multimap<Key, T, Hash, KeyEqual, Allocator>>
{
    typedef __MapTag __type;
};


template <typename Key, typename Compare, typename Allocator>
struct __CategoryTraits<set<Key, Compare, Allocator>>
{
    typedef __SetTag __type;
};


template <typename Key, typename Compare, typename Allocator>
struct __CategoryTraits<multiset<Key, Compare, Allocator>>
{
    typedef __SetTag __type;
};


template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_set<Key, Hash, KeyEqual, Allocator>>
{
    typedef __SetTag __type;
};


template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
struct __CategoryTraits<unordered_multiset<Key, Hash, KeyEqual, Allocator>>
{
    typedef __SetTag __type;
};


template <typename ...Ts>
struct __CategoryTraits<tuple<Ts...>>
{
    typedef __TupleTag __type;
};


template <typename T1, typename T2>
struct __CategoryTraits<pair<T1, T2>>
{
    typedef __TupleTag __type;
};


template <typename T, size_t N>
struct __CategoryTraits<array<T, N>>
{
    typedef __TupleTag __type;
};


template <typename T, typename Container>
struct __CategoryTraits<stack<T, Container>>
{
    typedef __StackTag __type;
};


template <typename T, typename Container>
struct __CategoryTraits<queue<T, Container>>
{
    typedef __QueueTag __type;
};


template <typename T, typename Container, typename Compare>
struct __CategoryTraits<priority_queue<T, Container, Compare>>
{
    typedef __PriorityQueueTag __type;
};


template <typename T>
using __Category = typename __CategoryTraits<T>::__type;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Category Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename...>
struct __MergeCategoryTraits;


template <>
struct __MergeCategoryTraits<>
{
    typedef __CommonTag __type;
};


template <typename T>
struct __MergeCategoryTraits<T>
{
    typedef T __type;
};


template <>
struct __MergeCategoryTraits<__CommonTag, __CommonTag>
{
    typedef __CommonTag __type;
};


template <typename T>
struct __MergeCategoryTraits<T, __CommonTag>
{
    typedef T __type;
};


template <typename T>
struct __MergeCategoryTraits<__CommonTag, T>
{
    typedef T __type;
};


template <typename T, typename U>
struct __MergeCategoryTraits<T, U>
{
    typedef T __type;
};


template <typename T, typename... Ts>
struct __MergeCategoryTraits<T, Ts...>
{
    typedef typename __MergeCategoryTraits<T, typename __MergeCategoryTraits<Ts...>::__type>::__type __type;
};


template <typename... Ts>
using __MergeCategory = typename __MergeCategoryTraits<Ts...>::__type;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sub Category Traits
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename>
struct __SubCategoryTraits
{
    typedef __Category<typename T::value_type> __type;
};


template <typename T>
struct __SubCategoryTraits<T, __CommonTag>
{
    typedef __CommonTag __type;
};


template <typename T>
struct __SubCategoryTraits<T, __TupleTag>
{
    template <typename>
    struct __TupleSubCategoryTraits;


    template <size_t... Is>
    struct __TupleSubCategoryTraits<index_sequence<Is...>>
    {
        typedef __MergeCategory<__Category<tuple_element_t<Is, T>>...> __type;
    };


    typedef typename __TupleSubCategoryTraits<make_index_sequence<tuple_size_v<T>>>::__type __type;
};


template <typename T>
using __SubCategory = typename __SubCategoryTraits<T, __Category<T>>::__type;


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
