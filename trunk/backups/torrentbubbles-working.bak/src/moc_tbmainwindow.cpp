/****************************************************************************
** tbMainWindow meta object code from reading C++ file 'tbmainwindow.h'
**
** Created: Mon May 23 20:03:12 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "tbmainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *tbMainWindow::className() const
{
    return "tbMainWindow";
}

QMetaObject *tbMainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_tbMainWindow( "tbMainWindow", &tbMainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString tbMainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbMainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString tbMainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbMainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* tbMainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"tbMainWindowSearchButton_clicked", 0, 0 };
    static const QUMethod slot_1 = {"tbMainWindowCancelButton_clicked", 0, 0 };
    static const QUMethod slot_2 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "tbMainWindowSearchButton_clicked()", &slot_0, QMetaData::Public },
	{ "tbMainWindowCancelButton_clicked()", &slot_1, QMetaData::Public },
	{ "languageChange()", &slot_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"tbMainWindow", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_tbMainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* tbMainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "tbMainWindow" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool tbMainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tbMainWindowSearchButton_clicked(); break;
    case 1: tbMainWindowCancelButton_clicked(); break;
    case 2: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool tbMainWindow::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool tbMainWindow::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool tbMainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
