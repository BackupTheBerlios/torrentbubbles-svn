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
 
 

#include <qsettings.h>
#include <qdir.h>
#include <iostream>
#include "torrentSearch.h"
#include "tbVariables.h"
#include <vector>
#include "debugmsg.h"


void loadConfigFiles();

torrentSearch parseSearchConfig(QString);

QString fileListFilter(QString,QString);
QStringList searchFiles;
vector<torrentSearch> torrentSearches;
tbVariables tbvariables;
QSettings settings;

// Loads the config files found under $home/.torrentBubbles/ into the program.
void loadConfigFiles() {
	//loading torrent searches.
	QDir d(QDir::homeDirPath() +"/.torrentBubbles" );
	
	if ( !d.exists() )
		fatalMsg( "load config, trying to find .torrentBubbles" );
	
	
	
	settings.setPath( "torrentBubbles", "torrentBubbles" );
	settings.insertSearchPath( QSettings::Unix, QDir::homeDirPath() +"/.torrentBubbles" );
	
	tbvariables.author = settings.readEntry( "/torrentbubbles/Author" );
	tbvariables.version = settings.readEntry( "/torrentbubbles/Version" );
	tbvariables.torrentProgram = settings.readEntry( "/torrentbubbles/TorrentProgram" );

	const QFileInfoList *list = d.entryInfoList();
	QFileInfoListIterator it( *list );
	QFileInfo *fi;
	
	while ( (fi = it.current()) != 0 ) {
	
		QString foundFile = fileListFilter(fi->fileName(),"torrentsearchrc");
		
		if (foundFile != NULL ) 
			torrentSearches.push_back(parseSearchConfig(foundFile));
		
		++it;
	}
	
	//Hard coded debug stuff.
	unsigned int indx;
	for (indx = 0; indx < torrentSearches.size(); indx++)
		cout << "searchNames are: " << torrentSearches[indx].searchName <<endl;
		
}


// This function parses the search config file and creates a torrentSearch object of it.
torrentSearch parseSearchConfig(QString inputFile) {
	//Get rid of trailing "rc"
	inputFile = inputFile.left(inputFile.length()-2);
	
	torrentSearch temp;
	QSettings settings;
	settings.setPath( "torrentBubbles", "torrentBubbles" );
	settings.insertSearchPath( QSettings::Unix, QDir::homeDirPath() +"/.torrentBubbles" );
	
	temp.searchName = settings.readEntry( "/"+inputFile+"/searchName" );
	temp.searchVersion = settings.readEntry( "/"+inputFile+"/searchVersion" );
	temp.searchAuthor = settings.readEntry( "/"+inputFile+"/searchAuthor" );
	temp.searchHost = settings.readEntry( "/"+inputFile+"/searchHost" );
	temp.searchURL = settings.readEntry( "/"+inputFile+"/searchURL" );
	temp.torrentHost = settings.readEntry("/"+inputFile+"/torrentHost" );
	temp.torrentName = settings.readEntry( "/"+inputFile+"/torrentName" );
	temp.torrentFile = settings.readEntry( "/"+inputFile+"/torrentFile" );
	temp.torrentSize = settings.readEntry( "/"+inputFile+"/torrentSize" );
	temp.torrentSeeders = settings.readEntry( "/"+inputFile+"/torrentSeeders" );
	temp.torrentLeechers = settings.readEntry( "/"+inputFile+"/torrentLeechers" );
	
	return temp;
}

//Checks if a string contains a given extension.
QString fileListFilter(QString file, QString extension) {
	
	const char* containsString = strstr ((const char*) file,(const char*) extension);
	
	if (containsString != NULL) {
		cout << "Found config file " << file << endl;
		return file;
	}
	
	return NULL;
}
