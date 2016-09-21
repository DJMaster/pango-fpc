//
// pango-language.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-language.h: Language handling routines
 *
 * Copyright (C) 1999 Red Hat Software
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

// #ifndef __PANGO_LANGUAGE_H__
// #define __PANGO_LANGUAGE_H__

// #include <glib.h>
// #include <glib-object.h>

// G_BEGIN_DECLS

type
  PangoLanguage = record
  end;
  PPangoLanguage = ^PangoLanguage;
  PPPangoLanguage = ^PPangoLanguage;

(**
 * PANGO_TYPE_LANGUAGE:
 *
 * The #GObject type for #PangoLanguage.
 *)
//todo #define PANGO_TYPE_LANGUAGE (pango_language_get_type ())

function pango_language_get_type(): GType; cdecl; external LIB_PANGO;
function pango_language_from_string(const language: pchar): PPangoLanguage; cdecl; external LIB_PANGO;

function pango_language_to_string(language: PPangoLanguage): pchar; cdecl; external LIB_PANGO;
(* For back compat.  Will have to keep indefinitely. *)
//todo #define pango_language_to_string(language) ((const char *)language)

function pango_language_get_sample_string(language: PPangoLanguage): pchar; cdecl; external LIB_PANGO;
function pango_language_get_default(): PPangoLanguage; cdecl; external LIB_PANGO;

function pango_language_matches(language: PPangoLanguage; const range_list: pchar): gboolean; cdecl; external LIB_PANGO;

// #include <pango/pango_script.h>

function pango_language_includes_script(language: PPangoLanguage; script: PangoScript): gboolean; cdecl; external LIB_PANGO;
function pango_language_get_scripts(language: PPangoLanguage; num_scripts: pcint): PPangoScript; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_LANGUAGE_H__ *)
