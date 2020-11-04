#include "parameter.h"

Parameter::Parameter(const QString& name, int value, int min, int max, QWidget *parent):
    QWidget(parent),
    m_value(value),
    m_name(new QLabel(name)),
    m_slider(new QSlider(Qt::Horizontal)),
    m_LCDNumber(new QLCDNumber())
{
    m_slider->setRange(min,max);
    m_slider->setValue(m_value);

    m_LCDNumber->setSegmentStyle(QLCDNumber::Flat);
    m_LCDNumber->display(m_value);

    connect(m_slider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            m_LCDNumber, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(m_slider, &QSlider::valueChanged, this, &Parameter::setValue);
}

Parameter::~Parameter()
{
    if (m_name)
        delete m_name;
    if (m_slider)
        delete m_slider;
    if (m_LCDNumber)
        delete m_LCDNumber;
}

int Parameter::value()
{
    return m_value;
}

void Parameter::setValue(int value)
{
    m_value = value;
}

QHBoxLayout* Parameter::parameterLayout()
{
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(m_name);
    layout->addWidget(m_slider);
    layout->addWidget(m_LCDNumber);
    return layout;
}
