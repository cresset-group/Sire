/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2010  Christopher Woods
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

#ifndef SIREFF_POTENTIALTABLE_H
#define SIREFF_POTENTIALTABLE_H

#include <QHash>
#include <QVector>
#include <QUuid>

#include "SireBase/packedarray2d.hpp"
#include "SireMaths/vector.h"
#include "SireVol/grid.h"

#include "SireMol/molnum.h"
#include "SireMol/cgidx.h"

#include "SireUnits/dimensions.h"

SIRE_BEGIN_HEADER

namespace SireFF
{
class MolPotentialTable;
class GridPotentialTable;
class PotentialTable;
}

SIREFF_EXPORT QDataStream& operator<<(QDataStream&, const SireFF::MolPotentialTable&);
SIREFF_EXPORT QDataStream& operator>>(QDataStream&, SireFF::MolPotentialTable&);

SIREFF_EXPORT QDataStream& operator<<(QDataStream&, const SireFF::GridPotentialTable&);
SIREFF_EXPORT QDataStream& operator>>(QDataStream&, SireFF::GridPotentialTable&);

SIREFF_EXPORT QDataStream& operator<<(QDataStream&, const SireFF::PotentialTable&);
SIREFF_EXPORT QDataStream& operator>>(QDataStream&, SireFF::PotentialTable&);

namespace SireMol
{
class MoleculeView;
class MoleculeGroup;
}

namespace SireFF
{

using SireMol::MoleculeView;
using SireMol::CGIdx;
using SireMol::CGAtomIdx;
using SireMol::MolNum;
using SireMol::MoleculeGroup;
using SireMol::AtomSelection;

using SireMaths::Vector;

using SireVol::Grid;
using SireVol::GridPtr;

using SireUnits::Dimension::MolarEnergy;

/** This class holds the potential at the points of all of the atoms of 
    selected CutGroups in a molecule. The MolPotentialTable is used
    to accumulate all of the potentials acting on these atoms during
    a field evaluation, and also to control which potentials are
    evaluated (as only the potentials on atoms in selected CutGroups
    are evaluated). This allows you to provide some control over
    the calculation, e.g. only placing a few protein residues into
    the field table, thereby preventing the potentials on all atoms
    in a protein from being evaluated if they aren't actually 
    necessary.
    
    @author Christopher Woods
*/
class SIREFF_EXPORT MolPotentialTable : public SireBase::PackedArray2D<MolarEnergy>
{

friend SIREFF_EXPORT QDataStream& ::operator<<(QDataStream&, const MolPotentialTable&);
friend SIREFF_EXPORT QDataStream& ::operator>>(QDataStream&, MolPotentialTable&);

public:
    typedef SireBase::PackedArray2D<MolarEnergy>::Array Array;

    MolPotentialTable();
    
    MolPotentialTable(const MoleculeView &molview);
    
    MolPotentialTable(const MolPotentialTable &other);
    
    ~MolPotentialTable();
    
    MolPotentialTable& operator=(const MolPotentialTable &other);
    MolPotentialTable& operator=(const MolarEnergy &potential);

    bool operator==(const MolPotentialTable &other) const;
    bool operator!=(const MolPotentialTable &other) const;

    MolPotentialTable& operator+=(const MolPotentialTable &other);
    MolPotentialTable& operator-=(const MolPotentialTable &other);
    
    MolPotentialTable operator+(const MolPotentialTable &other) const;
    MolPotentialTable operator-(const MolPotentialTable &other) const;

    MolPotentialTable& operator+=(const MolarEnergy &potential);
    MolPotentialTable& operator-=(const MolarEnergy &potential);
    
    MolPotentialTable operator+(const MolarEnergy &potential) const;
    MolPotentialTable operator-(const MolarEnergy &potential) const;

    MolPotentialTable& operator*=(double value);
    MolPotentialTable& operator/=(double value);

    MolPotentialTable operator*(double value) const;
    MolPotentialTable operator/(double value) const;

    MolPotentialTable operator-() const;

    static const char* typeName();
    
    const char* what() const
    {
        return MolPotentialTable::typeName();
    }

    void initialise();

    int nCutGroups() const;
    int nSelectedCutGroups() const;

    bool selectedAll() const;

    bool selected(CGIdx cgidx) const;

    MolNum molNum() const;

    const QUuid& molUID() const;
    
    int map(CGIdx cgidx) const;

    QVector<MolarEnergy> toVector() const;
    QVector<MolarEnergy> toVector(const AtomSelection &selection) const;
    
    bool add(const CGAtomIdx &cgatomidx, const MolarEnergy &potential);
    bool subtract(const CGAtomIdx &cgatomidx, const MolarEnergy &potential);

    bool add(const AtomSelection &selected_atoms, const MolarEnergy &potential);
    bool subtract(const AtomSelection &selected_atoms, const MolarEnergy &potential);

    void add(const MolPotentialTable &other);
    void subtract(const MolPotentialTable &other);

    void add(const MolarEnergy &potential);
    void subtract(const MolarEnergy &potential);
    
    void setAll(const MolarEnergy &potential);
    
    void multiply(double value);
    void divide(double value);

private:
    void assertCompatibleWith(const AtomSelection &selection) const;

    /** The number of this molecule */
    MolNum molnum;
    
    /** The UID of the molecular layout that the molecule possessed
        when this table was last constructed */
    QUuid moluid;
    
    /** The total number of CutGroups in this molecule */
    qint32 ncgroups;
    
    /** Index mapping CGIdx to index in table
        of that CutGroup. If this is empty then there
        is a one-to-one mapping (all CutGroups are present) */
    QHash<CGIdx,qint32> cgidx_to_idx;
};

/** A GridPotentialTable contains the potentials at point specified by a grid */
class SIREFF_EXPORT GridPotentialTable
{

friend SIREFF_EXPORT QDataStream& ::operator<<(QDataStream&, const GridPotentialTable&);
friend SIREFF_EXPORT QDataStream& ::operator>>(QDataStream&, GridPotentialTable&);

public:
    typedef QVector<MolarEnergy>::const_iterator const_iterator;
    typedef QVector<MolarEnergy>::iterator iterator;

    GridPotentialTable();
    GridPotentialTable(const Grid &grid);
    GridPotentialTable(const GridPotentialTable &other);
    
    ~GridPotentialTable();
    
    GridPotentialTable& operator=(const GridPotentialTable &other);
    GridPotentialTable& operator=(const MolarEnergy &potential);
    
    bool operator==(const GridPotentialTable &other) const;
    bool operator!=(const GridPotentialTable &other) const;
    
    GridPotentialTable& operator+=(const GridPotentialTable &other);
    GridPotentialTable& operator-=(const GridPotentialTable &other);
    
    GridPotentialTable operator+(const GridPotentialTable &other) const;
    GridPotentialTable operator-(const GridPotentialTable &other) const;
    
    GridPotentialTable& operator+=(const MolarEnergy &potential);
    GridPotentialTable& operator-=(const MolarEnergy &potential);
    
    GridPotentialTable operator+(const MolarEnergy &potential) const;
    GridPotentialTable operator-(const MolarEnergy &potential) const;
    
    GridPotentialTable& operator*=(double value);
    GridPotentialTable& operator/=(double value);
    
    GridPotentialTable operator*(double value) const;
    GridPotentialTable operator/(double value) const;
    
    GridPotentialTable operator-() const;
    
    MolarEnergy& operator[](int i);
    const MolarEnergy& operator[](int i) const;
    
    const MolarEnergy& at(int i) const;
    
    static const char* typeName();
    
    void initialise();
    
    int nPoints() const;
    int count() const;
    
    const Grid& grid() const;
    
    QVector<MolarEnergy> toVector() const;
    
    void add(int ipoint, const MolarEnergy &potential);
    void subtract(int ipoint, const MolarEnergy &potential);
    
    void add(const GridPotentialTable &other);
    void subtract(const GridPotentialTable &other);
    
    void add(const MolarEnergy &potential);
    void subtract(const MolarEnergy &potential);
    
    void setAll(const MolarEnergy &potential);
    
    void multiply(double value);
    void divide(double value);

    MolarEnergy* data();
    const MolarEnergy* data() const;

    const MolarEnergy* constData() const;

    iterator begin();
    iterator end();
    
    const_iterator begin() const;
    const_iterator end() const;
    
    const_iterator constBegin() const;
    const_iterator constEnd() const;

private:
    /** The grid that contains the points at which the field is evaluated */
    GridPtr grd;
    
    /** The potential at each of the grid points */
    QVector<MolarEnergy> potentialvals;
};

/** A PotentialTable is a workspace within which all of the potentials 
    at the points of atoms in molecules, or the points on a grid
    may be stored. A PotentialTable is used as storing the potentials
    may require lots of memory, and continually 
    creating a deleting such large amouts of memory would be inefficient. 
    Also, using a PotentialTable allows for potentials to be accumalated directly, 
    rather than requiring intermediate storage space for the 
    individual components.

    You create a potential table to hold all of the potentials at all of 
    the atoms of all of the molecules in a specified MoleculeGroup,
    or at all of the points of a passed Grid.
    
    The potentials are held in an array that holds the potentials for 
    the molecules in the same order as the molecules appear
    in the molecule group, or in an array that holds the potentials
    in the same order as they appear in the grid. 
    The potential table also comes with an index so you can quickly 
    look up the potential for a specific molecule.

    @author Christopher Woods
*/
class SIREFF_EXPORT PotentialTable
{

friend SIREFF_EXPORT QDataStream& ::operator<<(QDataStream&, const PotentialTable&);
friend SIREFF_EXPORT QDataStream& ::operator>>(QDataStream&, PotentialTable&);

public:
    PotentialTable();
    PotentialTable(const MoleculeGroup &molgroup);

    PotentialTable(const Grid &grid);
    PotentialTable(const QVector<GridPtr> &grids);
    
    PotentialTable(const MoleculeGroup &molgroup, const Grid &grid);
    PotentialTable(const MoleculeGroup &molgroup, const QVector<GridPtr> &grids);
    
    PotentialTable(const PotentialTable &other);
    
    ~PotentialTable();

    static const char* typeName();

    const char* what() const
    {
        return PotentialTable::typeName();
    }

    PotentialTable& operator=(const PotentialTable &other);
    PotentialTable& operator=(const MolarEnergy &potential);

    bool operator==(const PotentialTable &other) const;
    bool operator!=(const PotentialTable &other) const;

    PotentialTable& operator+=(const PotentialTable &other);
    PotentialTable& operator-=(const PotentialTable &other);
    
    PotentialTable operator+(const PotentialTable &other) const;
    PotentialTable operator-(const PotentialTable &other) const;

    PotentialTable& operator+=(const MolarEnergy &potential);
    PotentialTable& operator-=(const MolarEnergy &potential);
    
    PotentialTable operator+(const MolarEnergy &potential) const;
    PotentialTable operator-(const MolarEnergy &potential) const;
    
    PotentialTable& operator*=(double value);
    PotentialTable& operator/=(double value);
    
    PotentialTable operator*(double value) const;
    PotentialTable operator/(double value) const;

    PotentialTable operator-() const;

    bool contains(MolNum molnum) const;
    bool contains(const Grid &grid) const;

    void initialiseTables();

    void initialiseTable(MolNum molnum);
    void initialiseTable(const Grid &grid);

    MolPotentialTable& getTable(MolNum molnum);
    GridPotentialTable& getTable(const Grid &grid);

    const MolPotentialTable& getTable(MolNum molnum) const;
    const GridPotentialTable& getTable(const Grid &grid) const;

    const MolPotentialTable& constGetTable(MolNum molnum) const;
    const GridPotentialTable& constGetTable(const Grid &grid) const;

    bool isEmpty() const;

    const QHash<MolNum,qint32>& index() const;
    
    int indexOf(MolNum molnum) const;
    
    QList<MolNum> molNums() const;

    int nMolecules() const;

    MolPotentialTable* moleculeData();
    const MolPotentialTable* moleculeData() const;
    const MolPotentialTable* constMoleculeData() const;

    int nGrids() const;

    GridPotentialTable* gridData();
    const GridPotentialTable* gridData() const;
    const GridPotentialTable* constGridData() const;

    void assertContainsTableFor(MolNum molnum) const;
    void assertContainsTableFor(const Grid &grid) const;
    
    void add(const PotentialTable &other);
    void subtract(const PotentialTable &other);
    
    void add(const MolarEnergy &potential);
    void subtract(const MolarEnergy &potential);
    
    void setAll(const MolarEnergy &potential);
    
    void multiply(double value);
    void divide(double value);

private:
    void setGroup(const MoleculeGroup &molgroup);

    /** All of the molecule tables */
    QVector<MolPotentialTable> moltables_by_idx;

    /** All of the grid tables */
    QVector<GridPotentialTable> gridtables;

    /** Index mapping from the number of the Molecule to 
        the index of its force table in the above array */
    QHash<MolNum,qint32> molnum_to_idx;
};

#ifndef SIRE_SKIP_INLINE_FUNCTIONS

//////
////// Inline functions for MolPotentialTable
//////

/** Return the molecule number of the molecule whose fields are
    contained in this table */
SIRE_ALWAYS_INLINE MolNum MolPotentialTable::molNum() const
{
    return molnum;
}

/** Return the UID of the molecular layout of the molecule
    whose fields are contained in this table */
SIRE_ALWAYS_INLINE const QUuid& MolPotentialTable::molUID() const
{
    return moluid;
}

/** Return the total number of CutGroups in the molecule whose
    fields are contained in this table */
SIRE_ALWAYS_INLINE int MolPotentialTable::nCutGroups() const
{
    return ncgroups;
}

/** Return the number of selected CutGroups in this table 
    (the number of CutGroups for which fields are held) */
SIRE_ALWAYS_INLINE int MolPotentialTable::nSelectedCutGroups() const
{
    return SireBase::PackedArray2D<MolarEnergy>::count();
}

/** Return whether or not this table contains fields for all
    of the CutGroups in the molecule */
SIRE_ALWAYS_INLINE bool MolPotentialTable::selectedAll() const
{
    return this->nCutGroups() == this->nSelectedCutGroups();
}

/** Return whether or not the CutGroup at index 'cgidx' has been
    selected 
    
    \throw SireError::invalid_index
*/
SIRE_ALWAYS_INLINE bool MolPotentialTable::selected(CGIdx cgidx) const
{
    cgidx = CGIdx(cgidx.map(this->nCutGroups()));
    
    return this->selectedAll() or cgidx_to_idx.contains(cgidx);
}

/** Return the index of the fieldtable for the CutGroup at index
    'cgidx'. This returns -1 if there is no fieldtable for the
    specified CutGroup
    
    \throw SireError::invalid_index
*/
SIRE_ALWAYS_INLINE int MolPotentialTable::map(CGIdx cgidx) const
{
    if (this->selectedAll())
        return cgidx.map( this->nCutGroups() );
    else
        return cgidx_to_idx.value( CGIdx(cgidx.map(this->nCutGroups())), -1 );
}

//////
////// Inline functions for PotentialTable
//////

/** Return whether or not this contains a table for the 
    molecule with number 'molnum' */
SIRE_ALWAYS_INLINE bool PotentialTable::contains(MolNum molnum) const
{
    return molnum_to_idx.contains(molnum);
}

/** Return the table for the molecule with number 'molnum'

    \throw SireMol::missing_molecule
*/
SIRE_ALWAYS_INLINE MolPotentialTable& PotentialTable::getTable(MolNum molnum)
{
    QHash<MolNum,qint32>::const_iterator it = molnum_to_idx.constFind(molnum);
    
    if (it == molnum_to_idx.constEnd())
        this->assertContainsTableFor(molnum);
        
    return moltables_by_idx.data()[ it.value() ];
}

/** Return the table for the molecule with number 'molnum'

    \throw SireMol::missing_molecule
*/
SIRE_ALWAYS_INLINE const MolPotentialTable& PotentialTable::getTable(MolNum molnum) const
{
    QHash<MolNum,qint32>::const_iterator it = molnum_to_idx.constFind(molnum);
    
    if (it == molnum_to_idx.constEnd())
        this->assertContainsTableFor(molnum);
        
    return moltables_by_idx.constData()[ it.value() ];
}

/** Return the table for the molecule with number 'molnum'

    \throw SireMol::missing_molecule
*/
SIRE_ALWAYS_INLINE const MolPotentialTable& PotentialTable::constGetTable(MolNum molnum) const
{
    return this->getTable(molnum);
}

/** Return the number of molecule tables in this object */
SIRE_ALWAYS_INLINE int PotentialTable::nMolecules() const
{
    return moltables_by_idx.count();
}

/** Return the number of grid tables in this object */
SIRE_ALWAYS_INLINE int PotentialTable::nGrids() const
{
    return gridtables.count();
}

/** Return the index used to find the index into the field tables array 
    for the field table for the molecule with a specified number */
SIRE_ALWAYS_INLINE const QHash<MolNum,qint32>& PotentialTable::index() const
{
    return molnum_to_idx;
}

/** Return the numbers of molecules that have field tables in this
    table */
SIRE_ALWAYS_INLINE QList<MolNum> PotentialTable::molNums() const
{
    return molnum_to_idx.keys();
}

/** Return a raw point to the array of field tables for each molecule */
SIRE_ALWAYS_INLINE MolPotentialTable* PotentialTable::moleculeData()
{
    return moltables_by_idx.data();
}

/** Return a raw point to the array of field tables for each molecule */
SIRE_ALWAYS_INLINE const MolPotentialTable* PotentialTable::moleculeData() const
{
    return moltables_by_idx.constData();
}

/** Return a raw point to the array of field tables for each molecule */
SIRE_ALWAYS_INLINE const MolPotentialTable* PotentialTable::constMoleculeData() const
{
    return moltables_by_idx.constData();
}

/** Return a raw pointer to the array of field tables for each grid */
SIRE_ALWAYS_INLINE GridPotentialTable* PotentialTable::gridData()
{
    return gridtables.data();
}

/** Return a raw pointer to the array of field tables for each grid */
SIRE_ALWAYS_INLINE const GridPotentialTable* PotentialTable::gridData() const
{
    return gridtables.constData();
}

/** Return a raw pointer to the array of field tables for each grid */
SIRE_ALWAYS_INLINE const GridPotentialTable* PotentialTable::constGridData() const
{
    return gridtables.constData();
}

#endif //SIRE_SKIP_INLINE_FUNCTIONS

}

SireFF::MolPotentialTable operator+(const SireUnits::Dimension::MolarEnergy &potential,
                                    const SireFF::MolPotentialTable &table);


SireFF::MolPotentialTable operator*(double value, const SireFF::MolPotentialTable &table);

SireFF::PotentialTable operator+(const SireUnits::Dimension::MolarEnergy &potential,
                                 const SireFF::PotentialTable &table);


SireFF::PotentialTable operator*(double value, const SireFF::PotentialTable &table);

Q_DECLARE_METATYPE(SireFF::PotentialTable);
Q_DECLARE_METATYPE(SireFF::GridPotentialTable);
Q_DECLARE_METATYPE(SireFF::MolPotentialTable);

SIRE_EXPOSE_CLASS( SireFF::PotentialTable )
SIRE_EXPOSE_CLASS( SireFF::GridPotentialTable )
SIRE_EXPOSE_CLASS( SireFF::MolPotentialTable )

SIRE_END_HEADER

#endif
