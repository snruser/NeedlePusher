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

// SingleAxisControl Widgets includes
#include "qSlicerSingleAxisControlWidget.h"
#include "ui_qSlicerSingleAxisControlWidget.h"

#include <iostream>

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_NeedlePusher
class qSlicerSingleAxisControlWidgetPrivate
  : public Ui_qSlicerSingleAxisControlWidget
{
  Q_DECLARE_PUBLIC(qSlicerSingleAxisControlWidget);
protected:
  qSlicerSingleAxisControlWidget* const q_ptr;

public:
  qSlicerSingleAxisControlWidgetPrivate(
    qSlicerSingleAxisControlWidget& object);
  virtual void setupUi(qSlicerSingleAxisControlWidget*);
};

// --------------------------------------------------------------------------
qSlicerSingleAxisControlWidgetPrivate
::qSlicerSingleAxisControlWidgetPrivate(
  qSlicerSingleAxisControlWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerSingleAxisControlWidgetPrivate
::setupUi(qSlicerSingleAxisControlWidget* widget)
{
  this->Ui_qSlicerSingleAxisControlWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerSingleAxisControlWidget methods

//-----------------------------------------------------------------------------
qSlicerSingleAxisControlWidget
::qSlicerSingleAxisControlWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerSingleAxisControlWidgetPrivate(*this) )
{
  init();
}

//-----------------------------------------------------------------------------
qSlicerSingleAxisControlWidget
  ::qSlicerSingleAxisControlWidget(const char* title, QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerSingleAxisControlWidgetPrivate(*this) )
{
  init();
  this->setTitle(title);
}

//-----------------------------------------------------------------------------
void qSlicerSingleAxisControlWidget::init()
{
  Q_D(qSlicerSingleAxisControlWidget);

  d->setupUi(this);

  connect(d->AxisGroupBox, SIGNAL(clicked(bool)),
	  this, SLOT(testSlot(bool)));
}


//-----------------------------------------------------------------------------
qSlicerSingleAxisControlWidget
::~qSlicerSingleAxisControlWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerSingleAxisControlWidget::setTitle(const char* newTitle)
{
  Q_D(qSlicerSingleAxisControlWidget);
  
  d->AxisGroupBox->setTitle(newTitle);
}

//-----------------------------------------------------------------------------
void qSlicerSingleAxisControlWidget::testSlot(bool bTest)
{
  std::cerr << "Clicked" << std::endl;
}
