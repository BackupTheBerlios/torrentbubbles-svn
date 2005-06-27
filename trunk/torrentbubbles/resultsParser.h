/***************************************************************************
 *   Copyright (C) 2005 by Jesper Thomschutz   *
 *   evilhax0r@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef RESULTSPARSER_H
#define RESULTSPARSER_H

#include <qapplication.h>
#include <qhttp.h>
#include <qfile.h>
#include <qregexp.h>


#include <vector>
#include <iostream>

#include "torrentSearch.h"
#include "debugmsg.h"
#include "searchResult.h"

using namespace std;

class resultsParser :  public QThread {

public:
	
	resultsParser(QObject *o,vector<torrentSearch> ts)
	: receiver(o),torrentsearch(ts)
	{ ; }
	
	void run();
	void stop();
	//void getValue(QString,char*,QRegExp);
	void getValue(QString,QString,QString);

private:
	QObject *receiver;
	vector<torrentSearch> torrentsearch;	
	searchResult resultFound;

	int namePos;
	int filePos;
	int sizePos;
	int seedersPos;
	int leechersPos;
	unsigned int indx;

};


void resultsParser::run(){

	debugMsg("Running results parser");    

		
	for (indx = 0; indx < torrentSearches.size(); indx++) {
		
		QFile file( "results."+torrentSearches[indx].searchName );

		if ( !file.open(IO_ReadOnly) )
			fatalMsg("resultsParser:file.open()");
	
    		QString text = file.readAll();
		file.close();

    		QRegExp rx( torrentSearches[indx].torrentName );
		rx.setMinimal(TRUE);

		namePos = 0;
		filePos = 0;
		sizePos = 0;
		seedersPos = 0;
		leechersPos = 0;
		
		
		while (namePos >= 0) {
		
			namePos = rx.search(text, namePos);
			
			if (namePos > -1) {


				namePos += rx.matchedLength();
				resultFound.name= rx.cap( 1 ); 

				getValue(text,"file",torrentSearches[indx].torrentFile);
				getValue(text,"size",torrentSearches[indx].torrentSize);
				getValue(text,"leechers",torrentSearches[indx].torrentLeechers);
				getValue(text,"seeders",torrentSearches[indx].torrentSeeders);

			/*	printf("Hohoho, %s\n",(const char*) resultFound.name );
				printf("Hohoho File, %s\n",(const char*) resultFound.file );
				printf("Hohoho Size, %s\n",(const char*) resultFound.size );
				printf("Hohoho Seeders, %s\n",(const char*) resultFound.seeders );
				printf("Hohoho Leechers, %s\n",(const char*) resultFound.leechers ); */
				QCustomEvent *event = new QCustomEvent(10001);
				//new QString("Registering")
    				event->setData(&resultFound);
     				QApplication::postEvent(receiver, event);

			}
			
		}
	}
}

void resultsParser::getValue(QString text, QString type, QString regexp ) {
	
	
	QRegExp rx( regexp );
	rx.setMinimal(TRUE);
	
	if (type == "file"){
		filePos = rx.search(text, filePos);
		filePos += rx.matchedLength();
		resultFound.file= "http://"+torrentSearches[indx].torrentHost+"/"+rx.cap( 1 );
	}
	
	if (type == "size") {
		sizePos = rx.search(text, sizePos);
		sizePos += rx.matchedLength();
		resultFound.size= rx.cap( 1 );
	}
	
	if (type == "seeders"){
		seedersPos = rx.search(text, seedersPos);
		seedersPos += rx.matchedLength();
		resultFound.seeders= rx.cap( 1);
	}
	
	if (type == "leechers"){
		leechersPos = rx.search(text, leechersPos);
		leechersPos += rx.matchedLength();
		resultFound.leechers= rx.cap( 1);
	}

 }


	




#endif
