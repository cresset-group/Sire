/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2008  Christopher Woods
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

#ifndef SIREMM_INTERNALCOMPONENT_H
#define SIREMM_INTERNALCOMPONENT_H

#include <QSet>

#include "SireFF/ffcomponent.h"
#include "SireFF/ff.h"

SIRE_BEGIN_HEADER

namespace SireMM
{
class BondComponent;
class AngleComponent;
class DihedralComponent;

class ImproperComponent;
class UreyBradleyComponent;

class StretchStretchComponent;
class StretchBendComponent;
class BendBendComponent;
class StretchBendTorsionComponent;

class Intra14Component;
class Intra14CoulombComponent;
class Intra14LJComponent;

class InternalComponent;
}

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::BondComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::BondComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::AngleComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::AngleComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::DihedralComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::DihedralComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::ImproperComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::ImproperComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::UreyBradleyComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::UreyBradleyComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::StretchStretchComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::StretchStretchComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::StretchBendComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::StretchBendComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::BendBendComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::BendBendComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::StretchBendTorsionComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::StretchBendTorsionComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::InternalComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::InternalComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::Intra14Component&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::Intra14Component&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::Intra14CoulombComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::Intra14CoulombComponent&);

SIREMM_EXPORT QDataStream& operator<<(QDataStream&, const SireMM::Intra14LJComponent&);
SIREMM_EXPORT QDataStream& operator>>(QDataStream&, SireMM::Intra14LJComponent&);

namespace SireFF
{
class FF;
}

namespace SireMM
{

using SireFF::FF;
using SireFF::FFName;

using SireCAS::Symbol;

typedef SireFF::ComponentEnergy<BondComponent> BondEnergy;
typedef SireFF::ComponentEnergy<AngleComponent> AngleEnergy;
typedef SireFF::ComponentEnergy<DihedralComponent> DihedralEnergy;

typedef SireFF::ComponentEnergy<ImproperComponent> ImproperEnergy;
typedef SireFF::ComponentEnergy<UreyBradleyComponent> UreyBradleyEnergy;

typedef SireFF::ComponentEnergy<StretchStretchComponent> StretchStretchEnergy;
typedef SireFF::ComponentEnergy<StretchBendComponent> StretchBendEnergy;
typedef SireFF::ComponentEnergy<BendBendComponent> BendBendEnergy;
typedef SireFF::ComponentEnergy<StretchBendTorsionComponent> StretchBendTorsionEnergy;

typedef SireFF::ComponentEnergy<Intra14CoulombComponent> Intra14CoulombEnergy;
typedef SireFF::ComponentEnergy<Intra14LJComponent> Intra14LJEnergy;

class InternalEnergy;
class Intra14Energy;

/** This class represents a Bond component of a forcefield */
class SIREMM_EXPORT BondComponent : public SireFF::FFComponent
{
public:
    BondComponent(const FFName &ffname = FFName());
    BondComponent(const SireCAS::Symbol &symbol);
    
    BondComponent(const BondComponent &other);
    
    ~BondComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return BondComponent::typeName();
    }
    
    BondComponent* clone() const
    {
        return new BondComponent(*this);
    }
    
    const BondComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const BondEnergy &bondnrg) const;
    void changeEnergy(FF &ff, const BondEnergy &bondnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a Angle component of a forcefield */
class SIREMM_EXPORT AngleComponent : public SireFF::FFComponent
{
public:
    AngleComponent(const FFName &ffname = FFName());
    AngleComponent(const SireCAS::Symbol &symbol);
    
    AngleComponent(const AngleComponent &other);
    
    ~AngleComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return AngleComponent::typeName();
    }
    
    AngleComponent* clone() const
    {
        return new AngleComponent(*this);
    }
    
    const AngleComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const AngleEnergy &angnrg) const;
    void changeEnergy(FF &ff, const AngleEnergy &angnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a Dihedral component of a forcefield */
class SIREMM_EXPORT DihedralComponent : public SireFF::FFComponent
{
public:
    DihedralComponent(const FFName &ffname = FFName());
    DihedralComponent(const SireCAS::Symbol &symbol);
    
    DihedralComponent(const DihedralComponent &other);
    
    ~DihedralComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return DihedralComponent::typeName();
    }
    
    DihedralComponent* clone() const
    {
        return new DihedralComponent(*this);
    }
    
    const DihedralComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const DihedralEnergy &dihnrg) const;
    void changeEnergy(FF &ff, const DihedralEnergy &dihnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a Improper component of a forcefield */
class SIREMM_EXPORT ImproperComponent : public SireFF::FFComponent
{
public:
    ImproperComponent(const FFName &ffname = FFName());
    ImproperComponent(const SireCAS::Symbol &symbol);
    
    ImproperComponent(const ImproperComponent &other);
    
    ~ImproperComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return ImproperComponent::typeName();
    }
    
    ImproperComponent* clone() const
    {
        return new ImproperComponent(*this);
    }
    
    const ImproperComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const ImproperEnergy &impnrg) const;
    void changeEnergy(FF &ff, const ImproperEnergy &impnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a UreyBradley component of a forcefield */
class SIREMM_EXPORT UreyBradleyComponent : public SireFF::FFComponent
{
public:
    UreyBradleyComponent(const FFName &ffname = FFName());
    UreyBradleyComponent(const SireCAS::Symbol &symbol);
    
    UreyBradleyComponent(const UreyBradleyComponent &other);
    
    ~UreyBradleyComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return UreyBradleyComponent::typeName();
    }
    
    UreyBradleyComponent* clone() const
    {
        return new UreyBradleyComponent(*this);
    }
    
    const UreyBradleyComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const UreyBradleyEnergy &ubnrg) const;
    void changeEnergy(FF &ff, const UreyBradleyEnergy &ubnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a StretchStretch component of a forcefield */
class SIREMM_EXPORT StretchStretchComponent : public SireFF::FFComponent
{
public:
    StretchStretchComponent(const FFName &ffname = FFName());
    StretchStretchComponent(const SireCAS::Symbol &symbol);
    
    StretchStretchComponent(const StretchStretchComponent &other);
    
    ~StretchStretchComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return StretchStretchComponent::typeName();
    }
    
    StretchStretchComponent* clone() const
    {
        return new StretchStretchComponent(*this);
    }
    
    const StretchStretchComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const StretchStretchEnergy &ssnrg) const;
    void changeEnergy(FF &ff, const StretchStretchEnergy &ssnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a StretchBend component of a forcefield */
class SIREMM_EXPORT StretchBendComponent : public SireFF::FFComponent
{
public:
    StretchBendComponent(const FFName &ffname = FFName());
    StretchBendComponent(const SireCAS::Symbol &symbol);
    
    StretchBendComponent(const StretchBendComponent &other);
    
    ~StretchBendComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return StretchBendComponent::typeName();
    }
    
    StretchBendComponent* clone() const
    {
        return new StretchBendComponent(*this);
    }
    
    const StretchBendComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const StretchBendEnergy &sbnrg) const;
    void changeEnergy(FF &ff, const StretchBendEnergy &sbnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a BendBend component of a forcefield */
class SIREMM_EXPORT BendBendComponent : public SireFF::FFComponent
{
public:
    BendBendComponent(const FFName &ffname = FFName());
    BendBendComponent(const SireCAS::Symbol &symbol);
    
    BendBendComponent(const BendBendComponent &other);
    
    ~BendBendComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return BendBendComponent::typeName();
    }
    
    BendBendComponent* clone() const
    {
        return new BendBendComponent(*this);
    }
    
    const BendBendComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const BendBendEnergy &bbnrg) const;
    void changeEnergy(FF &ff, const BendBendEnergy &bbnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a StretchBendTorsion component of a forcefield */
class SIREMM_EXPORT StretchBendTorsionComponent : public SireFF::FFComponent
{
public:
    StretchBendTorsionComponent(const FFName &ffname = FFName());
    StretchBendTorsionComponent(const SireCAS::Symbol &symbol);
    
    StretchBendTorsionComponent(const StretchBendTorsionComponent &other);
    
    ~StretchBendTorsionComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return StretchBendTorsionComponent::typeName();
    }
    
    StretchBendTorsionComponent* clone() const
    {
        return new StretchBendTorsionComponent(*this);
    }
    
    const StretchBendTorsionComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const StretchBendTorsionEnergy &sbtnrg) const;
    void changeEnergy(FF &ff, const StretchBendTorsionEnergy &sbtnrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a intramolecular 1-4 nonbonded coulomb energy of a forcefield */
class SIREMM_EXPORT Intra14CoulombComponent : public SireFF::FFComponent
{
public:
    Intra14CoulombComponent(const FFName &ffname = FFName());
    Intra14CoulombComponent(const SireCAS::Symbol &symbol);
    
    Intra14CoulombComponent(const Intra14CoulombComponent &other);
    
    ~Intra14CoulombComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return Intra14CoulombComponent::typeName();
    }
    
    Intra14CoulombComponent* clone() const
    {
        return new Intra14CoulombComponent(*this);
    }
    
    const Intra14CoulombComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const Intra14CoulombEnergy &nrg) const;
    void changeEnergy(FF &ff, const Intra14CoulombEnergy &nrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents a intramolecular 1-4 nonbonded LJ energy of a forcefield */
class SIREMM_EXPORT Intra14LJComponent : public SireFF::FFComponent
{
public:
    Intra14LJComponent(const FFName &ffname = FFName());
    Intra14LJComponent(const SireCAS::Symbol &symbol);
    
    Intra14LJComponent(const Intra14LJComponent &other);
    
    ~Intra14LJComponent();
    
    static const char* typeName();
    
    const char* what() const
    {
        return Intra14LJComponent::typeName();
    }
    
    Intra14LJComponent* clone() const
    {
        return new Intra14LJComponent(*this);
    }
    
    const Intra14LJComponent& total() const
    {
        return *this;
    }

    void setEnergy(FF &ff, const Intra14LJEnergy &nrg) const;
    void changeEnergy(FF &ff, const Intra14LJEnergy &nrg) const;

    SireCAS::Symbols symbols() const
    {
        return *this;
    }
};

/** This class represents the sum of the intramolecular 1-4 nonbonded
    coulomb and LJ energies */
class SIREMM_EXPORT Intra14Component : public SireFF::FFComponent
{

friend SIREMM_EXPORT QDataStream& ::operator<<(QDataStream&, const Intra14Component&);
friend SIREMM_EXPORT QDataStream& ::operator>>(QDataStream&, Intra14Component&);

public:
    Intra14Component(const FFName &name = FFName());
    Intra14Component(const SireCAS::Symbol &symbol);
    
    Intra14Component(const Intra14Component &other);
    
    ~Intra14Component();
    
    const Intra14CoulombComponent& coulomb() const
    {
        return coul_component;
    }
    
    const Intra14LJComponent& lj() const
    {
        return lj_component;
    }
    
    const Intra14Component& total() const
    {
        return *this;
    }
    
    static const char* typeName();
    
    const char* what() const
    {
        return Intra14Component::typeName();
    }
    
    Intra14Component* clone() const
    {
        return new Intra14Component(*this);
    }

    void setEnergy(FF &ff, const Intra14Energy &nrg) const;
    void changeEnergy(FF &ff, const Intra14Energy &nrg) const;

    SireCAS::Symbols symbols() const;

protected:
    /** The coulomb component */
    Intra14CoulombComponent coul_component;
    
    /** The LJ component */
    Intra14LJComponent lj_component;
};

/** This class represents the sum of the internal MM energy
    components (bond, angle, dihedral, Urey-Bradley) */
class SIREMM_EXPORT InternalComponent : public SireFF::FFComponent
{

friend SIREMM_EXPORT QDataStream& ::operator<<(QDataStream&, const InternalComponent&);
friend SIREMM_EXPORT QDataStream& ::operator>>(QDataStream&, InternalComponent&);

public:
    InternalComponent(const FFName &name = FFName());
    InternalComponent(const SireCAS::Symbol &symbol);
    
    InternalComponent(const InternalComponent &other);
    
    ~InternalComponent();
    
    const BondComponent& bond() const
    {
        return bond_component;
    }
    
    const AngleComponent& angle() const
    {
        return angle_component;
    }
    
    const DihedralComponent& dihedral() const
    {
        return dihedral_component;
    }
    
    const ImproperComponent& improper() const
    {
        return improper_component;
    }
    
    const UreyBradleyComponent& ureyBradley() const
    {
        return ub_component;
    }
    
    const StretchStretchComponent& stretchStretch() const
    {
        return ss_component;
    }
    
    const StretchBendComponent& stretchBend() const
    {
        return sb_component;
    }
    
    const BendBendComponent& bendBend() const
    {
        return bb_component;
    }
    
    const StretchBendTorsionComponent& stretchBendTorsion() const
    {
        return sbt_component;
    }
    
    const Intra14Component& intra14() const
    {
        return nb_component;
    }
    
    const Intra14CoulombComponent& intra14Coulomb() const
    {
        return nb_component.coulomb();
    }
    
    const Intra14LJComponent& intra14LJ() const
    {
        return nb_component.lj();
    }
    
    const InternalComponent& total() const
    {
        return *this;
    }
    
    static const char* typeName();
    
    const char* what() const
    {
        return InternalComponent::typeName();
    }
    
    InternalComponent* clone() const
    {
        return new InternalComponent(*this);
    }

    void setEnergy(FF &ff, const InternalEnergy &nrg) const;
    void changeEnergy(FF &ff, const InternalEnergy &nrg) const;

    SireCAS::Symbols symbols() const;

protected:
    /** The bond component */
    BondComponent bond_component;
    /** The angle component */
    AngleComponent angle_component;
    /** The dihedral component */
    DihedralComponent dihedral_component;

    /** The improper component */
    ImproperComponent improper_component;
    /** The Urey-Bradley component */
    UreyBradleyComponent ub_component;
    
    /** The stretch-stretch component */
    StretchStretchComponent ss_component;
    /** The stretch-bend component */
    StretchBendComponent sb_component;
    /** The bend-bend component */
    BendBendComponent bb_component;
    /** The stretch-bend-torsion component */
    StretchBendTorsionComponent sbt_component;
    
    /** The intramolecular 1-4 nonbonded component */
    Intra14Component nb_component;
};

/** This class holds the complete intramolecular 1-4 energy (coulomb plus LJ) */
class SIREMM_EXPORT Intra14Energy
{
public:
    typedef Intra14Component Components;

    Intra14Energy(double cnrg=0, double ljnrg=0);
    
    Intra14Energy(const Intra14Energy &other);
    
    ~Intra14Energy();
    
    static const char* typeName()
    {
        return "SireMM::Intra14Energy";
    }
    
    const char* what() const
    {
        return Intra14Energy::typeName();
    }

    Intra14Energy& operator=(const Intra14Energy &other)
    {
        cnrg = other.cnrg;
        ljnrg = other.ljnrg;
        
        return *this;
    }
    
    Intra14Energy& operator+=(const Intra14Energy &other)
    {
        cnrg += other.cnrg;
        ljnrg += other.ljnrg;
    
        return *this;
    }
    
    Intra14Energy& operator-=(const Intra14Energy &other)
    {
        cnrg -= other.cnrg;
        ljnrg -= other.ljnrg;
    
        return *this;
    }
    
    Intra14Energy operator+(const Intra14Energy &other) const
    {
        return Intra14Energy( cnrg + other.cnrg, ljnrg + other.ljnrg );
    }
    
    Intra14Energy operator-(const Intra14Energy &other) const
    {
        return Intra14Energy( cnrg - other.cnrg, ljnrg - other.ljnrg );
    }
    
    Intra14Energy& operator+=(const Intra14CoulombEnergy &icnrg)
    {
        cnrg += icnrg.total();
        return *this;
    }
    
    Intra14Energy& operator+=(const Intra14LJEnergy &iljnrg)
    {
        ljnrg += iljnrg.total();
        return *this;
    }
    
    Intra14Energy& operator-=(const Intra14CoulombEnergy &icnrg)
    {
        cnrg -= icnrg.total();
        return *this;
    }
    
    Intra14Energy& operator-=(const Intra14LJEnergy &iljnrg)
    {
        ljnrg -= iljnrg.total();
        return *this;
    }
    
    Components components() const
    {
        return Components();
    }
    
    double component(const Intra14CoulombComponent&) const
    {
        return cnrg;
    }
    
    double component(const Intra14LJComponent&) const
    {
        return ljnrg;
    }
    
    double component(const Intra14Component&) const
    {
        return cnrg + ljnrg;
    }
    
    double coulomb() const
    {
        return cnrg;
    }
    
    double lj() const
    {
        return ljnrg;
    }
    
    double total() const
    {
        return cnrg + ljnrg;
    }
    
    operator double() const
    {
        //return the total energy
        return Intra14Energy::total();
    }
    
    operator SireUnits::Dimension::MolarEnergy() const
    {
        return SireUnits::Dimension::MolarEnergy( Intra14Energy::total() );
    }
    
    operator Intra14CoulombEnergy() const
    {
        return Intra14CoulombEnergy(cnrg);
    }
    
    operator Intra14LJEnergy() const
    {
        return Intra14LJEnergy(ljnrg);
    }

private:
    /** All of the component energies */
    double cnrg, ljnrg;
};

/** This class holds the complete molecule mechanics internal
    energy (combination of the bond, angle, dihedral and Urey-Bradley
    energies) */
class SIREMM_EXPORT InternalEnergy
{
public:
    typedef InternalComponent Components;

    InternalEnergy(double bondnrg=0, double anglenrg=0, double dihedralnrg=0, 
                   double impropernrg=0, double ubnrg=0,
                   double ssnrg=0, double sbnrg=0, double bbnrg=0, double sbtnrg=0,
                   Intra14Energy intra14nrg=Intra14Energy(0,0));
    
    InternalEnergy(const InternalEnergy &other);
    
    ~InternalEnergy();
    
    static const char* typeName()
    {
        return "SireMM::InternalEnergy";
    }
    
    const char* what() const
    {
        return InternalEnergy::typeName();
    }

    InternalEnergy& operator=(const InternalEnergy &other)
    {
        ibndnrg = other.ibndnrg;
        iangnrg = other.iangnrg;
        idihnrg = other.idihnrg;
        
        iimpnrg = other.iimpnrg;
        iubnrg = other.iubnrg;
        
        issnrg = other.issnrg;
        isbnrg = other.isbnrg;
        ibbnrg = other.ibbnrg;
        isbtnrg = other.isbtnrg;
        
        i14nrg = other.i14nrg;
        
        return *this;
    }
    
    InternalEnergy& operator+=(const InternalEnergy &other)
    {
        ibndnrg += other.ibndnrg;
        iangnrg += other.iangnrg;
        idihnrg += other.idihnrg;
        
        iimpnrg += other.iimpnrg;
        iubnrg += other.iubnrg;
        
        issnrg += other.issnrg;
        isbnrg += other.isbnrg;
        ibbnrg += other.ibbnrg;
        isbtnrg += other.isbtnrg;
    
        i14nrg += other.i14nrg;
    
        return *this;
    }
    
    InternalEnergy& operator-=(const InternalEnergy &other)
    {
        ibndnrg -= other.ibndnrg;
        iangnrg -= other.iangnrg;
        idihnrg -= other.idihnrg;
        
        iimpnrg -= other.iimpnrg;
        iubnrg -= other.iubnrg;
        
        issnrg -= other.issnrg;
        isbnrg -= other.isbnrg;
        ibbnrg -= other.ibbnrg;
        isbtnrg -= other.isbtnrg;
    
        i14nrg -= other.i14nrg;
    
        return *this;
    }
    
    InternalEnergy operator+(const InternalEnergy &other) const
    {
        return InternalEnergy( ibndnrg + other.ibndnrg,
                               iangnrg + other.iangnrg,
                               idihnrg + other.idihnrg,
                               iimpnrg + other.iimpnrg,
                               iubnrg + other.iubnrg,
                               issnrg + other.issnrg,
                               isbnrg + other.isbnrg,
                               ibbnrg + other.ibbnrg,
                               isbtnrg + other.isbtnrg,
                               i14nrg + other.i14nrg );
    }
    
    InternalEnergy operator-(const InternalEnergy &other) const
    {
        return InternalEnergy( ibndnrg - other.ibndnrg,
                               iangnrg - other.iangnrg,
                               idihnrg - other.idihnrg,
                               iimpnrg - other.iimpnrg,
                               iubnrg - other.iubnrg,
                               issnrg - other.issnrg,
                               isbnrg - other.isbnrg,
                               ibbnrg - other.ibbnrg,
                               isbtnrg - other.isbtnrg,
                               i14nrg - other.i14nrg );
    }
    
    InternalEnergy& operator+=(const BondEnergy &bndnrg)
    {
        ibndnrg += bndnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const AngleEnergy &angnrg)
    {
        iangnrg += angnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const DihedralEnergy &dihnrg)
    {
        idihnrg += dihnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const ImproperEnergy &impnrg)
    {
        iimpnrg += impnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const UreyBradleyEnergy &ubnrg)
    {
        iubnrg += ubnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const StretchStretchEnergy &ssnrg)
    {
        issnrg += ssnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const StretchBendEnergy &sbnrg)
    {
        isbnrg += sbnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const BendBendEnergy &bbnrg)
    {
        ibbnrg += bbnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const StretchBendTorsionEnergy sbtnrg)
    {
        isbtnrg += sbtnrg.total();
        return *this;
    }
    
    InternalEnergy& operator+=(const Intra14Energy &nrg)
    {
        i14nrg += nrg;
        return *this;
    }
    
    InternalEnergy& operator+=(const Intra14CoulombEnergy &nrg)
    {
        i14nrg += nrg;
        return *this;
    }
    
    InternalEnergy& operator+=(const Intra14LJEnergy &nrg)
    {
        i14nrg += nrg;
        return *this;
    }
    
    InternalEnergy& operator-=(const BondEnergy &bndnrg)
    {
        ibndnrg -= bndnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const AngleEnergy &angnrg)
    {
        iangnrg -= angnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const DihedralEnergy &dihnrg)
    {
        idihnrg -= dihnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const ImproperEnergy &impnrg)
    {
        iimpnrg -= impnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const UreyBradleyEnergy &ubnrg)
    {
        iubnrg -= ubnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const StretchStretchEnergy &ssnrg)
    {
        issnrg -= ssnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const StretchBendEnergy &sbnrg)
    {
        isbnrg -= sbnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const BendBendEnergy &bbnrg)
    {
        ibbnrg -= bbnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const StretchBendTorsionEnergy sbtnrg)
    {
        isbtnrg -= sbtnrg.total();
        return *this;
    }
    
    InternalEnergy& operator-=(const Intra14Energy &nrg)
    {
        i14nrg -= nrg;
        return *this;
    }
    
    InternalEnergy& operator-=(const Intra14CoulombEnergy &nrg)
    {
        i14nrg -= nrg;
        return *this;
    }
    
    InternalEnergy& operator-=(const Intra14LJEnergy &nrg)
    {
        i14nrg -= nrg;
        return *this;
    }
    
    Components components() const
    {
        return Components();
    }
    
    double component(const BondComponent&) const
    {
        return ibndnrg;
    }
    
    double component(const AngleComponent&) const
    {
        return iangnrg;
    }
    
    double component(const DihedralComponent&) const
    {
        return idihnrg;
    }
    
    double component(const ImproperComponent&) const
    {
        return iimpnrg;
    }
    
    double component(const UreyBradleyComponent&) const
    {
        return iubnrg;
    }
    
    double component(const StretchStretchComponent&) const
    {
        return issnrg;
    }
    
    double component(const StretchBendComponent&) const
    {
        return isbnrg;
    }
    
    double component(const BendBendComponent&) const
    {
        return ibbnrg;
    }
    
    double component(const StretchBendTorsionComponent&) const
    {
        return isbtnrg;
    }
    
    double component(const Intra14Component&) const
    {
        return i14nrg.total();
    }
    
    double component(const Intra14CoulombComponent&) const
    {
        return i14nrg.coulomb();
    }
    
    double component(const Intra14LJComponent&) const
    {
        return i14nrg.lj();
    }
    
    double component(const InternalComponent&) const
    {
        return ibndnrg + iangnrg + idihnrg + 
               iimpnrg + iubnrg +
               issnrg + isbnrg + ibbnrg + isbtnrg +
               i14nrg.total();
    }
    
    double bond() const
    {
        return ibndnrg;
    }
    
    double angle() const
    {
        return iangnrg;
    }
    
    double dihedral() const
    {
        return idihnrg;
    }
    
    double improper() const
    {
        return iimpnrg;
    }
    
    double ureyBradley() const
    {
        return iubnrg;
    }
    
    double stretchStretch() const
    {
        return issnrg;
    }
    
    double stretchBend() const
    {
        return isbnrg;
    }
    
    double bendBend() const
    {
        return ibbnrg;
    }
    
    double stretchBendTorsion() const
    {
        return isbtnrg;
    }
    
    double intra14() const
    {
        return i14nrg.total();
    }
    
    double intra14Coulomb() const
    {
        return i14nrg.coulomb();
    }
    
    double intra14LJ() const
    {
        return i14nrg.lj();
    }
    
    double total() const
    {
        return ibndnrg + iangnrg + idihnrg + 
               iimpnrg + iubnrg +
               issnrg + isbnrg + ibbnrg + isbtnrg +
               i14nrg.total();
    }
    
    operator double() const
    {
        //return the total energy
        return InternalEnergy::total();
    }
    
    operator SireUnits::Dimension::MolarEnergy() const
    {
        return SireUnits::Dimension::MolarEnergy( InternalEnergy::total() );
    }
    
    operator BondEnergy() const
    {
        return BondEnergy(ibndnrg);
    }

    operator AngleEnergy() const
    {
        return AngleEnergy(iangnrg);
    }
    
    operator DihedralEnergy() const
    {
        return DihedralEnergy(idihnrg);
    }
    
    operator ImproperEnergy() const
    {
        return ImproperEnergy(iimpnrg);
    }
    
    operator UreyBradleyEnergy() const
    {
        return UreyBradleyEnergy(iubnrg);
    }

    operator StretchStretchEnergy() const
    {
        return StretchStretchEnergy(issnrg);
    }

    operator StretchBendEnergy() const
    {
        return StretchBendEnergy(isbnrg);
    }
    
    operator BendBendEnergy() const
    {
        return BendBendEnergy(ibbnrg);
    }
    
    operator StretchBendTorsionEnergy() const
    {
        return StretchBendTorsionEnergy(isbtnrg);
    }

    operator Intra14Energy() const
    {
        return Intra14Energy(i14nrg.total());
    }
    
    operator Intra14CoulombEnergy() const
    {
        return Intra14CoulombEnergy(i14nrg.coulomb());
    }
    
    operator Intra14LJEnergy() const
    {
        return Intra14LJEnergy(i14nrg.lj());
    }

private:
    /** The intramolecular 1-4 nonbonded energies */
    Intra14Energy i14nrg;

    /** All of the component energies */
    double ibndnrg, iangnrg, idihnrg, 
           iimpnrg, iubnrg,
           issnrg, isbnrg, ibbnrg, isbtnrg;
};

} // end of namespace SireMM

SIRE_EXPOSE_CLASS( SireMM::BondComponent )
SIRE_EXPOSE_CLASS( SireMM::AngleComponent )
SIRE_EXPOSE_CLASS( SireMM::DihedralComponent )
SIRE_EXPOSE_CLASS( SireMM::ImproperComponent )
SIRE_EXPOSE_CLASS( SireMM::UreyBradleyComponent )
SIRE_EXPOSE_CLASS( SireMM::StretchStretchComponent )
SIRE_EXPOSE_CLASS( SireMM::StretchBendComponent )
SIRE_EXPOSE_CLASS( SireMM::BendBendComponent )
SIRE_EXPOSE_CLASS( SireMM::StretchBendTorsionComponent )

SIRE_EXPOSE_CLASS( SireMM::Intra14CoulombComponent )
SIRE_EXPOSE_CLASS( SireMM::Intra14LJComponent )
SIRE_EXPOSE_CLASS( SireMM::Intra14Component )

SIRE_EXPOSE_CLASS( SireMM::InternalComponent )

Q_DECLARE_METATYPE( SireMM::BondComponent )
Q_DECLARE_METATYPE( SireMM::AngleComponent )
Q_DECLARE_METATYPE( SireMM::DihedralComponent )
Q_DECLARE_METATYPE( SireMM::ImproperComponent )
Q_DECLARE_METATYPE( SireMM::UreyBradleyComponent )
Q_DECLARE_METATYPE( SireMM::StretchStretchComponent )
Q_DECLARE_METATYPE( SireMM::StretchBendComponent )
Q_DECLARE_METATYPE( SireMM::BendBendComponent )
Q_DECLARE_METATYPE( SireMM::StretchBendTorsionComponent )
Q_DECLARE_METATYPE( SireMM::Intra14CoulombComponent )
Q_DECLARE_METATYPE( SireMM::Intra14LJComponent )
Q_DECLARE_METATYPE( SireMM::Intra14Component )
Q_DECLARE_METATYPE( SireMM::InternalComponent )

SIRE_END_HEADER

#endif

