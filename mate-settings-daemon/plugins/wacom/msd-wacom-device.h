/*
 * Copyright (C) 2011 Red Hat, Inc.
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
 * Author: Bastien Nocera <hadess@hadess.net>
 *
 */

#ifndef __MSD_WACOM_DEVICE_MANAGER_H
#define __MSD_WACOM_DEVICE_MANAGER_H

#include <glib-object.h>
#include "msd-enums.h"

G_BEGIN_DECLS

#define NUM_ELEMS_MATRIX 9

#define MSD_TYPE_WACOM_DEVICE         (msd_wacom_device_get_type ())
#define MSD_WACOM_DEVICE(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), MSD_TYPE_WACOM_DEVICE, MsdWacomDevice))
#define MSD_WACOM_DEVICE_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), MSD_TYPE_WACOM_DEVICE, MsdWacomDeviceClass))
#define MSD_IS_WACOM_DEVICE(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MSD_TYPE_WACOM_DEVICE))
#define MSD_IS_WACOM_DEVICE_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), MSD_TYPE_WACOM_DEVICE))
#define MSD_WACOM_DEVICE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MSD_TYPE_WACOM_DEVICE, MsdWacomDeviceClass))

typedef struct MsdWacomDevicePrivate MsdWacomDevicePrivate;

typedef struct
{
        GObject                parent;
        MsdWacomDevicePrivate *priv;
} MsdWacomDevice;

typedef struct
{
        GObjectClass   parent_class;
} MsdWacomDeviceClass;

#define MSD_TYPE_WACOM_STYLUS         (msd_wacom_stylus_get_type ())
#define MSD_WACOM_STYLUS(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), MSD_TYPE_WACOM_STYLUS, MsdWacomStylus))
#define MSD_WACOM_STYLUS_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), MSD_TYPE_WACOM_STYLUS, MsdWacomStylusClass))
#define MSD_IS_WACOM_STYLUS(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MSD_TYPE_WACOM_STYLUS))
#define MSD_IS_WACOM_STYLUS_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), MSD_TYPE_WACOM_STYLUS))
#define MSD_WACOM_STYLUS_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MSD_TYPE_WACOM_STYLUS, MsdWacomStylusClass))

typedef struct MsdWacomStylusPrivate MsdWacomStylusPrivate;

typedef struct
{
        GObject                parent;
        MsdWacomStylusPrivate *priv;
} MsdWacomStylus;

typedef struct
{
        GObjectClass   parent_class;
} MsdWacomStylusClass;

typedef enum {
	WACOM_STYLUS_TYPE_UNKNOWN,
	WACOM_STYLUS_TYPE_GENERAL,
	WACOM_STYLUS_TYPE_INKING,
	WACOM_STYLUS_TYPE_AIRBRUSH,
	WACOM_STYLUS_TYPE_CLASSIC,
	WACOM_STYLUS_TYPE_MARKER,
	WACOM_STYLUS_TYPE_STROKE,
	WACOM_STYLUS_TYPE_PUCK
} MsdWacomStylusType;

GType            msd_wacom_stylus_get_type       (void);
GSettings      * msd_wacom_stylus_get_settings   (MsdWacomStylus *stylus);
const char     * msd_wacom_stylus_get_name       (MsdWacomStylus *stylus);
const char     * msd_wacom_stylus_get_icon_name  (MsdWacomStylus *stylus);
MsdWacomDevice * msd_wacom_stylus_get_device     (MsdWacomStylus *stylus);
gboolean         msd_wacom_stylus_get_has_eraser (MsdWacomStylus *stylus);
guint            msd_wacom_stylus_get_num_buttons(MsdWacomStylus *stylus);
int              msd_wacom_stylus_get_id         (MsdWacomStylus *stylus);
MsdWacomStylusType msd_wacom_stylus_get_stylus_type (MsdWacomStylus *stylus);

/* Tablet Buttons */
typedef enum {
	WACOM_TABLET_BUTTON_TYPE_NORMAL,
	WACOM_TABLET_BUTTON_TYPE_STRIP,
	WACOM_TABLET_BUTTON_TYPE_RING,
	WACOM_TABLET_BUTTON_TYPE_HARDCODED
} MsdWacomTabletButtonType;

/*
 * Positions of the buttons on the tablet in default right-handed mode
 * (ie with no rotation applied).
 */
typedef enum {
	WACOM_TABLET_BUTTON_POS_UNDEF = 0,
	WACOM_TABLET_BUTTON_POS_LEFT,
	WACOM_TABLET_BUTTON_POS_RIGHT,
	WACOM_TABLET_BUTTON_POS_TOP,
	WACOM_TABLET_BUTTON_POS_BOTTOM
} MsdWacomTabletButtonPos;

#define MAX_GROUP_ID 4

#define MSD_WACOM_NO_LED -1

typedef struct
{
	char                     *name;
	char                     *id;
	GSettings                *settings;
	MsdWacomTabletButtonType  type;
	MsdWacomTabletButtonPos   pos;
	int                       group_id, idx;
	int                       status_led;
	int                       has_oled;
} MsdWacomTabletButton;

void                  msd_wacom_tablet_button_free (MsdWacomTabletButton *button);
MsdWacomTabletButton *msd_wacom_tablet_button_copy (MsdWacomTabletButton *button);

/* Device types to apply a setting to */
typedef enum {
	WACOM_TYPE_INVALID =     0,
        WACOM_TYPE_STYLUS  =     (1 << 1),
        WACOM_TYPE_ERASER  =     (1 << 2),
        WACOM_TYPE_CURSOR  =     (1 << 3),
        WACOM_TYPE_PAD     =     (1 << 4),
        WACOM_TYPE_TOUCH   =     (1 << 5),
        WACOM_TYPE_ALL     =     WACOM_TYPE_STYLUS | WACOM_TYPE_ERASER | WACOM_TYPE_CURSOR | WACOM_TYPE_PAD | WACOM_TYPE_TOUCH
} MsdWacomDeviceType;

/* We use -1 for entire screen when setting/getting monitor value */
#define MSD_WACOM_SET_ALL_MONITORS -1

GType msd_wacom_device_get_type     (void);

void     msd_wacom_device_set_display         (MsdWacomDevice    *device,
                                               int                monitor);
gint     msd_wacom_device_get_display_monitor (MsdWacomDevice *device);
gboolean msd_wacom_device_get_display_matrix  (MsdWacomDevice *device,
                                               float           matrix[NUM_ELEMS_MATRIX]);
MsdWacomRotation msd_wacom_device_get_display_rotation (MsdWacomDevice *device);

MsdWacomDevice * msd_wacom_device_new              (GdkDevice *device);
GList          * msd_wacom_device_list_styli       (MsdWacomDevice *device);
const char     * msd_wacom_device_get_name         (MsdWacomDevice *device);
const char     * msd_wacom_device_get_layout_path  (MsdWacomDevice *device);
const char     * msd_wacom_device_get_path         (MsdWacomDevice *device);
const char     * msd_wacom_device_get_icon_name    (MsdWacomDevice *device);
const char     * msd_wacom_device_get_tool_name    (MsdWacomDevice *device);
gboolean         msd_wacom_device_reversible       (MsdWacomDevice *device);
gboolean         msd_wacom_device_is_screen_tablet (MsdWacomDevice *device);
gboolean         msd_wacom_device_is_isd           (MsdWacomDevice *device);
gboolean         msd_wacom_device_is_fallback      (MsdWacomDevice *device);
gint             msd_wacom_device_get_num_strips   (MsdWacomDevice *device);
gint             msd_wacom_device_get_num_rings    (MsdWacomDevice *device);
GSettings      * msd_wacom_device_get_settings     (MsdWacomDevice *device);
void             msd_wacom_device_set_current_stylus (MsdWacomDevice *device,
						      int             stylus_id);
MsdWacomStylus * msd_wacom_device_get_stylus_for_type (MsdWacomDevice     *device,
						       MsdWacomStylusType  type);

MsdWacomDeviceType msd_wacom_device_get_device_type (MsdWacomDevice *device);
gint           * msd_wacom_device_get_area          (MsdWacomDevice *device);
gint           * msd_wacom_device_get_default_area  (MsdWacomDevice *device);
const char     * msd_wacom_device_type_to_string    (MsdWacomDeviceType type);
GList          * msd_wacom_device_get_buttons       (MsdWacomDevice *device);
MsdWacomTabletButton *msd_wacom_device_get_button   (MsdWacomDevice   *device,
						     int               button,
						     GtkDirectionType *dir);
int msd_wacom_device_get_num_modes                  (MsdWacomDevice   *device,
						     int               group_id);
int msd_wacom_device_get_current_mode               (MsdWacomDevice   *device,
						     int               group_id);
int msd_wacom_device_set_next_mode                  (MsdWacomDevice       *device,
						     MsdWacomTabletButton *button);
MsdWacomRotation msd_wacom_device_rotation_name_to_type (const char *rotation);
const char     * msd_wacom_device_rotation_type_to_name (MsdWacomRotation type);


/* Helper and debug functions */
MsdWacomDevice * msd_wacom_device_create_fake (MsdWacomDeviceType  type,
					       const char         *name,
					       const char         *tool_name);

GList * msd_wacom_device_create_fake_cintiq   (void);
GList * msd_wacom_device_create_fake_bt       (void);
GList * msd_wacom_device_create_fake_x201     (void);
GList * msd_wacom_device_create_fake_intuos4  (void);

G_END_DECLS

#endif /* __MSD_WACOM_DEVICE_MANAGER_H */
