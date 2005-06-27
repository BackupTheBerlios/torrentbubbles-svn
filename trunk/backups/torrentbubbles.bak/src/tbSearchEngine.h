
#ifndef TBSEARCHENGINE_H
#define TBSEARCHENGINE_H

#include <qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qmultilineedit.h>
#include <qthread.h>
#include <qsemaphore.h>
#include <qmutex.h>
#include <qlayout.h>
#include <qmessagebox.h>
#include <qlabel.h>
#include <qthread.h>

#include "qhttp.h"
#include "qbuffer.h"
#include "qurl.h"
#include <string.h>	
#include "qstring.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qstringlist.h"


#include "torrentSearch.h"
#include <vector>
#include <iostream>


//#include "qthread.h"
#include "qhttp.h"
#include "qbuffer.h"
#include "qurl.h"
#include <string.h>	
#include "qprogressbar.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qstringlist.h"
//#include <qsignal.h>
//#include "torrentbubbles.moc" // depends on the name of the .cpp file with main

using namespace std;

class tbSearchEngine :  public QObject, public QThread {
 Q_OBJECT
public:
	
	tbSearchEngine(QObject *o,vector<torrentSearch> ts)
	: receiver(o),torrentsearches(ts)
	{ ; }
	
	void run();
	void stop();
	
public slots:
	void changed(int);
	void done(bool);

private:
	QObject *receiver;
	vector<torrentSearch> torrentsearches;
	QHttp http;
};


void tbSearchEngine::run(){
	
	qWarning("tbSearchEngine, run!\n");    
	
	QCustomEvent *event = new QCustomEvent(10001);
	event->setData(new QString("Registering"));
	QApplication::postEvent(receiver, event);
	
	
	
	unsigned int indx;
	for (indx = 0; indx < torrentsearches.size(); indx++) {
		cout << "searchNames are:!!! " << torrentsearches[indx].searchName <<endl;
		QString targetHost = torrentsearches[indx].searchHost;
		QString topic = "h4x";
		QHttpRequestHeader header("GET", "/search");
		header.setValue("Host", targetHost);
		header.setValue("User-Agent","Mozilla/5.0 (Linux i686)");
		header.setValue("engine","shiiiit");
   		header.setContentType("application/x-www-form-urlencoded");
		http.setHost(targetHost);
		http.request(header);
		connect(&http, SIGNAL(stateChanged(int)), this, SLOT(changed(int)));
		//QObject::connect(&http, SIGNAL(done(bool)), this, SLOT(done(bool)));	
	}
	
	
}



void tbSearchEngine::done(bool error)
{
    

	if (error)
		qDebug("error: %s", http.errorString().latin1());
	else {
		QString result(http.readAll());
	
		QFile file( "results.html" );  
		if ( file.open( IO_WriteOnly ) ) {
			QTextStream stream( &file );
			stream << result;
			file.close();
	    
		}
	}
}

void tbSearchEngine::changed(int newState){
	
	printf("Hoho!  %s \n",(const char*)http.currentRequest().value("engine"));
	printf("%d\n",newState);
	switch ( newState )
	{
		case 0:
			printf("Connection now Unconnected\n");
			//progressBar->setProgress(newState);
			break;
		case 1:
			printf("Connection now HostLookup\n");
			//progressBar->setProgress(newState);
			break;
		case 2:
			printf("Connection now Connecting\n");
			//progressBar->setProgress(newState);
			break;
		case 3:
			printf("Connection now Sending\n");
			//progressBar->setProgress(newState);
			break;
		case 4:
			printf("Connection now Reading\n");
			//progressBar->setProgress(newState);
			break;
		case 5:
			printf("Connection now Connected\n");
			//progressBar->setProgress(newState);
			break;
		case 6:
			printf("Connection now Closing\n");
			//progressBar->setProgress(newState);
			break;
	}
    
    
    
    
}

#endif

