//
// pangowin32.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangowin32.h:
 *
 * Copyright (C) 1999 Red Hat Software
 * Copyright (C) 2000 Tor Lillqvist
 * Copyright (C) 2001 Alexander Larsson
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

unit pangowin32;

{$mode objfpc}{$H+}

interface

uses
  windows,
  ctypes,
  pango,
  glib2;

const
  LIB_PANGOCAIRO = 'libpangowin32-1.0-0.dll';


// #include <glib.h>
// #include <pango/pango-font.h>
// #include <pango/pango-layout.h>

// G_BEGIN_DECLS

//todo #define STRICT
//todo #ifndef _WIN32_WINNT
//todo #define _WIN32_WINNT 0x0501 (* To get ClearType-related macros *)
//todo #endif
//todo #include <windows.h>
//todo #undef STRICT

(**
 * PANGO_RENDER_TYPE_WIN32:
 *
 * A string constant identifying the Win32 renderer. The associated quark (see
 * g_quark_from_string()) is used to identify the renderer in pango_find_map().
 *)
const
  PANGO_RENDER_TYPE_WIN32 = 'PangoRenderWin32';

(* Calls for applications
 *)
{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(pango_font_map_create_context)
function pango_win32_get_context(): PPangoContext; cdecl; external LIB_PANGO;
{$endif}

procedure pango_win32_render(hdc: HDC; font: PPangoFont; glyphs: PPangoGlyphString; x: gint; y: gint); cdecl; external LIB_PANGO;
procedure pango_win32_render_layout_line(hdc: HDC; line: PPangoLayoutLine; x: cint; y: cint); cdecl; external LIB_PANGO;
procedure pango_win32_render_layout(hdc: HDC; layout: PPangoLayout; x: cint; y: cint); cdecl; external LIB_PANGO;

procedure pango_win32_render_transformed(hdc: HDC; const matrix: PPangoMatrix; font: PPangoFont; glyphs: PPangoGlyphString; x: cint; y: cint); cdecl; external LIB_PANGO;

{$ifdef PANGO_ENABLE_ENGINE}

(* For shape engines
 *)

{$ifndef PANGO_DISABLE_DEPRECATED}
// G_DEPRECATED_FOR(PANGO_GET_UNKNOWN_GLYPH)
function pango_win32_get_unknown_glyph(font: PPangoFont; wc: gunichar): PangoGlyph; cdecl; external LIB_PANGO;
{$endif} (* PANGO_DISABLE_DEPRECATED *)
function pango_win32_font_get_glyph_index(font: PPangoFont; wc: gunichar): gint; cdecl; external LIB_PANGO;

function pango_win32_get_dc(): HDC; cdecl; external LIB_PANGO;

function pango_win32_get_debug_flag(): gboolean; cdecl; external LIB_PANGO;

function pango_win32_font_select_font(font: PPangoFont; hdc: HDC): gboolean; cdecl; external LIB_PANGO;
procedure pango_win32_font_done_font(font: PPangoFont); cdecl; external LIB_PANGO;
function pango_win32_font_get_metrics_factor(font: PPangoFont): double; cdecl; external LIB_PANGO;

{$endif}

(* API for libraries that want to use PangoWin32 mixed with classic
 * Win32 fonts.
 *)
type
  PangoWin32FontCache = record
  end;
  PPangoWin32FontCache = ^PangoWin32FontCache;

function pango_win32_font_cache_new(): PPangoWin32FontCache; cdecl; external LIB_PANGO;
procedure pango_win32_font_cache_free(cache: PPangoWin32FontCache); cdecl; external LIB_PANGO;

function pango_win32_font_cache_load(cache: PPangoWin32FontCache; const logfont: PLOGFONTA): HFONT; cdecl; external LIB_PANGO;
function pango_win32_font_cache_loadw(cache: PPangoWin32FontCache; const logfont: PLOGFONTW): HFONT; cdecl; external LIB_PANGO;
procedure pango_win32_font_cache_unload(cache: PPangoWin32FontCache; hfont_: HFONT); cdecl; external LIB_PANGO;

function pango_win32_font_map_for_display(): PPangoFontMap; cdecl; external LIB_PANGO;
procedure pango_win32_shutdown_display(); cdecl; external LIB_PANGO;
function pango_win32_font_map_get_font_cache(font_map: PPangoFontMap): PPangoWin32FontCache; cdecl; external LIB_PANGO;

function pango_win32_font_logfont(font: PPangoFont): PLOGFONTA; cdecl; external LIB_PANGO;
function pango_win32_font_logfontw(font: PPangoFont): PLOGFONTW; cdecl; external LIB_PANGO;

function pango_win32_font_description_from_logfont(const lfp: PLOGFONTA): PPangoFontDescription; cdecl; external LIB_PANGO;

function pango_win32_font_description_from_logfontw(const lfp: PLOGFONTW): PPangoFontDescription; cdecl; external LIB_PANGO;

// G_END_DECLS


implementation


end.

