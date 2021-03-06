// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config.hpp>
#include <ecst/mp/list.hpp>
#include <ecst/tag/component.hpp>
#include "./is_signature_list.hpp"

ECST_SIGNATURE_LIST_COMPONENT_NAMESPACE
{
    namespace impl
    {
        template <typename TComponentSignatureList, typename TComponentTag>
        constexpr auto signature_by_tag_impl(
            TComponentSignatureList csl, TComponentTag ct)
        {
            ECST_S_ASSERT_DT(valid(csl));
            ECST_S_ASSERT_DT(tag::component::valid(ct));

            return *bh::find_if(csl, [ct](auto cs)
                {
                    return mp::unwrapped(cs).has(ct);
                });
        }
    }

    template <typename TComponentSignatureList, typename TComponentTag>
    constexpr auto signature_by_tag(
        TComponentSignatureList csl, TComponentTag ct)
    {
        return decltype(impl::signature_by_tag_impl(csl, ct)){};
    }
}
ECST_SIGNATURE_LIST_COMPONENT_NAMESPACE_END
