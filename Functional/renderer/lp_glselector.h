#ifndef LP_GLSELECTOR_H
#define LP_GLSELECTOR_H

#include "Functional_global.h"
#include <memory>
#include <QObject>
#include <QMap>


class QOpenGLContext;
class QSurface;
class QOpenGLFramebufferObject;


class LP_ObjectImpl;
typedef std::shared_ptr<LP_ObjectImpl> LP_Object;
typedef std::weak_ptr<LP_ObjectImpl> LP_Objectw;

class LP_RendererCamImpl;
typedef std::shared_ptr<LP_RendererCamImpl> LP_RendererCam;

typedef void(*cb_c)(QOpenGLContext *);


class FUNCTIONAL_EXPORT LP_GLSelector : public QObject
{
    Q_OBJECT
public:

    LP_Objectw SelectInWorld(const QString &renderername, const QPoint &pos, int w=7, int h=7);

    void SelectCustom(const QString &renderername, void *cb, void *data=nullptr);
    std::vector<uint> SelectPoints3D(const QString &renderername, const std::vector<float[3]> &pts, const QPoint &pos, bool mask=false, int w=7, int h=7);
        std::vector<uint> SelectPoints3D(const QString &renderername, const float *pts, const size_t &npts, const QPoint &pos, bool mask=false, int w=7, int h=7);
//    std::vector<uint> SelectCustom(std::vector<cb_c> &objs, const QPoint &pos, int w=7, int h=7);
//    void Clear();

//    LP_GLRenderer *GetRenderer(const QString &name) const;
//    void AddRenderer(LP_GLRenderer *renderer);

    explicit LP_GLSelector();

    static std::vector<QVector3D> g_24ColorVector;

    static std::vector<QVector3D> gen24ColorVector(const int &limit);
signals:

private:

};

extern FUNCTIONAL_EXPORT std::unique_ptr<LP_GLSelector> g_GLSelector;

#endif // LP_GLSELECTOR_H