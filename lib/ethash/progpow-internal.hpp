// ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
// Copyright 2018 Pawel Bylica.
// Licensed under the Apache License, Version 2.0. See the LICENSE file.

#pragma once

#include "kiss99.hpp"
#include <ethash/ethash.hpp>
#include <array>

namespace progpow
{
using namespace ethash;

static constexpr int period_length = 50;
static constexpr uint32_t num_regs = 32;
static constexpr size_t l1_cache_size = 16 * 1024;
static constexpr size_t l1_cache_num_items = l1_cache_size / sizeof(uint32_t);

/// A variant of Keccak hash function for ProgPoW.
///
/// This Keccak hash function uses 800-bit permutation (Keccak-f[800]) with 576 bitrate.
/// It take exactly 576 bits of input (split across 3 arguments) and adds no padding.
///
/// @param header_hash  The 256-bit header hash.
/// @param nonce        The 64-bit nonce.
/// @param mix_hash     Additional 256-bits of data.
/// @return             The 256-bit output of the hash function.
hash256 keccak_progpow_256(
    const hash256& header_hash, uint64_t nonce, const hash256& mix_hash) noexcept;

/// The same as keccak_progpow_256() but uses null mix
/// and returns top 64 bits of the output being a big-endian prefix of the 256-bit hash.
uint64_t keccak_progpow_64(const hash256& header_hash, uint64_t nonce) noexcept;


}  // namespace progpow
