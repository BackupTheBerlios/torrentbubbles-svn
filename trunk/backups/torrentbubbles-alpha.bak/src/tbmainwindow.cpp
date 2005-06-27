/****************************************************************************
** Form implementation generated from reading ui file 'src/tbmainwindow.ui'
**
** Created: Tue Jun 7 12:41:36 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "tbmainwindow.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlabel.h>
#include <qprogressbar.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a tbMainWindow as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
tbMainWindow::tbMainWindow( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "tbMainWindow" );
    setSizeGripEnabled( TRUE );
    tbMainWindowLayout = new QGridLayout( this, 1, 1, 11, 6, "tbMainWindowLayout"); 

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    tbMainWindowSearchTextField = new QLineEdit( this, "tbMainWindowSearchTextField" );
    layout5->addWidget( tbMainWindowSearchTextField );

    tbMainWindowSearchButton = new QPushButton( this, "tbMainWindowSearchButton" );
    tbMainWindowSearchButton->setAutoDefault( TRUE );
    tbMainWindowSearchButton->setDefault( TRUE );
    layout5->addWidget( tbMainWindowSearchButton );

    tbMainWindowCancelButton = new QPushButton( this, "tbMainWindowCancelButton" );
    tbMainWindowCancelButton->setEnabled( FALSE );
    tbMainWindowCancelButton->setToggleButton( FALSE );
    tbMainWindowCancelButton->setAutoDefault( TRUE );
    tbMainWindowCancelButton->setDefault( TRUE );
    layout5->addWidget( tbMainWindowCancelButton );

    tbMainWindowLayout->addLayout( layout5, 0, 0 );

    tabWidget = new QTabWidget( this, "tabWidget" );

    Widget8 = new QWidget( tabWidget, "Widget8" );
    Widget8Layout = new QGridLayout( Widget8, 1, 1, 11, 6, "Widget8Layout"); 

    tbMainWindowResultsListView = new QListView( Widget8, "tbMainWindowResultsListView" );
    tbMainWindowResultsListView->addColumn( tr( "Name" ) );
    tbMainWindowResultsListView->addColumn( tr( "Size" ) );
    tbMainWindowResultsListView->addColumn( tr( "Seeders" ) );
    tbMainWindowResultsListView->addColumn( tr( "Leechers" ) );
    tbMainWindowResultsListView->addColumn( tr( "Link" ) );
    tbMainWindowResultsListView->setResizePolicy( QListView::AutoOneFit );

    Widget8Layout->addWidget( tbMainWindowResultsListView, 0, 0 );
    tabWidget->insertTab( Widget8, QString::fromLatin1("") );

    Widget9 = new QWidget( tabWidget, "Widget9" );

    textLabel1 = new QLabel( Widget9, "textLabel1" );
    textLabel1->setGeometry( QRect( 160, 100, 137, 110 ) );
    tabWidget->insertTab( Widget9, QString::fromLatin1("") );

    tbMainWindowLayout->addWidget( tabWidget, 1, 0 );

    tbMainWindowProgressBar = new QProgressBar( this, "tbMainWindowProgressBar" );

    tbMainWindowLayout->addWidget( tbMainWindowProgressBar, 2, 0 );
    languageChange();
    resize( QSize(593, 555).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( tbMainWindowSearchButton, SIGNAL( clicked() ), this, SLOT( tbMainWindowSearchButton_clicked() ) );
    connect( tbMainWindowCancelButton, SIGNAL( clicked() ), this, SLOT( tbMainWindowCancelButton_clicked() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
tbMainWindow::~tbMainWindow()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void tbMainWindow::languageChange()
{
    setCaption( tr( "Torrent Bubbles" ) );
    tbMainWindowSearchTextField->setText( tr( "linux" ) );
    tbMainWindowSearchButton->setText( tr( "&Search" ) );
    tbMainWindowSearchButton->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    tbMainWindowCancelButton->setText( tr( "Ca&ncel" ) );
    tbMainWindowCancelButton->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    tbMainWindowResultsListView->header()->setLabel( 0, tr( "Name" ) );
    tbMainWindowResultsListView->header()->setLabel( 1, tr( "Size" ) );
    tbMainWindowResultsListView->header()->setLabel( 2, tr( "Seeders" ) );
    tbMainWindowResultsListView->header()->setLabel( 3, tr( "Leechers" ) );
    tbMainWindowResultsListView->header()->setLabel( 4, tr( "Link" ) );
    tabWidget->changeTab( Widget8, tr( "Search" ) );
    textLabel1->setText( trUtf8( "\x3c\x62\x3e\x4a\x65\x73\x70\x65\x72\x20\x54\x68\x6f\x6d\x73\x63\x68\xc3\xbc\x74\x7a\x3c\x2f\x62\x3e\xa\x3c\x62\x72\x3e\x3c\x62\x72\x3e\xa\x65\x76\x69\x6c\x68\x61\x78\x30\x72\x40\x67\x6d\x61\x69\x6c\x2e\x63\x6f\x6d\xa\x3c\x62\x72\x3e\x3c\x62\x72\x3e\xa\x3a\x29" ) );
    tabWidget->changeTab( Widget9, tr( "&Authors" ) );
}

void tbMainWindow::tbMainWindowSearchButton_clicked()
{
    qWarning( "tbMainWindow::tbMainWindowSearchButton_clicked(): Not implemented yet" );
}

void tbMainWindow::tbMainWindowCancelButton_clicked()
{
    qWarning( "tbMainWindow::tbMainWindowCancelButton_clicked(): Not implemented yet" );
}

