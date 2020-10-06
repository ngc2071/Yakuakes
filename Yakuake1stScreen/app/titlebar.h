/*
  Copyright (C) 2008-2014 by Eike Hein <hein@kde.org>
  Copyright (C) 2020 by Ryan McCoskrie <work@ryanmccoskrie.me>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of
  the License or (at your option) version 3 or any later version
  accepted by the membership of KDE e.V. (or its successor appro-
  ved by the membership of KDE e.V.), which shall act as a proxy
  defined in Section 14 of version 3 of the license.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see https://www.gnu.org/licenses/.
*/


#ifndef TITLEBAR_H
#define TITLEBAR_H


#include <QWidget>
#include <QMouseEvent>


class MainWindow;
class Skin;

class QPushButton;


class TitleBar : public QWidget
{
    Q_OBJECT

    public:
        explicit TitleBar(MainWindow* mainWindow);
        ~TitleBar();

        void applySkin();
        void updateMask();
        void updateMenu();

        QString title();

        void setFocusButtonState(bool checked);


    public Q_SLOTS:
        void setTitle(const QString& title);


    protected:
        void resizeEvent(QResizeEvent*) override;
        void paintEvent(QPaintEvent*) override;
        void mouseMoveEvent(QMouseEvent*) override;


    private:
        void moveButtons();

        MainWindow* m_mainWindow;
        Skin* m_skin;

        QPushButton* m_focusButton;
        QPushButton* m_menuButton;
        QPushButton* m_quitButton;

        QString m_title;
};

#endif
