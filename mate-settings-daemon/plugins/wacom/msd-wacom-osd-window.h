/*
 * Copyright (C) 2012 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Olivier Fourdan <ofourdan@redhat.com>
 *
 */

#ifndef __MSD_WACOM_OSD_WINDOW_H
#define __MSD_WACOM_OSD_WINDOW_H

#include <gtk/gtk.h>
#include <glib-object.h>
#include "msd-wacom-device.h"

#define MSD_TYPE_WACOM_OSD_WINDOW         (msd_wacom_osd_window_get_type ())
#define MSD_WACOM_OSD_WINDOW(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), MSD_TYPE_WACOM_OSD_WINDOW, MsdWacomOSDWindow))
#define MSD_WACOM_OSD_WINDOW_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), MSD_TYPE_WACOM_OSD_WINDOW, MsdWacomOSDWindowClass))
#define MSD_IS_WACOM_OSD_WINDOW(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MSD_TYPE_WACOM_OSD_WINDOW))
#define MSD_IS_WACOM_OSD_WINDOW_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), MSD_TYPE_WACOM_OSD_WINDOW))
#define MSD_WACOM_OSD_WINDOW_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MSD_TYPE_WACOM_OSD_WINDOW, MsdWacomOSDWindowClass))

typedef struct MsdWacomOSDWindowPrivate MsdWacomOSDWindowPrivate;

typedef struct
{
        GtkWindow                 window;
        MsdWacomOSDWindowPrivate *priv;
} MsdWacomOSDWindow;

typedef struct
{
        GtkWindowClass            parent_class;
} MsdWacomOSDWindowClass;

GType                     msd_wacom_osd_window_get_type        (void) G_GNUC_CONST;
MsdWacomDevice *          msd_wacom_osd_window_get_device      (MsdWacomOSDWindow        *osd_window);
void                      msd_wacom_osd_window_set_message     (MsdWacomOSDWindow        *osd_window,
                                                                const gchar              *str);
const char *              msd_wacom_osd_window_get_message     (MsdWacomOSDWindow        *osd_window);
void                      msd_wacom_osd_window_set_active      (MsdWacomOSDWindow        *osd_window,
                                                                MsdWacomTabletButton     *button,
                                                                GtkDirectionType          dir,
                                                                gboolean                  active);
void                      msd_wacom_osd_window_set_mode        (MsdWacomOSDWindow        *osd_window,
                                                                gint                      group_id,
                                                                gint                      mode);
gboolean                  msd_wacom_osd_window_get_edition_mode (MsdWacomOSDWindow        *osd_window);
void                      msd_wacom_osd_window_set_edition_mode (MsdWacomOSDWindow        *osd_window,
                                                                 gboolean                  edition_mode);
GtkWidget *               msd_wacom_osd_window_new             (MsdWacomDevice           *pad,
                                                                const gchar              *message);

#endif /* __MSD_WACOM_OSD_WINDOW_H */
