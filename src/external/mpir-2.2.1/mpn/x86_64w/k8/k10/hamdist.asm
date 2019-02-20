
;  Version 1.0.4
;
;  Copyright 2008 Jason Moxham
;
;  Windows Conversion Copyright 2008 Brian Gladman
;
;  This file is part of the MPIR Library.
;  The MPIR Library is free software; you can redistribute it and/or modify
;  it under the terms of the GNU Lesser General Public License as published
;  by the Free Software Foundation; either version 2.1 of the License, or (at
;  your option) any later version.
;  The MPIR Library is distributed in the hope that it will be useful, but
;  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
;  License for more details.
;  You should have received a copy of the GNU Lesser General Public License
;  along with the MPIR Library; see the file COPYING.LIB.  If not, write
;  to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
;  Boston, MA 02110-1301, USA.

;	mp_limb_t mpn_hamdist(mp_ptr, mp_ptr, mp_size_t)
;	rax                      rdi,    rsi,       rdx
;	rax                      rcx,    rdx,        r8

%include "yasm_mac.inc"

    CPU  SSE4.2
    BITS 64

    FRAME_PROC mpn_hamdist, 0, rbx
    mov     rbx, r8
    xor     eax, eax
    sub     rbx, 4
    jc      .2

    xalign  16
.1: mov     r8, [rcx+rbx*8+24]
    mov     r9, [rcx+rbx*8+16]
    xor     r8, [rdx+rbx*8+24]
    popcnt  r8, r8
    add     rax, r8
    xor     r9, [rdx+rbx*8+16]
    popcnt  r9, r9
    add     rax, r9
    mov     r10, [rcx+rbx*8+8]
    mov     r11, [rcx+rbx*8]
    xor     r10, [rdx+rbx*8+8]
    popcnt  r10, r10
    add     rax, r10
    xor     r11, [rdx+rbx*8]
    popcnt  r11, r11
    add     rax, r11
    sub     rbx, 4
    jnc     .1
.2: add     rbx, 4
    jz      .3
    mov     r8, [rcx+rbx*8-8]
    xor     r8, [rdx+rbx*8-8]
    popcnt  r8, r8
    add     rax, r8
    dec     rbx
    jz      .3
    mov     r9, [rcx+rbx*8-8]
    xor     r9, [rdx+rbx*8-8]
    popcnt  r9, r9
    add     rax, r9
    dec     rbx
    jz      .3
    mov     r10, [rcx+rbx*8-8]
    xor     r10, [rdx+rbx*8-8]
    popcnt  r10, r10
    add     rax, r10
.3: END_PROC rbx

    end
