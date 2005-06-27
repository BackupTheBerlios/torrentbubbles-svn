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

#include "tbmainwindowimpl.h"
#include "debugmsg.h"
#include <qpushbutton.h>
#include <qthread.h>
#include <iostream>
#include <qprogressbar.h>
#include "loadConfig.h"
#include "tbSearchEngine.h"
#include "qhttp.h"
#include "qlineedit.h"
#include "resultsParser.h"
#include "searchResult.h"
#include <qlistview.h>

using namespace std;

tbSearchEngine* tempSearchEngine;
resultsParser* tempResultsParser;
searchResult* hoe;
QString currentSearch;

unsigned int doneCounter = 0;

tbMainWindowImpl::tbMainWindowImpl(QWidget *parent, const char *name)
    :tbMainWindow(parent, name){
			
	debugMsg("Loading config files...");
	loadConfigFiles();

}


void tbMainWindowImpl::tbMainWindowSearchButton_clicked(){	
	
	debugMsg("Clicked tbMainWindowSearchButton!");

	tbMainWindowProgressBar->setTotalSteps(0);
	tbMainWindowProgressBar->setProgress(0);

	tbMainWindowSearchButton->setEnabled(false);
	tbMainWindowCancelButton->setEnabled(true);

	unsigned int indx = 0;

	for (indx = 0; indx < torrentSearches.size(); indx++) {
		tbMainWindowProgressBar->setTotalSteps(tbMainWindowProgressBar->totalSteps()+4);
		tempSearchEngine = new tbSearchEngine(this,torrentSearches[indx],tbMainWindowSearchTextField->text());
		tempSearchEngine->start();
	}

}


void tbMainWindowImpl::tbMainWindowCancelButton_clicked(){

	debugMsg("Clicked tbMainWindowCancelButton!");
	
	tbMainWindowSearchButton->setEnabled(true);
	tbMainWindowCancelButton->setEnabled(false);
}



void tbMainWindowImpl::done(bool error){	

	if( error == FALSE ) {
		cout << "DONEprogress is: "<<tbMainWindowProgressBar->progress()<<endl;
		cout << "DONEtotalSteps is: "<<tbMainWindowProgressBar->totalSteps()<<endl;
		doneCounter++;
	
		if ( doneCounter == torrentSearches.size() ){
			
			debugMsg("Finished searching!");
			
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->totalSteps());
			tbMainWindowCancelButton_clicked();
			
			doneCounter = 0;
				
			tempResultsParser = new resultsParser(this,torrentSearches);
			tempResultsParser->start();

		}

	}else 
		fatalMsg("tbMainWindowImpl::done");
	
}
	

void tbMainWindowImpl::changed(int newState){

	switch ( newState )
	{
		case 0:
			debugMsg("Connection now Unconnected");
			break;
		case 1:
			debugMsg("Connection now HostLookup");
			break;
		case 2:
			debugMsg("Connection now Connecting");
			break;
		case 3:
			debugMsg("Connection now Sending");
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 4:
			debugMsg("Connection now Reading");
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 5:
			debugMsg("Connection now Connected");
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 6:
			debugMsg("Connection now Closing");
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
	}

}

void tbMainWindowImpl::addResultToGui(searchResult resultFound) {

	new QListViewItem( tbMainWindowResultsListView, resultFound.name,resultFound.size,resultFound.seeders,resultFound.leechers,resultFound.file);

}

void tbMainWindowImpl::customEvent(QCustomEvent *event) {
        switch (event->type()) {
                case 10001:
                {
			addResultToGui(*( (searchResult*) event->data()));
 			break;
                }

                default:
                {
                        qWarning("Unknown custom event type: %d", event->type());
                }
        }
}

