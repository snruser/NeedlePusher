/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerNeedlePusherModuleWidget_h
#define __qSlicerNeedlePusherModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerNeedlePusherModuleExport.h"

class qSlicerNeedlePusherModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_NEEDLEPUSHER_EXPORT qSlicerNeedlePusherModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerNeedlePusherModuleWidget(QWidget *parent=0);
  virtual ~qSlicerNeedlePusherModuleWidget();

  int previousDOF;

public slots:
  void onDOFChanged(int dof);


protected:
  QScopedPointer<qSlicerNeedlePusherModuleWidgetPrivate> d_ptr;
  
  virtual void setup();
  void AddAxisWidgets(int axisToAdd);
  void RemoveAxisWidgets(int axisToRemove);

private:
  Q_DECLARE_PRIVATE(qSlicerNeedlePusherModuleWidget);
  Q_DISABLE_COPY(qSlicerNeedlePusherModuleWidget);
};

#endif
