/** @file
    @brief Header

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_HandlerContainer_h_GUID_EAD5E6BA_FEDA_428B_0F12_B30FBE4AD6DB
#define INCLUDED_HandlerContainer_h_GUID_EAD5E6BA_FEDA_428B_0F12_B30FBE4AD6DB


// Internal Includes
#include "RemoteHandler.h"

// Library/third-party includes
// - none

// Standard includes
#include <vector>

namespace osvr {
    namespace client {
        /// @brief Wrapper for a container of handlers.
        class HandlerContainer {
        public:
            void update() {
                for (auto const& handler : m_handlers) {
                    handler->update();
                }
            }

            void add(RemoteHandlerPtr const& handler) {
                if (!handler) {
                    // Early out for null pointers.
                    return;
                }
                auto it = std::find(begin(m_handlers), end(m_handlers), handler);
                if (end(m_handlers) == it) {
                    // OK, not already in there. Add it.
                    m_handlers.push_back(handler);
                }
            }

            void remove(RemoteHandlerPtr const& handler) {
                if (!handler) {
                    // Early out for null pointers.
                    return;
                }
                auto it = std::find(begin(m_handlers), end(m_handlers), handler);
                if (end(m_handlers) != it) {
                    // Found it - erase it.
                    m_handlers.erase(it);
                }
            }

            private:
            std::vector<RemoteHandlerPtr> m_handlers;
        };
    } // namespace client
} // namespace osvr

#endif // INCLUDED_HandlerContainer_h_GUID_EAD5E6BA_FEDA_428B_0F12_B30FBE4AD6DB

