// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Helpers/clone_const_reference.hpp"
#include "InternalFlipMove.pypp.hpp"

namespace bp = boost::python;

#include "SireMaths/vectorproperty.h"

#include "SireMol/angleid.h"

#include "SireMol/atomidx.h"

#include "SireMol/bondid.h"

#include "SireMol/connectivity.h"

#include "SireMol/dihedralid.h"

#include "SireMol/molecule.h"

#include "SireMol/moleditor.h"

#include "SireMol/mover.hpp"

#include "SireMol/partialmolecule.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireSystem/system.h"

#include "SireUnits/dimensions.h"

#include "SireUnits/temperature.h"

#include "SireUnits/units.h"

#include "ensemble.h"

#include "flexibility.h"

#include "internalflipmove.h"

#include <QDebug>

#include <QTime>

#include "internalflipmove.h"

SireMove::InternalFlipMove __copy__(const SireMove::InternalFlipMove &other){ return SireMove::InternalFlipMove(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_InternalFlipMove_class(){

    { //::SireMove::InternalFlipMove
        typedef bp::class_< SireMove::InternalFlipMove, bp::bases< SireMove::MonteCarlo, SireMove::Move, SireBase::Property > > InternalFlipMove_exposer_t;
        InternalFlipMove_exposer_t InternalFlipMove_exposer = InternalFlipMove_exposer_t( "InternalFlipMove", "This class implements an intramolecular Monte Carlo move that uses\nthe move() method to perturb intramolecular degrees of freedom and\nthat may be applied to a random molecule (or part of a molecule)\nwithin a MoleculeGroup. It is based on the ZMatMove class. For dihedrals it makes\nso called flip moves where the perturbation is 180 +- random number.\n\nAuthor: Julien Michel\n", bp::init< bp::optional< SireBase::PropertyMap const & > >(( bp::arg("map")=SireBase::PropertyMap() ), "Null constructor") );
        bp::scope InternalFlipMove_scope( InternalFlipMove_exposer );
        InternalFlipMove_exposer.def( bp::init< SireMol::MoleculeGroup const &, bp::optional< SireBase::PropertyMap const & > >(( bp::arg("molgroup"), bp::arg("map")=SireBase::PropertyMap() ), "Construct the mover move for the passed group of molecules") );
        InternalFlipMove_exposer.def( bp::init< SireMove::Sampler const &, bp::optional< SireBase::PropertyMap const & > >(( bp::arg("sampler"), bp::arg("map")=SireBase::PropertyMap() ), "Construct the mover move that samples molecules from the\npassed sampler") );
        InternalFlipMove_exposer.def( bp::init< SireMove::InternalFlipMove const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMove::InternalFlipMove::centerOfMolecule
        
            typedef ::SireMove::GetPoint const & ( ::SireMove::InternalFlipMove::*centerOfMolecule_function_type)(  ) const;
            centerOfMolecule_function_type centerOfMolecule_function_value( &::SireMove::InternalFlipMove::centerOfMolecule );
            
            InternalFlipMove_exposer.def( 
                "centerOfMolecule"
                , centerOfMolecule_function_value
                , bp::return_value_policy<bp::clone_const_reference>()
                , "Return the function used to find the center of the molecule" );
        
        }
        { //::SireMove::InternalFlipMove::flexibilityProperty
        
            typedef ::SireBase::PropertyName const & ( ::SireMove::InternalFlipMove::*flexibilityProperty_function_type)(  ) const;
            flexibilityProperty_function_type flexibilityProperty_function_value( &::SireMove::InternalFlipMove::flexibilityProperty );
            
            InternalFlipMove_exposer.def( 
                "flexibilityProperty"
                , flexibilityProperty_function_value
                , bp::return_value_policy< bp::copy_const_reference >()
                , "Return the property used to find the flexibility of each molecule" );
        
        }
        { //::SireMove::InternalFlipMove::moleculeGroup
        
            typedef ::SireMol::MoleculeGroup const & ( ::SireMove::InternalFlipMove::*moleculeGroup_function_type)(  ) const;
            moleculeGroup_function_type moleculeGroup_function_value( &::SireMove::InternalFlipMove::moleculeGroup );
            
            InternalFlipMove_exposer.def( 
                "moleculeGroup"
                , moleculeGroup_function_value
                , bp::return_value_policy<bp::clone_const_reference>()
                , "Return the molecule group that is sampled for this move" );
        
        }
        { //::SireMove::InternalFlipMove::move
        
            typedef void ( ::SireMove::InternalFlipMove::*move_function_type)( ::SireSystem::System &,int,bool ) ;
            move_function_type move_function_value( &::SireMove::InternalFlipMove::move );
            
            InternalFlipMove_exposer.def( 
                "move"
                , move_function_value
                , ( bp::arg("system"), bp::arg("nmoves"), bp::arg("record_stats")=(bool)(true) )
                , "Actually perform nmoves moves of the molecules in the\nsystem system, optionally recording simulation statistics\nif record_stats is true" );
        
        }
        InternalFlipMove_exposer.def( bp::self != bp::self );
        { //::SireMove::InternalFlipMove::operator=
        
            typedef ::SireMove::InternalFlipMove & ( ::SireMove::InternalFlipMove::*assign_function_type)( ::SireMove::InternalFlipMove const & ) ;
            assign_function_type assign_function_value( &::SireMove::InternalFlipMove::operator= );
            
            InternalFlipMove_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        InternalFlipMove_exposer.def( bp::self == bp::self );
        { //::SireMove::InternalFlipMove::sampler
        
            typedef ::SireMove::Sampler const & ( ::SireMove::InternalFlipMove::*sampler_function_type)(  ) const;
            sampler_function_type sampler_function_value( &::SireMove::InternalFlipMove::sampler );
            
            InternalFlipMove_exposer.def( 
                "sampler"
                , sampler_function_value
                , bp::return_value_policy<bp::clone_const_reference>()
                , "Return the sampler used to sample molecules to move" );
        
        }
        { //::SireMove::InternalFlipMove::setCenterOfMolecule
        
            typedef void ( ::SireMove::InternalFlipMove::*setCenterOfMolecule_function_type)( ::SireMove::GetPoint const & ) ;
            setCenterOfMolecule_function_type setCenterOfMolecule_function_value( &::SireMove::InternalFlipMove::setCenterOfMolecule );
            
            InternalFlipMove_exposer.def( 
                "setCenterOfMolecule"
                , setCenterOfMolecule_function_value
                , ( bp::arg("center_function") )
                , "Set the function used to find the center of the molecule" );
        
        }
        { //::SireMove::InternalFlipMove::setFlexibilityProperty
        
            typedef void ( ::SireMove::InternalFlipMove::*setFlexibilityProperty_function_type)( ::SireBase::PropertyName const & ) ;
            setFlexibilityProperty_function_type setFlexibilityProperty_function_value( &::SireMove::InternalFlipMove::setFlexibilityProperty );
            
            InternalFlipMove_exposer.def( 
                "setFlexibilityProperty"
                , setFlexibilityProperty_function_value
                , ( bp::arg("property") )
                , "Set the name of the property used to find the flexibility of each molecule" );
        
        }
        { //::SireMove::InternalFlipMove::setGenerator
        
            typedef void ( ::SireMove::InternalFlipMove::*setGenerator_function_type)( ::SireMaths::RanGenerator const & ) ;
            setGenerator_function_type setGenerator_function_value( &::SireMove::InternalFlipMove::setGenerator );
            
            InternalFlipMove_exposer.def( 
                "setGenerator"
                , setGenerator_function_value
                , ( bp::arg("rangenerator") )
                , "Set the random number generator used to generate the random\nnumber used for this move" );
        
        }
        { //::SireMove::InternalFlipMove::setSampler
        
            typedef void ( ::SireMove::InternalFlipMove::*setSampler_function_type)( ::SireMove::Sampler const & ) ;
            setSampler_function_type setSampler_function_value( &::SireMove::InternalFlipMove::setSampler );
            
            InternalFlipMove_exposer.def( 
                "setSampler"
                , setSampler_function_value
                , ( bp::arg("sampler") )
                , "Set the sampler used to sample molecules for this move" );
        
        }
        { //::SireMove::InternalFlipMove::setSampler
        
            typedef void ( ::SireMove::InternalFlipMove::*setSampler_function_type)( ::SireMol::MoleculeGroup const & ) ;
            setSampler_function_type setSampler_function_value( &::SireMove::InternalFlipMove::setSampler );
            
            InternalFlipMove_exposer.def( 
                "setSampler"
                , setSampler_function_value
                , ( bp::arg("molgroup") )
                , "Set the sampler so that it draws molecules uniformly from the\nmolecule group molgroup" );
        
        }
        { //::SireMove::InternalFlipMove::toString
        
            typedef ::QString ( ::SireMove::InternalFlipMove::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMove::InternalFlipMove::toString );
            
            InternalFlipMove_exposer.def( 
                "toString"
                , toString_function_value
                , "Return a string representation of this move" );
        
        }
        { //::SireMove::InternalFlipMove::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMove::InternalFlipMove::typeName );
            
            InternalFlipMove_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        InternalFlipMove_exposer.staticmethod( "typeName" );
        InternalFlipMove_exposer.def( "__copy__", &__copy__);
        InternalFlipMove_exposer.def( "__deepcopy__", &__copy__);
        InternalFlipMove_exposer.def( "clone", &__copy__);
        InternalFlipMove_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMove::InternalFlipMove >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        InternalFlipMove_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMove::InternalFlipMove >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        InternalFlipMove_exposer.def( "__str__", &__str__< ::SireMove::InternalFlipMove > );
        InternalFlipMove_exposer.def( "__repr__", &__str__< ::SireMove::InternalFlipMove > );
    }

}
