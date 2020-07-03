/*
    UpgradeCategoryTraits.h
    =======================
        Upgrade category traits header.
*/

#ifndef __PPRINT_UPGRADE_CATEGORY_TRAITS_H
#define __PPRINT_UPGRADE_CATEGORY_TRAITS_H

#include "CategoryTag.h"

namespace pprint
{

////////////////////////////////////////////////////////////////////////////////
// Class __UpgradeCategoryTraits
////////////////////////////////////////////////////////////////////////////////

template <typename... Tags>
struct __UpgradeCategoryTraits;


template <typename Tag1, typename Tag2>
struct __UpgradeCategoryTraits<Tag1, Tag2>
{
    typedef Tag1 __Category;
};


template <typename Tag1>
struct __UpgradeCategoryTraits<Tag1, __CommonTag>
{
    typedef Tag1 __Category;
};


template <typename Tag1>
struct __UpgradeCategoryTraits<__CommonTag, Tag1>
{
    typedef Tag1 __Category;
};


template <>
struct __UpgradeCategoryTraits<__CommonTag, __CommonTag>
{
    typedef __CommonTag __Category;
};


template <typename Tag1, typename... Tags>
struct __UpgradeCategoryTraits<Tag1, Tags...>
{
    typedef typename __UpgradeCategoryTraits<
        Tag1,
        typename __UpgradeCategoryTraits<Tags...>::__Category
    >::__Category __Category;
};


}  // End namespace pprint


#endif  // __PPRINT_UPGRADE_CATEGORY_TRAITS_H
