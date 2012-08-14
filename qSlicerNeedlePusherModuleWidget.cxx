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
#include <QDebug>

// SlicerQt includes
#include "qSlicerNeedlePusherModuleWidget.h"
#include "qSlicerSingleAxisControlWidget.h"
#include "ui_qSlicerNeedlePusherModule.h"

#include <sstream>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerNeedlePusherModuleWidgetPrivate: public Ui_qSlicerNeedlePusherModule
{
public:
  qSlicerNeedlePusherModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerNeedlePusherModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModuleWidgetPrivate::qSlicerNeedlePusherModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerNeedlePusherModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModuleWidget::qSlicerNeedlePusherModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerNeedlePusherModuleWidgetPrivate )
{
  this->previousDOF = 0;
}

//-----------------------------------------------------------------------------
qSlicerNeedlePusherModuleWidget::~qSlicerNeedlePusherModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerNeedlePusherModuleWidget::setup()
{
  Q_D(qSlicerNeedlePusherModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
    
  connect(d->DOFSelector, SIGNAL(currentIndexChanged(int)),
	  this, SLOT(onDOFChanged(int)));
}

//-----------------------------------------------------------------------------
void qSlicerNeedlePusherModuleWidget::onDOFChanged(int dof)
{
  if( dof > this->previousDOF)
    {
      this->AddAxisWidgets(dof - this->previousDOF);
    }
  else
    {
      this->RemoveAxisWidgets(this->previousDOF - dof);
    }
  this->previousDOF = dof;
}

//-----------------------------------------------------------------------------
void qSlicerNeedlePusherModuleWidget::AddAxisWidgets(int axisToAdd)
{
  Q_D(qSlicerNeedlePusherModuleWidget);

  for(int i = 0; i < axisToAdd; i++)
    {
      std::stringstream axisName;
      axisName << "Axis " << d->WidgetLayout->count() + 1;
      qSlicerSingleAxisControlWidget* newAxis = new qSlicerSingleAxisControlWidget(axisName.str().c_str());
      this->setUpdatesEnabled(false);
      d->WidgetLayout->addWidget(newAxis);
      newAxis->show();
      this->setUpdatesEnabled(true);
    }
}

//-----------------------------------------------------------------------------
void qSlicerNeedlePusherModuleWidget::RemoveAxisWidgets(int axisToRemove)
{
  Q_D(qSlicerNeedlePusherModuleWidget);

  if(axisToRemove <= d->WidgetLayout->count())
    {
      for(int i = 0; i < axisToRemove; i++)
	{
	  d->WidgetLayout->itemAt(d->WidgetLayout->count()-1)->widget()->hide();
	  d->WidgetLayout->itemAt(d->WidgetLayout->count()-1)->widget()->deleteLater();
	  d->WidgetLayout->removeItem(d->WidgetLayout->itemAt(d->WidgetLayout->count()-1));
	}
    }
}
