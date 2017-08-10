/* Message catalogs for internationalization.
   Copyright (C) 1995-1997, 2000-2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as published
   by the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
   USA.  */

#ifndef _LIBINTL_H
#define _LIBINTL_H	1

#ifdef BUILDING_LIBINTL
#define LIBINTL_DLL_EXPORTED __declspec(dllexport)
#else
#define LIBINTL_DLL_EXPORTED __declspec(dllimport)
#endif

#include <locale.h>

/* The LC_MESSAGES locale category is the category used by the functions
   gettext() and dgettext().  It is specified in POSIX, but not in ANSI C.
   On systems that don't define it, use an arbitrary value instead.
   On Solaris, <locale.h> defines __LOCALE_H (or _LOCALE_H in Solaris 2.5)
   then includes <libintl.h> (i.e. this file!) and then only defines
   LC_MESSAGES.  To avoid a redefinition warning, don't define LC_MESSAGES
   in this case.  */
#if !defined LC_MESSAGES && !(defined __LOCALE_H || (defined _LOCALE_H && defined __sun))
# define LC_MESSAGES 1729
#endif

/* We define an additional symbol to signal that we use the GNU
   implementation of gettext.  */
#define __USE_GNU_GETTEXT 1

/* Provide information about the supported file formats.  Returns the
   maximum minor revision number supported for a given major revision.  */
#define __GNU_GETTEXT_SUPPORTED_REVISION(major) \
  ((major) == 0 || (major) == 1 ? 1 : -1)

/* Resolve a platform specific conflict on DJGPP.  GNU gettext takes
   precedence over _conio_gettext.  */
#ifdef __DJGPP__
# undef gettext
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* We redirect the functions to those prefixed with "libintl_".  This is
   necessary, because some systems define gettext/textdomain/... in the C
   library (namely, Solaris 2.4 and newer, and GNU libc 2.0 and newer).
   If we used the unprefixed names, there would be cases where the
   definition in the C library would override the one in the libintl.so
   shared library.  Recall that on ELF systems, the symbols are looked
   up in the following order:
     1. in the executable,
     2. in the shared libraries specified on the link command line, in order,
     3. in the dependencies of the shared libraries specified on the link
        command line,
     4. in the dlopen()ed shared libraries, in the order in which they were
        dlopen()ed.
   The definition in the C library would override the one in libintl.so if
   either
     * -lc is given on the link command line and -lintl isn't, or
     * -lc is given on the link command line before -lintl, or
     * libintl.so is a dependency of a dlopen()ed shared library but not
       linked to the executable at link time.
   Since Solaris gettext() behaves differently than GNU gettext(), this
   would be unacceptable.

   The redirection happens by default through macros in C, so that &gettext
   is independent of the compilation unit, but through inline functions in
   C++, in order not to interfere with the name mangling of class fields or
   class methods called 'gettext'.  */

/* The user can define _INTL_REDIRECT_INLINE or _INTL_REDIRECT_MACROS.
   If he doesn't, we choose the method.  A third possible method is
   _INTL_REDIRECT_ASM, supported only by GCC.  */
#if !(defined _INTL_REDIRECT_INLINE || defined _INTL_REDIRECT_MACROS)
# if __GNUC__ >= 2 && !defined __APPLE_CC__ && !defined __MINGW32__ && !(__GNUC__ == 2 && defined _AIX) && (defined __STDC__ || defined __cplusplus)
#  define _INTL_REDIRECT_ASM
# else
#  ifdef __cplusplus
#   define _INTL_REDIRECT_INLINE
#  else
#   define _INTL_REDIRECT_MACROS
#  endif
# endif
#endif
/* Auxiliary macros.  */
#ifdef _INTL_REDIRECT_ASM
# define _INTL_ASM(cname) __asm__ (_INTL_ASMNAME (__USER_LABEL_PREFIX__, #cname))
# define _INTL_ASMNAME(prefix,cnamestring) _INTL_STRINGIFY (prefix) cnamestring
# define _INTL_STRINGIFY(prefix) #prefix
#else
# define _INTL_ASM(cname)
#endif

/* Look up MSGID in the current default message catalog for the current
   LC_MESSAGES locale.  If not found, returns MSGID itself (the default
   text).  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_gettext (const char *__msgid);
static inline char *gettext (const char *__msgid)
{
  return libintl_gettext (__msgid);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define gettext libintl_gettext
#endif
extern LIBINTL_DLL_EXPORTED char *gettext (const char *__msgid)
       _INTL_ASM (libintl_gettext);
#endif

/* Look up MSGID in the DOMAINNAME message catalog for the current
   LC_MESSAGES locale.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_dgettext (const char *__domainname, const char *__msgid);
static inline char *dgettext (const char *__domainname, const char *__msgid)
{
  return libintl_dgettext (__domainname, __msgid);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define dgettext libintl_dgettext
#endif
extern LIBINTL_DLL_EXPORTED char *dgettext (const char *__domainname, const char *__msgid)
       _INTL_ASM (libintl_dgettext);
#endif

/* Look up MSGID in the DOMAINNAME message catalog for the current CATEGORY
   locale.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_dcgettext (const char *__domainname, const char *__msgid,
				int __category);
static inline char *dcgettext (const char *__domainname, const char *__msgid,
			       int __category)
{
  return libintl_dcgettext (__domainname, __msgid, __category);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define dcgettext libintl_dcgettext
#endif
extern LIBINTL_DLL_EXPORTED char *dcgettext (const char *__domainname, const char *__msgid,
			int __category)
       _INTL_ASM (libintl_dcgettext);
#endif


/* Similar to `gettext' but select the plural form corresponding to the
   number N.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_ngettext (const char *__msgid1, const char *__msgid2,
			       unsigned long int __n);
static inline char *ngettext (const char *__msgid1, const char *__msgid2,
			      unsigned long int __n)
{
  return libintl_ngettext (__msgid1, __msgid2, __n);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define ngettext libintl_ngettext
#endif
extern LIBINTL_DLL_EXPORTED char *ngettext (const char *__msgid1, const char *__msgid2,
		       unsigned long int __n)
       _INTL_ASM (libintl_ngettext);
#endif

/* Similar to `dgettext' but select the plural form corresponding to the
   number N.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_dngettext (const char *__domainname, const char *__msgid1,
				const char *__msgid2, unsigned long int __n);
static inline char *dngettext (const char *__domainname, const char *__msgid1,
			       const char *__msgid2, unsigned long int __n)
{
  return libintl_dngettext (__domainname, __msgid1, __msgid2, __n);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define dngettext libintl_dngettext
#endif
extern LIBINTL_DLL_EXPORTED char *dngettext (const char *__domainname,
			const char *__msgid1, const char *__msgid2,
			unsigned long int __n)
       _INTL_ASM (libintl_dngettext);
#endif

/* Similar to `dcgettext' but select the plural form corresponding to the
   number N.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_dcngettext (const char *__domainname,
				 const char *__msgid1, const char *__msgid2,
				 unsigned long int __n, int __category);
static inline char *dcngettext (const char *__domainname,
				const char *__msgid1, const char *__msgid2,
				unsigned long int __n, int __category)
{
  return libintl_dcngettext (__domainname, __msgid1, __msgid2, __n, __category);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define dcngettext libintl_dcngettext
#endif
extern LIBINTL_DLL_EXPORTED char *dcngettext (const char *__domainname,
			 const char *__msgid1, const char *__msgid2,
			 unsigned long int __n, int __category)
       _INTL_ASM (libintl_dcngettext);
#endif


/* Set the current default message catalog to DOMAINNAME.
   If DOMAINNAME is null, return the current default.
   If DOMAINNAME is "", reset to the default of "messages".  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_textdomain (const char *__domainname);
static inline char *textdomain (const char *__domainname)
{
  return libintl_textdomain (__domainname);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define textdomain libintl_textdomain
#endif
extern LIBINTL_DLL_EXPORTED char *textdomain (const char *__domainname)
       _INTL_ASM (libintl_textdomain);
#endif

/* Specify that the DOMAINNAME message catalog will be found
   in DIRNAME rather than in the system locale data base.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_bindtextdomain (const char *__domainname,
				     const char *__dirname);
static inline char *bindtextdomain (const char *__domainname,
				    const char *__dirname)
{
  return libintl_bindtextdomain (__domainname, __dirname);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define bindtextdomain libintl_bindtextdomain
#endif
extern LIBINTL_DLL_EXPORTED char *bindtextdomain (const char *__domainname, const char *__dirname)
       _INTL_ASM (libintl_bindtextdomain);
#endif

/* Specify the character encoding in which the messages from the
   DOMAINNAME message catalog will be returned.  */
#ifdef _INTL_REDIRECT_INLINE
extern LIBINTL_DLL_EXPORTED char *libintl_bind_textdomain_codeset (const char *__domainname,
					      const char *__codeset);
static inline char *bind_textdomain_codeset (const char *__domainname,
					     const char *__codeset)
{
  return libintl_bind_textdomain_codeset (__domainname, __codeset);
}
#else
#ifdef _INTL_REDIRECT_MACROS
# define bind_textdomain_codeset libintl_bind_textdomain_codeset
#endif
extern LIBINTL_DLL_EXPORTED char *bind_textdomain_codeset (const char *__domainname,
				      const char *__codeset)
       _INTL_ASM (libintl_bind_textdomain_codeset);
#endif


/* Support for format strings with positions in *printf(), following the
   POSIX/XSI specification.
   Note: These replacements for the *printf() functions are visible only
   in source files that #include <libintl.h> or #include "gettext.h".
   Packages that use *printf() in source files that don't refer to _()
   or gettext() but for which the format string could be the return value
   of _() or gettext() need to add this #include.  Oh well.  */

#if !0

#include <stdio.h>
#include <stddef.h>

/* Get va_list.  */
#if __STDC__ || defined __cplusplus || defined _MSC_VER
# include <stdarg.h>
#else
# include <varargs.h>
#endif

#undef fprintf
#define fprintf libintl_fprintf
extern LIBINTL_DLL_EXPORTED int fprintf (FILE *, const char *, ...);
#undef vfprintf
#define vfprintf libintl_vfprintf
extern LIBINTL_DLL_EXPORTED int vfprintf (FILE *, const char *, va_list);

#undef printf
#define printf libintl_printf
extern LIBINTL_DLL_EXPORTED int printf (const char *, ...);
#undef vprintf
#define vprintf libintl_vprintf
extern LIBINTL_DLL_EXPORTED int vprintf (const char *, va_list);

#undef sprintf
#define sprintf libintl_sprintf
extern LIBINTL_DLL_EXPORTED int sprintf (char *, const char *, ...);
#undef vsprintf
#define vsprintf libintl_vsprintf
extern LIBINTL_DLL_EXPORTED int vsprintf (char *, const char *, va_list);

#if 0

#undef snprintf
#define snprintf libintl_snprintf
extern LIBINTL_DLL_EXPORTED int snprintf (char *, size_t, const char *, ...);
#undef vsnprintf
#define vsnprintf libintl_vsnprintf
extern LIBINTL_DLL_EXPORTED int vsnprintf (char *, size_t, const char *, va_list);

#endif

#if 0

#undef asprintf
#define asprintf libintl_asprintf
extern LIBINTL_DLL_EXPORTED int asprintf (char **, const char *, ...);
#undef vasprintf
#define vasprintf libintl_vasprintf
extern LIBINTL_DLL_EXPORTED int vasprintf (char **, const char *, va_list);

#endif

#if 1

#undef fwprintf
#define fwprintf libintl_fwprintf
extern LIBINTL_DLL_EXPORTED int fwprintf (FILE *, const wchar_t *, ...);
#undef vfwprintf
#define vfwprintf libintl_vfwprintf
extern LIBINTL_DLL_EXPORTED int vfwprintf (FILE *, const wchar_t *, va_list);

#undef wprintf
#define wprintf libintl_wprintf
extern LIBINTL_DLL_EXPORTED int wprintf (const wchar_t *, ...);
#undef vwprintf
#define vwprintf libintl_vwprintf
extern LIBINTL_DLL_EXPORTED int vwprintf (const wchar_t *, va_list);

#undef swprintf
#define swprintf libintl_swprintf
extern LIBINTL_DLL_EXPORTED int swprintf (wchar_t *, size_t, const wchar_t *, ...);
#undef vswprintf
#define vswprintf libintl_vswprintf
extern LIBINTL_DLL_EXPORTED int vswprintf (wchar_t *, size_t, const wchar_t *, va_list);

#endif

#endif


/* Support for relocatable packages.  */

/* Sets the original and the current installation prefix of the package.
   Relocation simply replaces a pathname starting with the original prefix
   by the corresponding pathname with the current prefix instead.  Both
   prefixes should be directory names without trailing slash (i.e. use ""
   instead of "/").  */
#define libintl_set_relocation_prefix libintl_set_relocation_prefix
extern LIBINTL_DLL_EXPORTED void
       libintl_set_relocation_prefix (const char *orig_prefix,
				      const char *curr_prefix);


#ifdef __cplusplus
}
#endif

#endif /* libintl.h */
