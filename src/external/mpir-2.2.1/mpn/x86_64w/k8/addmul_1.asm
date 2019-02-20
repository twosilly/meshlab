
;  Copyright 2008 Jason Moxham
;
;  Windows Conversion Copyright 2008 Brian Gladman
;
;  This file is part of the MPIR Library.
;
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
;
;  mp_limb_t mpn_addmul_1(mp_ptr, mp_ptr, mp_size_t, mp_limb_t)
;  mp_limb_t mpn_inclsh_n(mp_ptr, mp_ptr, mp_size_t,   mp_uint)
;  rax                       rdi     rsi        rdx        rcx
;  rax                       rcx     rdx         r8        r9d

%include "yasm_mac.inc"

    CPU  Athlon64
    BITS 64

%define reg_save_list rbx, rsi, rdi

    xalign 16
	LEAF_PROC mpn_inclsh_n
	mov     r10, rcx
	mov     ecx, r9d
	mov     r9, 1
	shl     r9, cl
    mov     rcx, r10

    xalign 16
    LEAF_PROC mpn_addmul_1
    mov     rax, [rdx]
    cmp     r8, 1
    jnz     .1
    mul     r9
    add     [rcx], rax
    adc     rdx, 0
    mov     rax, rdx
    ret

    xalign   16
.1:	FRAME_PROC ?mpn_k8_addmul, 0, reg_save_list
	mov     r11, 5
	lea     rsi, [rdx+r8*8-40]
	lea     rdi, [rcx+r8*8-40]
	mov     rcx, r9
	sub     r11, r8
	mul     rcx
	db      0x26
	mov     r8, rax
	db      0x26
	mov     rax, [rsi+r11*8+8]
	db      0x26
	mov     r9, rdx
	db      0x26
	cmp     r11, 0
	db      0x26
	jge     .3
	
	xalign   16
.2:	mov     r10, 0
	mul     rcx
	add     [rdi+r11*8], r8
	adc     r9, rax
	db      0x26
	adc     r10, rdx
	mov     rax, [rsi+r11*8+16]
	mul     rcx
	add     [rdi+r11*8+8], r9
	adc     r10, rax
	mov     ebx, 0
	adc     rbx, rdx
	mov     rax, [rsi+r11*8+24]
	mov     r8, 0
	mov     r9, 0
	mul     rcx
	add     [rdi+r11*8+16], r10
	db      0x26
	adc     rbx, rax
	db      0x26
	adc     r8, rdx
	mov     rax, [rsi+r11*8+32]
	mul     rcx
	add     [rdi+r11*8+24], rbx
	db      0x26
	adc     r8, rax
	db      0x26
	adc     r9, rdx
	add     r11, 4
	mov     rax, [rsi+r11*8+8]
	jnc     .2
	
	xalign   16
.3:	mov     r10d, 0
	mul     rcx
	add     [rdi+r11*8], r8
	adc     r9, rax
	adc     r10, rdx
	cmp     r11, 2
	jz      .6
	ja      .7
	jp      .5
.4:	mov     rax, [rsi+r11*8+16]
	mul     rcx
	add     [rdi+r11*8+8], r9
	adc     r10, rax
	mov     ebx, 0
	adc     rbx, rdx
	mov     rax, [rsi+r11*8+24]
	mov     r8d, 0
	mul     rcx
	add     [rdi+r11*8+16], r10
	adc     rbx, rax
	adc     r8, rdx
	mov     rax, [rsi+r11*8+32]
	mul     rcx
	add     [rdi+r11*8+24], rbx
	mov     rbx, [rsp-8]
	adc     r8, rax
	adc     rdx, 0
	add     [rdi+r11*8+32], r8
	adc     rdx, 0
	mov     rax, rdx
    EXIT_PROC reg_save_list
	
	xalign   16
.5:	mov     rax, [rsi+r11*8+16]
	mul     rcx
	add     [rdi+r11*8+8], r9
	adc     r10, rax
	mov     r8d, 0
	adc     r8, rdx
	mov     rax, [rsi+r11*8+24]
	mul     rcx
	add     [rdi+r11*8+16], r10
	adc     r8, rax
	adc     rdx, 0
	add     [rdi+r11*8+24], r8
	adc     rdx, 0
	mov     rax, rdx
    EXIT_PROC reg_save_list
	
	xalign   16
.6:	mov     rax, [rsi+r11*8+16]
	mul     rcx
	add     [rdi+r11*8+8], r9
	adc     r10, rax
	mov     ebx, 0
	adc     rbx, rdx
	add     [rdi+r11*8+16], r10
	adc     rbx, 0
	mov     rax, rbx
    EXIT_PROC reg_save_list
	
	xalign   16
.7:	add     [rdi+r11*8+8], r9
	adc     r10, 0
	mov     rax, r10
.8:	END_PROC reg_save_list
    
    end
