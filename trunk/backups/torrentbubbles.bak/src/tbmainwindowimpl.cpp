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

using namespace std;

tbSearchEngine* temp;

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
	temp = new tbSearchEngine(this,torrentSearches);
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


