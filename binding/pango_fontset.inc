//
// pango-fontset.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-fontset.h: Font set handling
 *
 * Copyright (C) 2001 Red Hat Software
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

// #ifndef __PANGO_FONTSET_H__
// #define __PANGO_FONTSET_H__

// #include <pango/pango-coverage.h>
// #include <pango/pango-types.h>

// #include <glib-object.h>

// G_BEGIN_DECLS

(*
 * PangoFontset
 *)

(**
 * PANGO_TYPE_FONTSET:
 *
 * The #GObject type for #PangoFontset.
 *)
//todo #define PANGO_TYPE_FONTSET              (pango_fontset_get_type ())
//todo #define PANGO_FONTSET(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FONTSET, PangoFontset))
//todo #define PANGO_IS_FONTSET(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FONTSET))

function pango_fontset_get_type(): GType; cdecl; external LIB_PANGO;

type
  PangoFontset = record
  end;
  PPangoFontset = ^PangoFontset;

(**
 * PangoFontsetForeachFunc:
 * @fontset: a #PangoFontset
 * @font: a font from @fontset
 * @user_data: callback data
 *
 * A callback function used by pango_fontset_foreach() when enumerating
 * the fonts in a fontset.
 *
 * Returns: if %TRUE, stop iteration and return immediately.
 *
 * Since: 1.4
 **)
type
  PangoFontsetForeachFunc = function(fontset: PPangoFontset; font: PPangoFont; user_data: gpointer): gboolean; cdecl;

function pango_fontset_get_font(fontset: PPangoFontset; wc: guint): PPangoFont; cdecl; external LIB_PANGO;
function pango_fontset_get_metrics(fontset: PPangoFontset): PPangoFontMetrics; cdecl; external LIB_PANGO;
procedure pango_fontset_foreach(fontset: PPangoFontset; func: PangoFontsetForeachFunc; data: gpointer); cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_BACKEND}


//todo #define PANGO_FONTSET_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FONTSET, PangoFontsetClass))
//todo #define PANGO_IS_FONTSET_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FONTSET))
//todo #define PANGO_FONTSET_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FONTSET, PangoFontsetClass))

(**
 * PangoFontset:
 *
 * A #PangoFontset represents a set of #PangoFont to use
 * when rendering text. It is the result of resolving a
 * #PangoFontDescription against a particular #PangoContext.
 * It has operations for finding the component font for
 * a particular Unicode character, and for finding a composite
 * set of metrics for the entire fontset.
 *)
type
  PangoFontset = record
    parent_instance: GObject;
  end;

(**
 * PangoFontsetClass:
 * @parent_class: parent #GObjectClass.
 * @get_font: a function to get the font in the fontset that contains the
 * best glyph for the given Unicode character; see pango_fontset_get_font().
 * @get_metrics: a function to get overall metric information for the fonts
 * in the fontset; see pango_fontset_get_metrics().
 * @get_language: a function to get the language of the fontset.
 * @foreach: a function to loop over the fonts in the fontset. See
 * pango_fontset_foreach().
 *
 * The #PangoFontsetClass structure holds the virtual functions for
 * a particular #PangoFontset implementation.
 *)
type
  PangoFontsetClass = record
    GObjectClass parent_class;
    (*< public >*)

    get_font: function(fontset: PPangoFontset; wc: guint): PPangoFont; cdecl;

    get_metrics: function(fontset: PPangoFontset): PPangoFontMetrics; cdecl;
    get_language: function(fontset: PPangoFontset): PPangoLanguage; cdecl;
    foreach: procedure(fontset: PPangoFontset; func: PangoFontsetForeachFunc; data: gpointer); cdecl;

    (*< private >*)

    (* Padding for future expansion *)
    _pango_reserved1: procedure(); cdecl;
    _pango_reserved2: procedure(); cdecl;
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;
  PPangoFontsetClass = ^PangoFontsetClass;

(*
 * PangoFontsetSimple
 *)

(**
 * PANGO_TYPE_FONTSET_SIMPLE:
 *
 * The #GObject type for #PangoFontsetSimple.
 *)
(**
 * PangoFontsetSimple:
 *
 * #PangoFontsetSimple is a implementation of the abstract
 * #PangoFontset base class in terms of an array of fonts,  * which the creator provides when constructing the
 * #PangoFontsetSimple.
 *)
//todo #define PANGO_TYPE_FONTSET_SIMPLE       (pango_fontset_simple_get_type ())
//todo #define PANGO_FONTSET_SIMPLE(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FONTSET_SIMPLE, PangoFontsetSimple))
//todo #define PANGO_IS_FONTSET_SIMPLE(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FONTSET_SIMPLE))

type
  PangoFontsetSimple = record
  end;
  PPangoFontsetSimple = ^PangoFontsetSimple;

  PangoFontsetSimpleClass = record
  end;
  PPangoFontsetSimpleClass = ^PangoFontsetSimpleClass;

function pango_fontset_simple_get_type(): GType; cdecl; external LIB_PANGO;

function pango_fontset_simple_new(language: PPangoLanguage): PPangoFontsetSimple; cdecl; external LIB_PANGO;
procedure pango_fontset_simple_append(fontset: PPangoFontsetSimple; font: PPangoFont); cdecl; external LIB_PANGO;
function pango_fontset_simple_size(fontset: PPangoFontsetSimple): cint; cdecl; external LIB_PANGO;

{$endif} (* PANGO_ENABLE_BACKEND *)

// G_END_DECLS

// #endif (* __PANGO_FONTSET_H__ *)
