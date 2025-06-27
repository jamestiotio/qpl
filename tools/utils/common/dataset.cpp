/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/*
 *  Intel® Query Processing Library (Intel® QPL)
 *  Tools
 */

#include "dataset.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <system_error>

namespace qpl::tools {
dataset_t::dataset_t(const std::string& path) {
    // Check if the path is not empty
    if (path.empty()) { throw std::invalid_argument("Dataset path is empty"); }
    // Check if the path exists
    if (!std::filesystem::exists(path)) {
        throw std::filesystem::filesystem_error("Dataset path doesn't exist", path,
                                                std::make_error_code(std::errc::no_such_file_or_directory));
    }
    // Check if the path is a directory
    if (!std::filesystem::is_directory(path)) {
        throw std::filesystem::filesystem_error("Dataset path is not a directory", path,
                                                std::make_error_code(std::errc::not_a_directory));
    }
    auto real_path = canonical(absolute(std::filesystem::path(path.c_str())));
    path_          = real_path.string();

    for (const auto& entry : std::filesystem::directory_iterator(real_path)) {
        if (entry.is_symlink()) {
            std::cerr << "Skip this file because it is a symlink. Path=" << path_ << "/"
                      << entry.path().filename().string() << '\n';
        } else {
            std::ifstream file(entry.path(), std::ios::in | std::ios::binary);
            auto data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

            data_.insert(std::make_pair(entry.path().filename().string(), std::move(data)));
        }
    }
}

auto dataset_t::operator[](const std::string& file) const -> const std::vector<uint8_t>& {
    auto value = data_.find(file);

    if (value == data_.end()) { throw std::runtime_error("Couldn't open input file. Path=" + path_ + "/" + file); }

    return value->second;
}

auto dataset_t::get_data() const -> const dataset_data_t& {
    return this->data_;
}

std::ostream& operator<<(std::ostream& out, const dataset_t& dataset) {
    out << "Used dataset: " << dataset.path_ << '\n';

    for (auto& file : dataset.data_) {
        out << "--- " << file.first << '\n';
    }

    return out;
}

size_t dataset_t::size() const noexcept {
    return data_.size();
}
} // namespace qpl::tools
