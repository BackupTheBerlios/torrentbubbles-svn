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
#ifndef TBMAINWINDOWIMPL_H
#define TBMAINWINDOWIMPL_H

#include "tbmainwindow.h"
#include "searchResult.h"
#include <qevent.h>

class tbMainWindowImpl: public tbMainWindow {
Q_OBJECT
public:
    tbMainWindowImpl(QWidget *parent = 0, const char *name = 0);
    
public slots:
	virtual void tbMainWindowSearchButton_clicked();
	virtual void tbMainWindowCancelButton_clicked();
	void changed(int);
	void done(bool);
	void addResultToGui(searchResult);
	void customEvent(QCustomEvent*);	
};

#endif
