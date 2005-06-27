

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
	
	tbSearchEngine(QObject *o,torrentSearch ts,QString sp)
	: receiver(o),torrentsearch(ts),searchPhrase(sp)
	{ ; }
	
	void run();
	void stop();
	QHttp http;

private:
	QObject *receiver;
	torrentSearch torrentsearch;
	QString searchPhrase;	
};


void tbSearchEngine::run(){
	
	debugMsg("tbSearchEngine is running!");    
	

		cout << "Executing search on:" << torrentsearch.searchName;
		http.setHost(torrentsearch.searchHost);

    		//searchPhrase.replace( QChar(' '), "%20" );
		cout << "SEARCH PHRASE IS:" <<torrentsearch.searchURL+searchPhrase <<endl;
		cout << "\t It has id:" << http.get( (torrentsearch.searchURL+searchPhrase),(new QFile( "results."+torrentsearch.searchName )) )<<endl;
		
		QObject::connect(&http, SIGNAL(stateChanged(int)), receiver, SLOT(changed(int)));
		QObject::connect(&http, SIGNAL(done(bool)), receiver, SLOT(done(bool)));		
	
}


