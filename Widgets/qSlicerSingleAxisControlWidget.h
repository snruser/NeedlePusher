/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerSingleAxisControlWidget_h
#define __qSlicerSingleAxisControlWidget_h

// Qt includes
#include <QWidget>

// SingleAxisControl Widgets includes
#include "qSlicerNeedlePusherModuleWidgetsExport.h"

class qSlicerSingleAxisControlWidgetPrivate;

/// \ingroup Slicer_QtModules_NeedlePusher
class Q_SLICER_MODULE_NEEDLEPUSHER_WIDGETS_EXPORT qSlicerSingleAxisControlWidget
  : public QWidget
{
  Q_OBJECT
public:
  typedef QWidget Superclass;
  qSlicerSingleAxisControlWidget(QWidget *parent=0);
  qSlicerSingleAxisControlWidget(const char* title, QWidget *parent=0);
  virtual ~qSlicerSingleAxisControlWidget();
  
  void setTitle(const char* newTitle);

protected slots:
  void testSlot(bool bTest);

protected:
  QScopedPointer<qSlicerSingleAxisControlWidgetPrivate> d_ptr;
  void init();

private:
  Q_DECLARE_PRIVATE(qSlicerSingleAxisControlWidget);
  Q_DISABLE_COPY(qSlicerSingleAxisControlWidget);
};

#endif
