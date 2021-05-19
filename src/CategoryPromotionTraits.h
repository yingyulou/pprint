/*
    CategoryPromotionTraits.h
    =========================
        Upgrade category traits header.
*/

#ifndef __PPRINT_CATEGORY_PROMOTION_TRAITS_H
#define __PPRINT_CATEGORY_PROMOTION_TRAITS_H

#include "CategoryTag.hpp"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Class __CategoryPromotionTraits
////////////////////////////////////////////////////////////////////////////////

template <typename... Tags>
struct __CategoryPromotionTraits;


template <typename Tag1, typename Tag2>
struct __CategoryPromotionTraits<Tag1, Tag2>
{
    typedef Tag1 __Category;
};


template <typename Tag1>
struct __CategoryPromotionTraits<Tag1, __CommonTag>
{
    typedef Tag1 __Category;
};


template <typename Tag2>
struct __CategoryPromotionTraits<__CommonTag, Tag2>
{
    typedef Tag2 __Category;
};


template <>
struct __CategoryPromotionTraits<__CommonTag, __CommonTag>
{
    typedef __CommonTag __Category;
};


template <typename Tag1, typename... Tags>
struct __CategoryPromotionTraits<Tag1, Tags...>
{
    typedef typename __CategoryPromotionTraits<
        Tag1,
        typename __CategoryPromotionTraits<Tags...>::__Category
    >::__Category __Category;
};


}  // End namespace pprint


#endif  // __PPRINT_CATEGORY_PROMOTION_TRAITS_H
