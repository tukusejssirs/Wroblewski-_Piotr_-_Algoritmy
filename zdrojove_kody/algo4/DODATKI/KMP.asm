	.386p
	ifdef ??version
	if    ??version GT 500H
	.mmx
	endif
	endif
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "KMP.CPP"
	?debug	T "KMP.CPP"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_BSS	segment dword public use32 'BSS'
	align	4
_shift	label	dword
	db	16	dup(?)
_BSS	ends
_TEXT	segment dword public use32 'CODE'
@init_shifts$qpc	segment virtual
@@init_shifts$qpc	proc	near
?live16385@0:
   ;	
   ;	int init_shifts(char *w)
   ;	
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
	mov       edx,dword ptr [ebp+8]
	mov       esi,offset _shift
   ;	
   ;	{
   ;	 int i,j;
   ;	 shift[0]=-1;
   ;	
?live16385@16: ; EDX = w, ESI = &_shift
@1:
	mov       dword ptr [esi],-1
   ;	
   ;	 for(i=0,j=-1;i<M-1;i++,j++,shift[i]=j)
   ;	
	xor       ecx,ecx
	or        eax,-1
	jmp       short @6
   ;	
   ;		while((j>=0)&&(w[i]!=w[j])) j=shift[j];
   ;	
?live16385@48: ; EAX = j, EDX = w, ECX = i, ESI = &_shift
@5:
	mov       eax,dword ptr [esi+4*eax]
@6:
	test      eax,eax
	jl        short @7
	mov       bl,byte ptr [edx+ecx]
	cmp       bl,byte ptr [edx+eax]
	jne       short @5
@7:
	inc       ecx
	inc       eax
	mov       dword ptr [esi+4*ecx],eax
	cmp       ecx,3
	jl        short @6
   ;	
   ;	}
   ;	
?live16385@64: ; 
@9:
	pop       esi
	pop       ebx
	pop       ebp
	ret 
@@init_shifts$qpc	endp
@init_shifts$qpc	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@kmp$qpct1	segment virtual
@@kmp$qpct1	proc	near
?live16386@0:
   ;	
   ;	int kmp(char *w,char *t)
   ;	
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
	push      esi
	mov       ebx,dword ptr [ebp+12]
	mov       esi,dword ptr [ebp+8]
   ;	
   ;	{
   ;	 int i,j,N=strlen(t);
   ;	
?live16386@16: ; EBX = t, ESI = w
@10:
	push      ebx
	call      @_strlen
	pop       ecx
	mov       dword ptr [ebp-4],eax
   ;	
   ;	 for(i=0,j=0;i<N && j<M;i++,j++)
   ;	
	xor       edx,edx
	xor       eax,eax
	jmp       short @12
	jmp       short @15
   ;	
   ;		while((j>=0)&&(t[i]!=w[j])) j=shift[j];
   ;	
?live16386@48: ; EAX = j, EDX = i, EBX = t, ESI = w
@14:
	mov       eax,dword ptr [_shift+4*eax]
@15:
	test      eax,eax
	jl        short @16
	mov       cl,byte ptr [ebx+edx]
	cmp       cl,byte ptr [esi+eax]
	jne       short @14
@16:
	inc       edx
	inc       eax
@12:
	cmp       edx,dword ptr [ebp-4]
	jge       short @18
	cmp       eax,4
	jl        short @15
   ;	
   ;	 if (j==M) return i-M; else return -1;
   ;	
?live16386@64: ; EAX = j, EDX = i
@18:
	cmp       eax,4
	jne       short @19
	lea       eax,dword ptr [edx-4]
	jmp       short @20
@19:
	or        eax,-1
   ;	
   ;	}
   ;	
?live16386@80: ; 
@22:
@20:
	pop       esi
	pop       ebx
	pop       ecx
	pop       ebp
	ret 
@@kmp$qpct1	endp
@kmp$qpct1	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
_main	segment virtual
@_main	proc	near
?live16387@0:
   ;	
   ;	int main()
   ;	
	push      ebp
	mov       ebp,esp
	push      ebx
	push      esi
   ;	
   ;	{
   ;	 char *w="1010";
   ;	
@23:
	mov       ebx,offset s@
   ;	
   ;	 init_shifts(w);
   ;	
?live16387@32: ; EBX = w
	push      ebx
	call      @@init_shifts$qpc
	pop       ecx
   ;	
   ;	 char *t="abcd1010def";
   ;	
	mov       esi,offset s@+5
   ;	
   ;	 cout << "Wynik poszukiwañ="<<kmp(w,t)<<endl;
   ;	
?live16387@64: ; EBX = w, ESI = t
	push      offset @@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	push      esi
	push      ebx
	call      @@kmp$qpct1
	add       esp,8
	push      eax
	push      offset s@+17
	push      offset @std@cout
	call      @@std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%
	add       esp,8
	push      eax
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qi
	add       esp,8
	push      eax
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	add       esp,8
	xor       eax,eax
   ;	
   ;	}
   ;	
?live16387@80: ; 
@25:
@24:
	pop       esi
	pop       ebx
	pop       ebp
	ret 
@_main	endp
_main	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	segment virtual
@@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	proc	near
?live16388@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16388@16: ; EBX = os
@26:
	push      10
	push      ebx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@put$qc
	add       esp,8
	push      ebx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@flush$qv
	pop       ecx
	mov       eax,ebx
?live16388@64: ; 
@28:
@27:
	pop       ebx
	pop       ebp
	ret 
@@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	endp
@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	ends
_TEXT	ends
_DATA	segment dword public use32 'DATA'
@std@locale@numeric	segment virtual
	align	2
@@std@locale@numeric	label	dword
	dd	128
@std@locale@numeric	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@locale@__rw_ctype_category	segment virtual
	align	2
@@std@locale@__rw_ctype_category	label	dword
	dd	32
@std@locale@__rw_ctype_category	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%ctype$c%@table_size	segment virtual
	align	2
@@std@%ctype$c%@table_size	label	dword
	dd	256
@std@%ctype$c%@table_size	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$i%@radix	segment virtual
	align	2
@@std@%numeric_limits$i%@radix	label	dword
	dd	2
@std@%numeric_limits$i%@radix	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$i%@is_modulo	segment virtual
@@std@%numeric_limits$i%@is_modulo	label	byte
	db	0
@std@%numeric_limits$i%@is_modulo	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$b%@is_signed	segment virtual
@@std@%numeric_limits$b%@is_signed	label	byte
	db	1
@std@%numeric_limits$b%@is_signed	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
@std@%numeric_limits$c%@is_signed	segment virtual
@@std@%numeric_limits$c%@is_signed	label	byte
	db	1
@std@%numeric_limits$c%@is_signed	ends
_DATA	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	;	s@+0:
	db	"1010",0
	;	s@+5:
	db	"abcd1010def",0
	;	s@+17:
	db	"Wynik poszukiwa",241
	;	s@+33:
	db	"=",0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
 extrn   @std@cout:byte
	public	_shift
@_strlen equ _strlen
 extrn   _strlen:near
@@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%% equ @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qpqr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%:near
@@std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qi equ @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qi
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@$blsh$qi:near
@@std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%% equ @std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%
 extrn   @std@$blsh$qr42std@%basic_ostream$c19std@%char_traits$c%%pxc$r42std@%basic_ostream$c19std@%char_traits$c%%:near
@@std@%basic_ostream$c19std@%char_traits$c%%@put$qc equ @std@%basic_ostream$c19std@%char_traits$c%%@put$qc
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@put$qc:near
@@std@%basic_ostream$c19std@%char_traits$c%%@flush$qv equ @std@%basic_ostream$c19std@%char_traits$c%%@flush$qv
 extrn   @std@%basic_ostream$c19std@%char_traits$c%%@flush$qv:near
	?debug	D "F:\Borland\bcc55\Include\streambu.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\ostream.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/usefacet.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/codecvt.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/numbrw.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/rwlocale.cc" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\float.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cfloat.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\math.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/math.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\limits.stl" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\limits.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/iosbase.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/numeral.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/ctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/vendor.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/locvecto.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/locimpl.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\typeinfo.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\time.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\ctime.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stdexcep.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\iosfwd.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/iotraits.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_nfile.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stdio.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cstdio.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/traits.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/stdmutex.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\utility.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/iterator.cc" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/iterator.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\alloc.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\except.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\exceptio.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\new.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_lim.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\climits.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\search.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stdlib.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cstdlib.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\memory.stl" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\memory.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/string_r.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\wctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cwctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\tchar.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\wchar.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cwchar.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\mbctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\ctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cctype.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cstring.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\string.stl" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\mem.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_loc.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\locale.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_str.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\string.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/rwlocale.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stdarg.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/stdwind.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_null.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_defs.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\_stddef.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stddef.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\cstddef.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/stddefs.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\rw/rwstderr.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\ios.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\istream.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\compnent.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\stdcomp.h" 10303 10240
	?debug	D "F:\Borland\bcc55\Include\iostream.h" 10303 10240
	?debug	D "KMP.CPP" 11982 3129
	end
