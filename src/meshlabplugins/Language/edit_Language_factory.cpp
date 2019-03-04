/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005-2008                                           \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#include "edit_Language_factory.h"
#include "languagePlugin.h"

LanguageFactory::LanguageFactory()
{
        QAction_Language = new QAction(QIcon(":/images/language.png"),tr("Language window"), this);
		QAction_Language = new QAction(QIcon(":/images/language.png"),tr("Select Vertexes on a Plane"), this);
	
        actionList << QAction_Language;
        //actionList << QAction_Language;
        //actionList << editPointFittingPlane;
	
	foreach(QAction *editAction, actionList)
                editAction->setCheckable(true);
}
	
//从该插件获取可用操作的列表
QList<QAction *> LanguageFactory::actions() const
{
	return actionList;
}

//获取给定操作的编辑工具
MeshEditInterface* LanguageFactory::getMeshEditInterface(QAction *action)
{
        if(action == QAction_Language)
            return new LanguagePlugin(LanguagePlugin::SELECT_DEFAULT_MODE);
//        else if (action == editPointFittingPlane)
//            return new EditPointPlugin(EditPointPlugin::SELECT_FITTING_PLANE_MODE);

        assert(0); //永远不要被要求去做一个不在这里的动作
}

QString LanguageFactory::getEditToolDescription(QAction *)
{
        return LanguagePlugin::Info();
}

MESHLAB_PLUGIN_NAME_EXPORTER(LanguageFactory)
