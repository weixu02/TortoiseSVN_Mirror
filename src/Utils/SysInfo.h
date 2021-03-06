// TortoiseSVN - a Windows shell extension for easy version control

// Copyright (C) 2008-2010, 2014-2015 - TortoiseSVN

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#pragma once
#include <VersionHelpers.h>


/**
 * \ingroup Utils
 * This singleton class handles system information
 */
class SysInfo
{
private:
    SysInfo(void);
    ~SysInfo(void);
public:
    static const SysInfo& Instance();

    bool            IsWin7OrLater() const { return IsWindows7OrGreater(); }
#ifndef _WIN32_WINNT_WIN10
#define _WIN32_WINNT_WIN10 0x0A00
#endif
    bool            IsWin10OrLater() const { return IsWindowsVersionOrGreater(HIBYTE(_WIN32_WINNT_WIN10), LOBYTE(_WIN32_WINNT_WIN10), 0); }
};
