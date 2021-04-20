/* GStreamer
 * Copyright (C) 2021 FIXME <fixme@example.com>
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef _GST_IMLSCALE_H_
#define _GST_IMLSCALE_H_

#include <gst/video/video.h>
#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS

#define GST_TYPE_IMLSCALE   (gst_imlscale_get_type())
#define GST_IMLSCALE(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_IMLSCALE,GstImlscale))
#define GST_IMLSCALE_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_IMLSCALE,GstImlscaleClass))
#define GST_IS_IMLSCALE(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_IMLSCALE))
#define GST_IS_IMLSCALE_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_IMLSCALE))

typedef struct _GstImlscale GstImlscale;
typedef struct _GstImlscaleClass GstImlscaleClass;

struct _GstImlscale
{
  GstVideoFilter base_imlscale;

};

struct _GstImlscaleClass
{
  GstVideoFilterClass base_imlscale_class;
};

GType gst_imlscale_get_type (void);

G_END_DECLS

#endif
