/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* This file is used to define the properties of the filesystem
** images generated by build tools (mkbootfs and mkyaffs2image) and
** by the device side of adb.
*/

#ifndef _LIBS_CUTILS_PRIVATE_FS_CONFIG_H
#define _LIBS_CUTILS_PRIVATE_FS_CONFIG_H

#include <stdint.h>
#include <sys/cdefs.h>

#if defined(__BIONIC__)
#include <linux/capability.h>
#else  // defined(__BIONIC__)
#include "android_filesystem_capability.h"
#endif  // defined(__BIONIC__)

#define CAP_MASK_LONG(cap_name) (1ULL << (cap_name))

/*
 * binary format for the runtime <partition>/etc/fs_config_(dirs|files)
 * filesystem override files.
 */

/* The following structure is stored little endian */
struct fs_path_config_from_file {
    uint16_t len;
    uint16_t mode;
    uint16_t uid;
    uint16_t gid;
    uint64_t capabilities;
    char prefix[];
} __attribute__((__aligned__(sizeof(uint64_t))));

struct fs_path_config {
    unsigned mode;
    unsigned uid;
    unsigned gid;
    uint64_t capabilities;
    const char* prefix;
};

/* Rules for directories and files has moved to system/code/libcutils/fs_config.c */

__BEGIN_DECLS

/*
 * Used in:
 *  build/tools/fs_config/fs_config.c
 *  build/tools/fs_get_stats/fs_get_stats.c
 *  system/extras/ext4_utils/make_ext4fs_main.c
 *  external/squashfs-tools/squashfs-tools/android.c
 *  system/core/cpio/mkbootfs.c
 *  system/core/adb/file_sync_service.cpp
 *  system/extras/ext4_utils/canned_fs_config.c
 */
void fs_config(const char* path, int dir, const char* target_out_path, unsigned* uid, unsigned* gid,
               unsigned* mode, uint64_t* capabilities);

ssize_t fs_config_generate(char* buffer, size_t length, const struct fs_path_config* pc);

__END_DECLS

#endif /* _LIBS_CUTILS_PRIVATE_FS_CONFIG_H */
