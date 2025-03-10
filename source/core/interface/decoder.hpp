// Copyright (c) 2019 - 2021, Osamu Watanabe
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
//    modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once
#include <cstdint>
#include <memory>
#include <vector>

namespace open_htj2k {
class openhtj2k_decoder {
 private:
  std::unique_ptr<class openhtj2k_decoder_impl> impl;

 public:
#if defined(_MSC_VER) && !defined(OHTJ2K_STATIC)
  __declspec(dllexport) openhtj2k_decoder();
  __declspec(dllexport) openhtj2k_decoder(const char *, const uint8_t reduce_NL, uint32_t num_threads);
  __declspec(dllexport)
      openhtj2k_decoder(const uint8_t *, size_t, const uint8_t reduce_NL, uint32_t num_threads);
  __declspec(dllexport) void init(const uint8_t *, size_t, uint8_t reduce_NL, uint32_t num_threads);
  __declspec(dllexport) void parse();
  __declspec(dllexport) uint16_t get_num_component();
  __declspec(dllexport) uint32_t get_component_width(uint16_t);
  __declspec(dllexport) uint32_t get_component_height(uint16_t);
  __declspec(dllexport) uint8_t get_component_depth(uint16_t);
  __declspec(dllexport) bool get_component_signedness(uint16_t);
  __declspec(dllexport) void invoke(std::vector<int32_t *> &, std::vector<uint32_t> &,
                                    std::vector<uint32_t> &, std::vector<uint8_t> &, std::vector<bool> &);
  __declspec(dllexport) ~openhtj2k_decoder();
#else
  openhtj2k_decoder();
  openhtj2k_decoder(const char *, uint8_t reduce_NL, uint32_t num_threads);
  openhtj2k_decoder(const uint8_t *, size_t, uint8_t reduce_NL, uint32_t num_threads);
  void init(const uint8_t *, size_t, uint8_t reduce_NL, uint32_t num_threads);
  void parse();
  uint16_t get_num_component();
  uint32_t get_component_width(uint16_t);
  uint32_t get_component_height(uint16_t);
  uint8_t get_component_depth(uint16_t);
  bool get_component_signedness(uint16_t);
  void invoke(std::vector<int32_t *> &, std::vector<uint32_t> &, std::vector<uint32_t> &,
              std::vector<uint8_t> &, std::vector<bool> &);
  ~openhtj2k_decoder();
#endif
};
}  // namespace open_htj2k
