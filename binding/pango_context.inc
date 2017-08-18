//
// pango-context.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-context.h: Rendering contexts
 *
 * Copyright (C) 2000 Red Hat Software
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

// #ifndef __PANGO_CONTEXT_H__
// #define __PANGO_CONTEXT_H__

// #include <pango/pango-font.h>
// #include <pango/pango-fontmap.h>
// #include <pango/pango-attributes.h>

// G_BEGIN_DECLS

(* Sort of like a GC - application set information about how
 * to handle scripts
 *)

(* PangoContext typedefed in pango-fontmap.h *)
type
  PangoContextClass = record
  end;
  PPangoContextClass = ^PangoContextClass;

//todo #define PANGO_TYPE_CONTEXT              (pango_context_get_type ())
//todo #define PANGO_CONTEXT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CONTEXT, PangoContext))
//todo #define PANGO_CONTEXT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_CONTEXT, PangoContextClass))
//todo #define PANGO_IS_CONTEXT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_CONTEXT))
//todo #define PANGO_IS_CONTEXT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_CONTEXT))
//todo #define PANGO_CONTEXT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_CONTEXT, PangoContextClass))


(* The PangoContext and PangoContextClass structs are private; if you
 * need to create a subclass of these, file a bug.
 *)

function pango_context_get_type(): GType; cdecl; external LIB_PANGO;

function pango_context_new(): PPangoContext; cdecl; external LIB_PANGO;
procedure pango_context_changed(context: PPangoContext); cdecl; external LIB_PANGO;
procedure pango_context_set_font_map(context: PPangoContext; font_map: PPangoFontMap); cdecl; external LIB_PANGO;
function pango_context_get_font_map(context: PPangoContext): PPangoFontMap; cdecl; external LIB_PANGO;
function pango_context_get_serial(context: PPangoContext): guint; cdecl; external LIB_PANGO;
procedure pango_context_list_families(context: PPangoContext; families: PPPPangoFontFamily; n_families: pcint); cdecl; external LIB_PANGO;
function pango_context_load_font(context: PPangoContext; const desc: PPangoFontDescription): PPangoFont; cdecl; external LIB_PANGO;
function pango_context_load_fontset(context: PPangoContext; const desc: PPangoFontDescription; language: PPangoLanguage): PPangoFontset; cdecl; external LIB_PANGO;

function pango_context_get_metrics(context: PPangoContext; const desc: PPangoFontDescription; language: PPangoLanguage): PPangoFontMetrics; cdecl; external LIB_PANGO;

procedure pango_context_set_font_description(context: PPangoContext; const desc: PPangoFontDescription); cdecl; external LIB_PANGO;
function pango_context_get_font_description(context: PPangoContext): PPangoFontDescription; cdecl; external LIB_PANGO;
function pango_context_get_language(context: PPangoContext): PPangoLanguage; cdecl; external LIB_PANGO;
procedure pango_context_set_language(context: PPangoContext; language: PPangoLanguage); cdecl; external LIB_PANGO;
procedure pango_context_set_base_dir(context: PPangoContext; direction: PangoDirection); cdecl; external LIB_PANGO;
function pango_context_get_base_dir(context: PPangoContext): PangoDirection; cdecl; external LIB_PANGO;
procedure pango_context_set_base_gravity(context: PPangoContext; gravity: PangoGravity); cdecl; external LIB_PANGO;
function pango_context_get_base_gravity(context: PPangoContext): PangoGravity; cdecl; external LIB_PANGO;
function pango_context_get_gravity(context: PPangoContext): PangoGravity; cdecl; external LIB_PANGO;
procedure pango_context_set_gravity_hint(context: PPangoContext; hint: PangoGravityHint); cdecl; external LIB_PANGO;
function pango_context_get_gravity_hint(context: PPangoContext): PangoGravityHint; cdecl; external LIB_PANGO;

procedure pango_context_set_matrix(context: PPangoContext; const matrix: PPangoMatrix); cdecl; external LIB_PANGO;
function pango_context_get_matrix(context: PPangoContext): PPangoMatrix; cdecl; external LIB_PANGO;

(* Break a string of Unicode characters into segments with
 * consistent shaping/language engine and bidrectional level.
 * Returns a #GList of #PangoItem's
 *)
function pango_itemize(context: PPangoContext; const text: pchar; start_index: cint; length: cint; attrs: PPangoAttrList; cached_iter: PPangoAttrIterator): PGList; cdecl; external LIB_PANGO;
function pango_itemize_with_base_dir(context: PPangoContext; base_dir: PangoDirection; const text: pchar; start_index: cint; length: cint; attrs: PPangoAttrList; cached_iter: PPangoAttrIterator): PGList; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_CONTEXT_H__ *)
