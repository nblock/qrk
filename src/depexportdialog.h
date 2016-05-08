/*
 * This file is part of QRK - Qt Registrier Kasse
 *
 * Copyright (C) 2015-2016 Christian Kvasny <chris@ckvsoft.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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
 * Button Design, and Idea for the Layout are lean out from LillePOS, Copyright 2010, Martin Koller, kollix@aon.at
 *
*/

#ifndef DEPEXPORTDIALOG_H
#define DEPEXPORTDIALOG_H

#include <QDialog>
#include <QProgressBar>

class QFile;

namespace Ui {
  class DepExportDialog;
}

class DepExportDialog : public QDialog
{
    Q_OBJECT

  public:
    DepExportDialog(QWidget *parent = 0, QProgressBar *progressbar = 0);
    ~DepExportDialog();

  private slots:
    void onCancelButton_clicked();
    void onDateEditTo_dateChanged(const QDate &date);
    void onDateEditFrom_dateChanged(const QDate &date);

    void onExportButton_clicked();

  private:
    Ui::DepExportDialog *ui;
    bool depExport(QFile *outfile);

    QDateTime *fromDT;
    QDateTime *toDT;
    QProgressBar *progressbar;

};

#endif // DEPEXPORTDIALOG_H