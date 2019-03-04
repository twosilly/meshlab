#ifndef LANGUAGEPLUGIN_H
#define LANGUAGEPLUGIN_H

#include <QObject>
#include <common/interfaces.h>
class LanguagePlugin : public QObject, public MeshEditInterface
{
    Q_OBJECT
    Q_INTERFACES(MeshEditInterface)
public:
    enum {SELECT_DEFAULT_MODE, SELECT_FITTING_PLANE_MODE};
    explicit LanguagePlugin(int _editType);
    virtual ~LanguagePlugin() {}
    static const QString Info();
    void suggestedRenderingData(MeshModel & m, MLRenderingData& dt){};
    bool StartEdit(MeshModel &/*m*/, GLArea * /*parent*/, MLSceneGLSharedDataContext* /*cont*/){return 1;};
    void EndEdit(MeshModel &/*m*/, GLArea * /*parent*/, MLSceneGLSharedDataContext* /*cont*/){};
    void Decorate(MeshModel &/*m*/, GLArea * /*parent*/, QPainter *p){};
    void mousePressEvent(QMouseEvent *, MeshModel &, GLArea * ){};
    void mouseMoveEvent(QMouseEvent *, MeshModel &, GLArea * ){};
    void mouseReleaseEvent(QMouseEvent *, MeshModel &/*m*/, GLArea * ){};
    void keyPressEvent(QKeyEvent *, MeshModel &/*m*/, GLArea *){};
    void wheelEvent(QWheelEvent*, MeshModel &/*m*/, GLArea * ){};

signals:
    void setSelectionRendering(bool);
signals:

public slots:
private:
    // Could be SELECT_DEFAULT_MODE or SELECT_FITTING_PLANE_MODE
    int editType;
};

#endif // LANGUAGEPLUGIN_H
