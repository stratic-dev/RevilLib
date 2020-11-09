/*  Revil Format Library
    Copyright(C) 2017-2020 Lukas Cone

    This program is free software : you can redistribute it and / or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

#include "asset.hpp"
#include "datas/binreader.hpp"
#include "datas/except.hpp"
#include "datas/master_printer.hpp"
#include <map>

REAsset::Ptr REAsset::Load(const std::string &fileName) {
  BinReader rd(fileName);

  if (!rd.IsValid()) {
    throw es::FileNotFoundError(fileName);
  }

  return Load(rd);
}

REAsset::Ptr REAsset::Load(BinReaderRef rd) {
  rd.Push();
  REAssetBase base;
  rd.Read(base);
  rd.Pop();

  auto ass = REAsset_internal::Create(base);

  ass->Load(rd);
  return std::move(ass);
}

void REAsset_internal::Load(BinReaderRef rd) {
  const size_t fleSize = rd.GetSize();
  rd.ReadContainer(buffer, fleSize);
  Fixup();
  ClearESPointers();
}

void REAsset_internal::Assign(REAssetBase *data) {
  char *rawData = reinterpret_cast<char *>(data);
  es::allocator_hybrid_base::LinkStorage(buffer, rawData, 1);
  Build();
}
