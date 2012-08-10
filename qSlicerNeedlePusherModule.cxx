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

// Qt includes
#include <QtPlugin>

// ExtensionTemplate Logic includes
#include <vtkSlicerNeedlePusherLogic.h>

// ExtensionTemplate includes
#include "qSlicerNeedlePusherModule.h"
#include "qSlicerNeedlePusherModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerNeedlePusherModule, qSlicerNeedlePusherModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerNeedlePusherModulePrivate
{
public:
  qSlicerNeedlePusherModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerNeedlePusherModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModulePrivate::qSlicerNeedlePusherModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerNeedlePusherModule methods

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModule::qSlicerNeedlePusherModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerNeedlePusherModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModule::~qSlicerNeedlePusherModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerNeedlePusherModule::helpText()const
{
  return "This is a loadable module bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerNeedlePusherModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerNeedlePusherModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Laurent Chauvin (SNR)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerNeedlePusherModule::icon()const
{
  return QIcon(":/Icons/NeedlePusher.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerNeedlePusherModule::categories() const
{
  return QStringList() << "IGT";
}

//-----------------------------------------------------------------------------
QStringList qSlicerNeedlePusherModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerNeedlePusherModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerNeedlePusherModule::createWidgetRepresentation()
{
  return new qSlicerNeedlePusherModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerNeedlePusherModule::createLogic()
{
  return vtkSlicerNeedlePusherLogic::New();
}
