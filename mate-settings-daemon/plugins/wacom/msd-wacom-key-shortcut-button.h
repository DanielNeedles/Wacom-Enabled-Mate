/*
 * msd-wacom-key-shortcut-button.h
 *
 * Copyright © 2013 Red Hat, Inc.
 *
 * Author: Joaquim Rocha <jrocha@redhat.com>
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
 */

#ifndef __MSD_WACOM_KEY_SHORTCUT_BUTTON_H__
#define __MSD_WACOM_KEY_SHORTCUT_BUTTON_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON            (msd_wacom_key_shortcut_button_get_type ())
#define MSD_WACOM_KEY_SHORTCUT_BUTTON(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON, MsdWacomKeyShortcutButton))
#define MSD_WACOM_IS_KEY_SHORTCUT_BUTTON(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON))
#define MSD_WACOM_KEY_SHORTCUT_BUTTON_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON, MsdWacomKeyShortcutButtonClass))
#define MSD_WACOM_IS_KEY_SHORTCUT_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON))
#define MSD_WACOM_KEY_SHORTCUT_BUTTON_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON, MsdWacomKeyShortcutButtonClass))

typedef struct _MsdWacomKeyShortcutButton        MsdWacomKeyShortcutButton;
typedef struct _MsdWacomKeyShortcutButtonClass   MsdWacomKeyShortcutButtonClass;
typedef struct _MsdWacomKeyShortcutButtonPrivate MsdWacomKeyShortcutButtonPrivate;

GType msd_wacom_key_shortcut_button_mode_type (void) G_GNUC_CONST;
#define MSD_WACOM_TYPE_KEY_SHORTCUT_BUTTON_MODE (msd_wacom_key_shortcut_button_mode_type())

typedef enum
{
  MSD_WACOM_KEY_SHORTCUT_BUTTON_MODE_OTHER,
  MSD_WACOM_KEY_SHORTCUT_BUTTON_MODE_ALL
} MsdWacomKeyShortcutButtonMode;

struct _MsdWacomKeyShortcutButton
{
  GtkButton parent_instance;

  /*< private >*/
  MsdWacomKeyShortcutButtonPrivate *priv;
};

struct _MsdWacomKeyShortcutButtonClass
{
  GtkButtonClass parent_class;

  void (* key_shortcut_edited)  (MsdWacomKeyShortcutButton *key_shortcut_button);

  void (* key_shortcut_cleared) (MsdWacomKeyShortcutButton *key_shortcut_button);
};

GType          msd_wacom_key_shortcut_button_get_type        (void) G_GNUC_CONST;
GtkWidget    * msd_wacom_key_shortcut_button_new             (void);

#endif /* __MSD_WACOM_KEY_SHORTCUT_BUTTON_H__ */
