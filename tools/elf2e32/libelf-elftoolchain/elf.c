/*-
 * Copyright (c) 2006,2008 Joseph Koshy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <libelf.h>

#include "_libelf.h"

LIBELF_VCSID("$Id$");

/*
 * libelf_byteorder is initialized dynamically
 * in elf_version, libelf_arch and libelf_class
 * aren't used at all in practice.
 */
struct _libelf_globals _libelf = {
/*
	.libelf_arch		= LIBELF_ARCH,
	.libelf_byteorder	= LIBELF_BYTEORDER,
	.libelf_class		= LIBELF_CLASS,
*/
	.libelf_error		= 0,
	.libelf_fillchar	= 0,
	.libelf_version		= EV_NONE
};


#if defined(LIBELF_TEST_HOOKS)
int
_libelf_get_elf_class(Elf *elf)
{
	return elf->e_class;
}

void
_libelf_set_elf_class(Elf *elf, int c)
{
	elf->e_class = c;
}
#endif	/* LIBELF_TEST_HOOKS */