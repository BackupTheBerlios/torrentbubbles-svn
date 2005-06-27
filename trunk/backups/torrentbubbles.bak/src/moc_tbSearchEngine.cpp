/****************************************************************************
** tbSearchEngine meta object code from reading C++ file 'tbSearchEngine.h'
**
** Created: Thu May 19 12:07:41 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "tbSearchEngine.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *tbSearchEngine::className() const
{
    return "tbSearchEngine";
}

QMetaObject *tbSearchEngine::metaObj = 0;
static QMetaObjectCleanUp cleanUp_tbSearchEngine( "tbSearchEngine", &tbSearchEngine::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString tbSearchEngine::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbSearchEngine", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString tbSearchEngine::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "tbSearchEngine", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* tbSearchEngine::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"changed", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"done", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "changed(int)", &slot_0, QMetaData::Public },
	{ "done(bool)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"tbSearchEngine", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_tbSearchEngine.setMetaObject( metaObj );
    return metaObj;
}

void* tbSearchEngine::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "tbSearchEngine" ) )
	return this;
    if ( !qstrcmp( clname, "QThread" ) )
	return (QThread*)this;
    return QObject::qt_cast( clname );
}

bool tbSearchEngine::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: changed((int)static_QUType_int.get(_o+1)); break;
    case 1: done((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool tbSearchEngine::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool tbSearchEngine::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool tbSearchEngine::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
