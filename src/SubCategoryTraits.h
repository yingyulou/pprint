/*
    SubCategoryTraits.h
    ===================
        Sub category traits header.
*/

#ifndef __PPRINT_SUB_CATEGORY_TRAITS_H
#define __PPRINT_SUB_CATEGORY_TRAITS_H

#include <type_traits>
#include <tuple>
#include "CategoryTag.h"
#include "CategoryTraits.h"
#include "CategoryPromotionTraits.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Using
////////////////////////////////////////////////////////////////////////////////

using std::remove_const;
using std::tuple;


////////////////////////////////////////////////////////////////////////////////
// Class __SubCategoryTraits
////////////////////////////////////////////////////////////////////////////////

template <typename Tag, typename T>
struct __SubCategoryTraits;


template <typename T>
struct __SubCategoryTraits<__CommonTag, T>
{
    typedef void __Category;
};


template <typename T>
struct __SubCategoryTraits<__SequenceContainerTag, T>
{
    typedef typename __CategoryTraits<typename T::value_type>::__Category __Category;
};


template <typename T>
struct __SubCategoryTraits<__MapContainerTag, T>
{
    typedef __MapPairTag __Category;
};


template <typename T>
struct __SubCategoryTraits<__SetContainerTag, T>
{
    typedef typename __CategoryTraits<typename T::value_type>::__Category __Category;
};


template <typename T>
struct __SubCategoryTraits<__MapPairTag, T>
{
    typedef typename __CategoryPromotionTraits<
        typename __CategoryTraits<typename remove_const<typename T::first_type>::type>::__Category,
        typename __CategoryTraits<typename T::second_type>::__Category
    >::__Category __Category;
};


template <typename T>
struct __SubCategoryTraits<__PairTag, T>
{
    typedef typename __CategoryPromotionTraits<
        typename __CategoryTraits<typename T::first_type>::__Category,
        typename __CategoryTraits<typename T::second_type>::__Category
    >::__Category __Category;
};


template <typename... Types>
struct __SubCategoryTraits<__TupleTag, tuple<Types...>>
{
    typedef typename __CategoryPromotionTraits<
        typename __CategoryTraits<Types>::__Category...
    >::__Category __Category;
};


template <typename T>
struct __SubCategoryTraits<__StackTag, T>
{
    typedef typename __CategoryTraits<typename T::value_type>::__Category __Category;
};


template <typename T>
struct __SubCategoryTraits<__QueueTag, T>
{
    typedef typename __CategoryTraits<typename T::value_type>::__Category __Category;
};


}  // End namespace pprint


#endif  // __PPRINT_SUB_CATEGORY_TRAITS_H
