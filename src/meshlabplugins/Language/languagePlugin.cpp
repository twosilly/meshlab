#include "languagePlugin.h"

#include <QDebug>
LanguagePlugin::LanguagePlugin(int _editType) : editType(_editType)
{
    qDebug()<<"LanguagePlugin::LanguagePlugin";
//    QTranslator translator;
//    if (translator.load(QString("./language/meshlab_zh")))
//    {
//             qDebug()<<"SB:"<<translator.objectName();
//             app.installTranslator(&translator);
//    }else{
//        qDebug()<<"SB-BS:"<<translator.objectName();
//    }
}

const QString LanguagePlugin::Info()
{
     return tr("Choose a language and change languages!");
}
