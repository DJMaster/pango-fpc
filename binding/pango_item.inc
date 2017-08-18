//
// pango-item.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-item.h: Structure for storing run information
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

// #ifndef __PANGO_ITEM_H__
// #define __PANGO_ITEM_H__

// #include <pango/pango-types.h>

// G_BEGIN_DECLS


(**
 * PANGO_ANALYSIS_FLAG_CENTERED_BASELINE:
 *
 * Whether the segment should be shifted to center around the baseline.
 * Used in vertical writing directions mostly.
 *
 * Since: 1.16
 *)
const
  PANGO_ANALYSIS_FLAG_CENTERED_BASELINE = (1 shl 0);

(**
 * PANGO_ANALYSIS_FLAG_IS_ELLIPSIS:
 *
 * This flag is used to mark runs that hold ellipsized text,  * in an ellipsized layout.
 *
 * Since: 1.36.7
 *)
const
  PANGO_ANALYSIS_FLAG_IS_ELLIPSIS = (1 shl 1);

(**
 * PangoAnalysis:
 * @shape_engine: the engine for doing rendering-system-dependent processing.
 * @lang_engine: the engine for doing rendering-system-independent processing.
 * @font: the font for this segment.
 * @level: the bidirectional level for this segment.
 * @gravity: the glyph orientation for this segment (A #PangoGravity).
 * @flags: boolean flags for this segment (currently only one) (Since: 1.16).
 * @script: the detected script for this segment (A #PangoScript) (Since: 1.18).
 * @language: the detected language for this segment.
 * @extra_attrs: extra attributes for this segment.
 *
 * The #PangoAnalysis structure stores information about
 * the properties of a segment of text.
 *)
type
 PangoAnalysis = record
    shape_engine: PPangoEngineShape;
    lang_engine: PPangoEngineLang;
    font: PPangoFont;
  
    level: guint8;
    gravity: guint8; (* PangoGravity *)
    flags: guint8;
  
    script: guint8; (* PangoScript *)
    language: PPangoLanguage;
  
    extra_attrs: PGSList;
  end;
  PPangoAnalysis = ^PangoAnalysis;

(**
 * PangoItem:
 * @offset: byte offset of the start of this item in text.
 * @length: length of this item in bytes.
 * @num_chars: number of Unicode characters in the item.
 * @analysis: analysis results for the item.
 *
 * The #PangoItem structure stores information about a segment of text.
 *)
type
  PangoItem = record
    offset: gint;
    length: gint;
    num_chars: gint;
    analysis: PangoAnalysis;
  end;
  PPangoItem = ^PangoItem;

//todo #define PANGO_TYPE_ITEM (pango_item_get_type ())

function pango_item_get_type(): GType; cdecl; external LIB_PANGO;

function pango_item_new(): PPangoItem; cdecl; external LIB_PANGO;
function pango_item_copy(item: PPangoItem): PPangoItem; cdecl; external LIB_PANGO;
procedure pango_item_free(item: PPangoItem); cdecl; external LIB_PANGO;
function pango_item_split(orig: PPangoItem; split_index: cint; split_offset: cint): PPangoItem; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_ITEM_H__ *)
