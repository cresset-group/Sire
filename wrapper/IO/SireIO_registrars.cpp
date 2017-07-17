//WARNING - AUTOGENERATED FILE - CONTENTS WILL BE OVERWRITTEN!
#include <Python.h>

#include "SireIO_registrars.h"

#include "perturbationslibrary.h"
#include "tinker.h"
#include "iobase.h"
#include "pdb.h"
#include "amber.h"
#include "flexibilitylibrary.h"
#include "amberrst7.h"
#include "amberprm.h"
#include "protoms.h"
#include "moleculeparser.h"
#include "zmatrixmaker.h"
#include "trajectorymonitor.h"
#include "amberrst.h"

#include "Helpers/objectregistry.hpp"

void register_SireIO_objects()
{

    ObjectRegistry::registerConverterFor< SireIO::PerturbationsLibrary >();
    ObjectRegistry::registerConverterFor< SireIO::PerturbationsTemplate >();
    ObjectRegistry::registerConverterFor< SireIO::Tinker >();
    ObjectRegistry::registerConverterFor< SireIO::NullIO >();
    ObjectRegistry::registerConverterFor< SireIO::PDB >();
    ObjectRegistry::registerConverterFor< SireIO::Amber >();
    ObjectRegistry::registerConverterFor< SireIO::FlexibilityLibrary >();
    ObjectRegistry::registerConverterFor< SireIO::FlexibilityTemplate >();
    ObjectRegistry::registerConverterFor< SireIO::AmberRst7 >();
    ObjectRegistry::registerConverterFor< SireIO::AmberPrm >();
    ObjectRegistry::registerConverterFor< SireIO::ProtoMS >();
    ObjectRegistry::registerConverterFor< SireIO::NullParser >();
    ObjectRegistry::registerConverterFor< SireIO::ZmatrixMaker >();
    ObjectRegistry::registerConverterFor< SireIO::TrajectoryMonitor >();
    ObjectRegistry::registerConverterFor< SireIO::AmberRst >();

}

