/***************************************************************************
 *   Copyright (C) 2010~2010 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

/**
 * @addtogroup FcitxConfig
 */

/**
 * @file xdg.h
 * XDG Related path handle
 * @author CSSlayer
 * @version 4.0.0
 * @date 2010-05-02
 */

#ifndef _FCITX_XDG_H_
#define _FCITX_XDG_H_

#include <stdio.h>
#include <fcitx-utils/utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Get library file
     *
     * @param filename filename
     * @param mode file open mode
     * @param retFile return file name
     * @return FILE*
     **/
    FILE *FcitxXDGGetLibFile(const char *filename, const char *mode, char **retFile);
    
#ifdef FCITX_CONFIG_XDG_DEPRECATED
    /**
     * get a xdg file pointer with given path, if mode contains "w", it will create necessary parent folder,
     *
     * @param fileName filename
     * @param path returns by FcitxXDGGetPath
     * @param mode file open mode
     * @param len length of path
     * @param retFile return file name
     * @return FILE*
     * 
     * @deprecated
     * 
     * @see FcitxXDGGetPath
     **/
    FILE *FcitxXDGGetFile(const char *fileName, char **path, const char *mode, size_t len, char **retFile);
    
    /**
     * get xdg path with given arguement, do not use this directly
     *
     * @param len return array size
     * @param homeEnv homeEnv
     * @param homeDefault homeDefault
     * @param suffixHome suffixHome
     * @param dirsDefault dirsDefault
     * @param suffixGlobal suffixGlobal
     * 
     * @deprecated
     * 
     * @return char**
     **/
    char **FcitxXDGGetPath(
        size_t *len,
        const char* homeEnv,
        const char* homeDefault,
        const char* suffixHome,
        const char* dirsDefault,
        const char* suffixGlobal);
#endif
    
    /**
     * get xdg path with prefix
     *
     * @param len return array size
     * @param prefix prefix
     * 
     * @return char**
     * 
     * @since 4.2.1
     **/
    char **FcitxXDGGetPathWithPrefix(
        size_t *len,
        const char* prefix);

    /**
     * get xdg file with prefix string, usually [install_prefix]/fcitx/prefix/filename and ~/.config/fcitx/prefix/filename
     *
     * @param prefix prefix
     * @param fileName filename
     * @param mode file open mode
     * @param retFile file name to return
     * @return FILE*
     *
     **/
    FILE *FcitxXDGGetFileWithPrefix(const char* prefix, const char *fileName, const char *mode, char**retFile);
    /**
     * get xdg file with prefix string, usually ~/.config/fcitx/prefix/filename
     *
     * @param prefix prefix
     * @param fileName filename
     * @param mode file open mode
     * @param retFile file name to return
     * @return FILE*
     *
     **/
    FILE *FcitxXDGGetFileUserWithPrefix(const char* prefix, const char *fileName, const char *mode, char **retFile);
    /**
     * free xdg path return by FcitxXDGGetPath
     *
     * @param path path array
     * @return void
     **/
    void FcitxXDGFreePath(char **path);

    /**
     * Get All files under directory with a suffix
     *
     * @param path xdg subpath
     * @param suffix filename suffix
     * @param prefix filename prefix
     * @return StringHashSet*
     *
     * @since 4.2.0
     **/
    FcitxStringHashSet* FcitxXDGGetFiles(
        char* path,
        char* suffix,
        char* prefix
    );

#ifdef __cplusplus
}

#endif

#endif

// kate: indent-mode cstyle; space-indent on; indent-width 0;
