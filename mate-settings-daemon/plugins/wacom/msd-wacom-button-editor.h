/*
 * Copyright © 2013 Red Hat, Inc.
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
 * Author: Joaquim Rocha <jrocha@redhat.com>
 */

#ifndef __MSD_WACOM_BUTTON_EDITOR_H__
#define __MSD_WACOM_BUTTON_EDITOR_H__

#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MSD_WACOM_BUTTON_EDITOR_TYPE            (msd_wacom_button_editor_get_type ())
#define MSD_WACOM_BUTTON_EDITOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MSD_WACOM_BUTTON_EDITOR_TYPE, MsdWacomButtonEditor))
#define MSD_WACOM_IS_BUTTON_EDITOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MSD_WACOM_BUTTON_EDITOR_TYPE))
#define MSD_WACOM_BUTTON_EDITOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MSD_WACOM_BUTTON_EDITOR_TYPE, MsdWacomButtonEditorClass))
#define MSD_WACOM_IS_BUTTON_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MSD_WACOM_BUTTON_EDITOR_TYPE))
#define MSD_WACOM_BUTTON_EDITOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MSD_WACOM_BUTTON_EDITOR_TYPE, MsdWacomButtonEditorClass))

typedef struct _MsdWacomButtonEditor      MsdWacomButtonEditor;
typedef struct _MsdWacomButtonEditorClass MsdWacomButtonEditorClass;
typedef struct _MsdWacomButtonEditorPrivate MsdWacomButtonEditorPrivate;


struct _MsdWacomButtonEditor
{
  GtkGrid parent_instance;

  /*< private >*/
  MsdWacomButtonEditorPrivate *priv;
};

struct _MsdWacomButtonEditorClass
{
  GtkGridClass parent_class;

  void (* button_edited) (void);
  void (* done_editing) (void);
};

GtkWidget    * msd_wacom_button_editor_new      (void);

void           msd_wacom_button_editor_set_button (MsdWacomButtonEditor *self,
                                                   MsdWacomTabletButton *button,
                                                   GtkDirectionType      direction);

MsdWacomTabletButton * msd_wacom_button_editor_get_button (MsdWacomButtonEditor *self,
                                                           GtkDirectionType     *direction);


GType          msd_wacom_button_editor_get_type (void);

#endif /* __MSD_WACOM_BUTTON_EDITOR_H__ */
