/****************************************************************************
** Form interface generated from reading ui file 'src/tbmainwindow.ui'
**
** Created: Thu May 19 12:07:24 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TBMAINWINDOW_H
#define TBMAINWINDOW_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QPushButton;
class QTabWidget;
class QWidget;
class QListView;
class QListViewItem;
class QLabel;
class QProgressBar;

class tbMainWindow : public QDialog
{
    Q_OBJECT

public:
    tbMainWindow( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~tbMainWindow();

    QLineEdit* tbMainWindowSearchTextField;
    QPushButton* tbMainWindowSearchButton;
    QPushButton* tbMainWindowCancelButton;
    QTabWidget* tabWidget;
    QWidget* Widget8;
    QListView* tbMainWindowResultsListView;
    QWidget* Widget9;
    QLabel* textLabel1_2;
    QLabel* textLabel1;
    QProgressBar* tbMainWindowProgressBar;

public slots:
    virtual void tbMainWindowSearchButton_clicked();
    virtual void tbMainWindowCancelButton_clicked();

protected:
    QGridLayout* tbMainWindowLayout;
    QHBoxLayout* layout5;
    QGridLayout* Widget8Layout;

protected slots:
    virtual void languageChange();

};

#endif // TBMAINWINDOW_H
