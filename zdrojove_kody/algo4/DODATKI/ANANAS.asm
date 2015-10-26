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
	?debug	S "ANANAS.CPP"
	?debug	T "ANANAS.CPP"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
@kmp_ananas$qpc	segment virtual
@@kmp_ananas$qpc	proc	near
?live16385@0:
   ;	
   ;	int kmp_ananas(char *t)
   ;	
	push      ebp
	mov       ebp,esp
	mov       edx,dword ptr [ebp+8]
   ;	
   ;	{
   ;	int i=-1;
   ;	
?live16385@16: ; EDX = t
@1:
	or        eax,-1
   ;	
   ;	start: i++;
   ;	
?live16385@32: ; EAX = i, EDX = t
@2:
	inc       eax
   ;	
   ;	et0: if (t[i]!='a') goto start; i++;
   ;	
@3:
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,97
	jne       short @2
	inc       eax
   ;	
   ;	et1: if (t[i]!='n') goto et0; 	i++;
   ;	
@5:
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,110
	jne       short @3
	inc       eax
   ;	
   ;	et2: if (t[i]!='a') goto et0; 	i++;
   ;	
@7:
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,97
	jne       short @3
	inc       eax
   ;	
   ;	et3: if (t[i]!='n') goto et1; 	i++;
   ;	
@9:
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,110
	jne       short @5
	inc       eax
   ;	
   ;	     if (t[i]!='a') goto et2; 	i++;
   ;	
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,97
	jne       short @7
	inc       eax
   ;	
   ;	     if (t[i]!='s') goto et3; 	i++;
   ;	
	movsx     ecx,byte ptr [edx+eax]
	cmp       ecx,115
	jne       short @9
	inc       eax
   ;	
   ;	return i-6;
   ;	
?live16385@144: ; EAX = i
	add       eax,-6
   ;	
   ;	}
   ;	
?live16385@160: ; 
@14:
@13:
	pop       ebp
	ret 
@@kmp_ananas$qpc	endp
@kmp_ananas$qpc	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
_main	segment virtual
@_main	proc	near
?live16386@0:
   ;	
   ;	int main() 
   ;	
	push      ebp
	mov       ebp,esp
	push      ebx
   ;	
   ;	{
   ;	 char *t="w sklepie mo¿na by³o kupiæ ananasy i pomarañcze";
   ;	
@15:
	mov       ebx,offset s@
   ;	
   ;	 cout << "Wynik poszukiwañ="<<kmp_ananas(t)<<endl;
   ;	
?live16386@32: ; EBX = t
	push      offset @@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%
	push      ebx
	call      @@kmp_ananas$qpc
	pop       ecx
	push      eax
	push      offset s@+48
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
?live16386@48: ; 
@17:
@16:
	pop       ebx
	pop       ebp
	ret 
@_main	endp
_main	ends
_TEXT	ends
_TEXT	segment dword public use32 'CODE'
@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	segment virtual
@@std@%endl$c19std@%char_traits$c%%$qr42std@%basic_ostream$c19std@%char_traits$c%%$r42std@%basic_ostream$c19std@%char_traits$c%%	proc	near
?live16387@0:
	push      ebp
	mov       ebp,esp
	push      ebx
	mov       ebx,dword ptr [ebp+8]
?live16387@16: ; EBX = os
@18:
	push      10
	push      ebx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@put$qc
	add       esp,8
	push      ebx
	call      @@std@%basic_ostream$c19std@%char_traits$c%%@flush$qv
	pop       ecx
	mov       eax,ebx
?live16387@64: ; 
@20:
@19:
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
	db	"w sklepie mo",191
	;	s@+13:
	db	"na by",179
	;	s@+19:
	db	"o kupi",230
	;	s@+26:
	db	" ananasy i pomara",241
	;	s@+44:
	db	"cze",0
	;	s@+48:
	db	"Wynik poszukiwa",241
	;	s@+64:
	db	"=",0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
 extrn   @std@cout:byte
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
	?debug	D "ANANAS.CPP" 11982 3040
	end
