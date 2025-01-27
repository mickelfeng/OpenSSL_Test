/* Copyright (c) 2014 Alexander Lamaison <alexander.lamaison@gmail.com>
 * Copyright (c) 1999-2011 Douglas Gilbert. All rights reserved.
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided
 * that the following conditions are met:
 *
 *   Redistributions of source code must retain the above
 *   copyright notice, this list of conditions and the
 *   following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   Neither the name of the copyright holder nor the names
 *   of any other contributors may be used to endorse or
 *   promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

/* Headers */
/* #undef HAVE_UNISTD_H */
#define HAVE_INTTYPES_H
#define HAVE_STDLIB_H
/* #undef HAVE_SYS_SELECT_H */
/* #undef HAVE_SYS_UIO_H */
/* #undef HAVE_SYS_SOCKET_H */
/* #undef HAVE_SYS_IOCTL_H */
/* #undef HAVE_SYS_TIME_H */
/* #undef HAVE_SYS_UN_H */
#define HAVE_WINDOWS_H
#define HAVE_WS2TCPIP_H
#define HAVE_WINSOCK2_H
/* #undef HAVE_NTDEF_H */
#define HAVE_NTSTATUS_H

/* Libraries */
#define HAVE_LIBCRYPT32

/* Types */
#define HAVE_LONGLONG

/* Functions */
/* #undef HAVE_GETTIMEOFDAY */
#define HAVE_INET_ADDR
/* #undef HAVE_POLL */
#define HAVE_SELECT
#define HAVE_SOCKET
#define HAVE_STRTOLL
/* #undef HAVE_STRTOI64 */
/* #undef HAVE_SNPRINTF */

/* OpenSSL functions */
/* #undef HAVE_EVP_AES_128_CTR */

/* Socket non-blocking support */
/* #undef HAVE_O_NONBLOCK */
/* #undef HAVE_FIONBIO */
#define HAVE_IOCTLSOCKET
/* #undef HAVE_IOCTLSOCKET_CASE */
/* #undef HAVE_SO_NONBLOCK */
/* #undef HAVE_DISABLED_NONBLOCKING */

/* snprintf not in Visual Studio CRT and _snprintf dangerously incompatible.
   We provide a safe wrapper if snprintf not found */
#ifndef HAVE_SNPRINTF
#include <stdio.h>
#include <stdarg.h>
/* Want safe, 'n += snprintf(b + n ...)' like function. If cp_max_len is 1
* then assume cp is pointing to a null char and do nothing. Returns number
* number of chars placed in cp excluding the trailing null char. So for
* cp_max_len > 0 the return value is always < cp_max_len; for cp_max_len
* <= 0 the return value is 0 (and no chars are written to cp). */
//static int snprintf(char * cp, int cp_max_len, const char * fmt, ...)
//{
//    va_list args;
//    int n;
//
//    if (cp_max_len < 2)
//        return 0;
//    va_start(args, fmt);
//    n = vsnprintf(cp, cp_max_len, fmt, args);
//    va_end(args);
//    return (n < cp_max_len) ? n : (cp_max_len - 1);
//}

#define HAVE_SNPRINTF
#endif
