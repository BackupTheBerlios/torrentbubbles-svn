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
#include <qpushbutton.h>
#include <qthread.h>
#include <iostream>
#include <qprogressbar.h>
#include "loadConfig.h"
#include "tbSearchEngine.h"
#include "qhttp.h"
#include "qlineedit.h"
using namespace std;

tbSearchEngine* temp;
QString currentSearch;

tbMainWindowImpl::tbMainWindowImpl(QWidget *parent, const char *name)
    :tbMainWindow(parent, name)
{
			
	debugMsg("Loading config files...\n");
	loadConfigFiles();

}


void tbMainWindowImpl::tbMainWindowSearchButton_clicked()
{

	//debugMsg("Clicked search button!\n");
	tbMainWindowProgressBar->setTotalSteps(0);
	printf("scary! %d\n",	tbMainWindowProgressBar->totalSteps());
	tbMainWindowSearchButton->setEnabled(false);
	tbMainWindowCancelButton->setEnabled(true);
	temp = new tbSearchEngine(this,torrentSearches,tbMainWindowSearchTextField->text());
	temp->start();
	


}


void tbMainWindowImpl::tbMainWindowCancelButton_clicked()
{
	//debugMsg("Clicked cancel button!\n");
	
	tbMainWindowSearchButton->setEnabled(true);
	tbMainWindowCancelButton->setEnabled(false);
}



void tbMainWindowImpl::customEvent(QCustomEvent *event) {
	switch (event->type()) {
		case 10001:
		{
			cout << *( (QString*) event->data() ) <<endl;
			qWarning("Register search\n");
			//Add 4, since we have four states -- connected,sending,receiving,closed
			tbMainWindowProgressBar->setTotalSteps(tbMainWindowProgressBar->totalSteps()+4);
 			break;
		}

		case 10002:
		{
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			qWarning("HTTP Status report!\n");
			break;
		}

		default:
		{
			qWarning("Unknown custom event type: %d", event->type());
		}
	}
}

void tbMainWindowImpl::done(bool error)
{		
	cout << "skank!!! is done! " <<currentSearch<<endl;

	
	if (error)
		qDebug("error: %s", temp->http.errorString().latin1());
	else {
		//printf("Hoho2!  %s \n",(const char*)temp->http.currentRequest().value("engine"));
		QString result(temp->http.readAll());
		cout << result << endl;
		//QString evul = (const char*)temp->http.currentRequest().value("engine");
		//printf("wtf?%s\n",(const char*)evul);
		QFile file( "output."+currentSearch );  
		if ( file.open( IO_WriteOnly ) ) {
			QTextStream stream( &file );
			stream << result;
			file.close();
	    
		}
	} 
	
}


void tbMainWindowImpl::changed(int newState){
	
	printf("Hoho!  %s \n",(const char*)temp->http.currentRequest().value("engine"));
	printf("hum, ID is %d\n",temp->http.currentId());
	printf("%d\n",newState);
			currentSearch = temp->http.currentRequest().value("engine");
//sleep(2);
	switch ( newState )
	{
		case 0:
			printf("Connection now Unconnected\n");

			//tbMainWindowProgressBar->setProgress(newState);
			break;
		case 1:
			printf("Connection now HostLookup\n");
			//tbMainWindowProgressBar->setProgress(newState);
			break;
		case 2:
			printf("Connection now Connecting\n");
			//tbMainWindowProgressBar->setProgress(newState);
			break;
		case 3:
			printf("Connection now Sending\n");
			//tbMainWindowProgressBar->setProgress(newState);
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 4:
			printf("Connection now Reading\n");
			//tbMainWindowProgressBar->setProgress(newState);
			//temp->http.closeConnection();
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 5:
			printf("Connection now Connected\n");
			//tbMainWindowProgressBar->setProgress(newState);
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
		case 6:
			printf("Connection now Closing\n");
			//tbMainWindowProgressBar->setProgress(newState);
			tbMainWindowProgressBar->setProgress(tbMainWindowProgressBar->progress()+1);
			break;
	}
    
    
    
    
}

