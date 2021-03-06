#ifndef LP_SURFNET_H
#define LP_SURFNET_H

#include "lp_functional.h"
#include <opencv2/opencv.hpp>
#include <QThreadPool>
#include <QOpenGLShaderProgram>

class CMesh;

class LP_SURFNet : public LP_Functional
{
    Q_OBJECT
    REGISTER_FUNCTIONAL
public:
    explicit LP_SURFNet(QObject *parent = nullptr);

    // LP_Functional interface
    QWidget *DockUi() override;
    bool Run() override;
    bool eventFilter(QObject *watched, QEvent *event) override;
public slots:

    void FunctionalRender(QOpenGLContext *ctx, QSurface *surf, QOpenGLFramebufferObject *fbo, const LP_RendererCam &cam, const QVariant &options) override;

signals:

private:
    bool mInitialized = false;
    QThreadPool mPool;
    QOpenGLShaderProgram *mProgram = nullptr;
    std::shared_ptr<CMesh> mMeshX, mMeshY;
    std::vector<QVector3D> mVx, mVy;
    std::shared_ptr<QWidget> mWidget;
    QMap<uint,uint> mPoints;
    QString mCorrPath;
    std::vector<double> mAx;
    std::vector<double> mP;
    /**
     * @brief initializeGL initalize any OpenGL resource
     */
    void initializeGL();
};

#endif // LP_SURFNET_H
