/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_COMMON_BUFFER_HPP
#define QPL_SOURCES_MIDDLE_LAYER_COMMON_BUFFER_HPP

#include <cstdint>
#include <iterator>

#include "util/util.hpp"

namespace qpl::ml {

class buffer_t {
public:
    template <class iterator_t>
    buffer_t(iterator_t buffer_begin, iterator_t buffer_end) : begin_(&*buffer_begin), end_(&*buffer_end) {
        // Check if we've got valid iterators
        static_assert(util::is_random_access_iterator_v<iterator_t>(), "Passed inappropriate iterator");
    }

    [[nodiscard]] auto size() const noexcept -> uint32_t;

    [[nodiscard]] virtual auto data() const noexcept -> uint8_t*;

    [[nodiscard]] auto begin() const noexcept -> uint8_t*;

    [[nodiscard]] auto end() const noexcept -> uint8_t*;

    buffer_t(const buffer_t& other) {
        this->begin_ = other.begin_;
        this->end_   = other.end_;
    }
    buffer_t(buffer_t&& other)                         = delete;
    auto operator=(const buffer_t& other) -> buffer_t& = delete;
    auto operator=(buffer_t&& other) -> buffer_t&      = delete;

    virtual ~buffer_t() {
        begin_ = nullptr;
        end_   = nullptr;
    }

protected:
    buffer_t() noexcept = default;

private:
    uint8_t* begin_ = nullptr;
    uint8_t* end_   = nullptr;
};

} // namespace qpl::ml

#endif //QPL_SOURCES_MIDDLE_LAYER_COMMON_BUFFER_HPP
