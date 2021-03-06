/***************************************************************************
 *   Copyright (C) 2012~2012 by CSSlayer                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef CLIENT_IM_H
#define CLIENT_IM_H


#include <gio/gio.h>
#include "fcitx/ime.h"
#include "fcitx/frontend.h"

G_BEGIN_DECLS

typedef struct _FcitxClient        FcitxClient;
typedef struct _FcitxClientClass   FcitxClientClass;

#define FCITX_TYPE_CLIENT         (fcitx_client_get_type ())
#define FCITX_CLIENT(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), FCITX_TYPE_CLIENT, FcitxClient))
#define FCITX_CLIENT_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), FCITX_TYPE_CLIENT, FcitxClientClass))
#define FCITX_CLIENT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), FCITX_TYPE_CLIENT, FcitxClientClass))


typedef struct _FcitxPreeditItem {
    gchar* string;
    gint32 type;
} FcitxPreeditItem;

struct _FcitxClient {
    GObject parent_instance;
    GDBusProxy* improxy;
    GDBusProxy* icproxy;
    char servicename[64];
    char icname[64];
    int id;
    guint watch_id;
    GCancellable* cancellable;
};

struct _FcitxClientClass {
    GObjectClass parent_class;
};

typedef struct _FcitxIMItem {
    gchar* name;
    gchar* unique_name;
    gchar* langcode;
    gboolean enable;
} FcitxIMItem;


FcitxClient* fcitx_client_new();
gboolean fcitx_client_is_valid(FcitxClient* im);
int fcitx_client_process_key_sync(FcitxClient* im, guint32 keyval, guint32 keycode, guint32 state, FcitxKeyEventType type, guint32 t);
void fcitx_client_process_key(FcitxClient* im, GAsyncReadyCallback cb, gpointer user_data, guint32 keyval, guint32 keycode, guint32 state, FcitxKeyEventType type, guint32 t);

void fcitx_client_focusin(FcitxClient* im);
void fcitx_client_focusout(FcitxClient* im);
void fcitx_client_set_cusor_rect(FcitxClient* im, int x, int y, int w, int h);
void fcitx_client_set_surrounding_text(FcitxClient* im, gchar* text, guint cursor, guint anchor);
void fcitx_client_set_capacity(FcitxClient* im, FcitxCapacityFlags flags);
void fcitx_client_reset(FcitxClient* im);

GType        fcitx_client_get_type(void) G_GNUC_CONST;

G_END_DECLS

#endif //CLIENT_IM_H
