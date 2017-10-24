// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Mol2Substructure.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/parallel.h"

#include "SireBase/stringproperty.h"

#include "SireError/errors.h"

#include "SireIO/errors.h"

#include "SireIO/mol2.h"

#include "SireMol/atomcharges.h"

#include "SireMol/atomcoords.h"

#include "SireMol/atomelements.h"

#include "SireMol/molecule.h"

#include "SireMol/moleditor.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireSystem/system.h"

#include "SireUnits/units.h"

#include "mol2.h"

#include "mol2.h"

SireIO::Mol2Substructure __copy__(const SireIO::Mol2Substructure &other){ return SireIO::Mol2Substructure(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_Mol2Substructure_class(){

    { //::SireIO::Mol2Substructure
        typedef bp::class_< SireIO::Mol2Substructure > Mol2Substructure_exposer_t;
        Mol2Substructure_exposer_t Mol2Substructure_exposer = Mol2Substructure_exposer_t( "Mol2Substructure", "This class provides functionality for readingwriting\nMol2 SUBSTRUCTURE records.\n\nAuthor: Lester Hedges\n", bp::init< >("Default constructor.") );
        bp::scope Mol2Substructure_scope( Mol2Substructure_exposer );
        Mol2Substructure_exposer.def( bp::init< QString const &, QStringList & >(( bp::arg("line"), bp::arg("errors") ), "Constructor.") );
        Mol2Substructure_exposer.def( bp::init< SireMol::Residue const &, QStringList & >(( bp::arg("res"), bp::arg("errors") ), "Constructor.") );
        { //::SireIO::Mol2Substructure::getChain
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getChain_function_type)(  ) const;
            getChain_function_type getChain_function_value( &::SireIO::Mol2Substructure::getChain );
            
            Mol2Substructure_exposer.def( 
                "getChain"
                , getChain_function_value
                , "Get the substructure chain." );
        
        }
        { //::SireIO::Mol2Substructure::getChainSubType
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getChainSubType_function_type)(  ) const;
            getChainSubType_function_type getChainSubType_function_value( &::SireIO::Mol2Substructure::getChainSubType );
            
            Mol2Substructure_exposer.def( 
                "getChainSubType"
                , getChainSubType_function_value
                , "Get the subtype of the chain." );
        
        }
        { //::SireIO::Mol2Substructure::getComment
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getComment_function_type)(  ) const;
            getComment_function_type getComment_function_value( &::SireIO::Mol2Substructure::getComment );
            
            Mol2Substructure_exposer.def( 
                "getComment"
                , getComment_function_value
                , "Get the comment." );
        
        }
        { //::SireIO::Mol2Substructure::getDictType
        
            typedef ::qint64 ( ::SireIO::Mol2Substructure::*getDictType_function_type)(  ) const;
            getDictType_function_type getDictType_function_value( &::SireIO::Mol2Substructure::getDictType );
            
            Mol2Substructure_exposer.def( 
                "getDictType"
                , getDictType_function_value
                , "Get the dictionary type." );
        
        }
        { //::SireIO::Mol2Substructure::getInterBonds
        
            typedef ::qint64 ( ::SireIO::Mol2Substructure::*getInterBonds_function_type)(  ) const;
            getInterBonds_function_type getInterBonds_function_value( &::SireIO::Mol2Substructure::getInterBonds );
            
            Mol2Substructure_exposer.def( 
                "getInterBonds"
                , getInterBonds_function_value
                , "Get the number of inter substructure bonds." );
        
        }
        { //::SireIO::Mol2Substructure::getName
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getName_function_type)(  ) const;
            getName_function_type getName_function_value( &::SireIO::Mol2Substructure::getName );
            
            Mol2Substructure_exposer.def( 
                "getName"
                , getName_function_value
                , "Get the substructure name." );
        
        }
        { //::SireIO::Mol2Substructure::getNumber
        
            typedef ::qint64 ( ::SireIO::Mol2Substructure::*getNumber_function_type)(  ) const;
            getNumber_function_type getNumber_function_value( &::SireIO::Mol2Substructure::getNumber );
            
            Mol2Substructure_exposer.def( 
                "getNumber"
                , getNumber_function_value
                , "Get the substructure number." );
        
        }
        { //::SireIO::Mol2Substructure::getStatusBits
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getStatusBits_function_type)(  ) const;
            getStatusBits_function_type getStatusBits_function_value( &::SireIO::Mol2Substructure::getStatusBits );
            
            Mol2Substructure_exposer.def( 
                "getStatusBits"
                , getStatusBits_function_value
                , "Get the status bits." );
        
        }
        { //::SireIO::Mol2Substructure::getType
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*getType_function_type)(  ) const;
            getType_function_type getType_function_value( &::SireIO::Mol2Substructure::getType );
            
            Mol2Substructure_exposer.def( 
                "getType"
                , getType_function_value
                , "Get the substructure type." );
        
        }
        { //::SireIO::Mol2Substructure::toMol2Record
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*toMol2Record_function_type)(  ) const;
            toMol2Record_function_type toMol2Record_function_value( &::SireIO::Mol2Substructure::toMol2Record );
            
            Mol2Substructure_exposer.def( 
                "toMol2Record"
                , toMol2Record_function_value
                , "Generate a Mol2 record from the feature data." );
        
        }
        { //::SireIO::Mol2Substructure::toString
        
            typedef ::QString ( ::SireIO::Mol2Substructure::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireIO::Mol2Substructure::toString );
            
            Mol2Substructure_exposer.def( 
                "toString"
                , toString_function_value
                , "Generate a string representation of the object." );
        
        }
        { //::SireIO::Mol2Substructure::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireIO::Mol2Substructure::typeName );
            
            Mol2Substructure_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        Mol2Substructure_exposer.staticmethod( "typeName" );
        Mol2Substructure_exposer.def( "__copy__", &__copy__);
        Mol2Substructure_exposer.def( "__deepcopy__", &__copy__);
        Mol2Substructure_exposer.def( "clone", &__copy__);
        Mol2Substructure_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireIO::Mol2Substructure >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        Mol2Substructure_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireIO::Mol2Substructure >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        Mol2Substructure_exposer.def( "__str__", &__str__< ::SireIO::Mol2Substructure > );
        Mol2Substructure_exposer.def( "__repr__", &__str__< ::SireIO::Mol2Substructure > );
    }

}
