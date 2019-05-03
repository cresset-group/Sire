/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2007  Christopher Woods
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

#ifndef SIREMOL_MGNAME_H
#define SIREMOL_MGNAME_H

#include "SireID/name.h"

#include "mgid.h"

SIRE_BEGIN_HEADER

namespace SireMol
{
class MGName;
}

SIREMOL_EXPORT QDataStream& operator<<(QDataStream&, const SireMol::MGName&);
SIREMOL_EXPORT QDataStream& operator>>(QDataStream&, SireMol::MGName&);

namespace SireMol
{

/** This class holds the name of a MoleculeGroup.
    
    @author Christopher Woods
*/
class SIREMOL_EXPORT MGName : public SireID::Name, public MGID
{

friend SIREMOL_EXPORT QDataStream& ::operator<<(QDataStream&, const MGName&);
friend SIREMOL_EXPORT QDataStream& ::operator>>(QDataStream&, MGName&);

public:
    MGName();

    explicit MGName(const QString &name);
    
    MGName(const QString &name, SireID::CaseSensitivity case_sensitivity);
    
    MGName(const MGName &other);
    
    ~MGName();
    
    static const char* typeName();
    
    const char* what() const
    {
        return MGName::typeName();
    }
    
    MGName* clone() const;
    
    bool isNull() const;
    
    uint hash() const;
    
    QString toString() const;
    
    MGName& operator=(const MGName &other);
    
    bool operator==(const SireID::ID &other) const;
    
    bool operator==(const MGName &other) const;
    
    bool operator!=(const MGName &other) const;
    
    QList<MGNum> map(const MolGroupsBase &molgroups) const;
};

}

Q_DECLARE_METATYPE(SireMol::MGName);

SIRE_EXPOSE_CLASS( SireMol::MGName )

SIRE_END_HEADER

#endif

