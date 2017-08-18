//
// pango-decoder.h header binding for the Free Pascal Compiler aka FPC
//
// Binaries and demos available at http://www.djmaster.com/
//

(* Pango
 * pangofc-decoder.h: Custom encoders/decoders on a per-font basis.
 *
 * Copyright (C) 2004 Red Hat Software
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

// #ifndef __PANGO_DECODER_H_
// #define __PANGO_DECODER_H_

// #include <pango/pangofc-font.h>

// G_BEGIN_DECLS

//todo #define PANGO_TYPE_FC_DECODER       (pango_fc_decoder_get_type())
//todo #define PANGO_FC_DECODER(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_FC_DECODER, PangoFcDecoder))
//todo #define PANGO_IS_FC_DECODER(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), PANGO_TYPE_FC_DECODER))

//todo #define PANGO_FC_DECODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_FC_DECODER, PangoFcDecoderClass))
//todo #define PANGO_IS_FC_DECODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_FC_DECODER))
//todo #define PANGO_FC_DECODER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_FC_DECODER, PangoFcDecoderClass))

(**
 * PangoFcDecoder:
 *
 * #PangoFcDecoder is a virtual base class that implementations will
 * inherit from.  It's the interface that is used to define a custom
 * encoding for a font.  These objects are created in your code from a
 * function callback that was originally registered with
 * pango_fc_font_map_add_decoder_find_func().  Pango requires
 * information about the supported charset for a font as well as the
 * individual character to glyph conversions.  Pango gets that
 * information via the #get_charset and #get_glyph callbacks into your
 * object implementation.
 *
 * Since: 1.6
 **)
type
  PangoFcDecoder = record
    (*< private >*)
    parent_instance: GObject;
  end;
  PPangoFcDecoder = ^PangoFcDecoder;

(**
 * PangoFcDecoderClass:
 * @get_charset: This returns an #FcCharset given a #PangoFcFont that
 *  includes a list of supported characters in the font.  The
 *  #FcCharSet that is returned should be an internal reference to your
 *  code.  Pango will not free this structure.  It is important that
 *  you make this callback fast because this callback is called
 *  separately for each character to determine Unicode coverage.
 * @get_glyph: This returns a single #PangoGlyph for a given Unicode
 *  code point.
 *
 * Class structure for #PangoFcDecoder.
 *
 * Since: 1.6
 **)
type
  get_charset_func = function (decoder: PPangoFcDecoder; fcfont: PPangoFcFont): PFcCharSet; cdecl;
  get_glyph_func = function (decoder: PPangoFcDecoder; fcfont: PPangoFcFont; wc: guint32): PangoGlyph; cdecl;
  pango_reserved_func = procedure(); cdecl;
  PangoFcDecoderClass = record
    (*< private >*)
    parent_class: GObjectClass;
  
    (* vtable - not signals *)
    (*< public >*)
    get_charset: get_charset_func;
    get_glyph: get_glyph_func;
  
    (*< private >*)
  
    (* Padding for future expansion *)
    pango_reserved1: pango_reserved_func;
    pango_reserved2: pango_reserved_func;
    pango_reserved3: pango_reserved_func;
    pango_reserved4: pango_reserved_func;
  end;
  PPangoFcDecoderClass = ^PangoFcDecoderClass;

function pango_fc_decoder_get_type(): GType; cdecl; external LIB_PANGO;

function pango_fc_decoder_get_charset(decoder: PPangoFcDecoder; fcfont: PPangoFcFont): PFcCharSet; cdecl; external LIB_PANGO;

function pango_fc_decoder_get_glyph(decoder: PPangoFcDecoder; fcfont: PPangoFcFont; wc: guint32): PangoGlyph; cdecl; external LIB_PANGO;

// G_END_DECLS

// #endif (* __PANGO_DECODER_H_ *)

