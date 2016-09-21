//
// pangoft2.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangoft2.h:
 *
 * Copyright (C) 1999 Red Hat Software
 * Copyright (C) 2000 Tor Lillqvist
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

unit pangoft2;

{$mode objfpc}{$H+}

interface

uses
  ctypes,
  freetype,
  pango,
  glib2;

const
  LIB_PANGOFT2 = 'libpangoft2-1.0-0.dll';


// #include <fontconfig/fontconfig.h>

// #include <pango/pango-layout.h>
// #include <pango/pangofc-font.h>

// G_BEGIN_DECLS

{$ifndef PANGO_DISABLE_DEPRECATED}
(**
 * PANGO_RENDER_TYPE_FT2:
 *
 * A string constant that was used to identify shape engines that work
 * with the FreeType backend. See %PANGO_RENDER_TYPE_FC for the replacement.
 *)
const
  PANGO_RENDER_TYPE_FT2 = 'PangoRenderFT2';
{$endif}

//todo #define PANGO_TYPE_FT2_FONT_MAP              (pango_ft2_font_map_get_type ())
//todo #define PANGO_FT2_FONT_MAP(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FT2_FONT_MAP, PangoFT2FontMap))
//todo #define PANGO_FT2_IS_FONT_MAP(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FT2_FONT_MAP))

type
  PangoFT2FontMap = record
  end;
  PPangoFT2FontMap = ^PangoFT2FontMap;

(**
 * PangoFT2SubstituteFunc:
 * @pattern: the <type>FcPattern</type> to tweak.
 * @data: user data.
 *
 * Function type for doing final config tweaking on prepared FcPatterns.
 *)
type
  PangoFT2SubstituteFunc = procedure (pattern: PFcPattern; data: gpointer); cdecl;

(* Calls for applications *)

procedure pango_ft2_render(bitmap: PFT_Bitmap; font: PPangoFont; glyphs: PPangoGlyphString; x: gint; y: gint); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_render_transformed(bitmap: PFT_Bitmap; const matrix: PPangoMatrix; font: PPangoFont; glyphs: PPangoGlyphString; x: cint; y: cint); cdecl; external LIB_PANGOFT2;

procedure pango_ft2_render_layout_line(bitmap: PFT_Bitmap; line: PPangoLayoutLine; x: cint; y: cint); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_render_layout_line_subpixel(bitmap: PFT_Bitmap; line: PPangoLayoutLine; x: cint; y: cint); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_render_layout(bitmap: PFT_Bitmap; layout: PPangoLayout; x: cint; y: cint); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_render_layout_subpixel(bitmap: PFT_Bitmap; layout: PPangoLayout; x: cint; y: cint); cdecl; external LIB_PANGOFT2;

function pango_ft2_font_map_get_type(): GType; cdecl; external LIB_PANGOFT2;

function pango_ft2_font_map_new(): PPangoFontMap; cdecl; external LIB_PANGOFT2;
procedure pango_ft2_font_map_set_resolution(fontmap: PPangoFT2FontMap; dpi_x: cdouble; dpi_y: cdouble); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_font_map_set_default_substitute(fontmap: PPangoFT2FontMap; func: PangoFT2SubstituteFunc; data: gpointer; notify: GDestroyNotify); cdecl; external LIB_PANGOFT2;
procedure pango_ft2_font_map_substitute_changed(fontmap: PPangoFT2FontMap); cdecl; external LIB_PANGOFT2;
{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(pango_font_map_create_context)
function pango_ft2_font_map_create_context(fontmap: PPangoFT2FontMap): PPangoContext; cdecl; external LIB_PANGOFT2;
{$endif}


(* API for rendering modules
 *)
{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(pango_font_map_create_context)
function pango_ft2_get_context(dpi_x: cdouble; dpi_y: cdouble): PPangoContext; cdecl; external LIB_PANGOFT2;
// G_DEPRECATED_FOR(pango_ft2_font_map_new)
function pango_ft2_font_map_for_display(): PPangoFontMap; cdecl; external LIB_PANGOFT2;
// G_DEPRECATED
procedure pango_ft2_shutdown_display(); cdecl; external LIB_PANGOFT2;

// G_DEPRECATED_FOR(PANGO_GET_UNKNOWN_GLYPH)
function pango_ft2_get_unknown_glyph(font: PPangoFont): PangoGlyph; cdecl; external LIB_PANGOFT2;
// G_DEPRECATED_FOR(pango_fc_font_kern_glyphs)
function pango_ft2_font_get_kerning(font: PPangoFont; left: PangoGlyph; right: PangoGlyph): cint; cdecl; external LIB_PANGOFT2;
// G_DEPRECATED_FOR(pango_fc_font_lock_face)
function pango_ft2_font_get_face(font: PPangoFont): FT_Face; cdecl; external LIB_PANGOFT2;
// G_DEPRECATED_FOR(pango_font_get_coverage)
function pango_ft2_font_get_coverage(font: PPangoFont; language: PPangoLanguage): PPangoCoverage; cdecl; external LIB_PANGOFT2;
{$endif} (* PANGO_DISABLE_DEPRECATED *)

// G_END_DECLS


implementation


end.

