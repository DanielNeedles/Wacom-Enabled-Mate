/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2013 Przemo Firszt <przemo@firszt.eu>
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

#include "msd-wacom-oled-constants.h"

#ifndef __MSD_WACOM_OLED_H
#define __MSD_WACOM_OLED_H

G_BEGIN_DECLS

void set_oled (MsdWacomDevice *device, char *button_id, char *label);
char *msd_wacom_oled_gdkpixbuf_to_base64 (GdkPixbuf *pixbuf);

G_END_DECLS

#endif /* __MSD_WACOM_OLED_H */
