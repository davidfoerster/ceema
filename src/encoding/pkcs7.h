/**
 * Copyright 2017 Harold Bruintjes
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <types/bytes.h>

namespace ceema {

    namespace pkcs7 {

        inline void add_padding(byte_vector &data) {
            std::uint8_t val = static_cast<std::uint8_t>(crypto::random::random() & 0xFFu);
            if (!val) {
                val++;
            }
            data.reserve(data.size() + val);
            data.insert(data.end(), val, val);
        }

        inline void strip_padding(byte_vector &data) {
            std::uint8_t val = data.back();
            data.resize(data.size() - val);
        }

    }
}
