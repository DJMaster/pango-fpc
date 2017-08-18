//
// pangofc-font.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangofc-font.h: Base fontmap type for fontconfig-based backends
 *
 * Copyright (C) 2003 Red Hat Software
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

// #ifndef __PANGO_FC_FONT_H__
// #define __PANGO_FC_FONT_H__

// #include <pango/pango.h>
// #include <ft2build.h>
// #include FT_FREETYPE_H
// #include <fontconfig/fontconfig.h>

// G_BEGIN_DECLS

//todo #define PANGO_TYPE_FC_FONT              (pango_fc_font_get_type ())
//todo #define PANGO_FC_FONT(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FC_FONT, PangoFcFont))
//todo #define PANGO_IS_FC_FONT(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FC_FONT))

{.$if defined(PANGO_ENABLE_ENGINE) or defined(PANGO_ENABLE_BACKEND)}

(**
 * PANGO_RENDER_TYPE_FC:
 *
 * A string constant used to identify shape engines that work
 * with the fontconfig based backends. See the @engine_type field
 * of #PangoEngineInfo.
 **)
const
  PANGO_RENDER_TYPE_FC = 'PangoRenderFc';

{.$ifdef PANGO_ENABLE_BACKEND}

//todo #define PANGO_FC_FONT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FC_FONT, PangoFcFontClass))
//todo #define PANGO_IS_FC_FONT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FC_FONT))
//todo #define PANGO_FC_FONT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FC_FONT, PangoFcFontClass))

(**
 * PangoFcFont:
 *
 * #PangoFcFont is a base class for font implementations
 * using the Fontconfig and FreeType libraries and is used in
 * conjunction with #PangoFcFontMap. When deriving from this
 * class, you need to implement all of its virtual functions
 * other than shutdown() along with the get_glyph_extents()
 * virtual function from #PangoFont.
 **)
type
  PPangoFcFont = ^PangoFcFont;
  PangoFcFont = record
    parent_instance: PangoFont;
  
    font_pattern: PFcPattern; (* fully resolved pattern *)
    fontmap: PPangoFontMap;   (* associated map *)
    priv: gpointer;           (* used internally *)
    matrix: PangoMatrix;      (* used internally *)
    description: PPangoFontDescription;
  
    metrics_by_lang: PGSList;
  
    is_hinted: guint; // = 1
    is_transformed: guint; // = 1
  end;

(**
 * PangoFcFontClass:
 * @lock_face: Returns the FT_Face of the font and increases
 *  the reference count for the face by one.
 * @unlock_face: Decreases the reference count for the
 *  FT_Face of the font by one. When the count is zero,  *  the #PangoFcFont subclass is allowed to free the
 *  FT_Face.
 * @has_char: Return %TRUE if the the font contains a glyph
 *   corresponding to the specified character.
 * @get_glyph: Gets the glyph that corresponds to the given
 *   Unicode character.
 * @get_unknown_glyph: (nullable): Gets the glyph that
 *   should be used to display an unknown-glyph indication
 *   for the specified Unicode character.  May be %NULL.
 * @shutdown: (nullable): Performs any font-specific
 *   shutdown code that needs to be done when
 *   pango_fc_font_map_shutdown is called.  May be %NULL.
 *
 * Class structure for #PangoFcFont.
 **)
type
  PPangoFcFontClass = ^PangoFcFontClass;
  PangoFcFontClass = record
    (*< private >*)
    parent_class: PangoFontClass;
  
    (*< public >*)
    lock_face: function(font: PPangoFcFont): FT_Face; cdecl;
    unlock_face: procedure(font: PPangoFcFont); cdecl;
    has_char: function(font: PPangoFcFont; wc: gunichar): gboolean; cdecl;
    get_glyph: function(font: PPangoFcFont; wc: gunichar): guint; cdecl;
    get_unknown_glyph: function(font: PPangoFcFont; wc: gunichar): PangoGlyph; cdecl;
    shutdown: procedure(font: PPangoFcFont); cdecl;
    (*< private >*)
  
    (* Padding for future expansion *)
    _pango_reserved1: procedure(); cdecl;
    _pango_reserved2: procedure(); cdecl;
    _pango_reserved3: procedure(); cdecl;
    _pango_reserved4: procedure(); cdecl;
  end;

{.$endif} (* PANGO_ENABLE_BACKEND *)

function pango_fc_font_has_char(font: PPangoFcFont; wc: gunichar): gboolean; cdecl; external LIB_PANGO;
function pango_fc_font_get_glyph(font: PPangoFcFont; wc: gunichar): guint; cdecl; external LIB_PANGO;
{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(PANGO_GET_UNKNOWN_GLYPH)
function pango_fc_font_get_unknown_glyph(font: PPangoFcFont; wc: gunichar): PangoGlyph; cdecl; external LIB_PANGO;
procedure pango_fc_font_kern_glyphs(font: PPangoFcFont; glyphs: PPangoGlyphString); cdecl; external LIB_PANGO; deprecated;
{$endif} (* PANGO_DISABLE_DEPRECATED *)

{.$endif} (* PANGO_ENABLE_ENGINE || PANGO_ENABLE_BACKEND *)

function pango_fc_font_get_type(): GType; cdecl; external LIB_PANGO;

function pango_fc_font_lock_face(font: PPangoFcFont): FT_Face; cdecl; external LIB_PANGO;
procedure pango_fc_font_unlock_face(font: PPangoFcFont); cdecl; external LIB_PANGO;

// G_END_DECLS
// #endif (* __PANGO_FC_FONT_H__ *)
