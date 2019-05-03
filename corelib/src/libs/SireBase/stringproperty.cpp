/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2013  Christopher Woods
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2 of the License, or
  *  (at your option) any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  *
  *  For full details of the license please see the COPYING file
  *  that should have come with this distribution.
  *
  *  You can contact the authors via the developer's mailing list
  *  at http://siremol.org
  *
\*********************************************/

#include "stringproperty.h"
#include "numberproperty.h"
#include "booleanproperty.h"

#include "SireError/errors.h"

#include "SireStream/sharestrings.h"
#include "SireStream/datastream.h"
#include "SireStream/shareddatastream.h"

#include <QDebug>

using namespace SireBase;
using namespace SireStream;

static const RegisterMetaType<StringProperty> r_stringprop;

QDataStream &operator<<(QDataStream &ds, const StringProperty &s)
{
    writeHeader(ds, r_stringprop, 1);
    
    SharedDataStream sds(ds);
    
    sds << s.s;
    
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StringProperty &s)
{
    VersionID v = readHeader(ds, r_stringprop);
    
    if (v == 1)
    {
        SharedDataStream sds(ds);
        sds >> s.s;
    }
    else
        throw version_error(v, "1", r_stringprop, CODELOC);
    
    return ds;
}

/** Constructor */
StringProperty::StringProperty() : ConcreteProperty<StringProperty,Property>()
{}

/** Construct from the passed string */
StringProperty::StringProperty(const QString &str)
               : ConcreteProperty<StringProperty,Property>(),
                 s(shareString(str))
{}

/** Construct from the the passed number */
StringProperty::StringProperty(double value)
               : ConcreteProperty<StringProperty,Property>(),
                 s(shareString(QString::number(value)))
{}

/** Cast from the passed property */
StringProperty::StringProperty(const Property &other)
               : ConcreteProperty<StringProperty,Property>(other),
                 s(shareString(other.asAString()))
{}

/** Copy constructor */
StringProperty::StringProperty(const StringProperty &other)
               : ConcreteProperty<StringProperty,Property>(other), s(other.s)
{}

/** Destructor */
StringProperty::~StringProperty()
{}

/** Copy assignment operator */
StringProperty& StringProperty::operator=(const StringProperty &other)
{
    s = other.s;
    return *this;
}

/** Comparison operator */
bool StringProperty::operator==(const StringProperty &other) const
{
    return s == other.s;
}

/** Comparison operator */
bool StringProperty::operator!=(const StringProperty &other) const
{
    return s != other.s;
}

const char* StringProperty::typeName()
{
    return QMetaType::typeName( qMetaTypeId<StringProperty>() );
}

QString StringProperty::toString() const
{
    return s;
}

/** Return the actual string */
QString StringProperty::value() const
{
    return s;
}

bool StringProperty::isAString() const
{
    return true;
}

bool StringProperty::isADouble() const
{
    try
    {
        NumberProperty n(s);
        return n.isADouble();
    }
    catch(...)
    {
        return false;
    }
}

bool StringProperty::isAnInteger() const
{
    try
    {
        NumberProperty n(s);
        return n.isAnInteger();
    }
    catch(...)
    {
        return false;
    }
}

bool StringProperty::isABoolean() const
{
    try
    {
        BooleanProperty b(s);
    }
    catch(...)
    {
        return false;
    }
    
    return true;
}

QString StringProperty::asAString() const
{
    return s;
}

double StringProperty::asADouble() const
{
    try
    {
        NumberProperty n(s);
        return n.asADouble();
    }
    catch(...)
    {}
    
    throw SireError::invalid_cast( QObject::tr(
            "Cannot cast the StringProperty('%1') as a double")
                .arg(s), CODELOC );
    
    return 0;
}

int StringProperty::asAnInteger() const
{
    try
    {
        NumberProperty n(s);
        return n.asAnInteger();
    }
    catch(...)
    {}
    
    throw SireError::invalid_cast( QObject::tr(
            "Cannot cast the StringProperty('%1') as an integer")
                .arg(s), CODELOC );
    
    return 0;
}

bool StringProperty::asABoolean() const
{
    try
    {
        BooleanProperty n(s);
        return n.asABoolean();
    }
    catch(...)
    {}
    
    throw SireError::invalid_cast( QObject::tr(
            "Cannot cast the StringProperty('%1') as a boolean")
                .arg(s), CODELOC );
    
    return 0;
}
