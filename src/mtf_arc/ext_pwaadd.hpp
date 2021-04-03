/*  Revil Format Library
    Copyright(C) 2020 Lukas Cone

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

#pragma once
#include "ext_base.hpp"

namespace MT_PWAADD {
static const MtExtensionsStorage extCommon{
    /**/ //
    {"ean", 0x4E397417},
    {"efl", 0x6D5AE854},
    {"fsm", 0x66B45610},
    {"gfd", 0x2D462600},
    {"gii", 0x07F768AF},
    {"gmd", 0x242BB29A},
    {"gui", 0x22948394},
    {"h2d", 0x694348E3},
    {"chr", 0x194BE415},
    {"lcm", 0x39C52040},
    {"lmt", 0x76820D81},
    {"lpm", 0x0C41C74D},
    {"mca", 0x79C47B59},
    {"mod", 0x58A15856},
    {"mrl", 0x2749C8A8},
    {"prp", 0x272B80EA},
    {"sbc", 0x51FC779F},
    {"sbkr", 0x15D782FB},
    {"sdl", 0x4C0DB839},
    {"srq", 0x1BCC4966}, // dupe
    {"srqr", 0x1BCC4966},
    {"stq", 0x167DBBFF}, // dupe
    {"stqr", 0x167DBBFF},
    {"tex", 0x241F5DEB},
};

static const MtExtFixupStorage fixups{
    {0x167DBBFF, "stqr"},
    {0x1BCC4966, "srqr"},
};

static const TitleSupport supp3DS{
    ArcSupport{0x10},
    ModSupport{0xE6},
    TexSupport{0xA5},
    LmtSupport{67},
};

static const TitleSupports supp{Platform::N3DS, supp3DS};
} // namespace MT_PWAADD

static const MtExtensions extPWAADD{MT_PWAADD::extCommon, MT_PWAADD::fixups,
                                    MT_PWAADD::supp, Platform::N3DS};
