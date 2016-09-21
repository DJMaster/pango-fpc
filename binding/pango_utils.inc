//
// pango-utils.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-utils.c: Utilities for internal functions and modules
 *
 * Copyright (C) 2000 Red Hat Software
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,  * Boston, MA 02111-1307, USA.
 *)

// #ifndef __PANGO_UTILS_H__
// #define __PANGO_UTILS_H__

// #include <stdio.h>
// #include <glib.h>
// #include <pango/pango-font.h>

// G_BEGIN_DECLS

// G_DEPRECATED
function pango_split_file_list(const str: pchar): ppchar; cdecl; external LIB_PANGO;

// G_DEPRECATED
function pango_trim_string(const str: pchar): pchar; cdecl; external LIB_PANGO;
// G_DEPRECATED
//todo function pango_read_line(FILE *stream; str: PGString): gint; cdecl; external LIB_PANGO;
// G_DEPRECATED
function pango_skip_space(const pos: ppchar): gboolean; cdecl; external LIB_PANGO;
// G_DEPRECATED
function pango_scan_word(const pos: ppchar; out_: PGString): gboolean; cdecl; external LIB_PANGO;
// G_DEPRECATED
function pango_scan_string(const pos: ppchar; out_: PGString): gboolean; cdecl; external LIB_PANGO;
// G_DEPRECATED
function pango_scan_int(const pos: ppchar; out_: pcint): gboolean; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}
// G_DEPRECATED
function pango_config_key_get_system(const key: pchar): pchar; cdecl; external LIB_PANGO;
// G_DEPRECATED
function pango_config_key_get(const key: pchar): pchar; cdecl; external LIB_PANGO;
// G_DEPRECATED
procedure pango_lookup_aliases(const fontname: pchar; families: pppchar; n_families: pcint); cdecl; external LIB_PANGO;
{$endif} (* PANGO_ENABLE_BACKEND *)

// G_DEPRECATED
function pango_parse_enum(type_: GType; const str: pchar; value: pcint; warn: gboolean; possible_values: ppchar): gboolean; cdecl; external LIB_PANGO;

(* Functions for parsing textual representations
 * of PangoFontDescription fields. They return TRUE if the input string
 * contains a valid value, which then has been assigned to the corresponding
 * field in the PangoFontDescription. If the warn parameter is TRUE,  * a warning is printed (with g_warning) if the string does not
 * contain a valid value.
 *)
function pango_parse_style(const str: pchar; style: PPangoStyle; warn: gboolean): gboolean; cdecl; external LIB_PANGO;
function pango_parse_variant(const str: pchar; variant: PPangoVariant; warn: gboolean): gboolean; cdecl; external LIB_PANGO;
function pango_parse_weight(const str: pchar; weight: PPangoWeight; warn: gboolean): gboolean; cdecl; external LIB_PANGO;
function pango_parse_stretch(const str: pchar; stretch: PPangoStretch; warn: gboolean): gboolean; cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}

(* On Unix, return the name of the "pango" subdirectory of SYSCONFDIR
 * (which is set at compile time). On Win32, return the Pango
 * installation directory (which is set at installation time, and
 * stored in the registry). The returned string should not be
 * g_free'd.
 *)
// G_DEPRECATED
function pango_get_sysconf_subdirectory(): pchar; cdecl; external LIB_PANGO;

(* Ditto for LIBDIR/pango. On Win32, use the same Pango
 * installation directory. This returned string should not be
 * g_free'd either.
 *)
// G_DEPRECATED
function pango_get_lib_subdirectory(): pchar; cdecl; external LIB_PANGO;

{$endif} (* PANGO_ENABLE_BACKEND *)

(* Hint line position and thickness.
 *)
procedure pango_quantize_line_geometry(thickness: pcint; position: pcint); cdecl; external LIB_PANGO;

(* A routine from fribidi that we either wrap or provide ourselves.
 *)
//todo function pango_log2vis_get_embedding_levels(const text: pgchar; length: cint; pbase_dir: PPangoDirection): pguint8; cdecl; external LIB_PANGO;

(* Unicode characters that are zero-width and should not be rendered
 * normally.
 *)
function pango_is_zero_width(ch: gunichar): gboolean; cdecl; external LIB_PANGO;

(* Pango version checking *)

(* Encode a Pango version as an integer *)
(**
 * PANGO_VERSION_ENCODE:
 * @major: the major component of the version number
 * @minor: the minor component of the version number
 * @micro: the micro component of the version number
 *
 * This macro encodes the given Pango version into an integer.  The numbers
 * returned by %PANGO_VERSION and pango_version() are encoded using this macro.
 * Two encoded version numbers can be compared as integers.
 *)
//todo #define PANGO_VERSION_ENCODE(major, minor, micro) (     \
//todo    ((major) * 10000)                             \
//todo  + ((minor) *   100)                             \
//todo  + ((micro) *     1))

(* Encoded version of Pango at compile-time *)
(**
 * PANGO_VERSION:
 *
 * The version of Pango available at compile-time, encoded using PANGO_VERSION_ENCODE().
 *)
(**
 * PANGO_VERSION_STRING:
 *
 * A string literal containing the version of Pango available at compile-time.
 *)
(**
 * PANGO_VERSION_MAJOR:
 *
 * The major component of the version of Pango available at compile-time.
 *)
(**
 * PANGO_VERSION_MINOR:
 *
 * The minor component of the version of Pango available at compile-time.
 *)
(**
 * PANGO_VERSION_MICRO:
 *
 * The micro component of the version of Pango available at compile-time.
 *)
//todo #define PANGO_VERSION PANGO_VERSION_ENCODE(     \
//todo  PANGO_VERSION_MAJOR,                    \
//todo  PANGO_VERSION_MINOR,                    \
//todo  PANGO_VERSION_MICRO)

(* Check that compile-time Pango is as new as required *)
(**
 * PANGO_VERSION_CHECK:
 * @major: the major component of the version number
 * @minor: the minor component of the version number
 * @micro: the micro component of the version number
 *
 * Checks that the version of Pango available at compile-time is not older than
 * the provided version number.
 *)
//todo #define PANGO_VERSION_CHECK(major,minor,micro)    \
//todo  (PANGO_VERSION >= PANGO_VERSION_ENCODE(major,minor,micro))


(* Return encoded version of Pango at run-time *)
function pango_version(): cint; cdecl; external LIB_PANGO;

(* Return run-time Pango version as an string *)
function pango_version_string(): pchar; cdecl; external LIB_PANGO;

(* Check that run-time Pango is as new as required *)
function pango_version_check(required_major: cint; required_minor: cint; required_micro: cint): pchar; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_UTILS_H__ *)
