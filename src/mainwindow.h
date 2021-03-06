// Copyright (C) 2012, Chris J. Foster and the other authors and contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of the software's owners nor the names of its
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// (This is the BSD 3-clause license)


#ifndef DISPLAZ_MAINWINDOW_H_INCLUDED
#define DISPLAZ_MAINWINDOW_H_INCLUDED

#include <QtCore/QDir>
#include <QtGui/QMainWindow>

#include <memory>

class QActionGroup;
class QSignalMapper;
class QPlainTextEdit;
class QProgressBar;
class QModelIndex;

class HelpDialog;
class View3D;
class ShaderEditor;
class LogViewer;
class GeometryCollection;


//------------------------------------------------------------------------------
/// Main window for point cloud viewer application
class PointViewerMainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        PointViewerMainWindow();

        /// Hint at an appropriate size
        QSize sizeHint() const;

        GeometryCollection& geometries() { return *m_geometries; }

    public slots:
        void runCommand(const QByteArray& command);
        void openShaderFile(const QString& shaderFileName);

    protected:
        void keyReleaseEvent(QKeyEvent* event);
        void dragEnterEvent(QDragEnterEvent *event);
        void dropEvent(QDropEvent *event);

    private slots:
        void openFiles();
        void openShaderFile();
        void saveShaderFile();
        void reloadFiles();
        void screenShot();
        void helpDialog();
        void aboutDialog();
        void setBackground(const QString& name);
        void chooseBackground();
        void updateTitle();
        void setProgressBarText(QString text);
        void geometryRowsInserted(const QModelIndex& parent, int first, int last);

    private:
        QColor backgroundColFromName(const QString& name) const;

        // Gui objects
        QProgressBar* m_progressBar;
        View3D* m_pointView;
        ShaderEditor* m_shaderEditor;
        HelpDialog* m_helpDialog;
        LogViewer* m_logTextView;

        // Gui state
        QDir m_currFileDir;
        QString m_currShaderFileName;

        // Currently loaded geometry
        GeometryCollection* m_geometries;
};


#endif // DISPLAZ_MAINWINDOW_H_INCLUDED
