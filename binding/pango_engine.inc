//
// pango-engine.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pango-engine.h: Engines for script and language specific processing
 *
 * Copyright (C) 2000,2003 Red Hat Software
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

// #ifndef __PANGO_ENGINE_H__
// #define __PANGO_ENGINE_H__

// #include <pango/pango-types.h>
// #include <pango/pango-item.h>
// #include <pango/pango-font.h>
// #include <pango/pango-glyph.h>
// #include <pango/pango-script.h>

// G_BEGIN_DECLS

{$ifdef PANGO_ENABLE_ENGINE}

(**
 * PANGO_RENDER_TYPE_NONE:
 *
 * A string constant defining the render type
 * for engines that are not rendering-system specific.
 *
 * Deprecated: 1.38
 *)
const
  PANGO_RENDER_TYPE_NONE = 'PangoRenderNone';

//todo #define PANGO_TYPE_ENGINE              (pango_engine_get_type ())
//todo #define PANGO_ENGINE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_ENGINE, PangoEngine))
//todo #define PANGO_IS_ENGINE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_ENGINE))
//todo #define PANGO_ENGINE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_ENGINE, PangoEngineClass))
//todo #define PANGO_IS_ENGINE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_ENGINE))
//todo #define PANGO_ENGINE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_ENGINE, PangoEngineClass))

(**
 * PangoEngine:
 *
 * #PangoEngine is the base class for all types of language and
 * script specific engines. It has no functionality by itself.
 *
 * Deprecated: 1.38
 **)
type
  PangoEngine = record
    (*< private >*)
    parent_instance: GObject;
  end;
  PPangoEngine = ^PangoEngine;

(**
 * PangoEngineClass:
 *
 * Class structure for #PangoEngine
 *
 * Deprecated: 1.38
 **)
type
  PangoEngineClass = record
  (*< private >*)
    parent_class: GObjectClass;
  end;
  PPangoEngineClass = ^PangoEngineClass;

function pango_engine_get_type(): GType; cdecl; external LIB_PANGO;

(**
 * PANGO_ENGINE_TYPE_LANG:
 *
 * A string constant defining the engine type for language engines.
 * These engines derive from #PangoEngineLang.
 *
 * Deprecated: 1.38
 *)
const
  PANGO_ENGINE_TYPE_LANG = 'PangoEngineLang';

//todo #define PANGO_TYPE_ENGINE_LANG              (pango_engine_lang_get_type ())
//todo #define PANGO_ENGINE_LANG(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_ENGINE_LANG, PangoEngineLang))
//todo #define PANGO_IS_ENGINE_LANG(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_ENGINE_LANG))
//todo #define PANGO_ENGINE_LANG_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_ENGINE_LANG, PangoEngineLangClass))
//todo #define PANGO_IS_ENGINE_LANG_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_ENGINE_LANG))
//todo #define PANGO_ENGINE_LANG_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_ENGINE_LANG, PangoEngineLangClass))

(**
 * PangoEngineLang:
 *
 * The #PangoEngineLang class is implemented by engines that
 * customize the rendering-system independent part of the
 * Pango pipeline for a particular script or language. For
 * instance, a custom #PangoEngineLang could be provided for
 * Thai to implement the dictionary-based word boundary
 * lookups needed for that language.
 *
 * Deprecated: 1.38
 **)
type
  PangoEngineLang = record
    (*< private >*)
    parent_instance: PangoEngine;
  end;

(**
 * PangoEngineLangClass:
 * @script_break: (nullable): Provides a custom implementation of
 * pango_break().  If %NULL, pango_default_break() is used instead. If
 * not %NULL, for Pango versions before 1.16 (module interface version
 * before 1.6.0), this was called instead of pango_default_break(),  * but in newer versions, pango_default_break() is always called and
 * this is called after that to allow tailoring the breaking results.
 *
 * Class structure for #PangoEngineLang
 *
 * Deprecated: 1.38
 **)
type
  PangoEngineLangClass = record
    (*< private >*)
    parent_class: PangoEngineClass;
  
    (*< public >*)
    script_break: procedure(engine: PPangoEngineLang; const text: pchar; len: cint; analysis: PPangoAnalysis; attrs: PPangoLogAttr; attrs_len: cint); cdecl;
  end;
  PPangoEngineLangClass = ^PangoEngineLangClass;


function pango_engine_lang_get_type(): GType; cdecl; external LIB_PANGO;

(**
 * PANGO_ENGINE_TYPE_SHAPE:
 *
 * A string constant defining the engine type for shaping engines.
 * These engines derive from #PangoEngineShape.
 *
 * Deprecated: 1.38
 *)
const
  PANGO_ENGINE_TYPE_SHAPE = 'PangoEngineShape';

//todo #define PANGO_TYPE_ENGINE_SHAPE              (pango_engine_shape_get_type ())
//todo #define PANGO_ENGINE_SHAPE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_ENGINE_SHAPE, PangoEngineShape))
//todo #define PANGO_IS_ENGINE_SHAPE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_ENGINE_SHAPE))
//todo #define PANGO_ENGINE_SHAPE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_ENGINE_SHAPE, PangoEngine_ShapeClass))
//todo #define PANGO_IS_ENGINE_SHAPE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_ENGINE_SHAPE))
//todo #define PANGO_ENGINE_SHAPE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_ENGINE_SHAPE, PangoEngineShapeClass))

(**
 * PangoEngineShape:
 *
 * The #PangoEngineShape class is implemented by engines that
 * customize the rendering-system dependent part of the
 * Pango pipeline for a particular script or language.
 * A #PangoEngineShape implementation is then specific to both
 * a particular rendering system or group of rendering systems
 * and to a particular script. For instance, there is one
 * #PangoEngineShape implementation to handle shaping Arabic
 * for Fontconfig-based backends.
 *
 * Deprecated: 1.38
 **)
type
  PangoEngineShape = record
    parent_instance: PangoEngine;
  end;

(**
 * PangoEngineShapeClass:
 * @script_shape: Given a font, a piece of text, and a #PangoAnalysis
 *   structure, converts characters to glyphs and positions the
 *   resulting glyphs. The results are stored in the #PangoGlyphString
 *   that is passed in. (The implementation should resize it
 *   appropriately using pango_glyph_string_set_size()). All fields
 *   of the @log_clusters and @glyphs array must be filled in, with
 *   the exception that Pango will automatically generate
 *   <literal>glyphs->glyphs[i].attr.is_cluster_start</literal>
 *   using the @log_clusters array. Each input character must occur in one
 *   of the output logical clusters;
 *   if no rendering is desired for a character, this may involve
 *   inserting glyphs with the #PangoGlyph ID #PANGO_GLYPH_EMPTY, which
 *   is guaranteed never to render. If the shaping fails for any reason,  *   the shaper should return with an empty (zero-size) glyph string.
 *   If the shaper has not set the size on the glyph string yet, simply
 *   returning signals the failure too.
 * @covers: Returns the characters that this engine can cover
 *   with a given font for a given language. If not overridden, the default
 *   implementation simply returns the coverage information for the
 *   font itself unmodified.
 *
 * Class structure for #PangoEngineShape
 *
 * Deprecated: 1.38
 **)
type
  PangoEngineShapeClass = record
    (*< private >*)
    parent_class: PangoEngineClass;
  
    (*< public >*)
    script_shape: procedure(engine: PPangoEngineShape; font: PPangoFont; const item_text: pchar; item_length: cuint; const analysis: PPangoAnalysis; glyphs: PPangoGlyphString; const paragraph_text: pchar; paragraph_length: cuint); cdecl;
    covers: function(engine: PPangoEngineShape; font: PPangoFont; language: PPangoLanguage; wc: gunichar): PangoCoverageLevel; cdecl;
  end;
  PPangoEngineShapeClass = ^PangoEngineShapeClass;

function pango_engine_shape_get_type(): GType; cdecl; external LIB_PANGO;


(**
 * PangoEngineScriptInfo:
 * @script: a #PangoScript. The value %PANGO_SCRIPT_COMMON has
 * the special meaning here of "all scripts"
 * @langs: a semicolon separated list of languages that this
 * engine handles for this script. This may be empty,  * in which case the engine is saying that it is a
 * fallback choice for all languages for this range,  * but should not be used if another engine
 * indicates that it is specific for the language for
 * a given code point. An entry in this list of "*"
 * indicates that this engine is specific to all
 * languages for this range.
 *
 * The #PangoEngineScriptInfo structure contains
 * information about how the shaper covers a particular script.
 *
 * Deprecated: 1.38
 *)
type
  PangoEngineScriptInfo = record
    script: PangoScript;
    langs: pgchar;
  end;
  PPangoEngineScriptInfo = ^PangoEngineScriptInfo;

(**
 * PangoEngineInfo:
 * @id: a unique string ID for the engine.
 * @engine_type: a string identifying the engine type.
 * @render_type: a string identifying the render type.
 * @scripts: array of scripts this engine supports.
 * @n_scripts: number of items in @scripts.
 *
 * The #PangoEngineInfo structure contains information about a particular
 * engine. It contains the following fields:
 *
 * Deprecated: 1.38
 *)
type
  PangoEngineInfo = record
    id: pgchar;
    engine_type: pgchar;
    render_type: pgchar;
    scripts: PPangoEngineScriptInfo;
    n_scripts: gint;
  end;
  PPangoEngineInfo = ^PangoEngineInfo;

(**
 * script_engine_list: (skip)
 * @engines: location to store a pointer to an array of engines.
 * @n_engines: location to store the number of elements in @engines.
 *
 * Do not use.
 *
 * Deprecated: 1.38
 **)
procedure script_engine_list(engines: PPPangoEngineInfo; n_engines: pcint); cdecl; external LIB_PANGO; deprecated;

(**
 * script_engine_init: (skip)
 * @module: a #GTypeModule structure used to associate any
 *  GObject types created in this module with the module.
 *
 * Do not use.
 *
 * Deprecated: 1.38
 **)
procedure script_engine_init(module: PGTypeModule); cdecl; external LIB_PANGO; deprecated;

(**
 * script_engine_exit: (skip)
 *
 * Do not use.
 *
 * Deprecated: 1.38
 **)
procedure script_engine_exit(); cdecl; external LIB_PANGO; deprecated;

(**
 * script_engine_create: (skip)
 * @id: the ID of an engine as reported by script_engine_list.
 *
 * Do not use.
 *
 * Deprecated: 1.38
 **)
function script_engine_create(const id: Pchar): PPangoEngine; cdecl; external LIB_PANGO; deprecated;

(* Utility macro used by PANGO_ENGINE_LANG_DEFINE_TYPE and
 * PANGO_ENGINE_LANG_DEFINE_TYPE
 *)
//todo #define PANGO_ENGINE_DEFINE_TYPE(name, prefix, class_init, instance_init, parent_type) \
//todo static GType prefix ## _type;        \
//todo static void          \
//todo prefix ## _register_type (GTypeModule *module)      \
//todo {           \
//todo   const GTypeInfo object_info =        \
//todo     {           \
//todo       sizeof (name ## Class),        \
//todo       (GBaseInitFunc) NULL,        \
//todo       (GBaseFinalizeFunc) NULL,        \
//todo       (GClassInitFunc) class_init,       \
//todo       (GClassFinalizeFunc) NULL,       \
//todo       NULL,          (* class_data *)       \
//todo       sizeof (name),         \
//todo       0,             (* n_prelocs *)       \
//todo       (GInstanceInitFunc) instance_init,      \
//todo       NULL           (* value_table *)       \
//todo     };           \
//todo            \
//todo   prefix ## _type =  g_type_module_register_type (module, parent_type,   \
//todo         # name,    \
//todo         &object_info, 0);   \
//todo }

(**
 * PANGO_ENGINE_LANG_DEFINE_TYPE:
 * @name: Name of the the type to register (for example:, <literal>ArabicEngineFc</literal>
 * @prefix: Prefix for symbols that will be defined (for example:, <literal>arabic_engine_fc</literal>
 * @class_init: (nullable): Class initialization function for the new type, or %NULL
 * @instance_init: (nullable): Instance initialization function for the new type, or %NULL
 *
 * Outputs the necessary code for GObject type registration for a
 * #PangoEngineLang class defined in a module. Two static symbols
 * are defined.
 *
 * <programlisting>
 *  static GType <replaceable>prefix</replaceable>_type;
 *  static void <replaceable>prefix</replaceable>_register_type (GTypeModule module);
 * </programlisting>
 *
 * The <function><replaceable>prefix</replaceable>_register_type()</function>
 * function should be called in your script_engine_init() function for
 * each type that your module implements, and then your script_engine_create()
 * function can create instances of the object as follows:
 *
 * <informalexample><programlisting>
 *  PangoEngine *engine = g_object_new (<replaceable>prefix</replaceable>_type, NULL);
 * </programlisting></informalexample>
 *
 * Deprecated: 1.38
 **)
//todo #define PANGO_ENGINE_LANG_DEFINE_TYPE(name, prefix, class_init, instance_init) \
//todo   PANGO_ENGINE_DEFINE_TYPE (name, prefix,    \
//todo        class_init, instance_init,   \
//todo        PANGO_TYPE_ENGINE_LANG)

(**
 * PANGO_ENGINE_SHAPE_DEFINE_TYPE:
 * @name: Name of the the type to register (for example:, <literal>ArabicEngineFc</literal>
 * @prefix: Prefix for symbols that will be defined (for example:, <literal>arabic_engine_fc</literal>
 * @class_init: (nullable): Class initialization function for the new type, or %NULL
 * @instance_init: (nullable): Instance initialization function for the new type, or %NULL
 *
 * Outputs the necessary code for GObject type registration for a
 * #PangoEngineShape class defined in a module. Two static symbols
 * are defined.
 *
 * <programlisting>
 *  static GType <replaceable>prefix</replaceable>_type;
 *  static void <replaceable>prefix</replaceable>_register_type (GTypeModule module);
 * </programlisting>
 *
 * The <function><replaceable>prefix</replaceable>_register_type()</function>
 * function should be called in your script_engine_init() function for
 * each type that your module implements, and then your script_engine_create()
 * function can create instances of the object as follows:
 *
 * <informalexample><programlisting>
 *  PangoEngine *engine = g_object_new (<replaceable>prefix</replaceable>_type, NULL);
 * </programlisting></informalexample>
 *
 * Deprecated: 1.38
 **)
//todo #define PANGO_ENGINE_SHAPE_DEFINE_TYPE(name, prefix, class_init, instance_init) \
//todo   PANGO_ENGINE_DEFINE_TYPE (name, prefix,    \
//todo        class_init, instance_init,   \
//todo        PANGO_TYPE_ENGINE_SHAPE)

(* Macro used for possibly builtin Pango modules. Not useful
 * for externally build modules. If we are compiling a module standalone,  * then we name the entry points script_engine_list, etc. But if we
 * are compiling it for inclusion directly in Pango, then we need them to
 * to have distinct names for this module, so we prepend a prefix.
 *
 * The two intermediate macros are to deal with details of the C
 * preprocessor; token pasting tokens must be function arguments,  * and macro substitution isn't used on function arguments that
 * are used for token pasting.
 *)
//todo #ifdef PANGO_MODULE_PREFIX
//todo #define PANGO_MODULE_ENTRY(func) _PANGO_MODULE_ENTRY2(PANGO_MODULE_PREFIX,func)
//todo #define _PANGO_MODULE_ENTRY2(prefix,func) _PANGO_MODULE_ENTRY3(prefix,func)
//todo #define _PANGO_MODULE_ENTRY3(prefix,func) prefix##_script_engine_##func
//todo #else
//todo #define PANGO_MODULE_ENTRY(func) script_engine_##func
//todo #endif

{$endif} (* PANGO_ENABLE_ENGINE *)

// G_END_DECLS

// #endif (* __PANGO_ENGINE_H__ *)
