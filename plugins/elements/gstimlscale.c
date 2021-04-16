#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstimlscale.h"
#include "../../gst/gst-i18n-lib.h"

GST_DEBUG_CATEGORY_STATIC (gst_myfilter_debug);
#define GST_IMLSCALE_DEFAULT gst_myfilter_debug

#define _do_init \
    GST_DEBUG_CATEGORY_INIT (gst_myfilter_debug, "myfilter", 0, \
    "imlscaler element");
#define gst_capsfilter_parent_class parent_class

G_DEFINE_TYPE_WITH_CODE (GstMyFilter, gst_my_filter, GST_TYPE_ELEMENT,
    _do_init);

static GstFlowReturn gst_my_filter_chain (GstPad *pad, GstObject *parent, GstBuffer *buf);


static GstStaticPadTemplate sinktemplate = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);

static GstStaticPadTemplate srctemplate = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);


static void
gst_my_filter_class_init (GstMyFilterClass * klass)
{

  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);


  gst_element_class_add_static_pad_template (element_class, &srctemplate);
  gst_element_class_add_static_pad_template (element_class, &sinktemplate);

  gst_element_class_set_static_metadata (element_class,
    "An example plugin",
    "Example/FirstExample",
    "Shows the basic structure of a plugin",
    "your name <your.name@your.isp>");

  /* configure event function on the pad before adding
   * the pad to the element */
  //gst_pad_set_event_function (filter->sinkpad, gst_my_filter_sink_event);

}


static gboolean
plugin_init (GstPlugin *plugin)
{
  return gst_element_register(plugin, "my_filter", GST_RANK_NONE, GST_TYPE_MY_FILTER);
  //return GST_ELEMENT_REGISTER (my_filter, plugin);
}


GST_PLUGIN_DEFINE (
  GST_VERSION_MAJOR,
  GST_VERSION_MINOR,
  my_filter,
  "My filter plugin",
  plugin_init,
  VERSION,
  "LGPL",
  "GStreamer",
  "http://gstreamer.net/"
)

static void
gst_my_filter_init (GstMyFilter *filter)
{
  /* pad through which data comes in to the element */
  filter->sinkpad = gst_pad_new_from_static_template (
    &sinktemplate, "sink");
  /* pads are configured here with gst_pad_set_*_function () */



  gst_element_add_pad (GST_ELEMENT (filter), filter->sinkpad);

  /* pad through which data goes out of the element */
  filter->srcpad = gst_pad_new_from_static_template (
    &srctemplate, "src");
  /* pads are configured here with gst_pad_set_*_function () */


  gst_element_add_pad (GST_ELEMENT (filter), filter->srcpad);

  /* properties initial value */
  filter->silent = FALSE;

  gst_pad_set_chain_function (filter->sinkpad, gst_my_filter_chain);
}

static GstFlowReturn
gst_my_filter_chain (GstPad    *pad,
             GstObject *parent,
             GstBuffer *buf)
{
  GstMyFilter *filter = GST_MY_FILTER (parent);
  
  if(!filter->silent)
     g_print("Have data of size %"G_GSIZE_FORMAT"bytes!\n", gst_buffer_get_size(buf));

  return gst_pad_push(filter->srcpad, buf);
}




