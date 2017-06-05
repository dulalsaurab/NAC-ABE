/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2017, Regents of the University of California.
 *
 * This file is part of ndnabac, a certificate management system based on NDN.
 *
 * ndnabac is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * ndnabac is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received copies of the GNU General Public License along with
 * ndnabac, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndnabac authors and contributors.
 */

#include "private-key.hpp"

namespace ndn {
namespace ndnabac {
namespace algo {

Buffer
PrivateKey::toBuffer()
{
  // From Glib:
  // struct GByteArray {
  //   guint8 *data;
  //   guint len;
  // }
  return Buffer(m_prv->data, m_prv->len);
}

void
PrivateKey::fromBuffer(const Buffer& buffer)
{
  Buffer tempBuf(buffer.buf(), buffer.size());
  m_prv = g_byte_array_new();
  g_byte_array_append(m_prv, tempBuf.buf(), static_cast<guint>(tempBuf.size()));
}

} // namespace algo
} // namespace ndnabac
} // namespace ndn
