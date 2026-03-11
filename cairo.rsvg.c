#include <librsvg/rsvg.h>
#include <cairo.h>

int cairo_fixlang_rsvg_render_svg(
    cairo_t *cr,
    const char *svg_data,
    double x, double y
)
{
    GError *error = NULL;
    RsvgHandle *handle = rsvg_handle_new_from_data(
        (const guint8 *)svg_data, strlen(svg_data), &error
    );
    if (!handle) {
        if (error) g_error_free(error);
        return 0;
    }

    RsvgRectangle viewport;
    double width, height;
    if (!rsvg_handle_get_intrinsic_size_in_pixels(handle, &width, &height)) {
        /* Fall back to a default viewport if intrinsic size is unavailable. */
        viewport.x = x;
        viewport.y = y;
        viewport.width = 0;
        viewport.height = 0;
    } else {
        viewport.x = x;
        viewport.y = y;
        viewport.width = width;
        viewport.height = height;
    }

    gboolean ok = rsvg_handle_render_document(handle, cr, &viewport, &error);
    g_object_unref(handle);

    if (!ok) {
        if (error) g_error_free(error);
        return 0;
    }

    return 1;
}

int cairo_fixlang_rsvg_get_intrinsic_size(
    const char *svg_data,
    double *width, double *height
)
{
    GError *error = NULL;
    RsvgHandle *handle = rsvg_handle_new_from_data(
        (const guint8 *)svg_data, strlen(svg_data), &error
    );
    if (!handle) {
        if (error) g_error_free(error);
        return 0;
    }

    gboolean ok = rsvg_handle_get_intrinsic_size_in_pixels(handle, width, height);
    g_object_unref(handle);

    return ok ? 1 : 0;
}
