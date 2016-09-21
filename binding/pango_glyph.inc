//
// pango-glyph.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-glyph.h: Glyph storage
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

// #ifndef __PANGO_GLYPH_H__
// #define __PANGO_GLYPH_H__

// #include <pango/pango-types.h>
// #include <pango/pango-item.h>

// G_BEGIN_DECLS

(* 1024ths of a device unit *)
(**
 * PangoGlyphUnit:
 *
 * The #PangoGlyphUnit type is used to store dimensions within
 * Pango. Dimensions are stored in 1/%PANGO_SCALE of a device unit.
 * (A device unit might be a pixel for screen display, or
 * a point on a printer.) %PANGO_SCALE is currently 1024, and
 * may change in the future (unlikely though), but you should not
 * depend on its exact value. The PANGO_PIXELS() macro can be used
 * to convert from glyph units into device units with correct rounding.
 *)
type
  PangoGlyphUnit = gint32;

(* Positioning information about a glyph
 *)
(**
 * PangoGlyphGeometry:
 * @width: the logical width to use for the the character.
 * @x_offset: horizontal offset from nominal character position.
 * @y_offset: vertical offset from nominal character position.
 *
 * The #PangoGlyphGeometry structure contains width and positioning
 * information for a single glyph.
 *)
type
  PangoGlyphGeometry = record
    width: PangoGlyphUnit;
    x_offset: PangoGlyphUnit;
    y_offset: PangoGlyphUnit;
  end;
  PPangoGlyphGeometry = ^PangoGlyphGeometry;

(* Visual attributes of a glyph
 *)
(**
 * PangoGlyphVisAttr:
 * @is_cluster_start: set for the first logical glyph in each cluster. (Clusters
 * are stored in visual order, within the cluster, glyphs
 * are always ordered in logical order, since visual
 * order is meaningless; that is, in Arabic text, accent glyphs
 * follow the glyphs for the base character.)
 *
 * The PangoGlyphVisAttr is used to communicate information between
 * the shaping phase and the rendering phase.  More attributes may be
 * added in the future.
 *)
type
  PangoGlyphVisAttr = record
    is_cluster_start: guint; //todo is_cluster_start: guint = 1;
  end;
  PPangoGlyphVisAttr = ^PangoGlyphVisAttr;

(* A single glyph
 *)
(**
 * PangoGlyphInfo:
 * @glyph: the glyph itself.
 * @geometry: the positional information about the glyph.
 * @attr: the visual attributes of the glyph.
 *
 * The #PangoGlyphInfo structure represents a single glyph together with
 * positioning information and visual attributes.
 * It contains the following fields.
 *)
type
  PangoGlyphInfo = record
    glyph: PangoGlyph;
    geometry: PangoGlyphGeometry;
    attr: PangoGlyphVisAttr;
  end;
  PPangoGlyphInfo = ^PangoGlyphInfo;

(* A string of glyphs with positional information and visual attributes -
 * ready for drawing
 *)
(**
 * PangoGlyphString:
 * @num_glyphs: number of the glyphs in this glyph string.
 * @glyphs: (array length=num_glyphs): array of glyph information
 *          for the glyph string.
 * @log_clusters: logical cluster info, indexed by the byte index
 *                within the text corresponding to the glyph string.
 *
 * The #PangoGlyphString structure is used to store strings
 * of glyphs with geometry and visual attribute information.
 * The storage for the glyph information is owned
 * by the structure which simplifies memory management.
 *)
type
  PangoGlyphString = record
    num_glyphs: gint;
  
    glyphs: PPangoGlyphInfo;
  
  (* This is a memory inefficient way of representing the information
   * here - each value gives the byte index within the text
   * corresponding to the glyph string of the start of the cluster to
   * which the glyph belongs.
   *)
    log_clusters: pgint;
  
    (*< private >*)
    space: gint;
  end;
  PPangoGlyphString = ^PangoGlyphString;

(**
 * PANGO_TYPE_GLYPH_STRING:
 *
 * The #GObject type for #PangoGlyphString.
 *)
//todo #define PANGO_TYPE_GLYPH_STRING (pango_glyph_string_get_type ())

function pango_glyph_string_new(): PPangoGlyphString; cdecl; external LIB_PANGO;
procedure pango_glyph_string_set_size(string_: PPangoGlyphString; new_len: gint); cdecl; external LIB_PANGO;
function pango_glyph_string_get_type(): GType; cdecl; external LIB_PANGO;
function pango_glyph_string_copy(string_: PPangoGlyphString): PPangoGlyphString; cdecl; external LIB_PANGO;
procedure pango_glyph_string_free(string_: PPangoGlyphString); cdecl; external LIB_PANGO;
procedure pango_glyph_string_extents(glyphs: PPangoGlyphString; font: PPangoFont; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;
function pango_glyph_string_get_width(glyphs: PPangoGlyphString): cint; cdecl; external LIB_PANGO;

procedure pango_glyph_string_extents_range(glyphs: PPangoGlyphString; start: cint; end_: cint; font: PPangoFont; ink_rect: PPangoRectangle; logical_rect: PPangoRectangle); cdecl; external LIB_PANGO;

procedure pango_glyph_string_get_logical_widths(glyphs: PPangoGlyphString; const text: Pchar; length: cint; embedding_level: cint; logical_widths: pcint); cdecl; external LIB_PANGO;

procedure pango_glyph_string_index_to_x(glyphs: PPangoGlyphString; text: Pchar; length: cint; analysis: PPangoAnalysis; index_: cint; trailing: gboolean; x_pos: pcint); cdecl; external LIB_PANGO;
procedure pango_glyph_string_x_to_index(glyphs: PPangoGlyphString; text: Pchar; length: cint; analysis: PPangoAnalysis; x_pos: cint; index_: pcint; trailing: pcint); cdecl; external LIB_PANGO;

(* Turn a string of characters into a string of glyphs
 *)
procedure pango_shape(const text: Pgchar; length: gint; const analysis: PPangoAnalysis; glyphs: PPangoGlyphString); cdecl; external LIB_PANGO;

procedure pango_shape_full(const item_text: Pgchar; item_length: gint; const paragraph_text: Pgchar; paragraph_length: gint; const analysis: PPangoAnalysis; glyphs: PPangoGlyphString); cdecl; external LIB_PANGO;

function pango_reorder_items(logical_items: PGList): PGList; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_GLYPH_H__ *)
