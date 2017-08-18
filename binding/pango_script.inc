//
// pango-script.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-script.h: Script tag handling
 *
 * Copyright (C) 2002 Red Hat Software
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *)

// #ifndef __PANGO_SCRIPT_H__
// #define __PANGO_SCRIPT_H__

// #include <glib.h>

// G_BEGIN_DECLS

(**
 * PangoScriptIter:
 *
 * A #PangoScriptIter is used to iterate through a string
 * and identify ranges in different scripts.
 **)
type
  PangoScriptIter = record
  end;
  PPangoScriptIter = ^PangoScriptIter;

function pango_script_for_unichar(ch: gunichar): PangoScript; cdecl; external LIB_PANGO;

function pango_script_iter_new(const text: pchar; length: cint): PPangoScriptIter; cdecl; external LIB_PANGO;
procedure pango_script_iter_get_range(iter: PPangoScriptIter; const start: ppchar; const end_: ppchar; script: PPangoScript); cdecl; external LIB_PANGO;
function pango_script_iter_next(iter: PPangoScriptIter): gboolean; cdecl; external LIB_PANGO;
procedure pango_script_iter_free(iter: PPangoScriptIter); cdecl; external LIB_PANGO;

// #include <pango/pango-language.h>

function pango_script_get_sample_language(script: PangoScript): PPangoLanguage; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_SCRIPT_H__ *)
