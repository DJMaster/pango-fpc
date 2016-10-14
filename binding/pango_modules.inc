//
// pango-modules.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-modules.h:
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

// #ifndef __PANGO_MODULES_H__
// #define __PANGO_MODULES_H__

// #include <pango/pango-engine.h>

// G_BEGIN_DECLS

{$ifdef PANGO_ENABLE_BACKEND}

type
  PangoMap = record
  end;
  PPangoMap = ^PangoMap;

  PangoMapEntry = record
  end;
  PPangoMapEntry = ^PangoMapEntry;


(**
 * PangoIncludedModule:
 * @list: a function that lists the engines defined in this module.
 * @init: a function to initialize the module.
 * @exit: a function to finalize the module.
 * @create: a function to create an engine, given the engine name.
 *
 * The #PangoIncludedModule structure for a statically linked module
 * contains the functions that would otherwise be loaded from a dynamically
 * loaded module.
 *
 * Deprecated: 1.38
 *)
type
  PangoIncludedModule = record
    list: procedure(engines: PPPangoEngineInfo; n_engines: pcint); cdecl;
    init: procedure(module: PGTypeModule); cdecl;
    exit_: procedure(); cdecl;
    create: function(const id: pchar): PangoEngine; cdecl;
  end;
  PPangoIncludedModule = ^PangoIncludedModule;

function pango_find_map(language: PPangoLanguage; engine_type_id: guint; render_type_id: guint): PPangoMap; cdecl; external LIB_PANGO; deprecated;
function pango_map_get_engine(map: PPangoMap; script: PangoScript): PPangoEngine; cdecl; external LIB_PANGO; deprecated;
procedure pango_map_get_engines(map: PPangoMap; script: PangoScript; *exact_engines: PGSList; *fallback_engines: PGSList); cdecl; external LIB_PANGO; deprecated;
procedure pango_module_register(module: PPangoIncludedModule); cdecl; external LIB_PANGO; deprecated;

{$endif} (* PANGO_ENABLE_BACKEND *)

// G_END_DECLS

// #endif (* __PANGO_MODULES_H__ *)
