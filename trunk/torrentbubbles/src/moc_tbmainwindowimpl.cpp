/****************************************************************************
** tbMainWindowImpl meta object code from reading C++ file 'tbmainwindowimpl.h'
**
** Created: Mon Jun 27 13:59:38 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "tbmainwindowimpl.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *tbMainWindowImpl::className() const
{
    return "tbMainWindowImpl";
}

QMetaObject *tbMainWindowImpl::metaObj = 0;
static QMetaObjectCleanUp cleanUp_tbMainWindowImpl( "tbMainWindowImpl", &tbMainWindowImpl::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString tbMainWindowImpl::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbMainWindowImpl", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString tbMainWindowImpl::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbMainWindowImpl", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* tbMainWindowImpl::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = tbMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"tbMainWindowSearchButton_clicked", 0, 0 };
    static const QUMethod slot_1 = {"tbMainWindowCancelButton_clicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"changed", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"done", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QCustomEvent", QUParameter::In }
    };
    static const QUMethod slot_4 = {"customEvent", 1, param_slot_4 };
    static const QUMethod slot_5 = {"tbMainWindowResultsListView_doubleClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "tbMainWindowSearchButton_clicked()", &slot_0, QMetaData::Public },
	{ "tbMainWindowCancelButton_clicked()", &slot_1, QMetaData::Public },
	{ "changed(int)", &slot_2, QMetaData::Public },
	{ "done(bool)", &slot_3, QMetaData::Public },
	{ "customEvent(QCustomEvent*)", &slot_4, QMetaData::Public },
	{ "tbMainWindowResultsListView_doubleClicked()", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"tbMainWindowImpl", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_tbMainWindowImpl.setMetaObject( metaObj );
    return metaObj;
}

void* tbMainWindowImpl::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "tbMainWindowImpl" ) )
	return this;
    return tbMainWindow::qt_cast( clname );
}

bool tbMainWindowImpl::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tbMainWindowSearchButton_clicked(); break;
    case 1: tbMainWindowCancelButton_clicked(); break;
    case 2: changed((int)static_QUType_int.get(_o+1)); break;
    case 3: done((bool)static_QUType_bool.get(_o+1)); break;
    case 4: customEvent((QCustomEvent*)static_QUType_ptr.get(_o+1)); break;
    case 5: tbMainWindowResultsListView_doubleClicked(); break;
    default:
	return tbMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool tbMainWindowImpl::qt_emit( int _id, QUObject* _o )
{
    return tbMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool tbMainWindowImpl::qt_property( int id, int f, QVariant* v)
{
    return tbMainWindow::qt_property( id, f, v);
}

bool tbMainWindowImpl::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
