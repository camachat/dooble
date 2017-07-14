/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef dooble_page_h
#define dooble_page_h

#include <QWidget>

#include "ui_dooble_page.h"

class dooble_web_engine_view;

class dooble_page: public QWidget
{
  Q_OBJECT

 public:
  dooble_page(QWidget *parent);

 private:
  enum ConstantsEnum
  {
    MAXIMUM_HISTORY_ITEMS = 20
  };

  Ui_dooble_page m_ui;
  dooble_web_engine_view *m_view;
  void load_page(const QUrl &url);
  void prepare_icons(void);

 private slots:
  void slot_go_backward(void);
  void slot_go_forward(void);
  void slot_load_finished(bool ok);
  void slot_load_page(void);
  void slot_load_progress(int progress);
  void slot_open_url(void);
  void slot_prepare_backward_menu(void);
  void slot_prepare_forward_menu(void);
  void slot_prepare_standard_menus(void);
  void slot_url_changed(const QUrl &url);

 signals:
  void close_tab(void);
  void iconChanged(const QIcon &icon);
  void loadFinished(bool ok);
  void loadStarted(void);
  void new_tab(void);
  void new_window(void);
  void quit_dooble(void);
  void titleChanged(const QString &title);
};

#endif
