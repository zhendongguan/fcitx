/***************************************************************************
 *   Copyright (C) 2011~2012 by CSSlayer                                   *
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

#include <QInputContextPlugin>
#include <QDBusConnection>
#include "fcitx-input-context.h"

/* The class Definition */
class FcitxPlugin: public QInputContextPlugin
{

private:
    /**
     * The language list for Fcitx.
     */
    static QStringList fcitx_languages;

public:

    FcitxPlugin(QObject *parent = 0);

    ~FcitxPlugin();

    QStringList keys() const;

    QStringList languages(const QString &key);

    QString description(const QString &key);

    QInputContext *create(const QString &key);

    QString displayName(const QString &key);

private:
};


/* Implementations */
QStringList FcitxPlugin::fcitx_languages;


FcitxPlugin::FcitxPlugin(QObject *parent)
    : QInputContextPlugin(parent)
{
}


FcitxPlugin::~FcitxPlugin()
{
}

QStringList
FcitxPlugin::keys() const
{
    QStringList identifiers;
    identifiers.push_back(FCITX_IDENTIFIER_NAME);
    return identifiers;
}


QStringList
FcitxPlugin::languages(const QString & key)
{
    if (key.toLower() != FCITX_IDENTIFIER_NAME) {
        return QStringList();
    }

    if (fcitx_languages.empty()) {
        fcitx_languages.push_back("zh");
        fcitx_languages.push_back("ja");
        fcitx_languages.push_back("ko");
    }
    return fcitx_languages;
}


QString
FcitxPlugin::description(const QString &key)
{
    if (key.toLower() != FCITX_IDENTIFIER_NAME) {
        return QString("");
    }

    return QString::fromUtf8("Qt immodule plugin for Fcitx");
}


QInputContext *
FcitxPlugin::create(const QString &key)
{
    if (key.toLower() != FCITX_IDENTIFIER_NAME) {
        return NULL;
    }

    return static_cast<QInputContext *>(new QFcitxInputContext());
}


QString FcitxPlugin::displayName(const QString &key)
{
    return key;
}

Q_EXPORT_PLUGIN2(FcitxPlugin, FcitxPlugin)

// kate: indent-mode cstyle; space-indent on; indent-width 0;
