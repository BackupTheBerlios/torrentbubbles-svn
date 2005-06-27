

#include <qapplication.h>
#include <qhttp.h>
#include <qfile.h>

#include <vector>
#include <iostream>

#include "torrentSearch.h"
#include "debugmsg.h"


using namespace std;

class tbSearchEngine :  public QThread {

public:
	
	tbSearchEngine(QObject *o,vector<torrentSearch> ts,QString sp)
	: receiver(o),torrentsearches(ts),searchPhrase(sp)
	{ ; }
	
	void run();
	void stop();
	QHttp http;

private:
	QObject *receiver;
	vector<torrentSearch> torrentsearches;
	QString searchPhrase;	
};


void tbSearchEngine::run(){
	
	qWarning("tbSearchEngine, run!\n");    
	
	QCustomEvent *event = new QCustomEvent(10001);
	event->setData(new QString("Registering"));
	QApplication::postEvent(receiver, event);
	
	
	
	unsigned int indx = 0;
	for (indx = 0; indx < torrentsearches.size(); indx++) {
		

		/*  
		//Incase we need header spoofing
		QString targetHost = torrentsearches[indx].searchHost;
		QString targetName = torrentsearches[indx].searchName;
		QHttpRequestHeader header("GET", "/search");
		header.setValue("Host", targetHost);
		header.setValue("User-Agent","Mozilla/5.0 (Linux i686)");
		header.setValue("engine",targetName);
   		header.setContentType("application/x-www-form-urlencoded");
		*/
		cout << "Executing search on:" << torrentsearches[indx].searchName <<endl;
		http.setHost(torrentsearches[indx].searchHost);
		http.get( torrentsearches[indx].searchURL+searchPhrase ,(new QFile( "freakyzzz."+torrentsearches[indx].searchName )) );

		QObject::connect(&http, SIGNAL(stateChanged(int)), receiver, SLOT(changed(int)));
		QObject::connect(&http, SIGNAL(done(bool)), receiver, SLOT(done(bool)));	
		
	}	
	
}


