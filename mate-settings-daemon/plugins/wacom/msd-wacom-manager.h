/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2007 William Jon McCann <mccann@jhu.edu>
 * Copyright (C) 2010 Red Hat, Inc.
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
 */

#ifndef __MSD_WACOM_MANAGER_H
#define __MSD_WACOM_MANAGER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MSD_TYPE_WACOM_MANAGER         (msd_wacom_manager_get_type ())
#define MSD_WACOM_MANAGER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), MSD_TYPE_WACOM_MANAGER, MsdWacomManager))
#define MSD_WACOM_MANAGER_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), MSD_TYPE_WACOM_MANAGER, MsdWacomManagerClass))
#define MSD_IS_WACOM_MANAGER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MSD_TYPE_WACOM_MANAGER))
#define MSD_IS_WACOM_MANAGER_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), MSD_TYPE_WACOM_MANAGER))
#define MSD_WACOM_MANAGER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MSD_TYPE_WACOM_MANAGER, MsdWacomManagerClass))

typedef struct MsdWacomManagerPrivate MsdWacomManagerPrivate;

typedef struct
{
        GObject                     parent;
        MsdWacomManagerPrivate *priv;
} MsdWacomManager;

typedef struct
{
        GObjectClass   parent_class;
} MsdWacomManagerClass;

GType                   msd_wacom_manager_get_type            (void);

MsdWacomManager *       msd_wacom_manager_new                 (void);
gboolean                msd_wacom_manager_start               (MsdWacomManager *manager,
                                                               GError         **error);
void                    msd_wacom_manager_stop                (MsdWacomManager *manager);

G_END_DECLS

#endif /* __MSD_WACOM_MANAGER_H */
