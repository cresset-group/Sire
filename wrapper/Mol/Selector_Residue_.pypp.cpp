// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Selector_Residue_.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/errors.h"

#include "SireError/errors.h"

#include "SireMol/errors.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "atom.h"

#include "atomidcombos.h"

#include "chain.h"

#include "evaluator.h"

#include "molecule.h"

#include "mover.hpp"

#include "mover_metaid.h"

#include "reseditor.h"

#include "residue.h"

#include "selector.hpp"

#include "residue.h"

SireMol::Selector<SireMol::Residue> __copy__(const SireMol::Selector<SireMol::Residue> &other){ return SireMol::Selector<SireMol::Residue>(other); }

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_Selector_Residue__class(){

    { //::SireMol::Selector< SireMol::Residue >
        typedef bp::class_< SireMol::Selector< SireMol::Residue >, bp::bases< SireMol::MoleculeView, SireBase::Property > > Selector_Residue__exposer_t;
        Selector_Residue__exposer_t Selector_Residue__exposer = Selector_Residue__exposer_t( "Selector_Residue_", "", bp::init< >("") );
        bp::scope Selector_Residue__scope( Selector_Residue__exposer );
        Selector_Residue__exposer.def( bp::init< SireMol::Residue const & >(( bp::arg("view") ), "") );
        Selector_Residue__exposer.def( bp::init< SireMol::MoleculeData const & >(( bp::arg("moldata") ), "") );
        Selector_Residue__exposer.def( bp::init< SireMol::MoleculeData const &, SireMol::AtomSelection const & >(( bp::arg("moldata"), bp::arg("selected_atoms") ), "") );
        Selector_Residue__exposer.def( bp::init< SireMol::MoleculeData const &, SireMol::Residue::ID const & >(( bp::arg("moldata"), bp::arg("viewid") ), "") );
        Selector_Residue__exposer.def( bp::init< SireMol::MoleculeData const &, QList< SireMol::ResIdx > const & >(( bp::arg("moldata"), bp::arg("idxs") ), "") );
        Selector_Residue__exposer.def( bp::init< SireMol::Selector< SireMol::Residue > const & >(( bp::arg("other") ), "") );
        { //::SireMol::Selector< SireMol::Residue >::add
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*add_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) const;
            add_function_type add_function_value( &::SireMol::Selector< SireMol::Residue >::add );
            
            Selector_Residue__exposer.def( 
                "add"
                , add_function_value
                , ( bp::arg("other") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::add
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*add_function_type)( ::SireMol::Residue const & ) const;
            add_function_type add_function_value( &::SireMol::Selector< SireMol::Residue >::add );
            
            Selector_Residue__exposer.def( 
                "add"
                , add_function_value
                , ( bp::arg("view") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::add
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*add_function_type)( ::SireMol::Residue::ID const & ) const;
            add_function_type add_function_value( &::SireMol::Selector< SireMol::Residue >::add );
            
            Selector_Residue__exposer.def( 
                "add"
                , add_function_value
                , ( bp::arg("id") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::contains
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*contains_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) const;
            contains_function_type contains_function_value( &::SireMol::Selector< SireMol::Residue >::contains );
            
            Selector_Residue__exposer.def( 
                "contains"
                , contains_function_value
                , ( bp::arg("other") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::contains
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*contains_function_type)( ::SireMol::Residue const & ) const;
            contains_function_type contains_function_value( &::SireMol::Selector< SireMol::Residue >::contains );
            
            Selector_Residue__exposer.def( 
                "contains"
                , contains_function_value
                , ( bp::arg("view") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::contains
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*contains_function_type)( ::SireMol::Residue::ID const & ) const;
            contains_function_type contains_function_value( &::SireMol::Selector< SireMol::Residue >::contains );
            
            Selector_Residue__exposer.def( 
                "contains"
                , contains_function_value
                , ( bp::arg("id") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::evaluate
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Evaluator ( ::SireMol::Selector< SireMol::Residue >::*evaluate_function_type)(  ) const;
            evaluate_function_type evaluate_function_value( &::SireMol::Selector< SireMol::Residue >::evaluate );
            
            Selector_Residue__exposer.def( 
                "evaluate"
                , evaluate_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::evaluate
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Evaluator ( ::SireMol::Selector< SireMol::Residue >::*evaluate_function_type)( int ) const;
            evaluate_function_type evaluate_function_value( &::SireMol::Selector< SireMol::Residue >::evaluate );
            
            Selector_Residue__exposer.def( 
                "evaluate"
                , evaluate_function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::evaluate
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Evaluator ( ::SireMol::Selector< SireMol::Residue >::*evaluate_function_type)( int,int ) const;
            evaluate_function_type evaluate_function_value( &::SireMol::Selector< SireMol::Residue >::evaluate );
            
            Selector_Residue__exposer.def( 
                "evaluate"
                , evaluate_function_value
                , ( bp::arg("i"), bp::arg("j") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::hasMetadata
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*hasMetadata_function_type)( ::SireBase::PropertyName const & ) const;
            hasMetadata_function_type hasMetadata_function_value( &::SireMol::Selector< SireMol::Residue >::hasMetadata );
            
            Selector_Residue__exposer.def( 
                "hasMetadata"
                , hasMetadata_function_value
                , ( bp::arg("metakey") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::hasMetadata
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*hasMetadata_function_type)( ::SireBase::PropertyName const &,::SireBase::PropertyName const & ) const;
            hasMetadata_function_type hasMetadata_function_value( &::SireMol::Selector< SireMol::Residue >::hasMetadata );
            
            Selector_Residue__exposer.def( 
                "hasMetadata"
                , hasMetadata_function_value
                , ( bp::arg("key"), bp::arg("metakey") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::hasProperty
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*hasProperty_function_type)( ::SireBase::PropertyName const & ) const;
            hasProperty_function_type hasProperty_function_value( &::SireMol::Selector< SireMol::Residue >::hasProperty );
            
            Selector_Residue__exposer.def( 
                "hasProperty"
                , hasProperty_function_value
                , ( bp::arg("key") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::index
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Residue::Index ( ::SireMol::Selector< SireMol::Residue >::*index_function_type)( int ) const;
            index_function_type index_function_value( &::SireMol::Selector< SireMol::Residue >::index );
            
            Selector_Residue__exposer.def( 
                "index"
                , index_function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*intersection_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) const;
            intersection_function_type intersection_function_value( &::SireMol::Selector< SireMol::Residue >::intersection );
            
            Selector_Residue__exposer.def( 
                "intersection"
                , intersection_function_value
                , ( bp::arg("other") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*intersection_function_type)( ::SireMol::Residue const & ) const;
            intersection_function_type intersection_function_value( &::SireMol::Selector< SireMol::Residue >::intersection );
            
            Selector_Residue__exposer.def( 
                "intersection"
                , intersection_function_value
                , ( bp::arg("view") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*intersection_function_type)( ::SireMol::Residue::ID const & ) const;
            intersection_function_type intersection_function_value( &::SireMol::Selector< SireMol::Residue >::intersection );
            
            Selector_Residue__exposer.def( 
                "intersection"
                , intersection_function_value
                , ( bp::arg("id") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersects
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*intersects_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) const;
            intersects_function_type intersects_function_value( &::SireMol::Selector< SireMol::Residue >::intersects );
            
            Selector_Residue__exposer.def( 
                "intersects"
                , intersects_function_value
                , ( bp::arg("other") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersects
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*intersects_function_type)( ::SireMol::Residue const & ) const;
            intersects_function_type intersects_function_value( &::SireMol::Selector< SireMol::Residue >::intersects );
            
            Selector_Residue__exposer.def( 
                "intersects"
                , intersects_function_value
                , ( bp::arg("view") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::intersects
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*intersects_function_type)( ::SireMol::Residue::ID const & ) const;
            intersects_function_type intersects_function_value( &::SireMol::Selector< SireMol::Residue >::intersects );
            
            Selector_Residue__exposer.def( 
                "intersects"
                , intersects_function_value
                , ( bp::arg("id") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::invert
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*invert_function_type)(  ) const;
            invert_function_type invert_function_value( &::SireMol::Selector< SireMol::Residue >::invert );
            
            Selector_Residue__exposer.def( 
                "invert"
                , invert_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::isEmpty
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*isEmpty_function_type)(  ) const;
            isEmpty_function_type isEmpty_function_value( &::SireMol::Selector< SireMol::Residue >::isEmpty );
            
            Selector_Residue__exposer.def( 
                "isEmpty"
                , isEmpty_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::metadataKeys
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::QStringList ( ::SireMol::Selector< SireMol::Residue >::*metadataKeys_function_type)(  ) const;
            metadataKeys_function_type metadataKeys_function_value( &::SireMol::Selector< SireMol::Residue >::metadataKeys );
            
            Selector_Residue__exposer.def( 
                "metadataKeys"
                , metadataKeys_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::metadataKeys
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::QStringList ( ::SireMol::Selector< SireMol::Residue >::*metadataKeys_function_type)( ::SireBase::PropertyName const & ) const;
            metadataKeys_function_type metadataKeys_function_value( &::SireMol::Selector< SireMol::Residue >::metadataKeys );
            
            Selector_Residue__exposer.def( 
                "metadataKeys"
                , metadataKeys_function_value
                , ( bp::arg("key") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::move
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Selector< SireMol::Residue > > ( ::SireMol::Selector< SireMol::Residue >::*move_function_type)(  ) const;
            move_function_type move_function_value( &::SireMol::Selector< SireMol::Residue >::move );
            
            Selector_Residue__exposer.def( 
                "move"
                , move_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::move
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Selector< SireMol::Residue > > ( ::SireMol::Selector< SireMol::Residue >::*move_function_type)( int ) const;
            move_function_type move_function_value( &::SireMol::Selector< SireMol::Residue >::move );
            
            Selector_Residue__exposer.def( 
                "move"
                , move_function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::move
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Selector< SireMol::Residue > > ( ::SireMol::Selector< SireMol::Residue >::*move_function_type)( int,int ) const;
            move_function_type move_function_value( &::SireMol::Selector< SireMol::Residue >::move );
            
            Selector_Residue__exposer.def( 
                "move"
                , move_function_value
                , ( bp::arg("i"), bp::arg("j") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::nViews
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef int ( ::SireMol::Selector< SireMol::Residue >::*nViews_function_type)(  ) const;
            nViews_function_type nViews_function_value( &::SireMol::Selector< SireMol::Residue >::nViews );
            
            Selector_Residue__exposer.def( 
                "nViews"
                , nViews_function_value
                , "" );
        
        }
        Selector_Residue__exposer.def( bp::self != bp::self );
        { //::SireMol::Selector< SireMol::Residue >::operator()
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Residue ( ::SireMol::Selector< SireMol::Residue >::*__call___function_type)( int ) const;
            __call___function_type __call___function_value( &::SireMol::Selector< SireMol::Residue >::operator() );
            
            Selector_Residue__exposer.def( 
                "__call__"
                , __call___function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator()
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*__call___function_type)( int,int ) const;
            __call___function_type __call___function_value( &::SireMol::Selector< SireMol::Residue >::operator() );
            
            Selector_Residue__exposer.def( 
                "__call__"
                , __call___function_value
                , ( bp::arg("i"), bp::arg("j") )
                , "" );
        
        }
        Selector_Residue__exposer.def( bp::self + bp::self );
        Selector_Residue__exposer.def( bp::self + bp::other< SireMol::ResID >() );
        Selector_Residue__exposer.def( bp::self + bp::other< SireMol::Residue >() );
        Selector_Residue__exposer.def( bp::self - bp::self );
        Selector_Residue__exposer.def( bp::self - bp::other< SireMol::ResID >() );
        Selector_Residue__exposer.def( bp::self - bp::other< SireMol::Residue >() );
        { //::SireMol::Selector< SireMol::Residue >::operator=
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > & ( ::SireMol::Selector< SireMol::Residue >::*assign_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) ;
            assign_function_type assign_function_value( &::SireMol::Selector< SireMol::Residue >::operator= );
            
            Selector_Residue__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator=
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > & ( ::SireMol::Selector< SireMol::Residue >::*assign_function_type)( ::SireMol::Residue const & ) ;
            assign_function_type assign_function_value( &::SireMol::Selector< SireMol::Residue >::operator= );
            
            Selector_Residue__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("view") )
                , bp::return_self< >()
                , "" );
        
        }
        Selector_Residue__exposer.def( bp::self == bp::self );
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( int ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireMol::AtomID const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("atomid") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireMol::ResID const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("resid") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireMol::CGID const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("cgid") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireMol::ChainID const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("chainid") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireMol::SegID const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("segid") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::operator[]
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::MolViewPtr ( ::SireMol::Selector< SireMol::Residue >::*__getitem___function_type)( ::SireID::Index const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::Selector< SireMol::Residue >::operator[] );
            
            Selector_Residue__exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("idx") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::propertyKeys
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::QStringList ( ::SireMol::Selector< SireMol::Residue >::*propertyKeys_function_type)(  ) const;
            propertyKeys_function_type propertyKeys_function_value( &::SireMol::Selector< SireMol::Residue >::propertyKeys );
            
            Selector_Residue__exposer.def( 
                "propertyKeys"
                , propertyKeys_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selectedAll
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef bool ( ::SireMol::Selector< SireMol::Residue >::*selectedAll_function_type)(  ) const;
            selectedAll_function_type selectedAll_function_value( &::SireMol::Selector< SireMol::Residue >::selectedAll );
            
            Selector_Residue__exposer.def( 
                "selectedAll"
                , selectedAll_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::AtomSelection ( ::SireMol::Selector< SireMol::Residue >::*selection_function_type)(  ) const;
            selection_function_type selection_function_value( &::SireMol::Selector< SireMol::Residue >::selection );
            
            Selector_Residue__exposer.def( 
                "selection"
                , selection_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::AtomSelection ( ::SireMol::Selector< SireMol::Residue >::*selection_function_type)( int ) const;
            selection_function_type selection_function_value( &::SireMol::Selector< SireMol::Residue >::selection );
            
            Selector_Residue__exposer.def( 
                "selection"
                , selection_function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selection
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::AtomSelection ( ::SireMol::Selector< SireMol::Residue >::*selection_function_type)( int,int ) const;
            selection_function_type selection_function_value( &::SireMol::Selector< SireMol::Residue >::selection );
            
            Selector_Residue__exposer.def( 
                "selection"
                , selection_function_value
                , ( bp::arg("i"), bp::arg("j") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selector
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*selector_function_type)(  ) const;
            selector_function_type selector_function_value( &::SireMol::Selector< SireMol::Residue >::selector );
            
            Selector_Residue__exposer.def( 
                "selector"
                , selector_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selector
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*selector_function_type)( int ) const;
            selector_function_type selector_function_value( &::SireMol::Selector< SireMol::Residue >::selector );
            
            Selector_Residue__exposer.def( 
                "selector"
                , selector_function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::selector
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*selector_function_type)( int,int ) const;
            selector_function_type selector_function_value( &::SireMol::Selector< SireMol::Residue >::selector );
            
            Selector_Residue__exposer.def( 
                "selector"
                , selector_function_value
                , ( bp::arg("i"), bp::arg("j") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::subtract
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*subtract_function_type)( ::SireMol::Selector< SireMol::Residue > const & ) const;
            subtract_function_type subtract_function_value( &::SireMol::Selector< SireMol::Residue >::subtract );
            
            Selector_Residue__exposer.def( 
                "subtract"
                , subtract_function_value
                , ( bp::arg("other") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::subtract
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*subtract_function_type)( ::SireMol::Residue const & ) const;
            subtract_function_type subtract_function_value( &::SireMol::Selector< SireMol::Residue >::subtract );
            
            Selector_Residue__exposer.def( 
                "subtract"
                , subtract_function_value
                , ( bp::arg("view") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::subtract
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::SireMol::Selector< SireMol::Residue > ( ::SireMol::Selector< SireMol::Residue >::*subtract_function_type)( ::SireMol::Residue::ID const & ) const;
            subtract_function_type subtract_function_value( &::SireMol::Selector< SireMol::Residue >::subtract );
            
            Selector_Residue__exposer.def( 
                "subtract"
                , subtract_function_value
                , ( bp::arg("id") )
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::toString
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef ::QString ( ::SireMol::Selector< SireMol::Residue >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::Selector< SireMol::Residue >::toString );
            
            Selector_Residue__exposer.def( 
                "toString"
                , toString_function_value
                , "" );
        
        }
        { //::SireMol::Selector< SireMol::Residue >::typeName
        
            typedef SireMol::Selector< SireMol::Residue > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::Selector< SireMol::Residue >::typeName );
            
            Selector_Residue__exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        Selector_Residue__exposer.staticmethod( "typeName" );
        Selector_Residue__exposer.def( "__copy__", &__copy__);
        Selector_Residue__exposer.def( "__deepcopy__", &__copy__);
        Selector_Residue__exposer.def( "clone", &__copy__);
        Selector_Residue__exposer.def( "__str__", &__str__< ::SireMol::Selector<SireMol::Residue> > );
        Selector_Residue__exposer.def( "__repr__", &__str__< ::SireMol::Selector<SireMol::Residue> > );
        Selector_Residue__exposer.def( "__len__", &__len_size< ::SireMol::Selector<SireMol::Residue> > );
    }

}
